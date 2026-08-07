#include <arpa/inet.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fmtmsg.h>
#include <fnmatch.h>
#include <ftw.h>
#include <limits.h>
#include <math.h>
#include <netinet/in.h>
#include <p101_c/p101_complex.h>
#include <p101_c/p101_ctype.h>
#include <p101_c/p101_fenv.h>
#include <p101_c/p101_inttypes.h>
#include <p101_c/p101_locale.h>
#include <p101_c/p101_math.h>
#include <p101_c/p101_setjmp.h>
#include <p101_c/p101_signal.h>
#include <p101_c/p101_stdatomic.h>
#include <p101_c/p101_stdio.h>
#include <p101_c/p101_stdlib.h>
#include <p101_c/p101_string.h>
#include <p101_c/p101_time.h>
#include <p101_c/p101_wchar.h>
#include <p101_c/p101_wctype.h>
#include <p101_env/env.h>
#include <p101_error/error.h>
#include <pthread.h>
#include <search.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <utmpx.h>

static int    failures;
static size_t fault_resource_events;
static FILE  *outcome_stream;
static bool   native_child_process;
static int    native_child_status = EXIT_SUCCESS;

#define P101_TEST_ERRNO_SENTINEL 0x5A5A

#ifdef __linux__
    #define P101_TEST_PLATFORM "linux"
#elif defined(__APPLE__)
    #define P101_TEST_PLATFORM "macos"
#elif defined(__FreeBSD__)
    #define P101_TEST_PLATFORM "freebsd"
#else
    #define P101_TEST_PLATFORM "posix"
#endif

#define EXPECT(condition)                                                                                                                                                                                                                                          \
    do                                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                              \
        if(!(condition))                                                                                                                                                                                                                                           \
        {                                                                                                                                                                                                                                                          \
            fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition);                                                                                                                                                                                   \
            failures++;                                                                                                                                                                                                                                            \
        }                                                                                                                                                                                                                                                          \
    } while(0)

#define P101_NATIVE_CLEANUP_ERRNO(expression)                                                                                                                                                                                                                      \
    do                                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                              \
        if((expression) != 0)                                                                                                                                                                                                                                      \
        {                                                                                                                                                                                                                                                          \
            fprintf(stderr, "native cleanup failed: %s: %s\n", #expression, strerror(errno));                                                                                                                                                                      \
            native_passed = false;                                                                                                                                                                                                                                 \
        }                                                                                                                                                                                                                                                          \
    } while(0)

#define P101_NATIVE_CLEANUP_STATUS(expression)                                                                                                                                                                                                                     \
    do                                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                              \
        int p101_cleanup_status_ = (expression);                                                                                                                                                                                                                   \
        if(p101_cleanup_status_ != 0)                                                                                                                                                                                                                              \
        {                                                                                                                                                                                                                                                          \
            fprintf(stderr, "native cleanup failed: %s: status %d\n", #expression, p101_cleanup_status_);                                                                                                                                                          \
            native_passed = false;                                                                                                                                                                                                                                 \
        }                                                                                                                                                                                                                                                          \
    } while(0)

#define P101_NATIVE_CLEANUP_UNLINK_IF_PRESENT(path)                                                                                                                                                                                                                \
    do                                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                              \
        bool p101_cleanup_ok_;                                                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                   \
        p101_cleanup_ok_ = native_unlink_if_present(path);                                                                                                                                                                                                         \
        if(!p101_cleanup_ok_)                                                                                                                                                                                                                                      \
        {                                                                                                                                                                                                                                                          \
            native_passed = false;                                                                                                                                                                                                                                 \
        }                                                                                                                                                                                                                                                          \
    } while(0)

#define P101_NATIVE_FORMAT_PID_PATH_OR_SKIP(buffer, format)                                                                                                                                                                                                        \
    do                                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                              \
        bool p101_format_ok_;                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                   \
        p101_format_ok_ = native_format_pid_path((buffer), sizeof(buffer), (format));                                                                                                                                                                              \
        if(!p101_format_ok_)                                                                                                                                                                                                                                       \
        {                                                                                                                                                                                                                                                          \
            fprintf(stderr, "native setup failed: path formatting\n");                                                                                                                                                                                             \
            native_child_status = 77;                                                                                                                                                                                                                              \
            goto native_child_done_;                                                                                                                                                                                                                               \
        }                                                                                                                                                                                                                                                          \
    } while(0)

struct fault_state
{
    int checks;
    int code;
};

static pid_t native_waitpid_nointr(pid_t pid, int *status) P101_ATTR_SEMANTIC_ROLE("p101:test:eintr-safe-wait-adapter")
{
    pid_t result;

    do
    {
        result = waitpid(pid, status, 0);
    } while(result < 0 && errno == EINTR);
    return result;
}

static void write_outcome(const char *wrapper, const char *domain, const char *symbol, int code, int passed)
{
    int written;

    if(outcome_stream != NULL)
    {
        written = fprintf(outcome_stream, "P101WRAPPER\t1\tFAULT\t%s\tlib_c\t%s\t%s\t%s\t%d\t%s\n", P101_TEST_PLATFORM, wrapper, domain, symbol, code, passed ? "PASS" : "FAIL");
        if(written < 0 || fflush(outcome_stream) != 0)
        {
            fprintf(stderr, "FAIL: cannot write wrapper outcome receipt\n");
            failures++;
        }
    }
}

static int fail_next_call(const struct p101_env *env, const char *call_name, void *user_data)
{
    struct fault_state *state;

    (void)env;
    (void)call_name;
    state = user_data;
    state->checks++;
    return state->code;
}

static void count_fd_event(const struct p101_env *env, p101_env_fd_event event, int fd, const char *file_name, const char *function_name, int line_number, void *user_data)
{
    (void)env;
    (void)event;
    (void)fd;
    (void)file_name;
    (void)function_name;
    (void)line_number;
    (void)user_data;
    fault_resource_events++;
}

static void count_alloc_event(const struct p101_env *env, p101_env_alloc_event event, const void *ptr, const void *new_ptr, size_t size, const char *file_name, const char *function_name, int line_number, void *user_data)
{
    (void)env;
    (void)event;
    (void)ptr;
    (void)new_ptr;
    (void)size;
    (void)file_name;
    (void)function_name;
    (void)line_number;
    (void)user_data;
    fault_resource_events++;
}

static void count_resource_event(const struct p101_env *env, p101_env_resource_kind event, const char *resource_class, const char *resource_id, const char *related_id, size_t size, const char *metadata, const char *file_name, const char *function_name,
                                 int line_number, void *user_data)
{
    (void)env;
    (void)event;
    (void)resource_class;
    (void)resource_id;
    (void)related_id;
    (void)size;
    (void)metadata;
    (void)file_name;
    (void)function_name;
    (void)line_number;
    (void)user_data;
    fault_resource_events++;
}

/* P101_TEST_CASE(p101_clock) */
static void test_p101_clock(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int         errors[]      = {EOVERFLOW};
    static const char *const error_names[] = {"EOVERFLOW"};
#elif defined(__APPLE__)
    static const int         errors[]      = {EOVERFLOW};
    static const char *const error_names[] = {"EOVERFLOW"};
#elif defined(__FreeBSD__)
    static const int         errors[]      = {EOVERFLOW};
    static const char *const error_names[] = {"EOVERFLOW"};
#else
    static const int         errors[]      = {EOVERFLOW};
    static const char *const error_names[] = {"EOVERFLOW"};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};
        int                failures_before;

        failures_before = failures;
        EXPECT(p101_error_has_no_error(err));
        fault_resource_events = 0U;
        errno                 = P101_TEST_ERRNO_SENTINEL;
        p101_env_set_fault_injector(env, fail_next_call, &state);
        clock_t result = p101_clock(env, err);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.code));
        EXPECT(errno == P101_TEST_ERRNO_SENTINEL);
        EXPECT(result == ((clock_t)-1));
        EXPECT(fault_resource_events == 0U);
        write_outcome("p101_clock", "errno", error_names[index], state.code, failures == failures_before);
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
    {
        int   native_status = 0;
        pid_t native_pid    = fork();

        EXPECT(native_pid >= 0);
        if(native_pid == 0)
        {
            bool               native_passed = true;
            struct p101_error *native_err    = NULL;
            struct p101_env   *native_env    = NULL;

            native_child_process = true;
            failures             = 0;
            (void)alarm(2U);
            if(unsetenv("P101_CALL_LOG") != 0 || unsetenv("P101_RESOURCE_LOG") != 0)
            {
                fprintf(stderr, "native setup failed: cannot clear p101 logging environment\n");
                native_child_status = 77;
                goto native_child_done_;
            }
            native_err = p101_error_create(false);
            if(native_err == NULL)
            {
                native_child_status = 77;
                goto native_child_done_;
            }
            native_env = p101_env_create(native_err, NULL);
            if(native_env == NULL)
            {
                native_child_status = 77;
                goto native_child_done_;
            }
            clock_t native_result = p101_clock(native_env, native_err);
            (void)native_result;
            if(p101_error_has_error(native_err))
            {
                fprintf(stderr, "native smoke failed: p101_clock: %s\n", p101_error_get_message(native_err));
                native_passed = false;
            }
            native_child_status = native_passed ? EXIT_SUCCESS : EXIT_FAILURE;
        native_child_done_:
            p101_env_destroy(native_env);
            p101_error_destroy(native_err);
        }
        if(native_pid > 0)
        {
            EXPECT(native_waitpid_nointr(native_pid, &native_status) == native_pid);
            if(WIFSIGNALED(native_status))
            {
                fprintf(stderr, "native smoke terminated by signal: p101_clock: %d\n", WTERMSIG(native_status));
            }
            EXPECT(WIFEXITED(native_status));
            if(WIFEXITED(native_status))
            {
                if(WEXITSTATUS(native_status) != EXIT_SUCCESS)
                {
                    fprintf(stderr, "native smoke exited unsuccessfully: p101_clock: %d\n", WEXITSTATUS(native_status));
                }
                EXPECT(WEXITSTATUS(native_status) == EXIT_SUCCESS);
            }
        }
        p101_error_reset(err);
    }
}

/* P101_TEST_CASE(p101_mktime) */
static void test_p101_mktime(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int         errors[]      = {EOVERFLOW};
    static const char *const error_names[] = {"EOVERFLOW"};
#elif defined(__APPLE__)
    static const int         errors[]      = {EOVERFLOW};
    static const char *const error_names[] = {"EOVERFLOW"};
#elif defined(__FreeBSD__)
    static const int         errors[]      = {EOVERFLOW};
    static const char *const error_names[] = {"EOVERFLOW"};
#else
    static const int         errors[]      = {EOVERFLOW};
    static const char *const error_names[] = {"EOVERFLOW"};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};
        int                failures_before;

        failures_before = failures;
        EXPECT(p101_error_has_no_error(err));
        fault_resource_events = 0U;
        errno                 = P101_TEST_ERRNO_SENTINEL;
        p101_env_set_fault_injector(env, fail_next_call, &state);
        time_t result = p101_mktime(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.code));
        EXPECT(errno == P101_TEST_ERRNO_SENTINEL);
        EXPECT(result == ((time_t)-1));
        EXPECT(fault_resource_events == 0U);
        write_outcome("p101_mktime", "errno", error_names[index], state.code, failures == failures_before);
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
    {
        int   native_status = 0;
        pid_t native_pid    = fork();

        EXPECT(native_pid >= 0);
        if(native_pid == 0)
        {
            bool               native_passed = true;
            struct p101_error *native_err    = NULL;
            struct p101_env   *native_env    = NULL;

            native_child_process = true;
            failures             = 0;
            (void)alarm(2U);
            if(unsetenv("P101_CALL_LOG") != 0 || unsetenv("P101_RESOURCE_LOG") != 0)
            {
                fprintf(stderr, "native setup failed: cannot clear p101 logging environment\n");
                native_child_status = 77;
                goto native_child_done_;
            }
            native_err = p101_error_create(false);
            if(native_err == NULL)
            {
                native_child_status = 77;
                goto native_child_done_;
            }
            native_env = p101_env_create(native_err, NULL);
            if(native_env == NULL)
            {
                native_child_status = 77;
                goto native_child_done_;
            }
            struct tm native_argument_2 = {0};
            time_t    native_result     = p101_mktime(native_env, native_err, &native_argument_2);
            (void)native_result;
            if(p101_error_has_error(native_err))
            {
                fprintf(stderr, "native smoke failed: p101_mktime: %s\n", p101_error_get_message(native_err));
                native_passed = false;
            }
            native_child_status = native_passed ? EXIT_SUCCESS : EXIT_FAILURE;
        native_child_done_:
            p101_env_destroy(native_env);
            p101_error_destroy(native_err);
        }
        if(native_pid > 0)
        {
            EXPECT(native_waitpid_nointr(native_pid, &native_status) == native_pid);
            if(WIFSIGNALED(native_status))
            {
                fprintf(stderr, "native smoke terminated by signal: p101_mktime: %d\n", WTERMSIG(native_status));
            }
            EXPECT(WIFEXITED(native_status));
            if(WIFEXITED(native_status))
            {
                if(WEXITSTATUS(native_status) != EXIT_SUCCESS)
                {
                    fprintf(stderr, "native smoke exited unsuccessfully: p101_mktime: %d\n", WEXITSTATUS(native_status));
                }
                EXPECT(WEXITSTATUS(native_status) == EXIT_SUCCESS);
            }
        }
        p101_error_reset(err);
    }
}

/* P101_TEST_CASE(p101_strftime) */
static void test_p101_strftime(struct p101_env *env, struct p101_error *err)
{
    char          argument_2[4];
    unsigned char argument_2_before[sizeof(argument_2)];
    memset(argument_2, 0xA5, sizeof(argument_2));
    memcpy(argument_2_before, argument_2, sizeof(argument_2));
#ifdef __linux__
    static const int         errors[]      = {EINVAL, EOVERFLOW, ERANGE};
    static const char *const error_names[] = {"EINVAL", "EOVERFLOW", "ERANGE"};
#elif defined(__APPLE__)
    static const int         errors[]      = {EINVAL, EOVERFLOW, ERANGE};
    static const char *const error_names[] = {"EINVAL", "EOVERFLOW", "ERANGE"};
#elif defined(__FreeBSD__)
    static const int         errors[]      = {EINVAL, EOVERFLOW, ERANGE};
    static const char *const error_names[] = {"EINVAL", "EOVERFLOW", "ERANGE"};
#else
    static const int         errors[]      = {EINVAL, EOVERFLOW, ERANGE};
    static const char *const error_names[] = {"EINVAL", "EOVERFLOW", "ERANGE"};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};
        int                failures_before;

        failures_before = failures;
        EXPECT(p101_error_has_no_error(err));
        fault_resource_events = 0U;
        errno                 = P101_TEST_ERRNO_SENTINEL;
        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_strftime(env, err, argument_2, 0, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.code));
        EXPECT(errno == P101_TEST_ERRNO_SENTINEL);
        EXPECT(result == (0));
        EXPECT(memcmp(argument_2, argument_2_before, sizeof(argument_2)) == 0);
        EXPECT(fault_resource_events == 0U);
        write_outcome("p101_strftime", "errno", error_names[index], state.code, failures == failures_before);
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
    {
        int   native_status = 0;
        pid_t native_pid    = fork();

        EXPECT(native_pid >= 0);
        if(native_pid == 0)
        {
            bool               native_passed = true;
            struct p101_error *native_err    = NULL;
            struct p101_env   *native_env    = NULL;

            native_child_process = true;
            failures             = 0;
            (void)alarm(2U);
            if(unsetenv("P101_CALL_LOG") != 0 || unsetenv("P101_RESOURCE_LOG") != 0)
            {
                fprintf(stderr, "native setup failed: cannot clear p101 logging environment\n");
                native_child_status = 77;
                goto native_child_done_;
            }
            native_err = p101_error_create(false);
            if(native_err == NULL)
            {
                native_child_status = 77;
                goto native_child_done_;
            }
            native_env = p101_env_create(native_err, NULL);
            if(native_env == NULL)
            {
                native_child_status = 77;
                goto native_child_done_;
            }
            char      native_argument_2[PATH_MAX] = {0};
            struct tm native_argument_5           = {0};
            size_t    native_result               = p101_strftime(native_env, native_err, native_argument_2, 0, "p101", &native_argument_5);
            (void)native_result;
            if(p101_error_has_error(native_err))
            {
                fprintf(stderr, "native smoke failed: p101_strftime: %s\n", p101_error_get_message(native_err));
                native_passed = false;
            }
            native_child_status = native_passed ? EXIT_SUCCESS : EXIT_FAILURE;
        native_child_done_:
            p101_env_destroy(native_env);
            p101_error_destroy(native_err);
        }
        if(native_pid > 0)
        {
            EXPECT(native_waitpid_nointr(native_pid, &native_status) == native_pid);
            if(WIFSIGNALED(native_status))
            {
                fprintf(stderr, "native smoke terminated by signal: p101_strftime: %d\n", WTERMSIG(native_status));
            }
            EXPECT(WIFEXITED(native_status));
            if(WIFEXITED(native_status))
            {
                if(WEXITSTATUS(native_status) != EXIT_SUCCESS)
                {
                    fprintf(stderr, "native smoke exited unsuccessfully: p101_strftime: %d\n", WEXITSTATUS(native_status));
                }
                EXPECT(WEXITSTATUS(native_status) == EXIT_SUCCESS);
            }
        }
        p101_error_reset(err);
    }
}

/* P101_TEST_CASE(p101_time) */
static void test_p101_time(struct p101_env *env, struct p101_error *err)
{
    time_t        argument_2[4];
    unsigned char argument_2_before[sizeof(argument_2)];
    memset(argument_2, 0xA5, sizeof(argument_2));
    memcpy(argument_2_before, argument_2, sizeof(argument_2));
#ifdef __linux__
    static const int         errors[]      = {EFAULT, EOVERFLOW};
    static const char *const error_names[] = {"EFAULT", "EOVERFLOW"};
#elif defined(__APPLE__)
    static const int         errors[]      = {EOVERFLOW};
    static const char *const error_names[] = {"EOVERFLOW"};
#elif defined(__FreeBSD__)
    static const int         errors[]      = {EOVERFLOW};
    static const char *const error_names[] = {"EOVERFLOW"};
#else
    static const int         errors[]      = {EOVERFLOW};
    static const char *const error_names[] = {"EOVERFLOW"};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};
        int                failures_before;

        failures_before = failures;
        EXPECT(p101_error_has_no_error(err));
        fault_resource_events = 0U;
        errno                 = P101_TEST_ERRNO_SENTINEL;
        p101_env_set_fault_injector(env, fail_next_call, &state);
        time_t result = p101_time(env, err, argument_2);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.code));
        EXPECT(errno == P101_TEST_ERRNO_SENTINEL);
        EXPECT(result == ((time_t)-1));
        EXPECT(memcmp(argument_2, argument_2_before, sizeof(argument_2)) == 0);
        EXPECT(fault_resource_events == 0U);
        write_outcome("p101_time", "errno", error_names[index], state.code, failures == failures_before);
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
    {
        int   native_status = 0;
        pid_t native_pid    = fork();

        EXPECT(native_pid >= 0);
        if(native_pid == 0)
        {
            bool               native_passed = true;
            struct p101_error *native_err    = NULL;
            struct p101_env   *native_env    = NULL;

            native_child_process = true;
            failures             = 0;
            (void)alarm(2U);
            if(unsetenv("P101_CALL_LOG") != 0 || unsetenv("P101_RESOURCE_LOG") != 0)
            {
                fprintf(stderr, "native setup failed: cannot clear p101 logging environment\n");
                native_child_status = 77;
                goto native_child_done_;
            }
            native_err = p101_error_create(false);
            if(native_err == NULL)
            {
                native_child_status = 77;
                goto native_child_done_;
            }
            native_env = p101_env_create(native_err, NULL);
            if(native_env == NULL)
            {
                native_child_status = 77;
                goto native_child_done_;
            }
            time_t native_argument_2 = {0};
            time_t native_result     = p101_time(native_env, native_err, &native_argument_2);
            (void)native_result;
            if(p101_error_has_error(native_err))
            {
                fprintf(stderr, "native smoke failed: p101_time: %s\n", p101_error_get_message(native_err));
                native_passed = false;
            }
            native_child_status = native_passed ? EXIT_SUCCESS : EXIT_FAILURE;
        native_child_done_:
            p101_env_destroy(native_env);
            p101_error_destroy(native_err);
        }
        if(native_pid > 0)
        {
            EXPECT(native_waitpid_nointr(native_pid, &native_status) == native_pid);
            if(WIFSIGNALED(native_status))
            {
                fprintf(stderr, "native smoke terminated by signal: p101_time: %d\n", WTERMSIG(native_status));
            }
            EXPECT(WIFEXITED(native_status));
            if(WIFEXITED(native_status))
            {
                if(WEXITSTATUS(native_status) != EXIT_SUCCESS)
                {
                    fprintf(stderr, "native smoke exited unsuccessfully: p101_time: %d\n", WEXITSTATUS(native_status));
                }
                EXPECT(WEXITSTATUS(native_status) == EXIT_SUCCESS);
            }
        }
        p101_error_reset(err);
    }
}

/* P101_TEST_CASE(p101_timespec_get) */
static void test_p101_timespec_get(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int         errors[]      = {EIO};
    static const char *const error_names[] = {"EIO"};
#elif defined(__APPLE__)
    static const int         errors[]      = {EIO};
    static const char *const error_names[] = {"EIO"};
#elif defined(__FreeBSD__)
    static const int         errors[]      = {EIO};
    static const char *const error_names[] = {"EIO"};
#else
    static const int         errors[]      = {EIO};
    static const char *const error_names[] = {"EIO"};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};
        int                failures_before;

        failures_before = failures;
        EXPECT(p101_error_has_no_error(err));
        fault_resource_events = 0U;
        errno                 = P101_TEST_ERRNO_SENTINEL;
        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_timespec_get(env, err, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.code));
        EXPECT(errno == P101_TEST_ERRNO_SENTINEL);
        EXPECT(result == (0));
        EXPECT(fault_resource_events == 0U);
        write_outcome("p101_timespec_get", "errno", error_names[index], state.code, failures == failures_before);
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
    {
        int   native_status = 0;
        pid_t native_pid    = fork();

        EXPECT(native_pid >= 0);
        if(native_pid == 0)
        {
            bool               native_passed = true;
            struct p101_error *native_err    = NULL;
            struct p101_env   *native_env    = NULL;

            native_child_process = true;
            failures             = 0;
            (void)alarm(2U);
            if(unsetenv("P101_CALL_LOG") != 0 || unsetenv("P101_RESOURCE_LOG") != 0)
            {
                fprintf(stderr, "native setup failed: cannot clear p101 logging environment\n");
                native_child_status = 77;
                goto native_child_done_;
            }
            native_err = p101_error_create(false);
            if(native_err == NULL)
            {
                native_child_status = 77;
                goto native_child_done_;
            }
            native_env = p101_env_create(native_err, NULL);
            if(native_env == NULL)
            {
                native_child_status = 77;
                goto native_child_done_;
            }
            struct timespec native_argument_2 = {0};
            int             native_result     = p101_timespec_get(native_env, native_err, &native_argument_2, 0);
            (void)native_result;
            if(p101_error_has_error(native_err))
            {
                fprintf(stderr, "native smoke failed: p101_timespec_get: %s\n", p101_error_get_message(native_err));
                native_passed = false;
            }
            native_child_status = native_passed ? EXIT_SUCCESS : EXIT_FAILURE;
        native_child_done_:
            p101_env_destroy(native_env);
            p101_error_destroy(native_err);
        }
        if(native_pid > 0)
        {
            EXPECT(native_waitpid_nointr(native_pid, &native_status) == native_pid);
            if(WIFSIGNALED(native_status))
            {
                fprintf(stderr, "native smoke terminated by signal: p101_timespec_get: %d\n", WTERMSIG(native_status));
            }
            EXPECT(WIFEXITED(native_status));
            if(WIFEXITED(native_status))
            {
                if(WEXITSTATUS(native_status) != EXIT_SUCCESS)
                {
                    fprintf(stderr, "native smoke exited unsuccessfully: p101_timespec_get: %d\n", WEXITSTATUS(native_status));
                }
                EXPECT(WEXITSTATUS(native_status) == EXIT_SUCCESS);
            }
        }
        p101_error_reset(err);
    }
}

int main(void)
{
    const char        *outcome_path;
    struct p101_error *err = NULL;
    struct p101_env   *env = NULL;
    int                status;

    outcome_path = getenv("P101_WRAPPER_OUTCOME_LOG");
    if(outcome_path != NULL && outcome_path[0] != '\0')
    {
        outcome_stream = fopen(outcome_path, "a");
        if(outcome_stream == NULL)
        {
            fprintf(stderr, "FAIL: cannot open wrapper outcome receipt\n");
            failures++;
        }
    }
    if(failures == 0)
    {
        err = p101_error_create(false);
    }
    if(err != NULL)
    {
        env = p101_env_create(err, NULL);
    }
    if(env == NULL)
    {
        failures++;
    }
    else
    {
        p101_env_set_fd_observer(env, count_fd_event, NULL);
        p101_env_set_alloc_observer(env, count_alloc_event, NULL);
        p101_env_set_resource_observer(env, count_resource_event, NULL);
        if(!native_child_process)
        {
            test_p101_clock(env, err);
        }
        if(!native_child_process)
        {
            test_p101_mktime(env, err);
        }
        if(!native_child_process)
        {
            test_p101_strftime(env, err);
        }
        if(!native_child_process)
        {
            test_p101_time(env, err);
        }
        if(!native_child_process)
        {
            test_p101_timespec_get(env, err);
        }
    }
    p101_env_destroy(env);
    p101_error_destroy(err);
    if(outcome_stream != NULL && fclose(outcome_stream) != 0)
    {
        fprintf(stderr, "FAIL: cannot close wrapper outcome receipt\n");
        failures++;
    }
    if(native_child_process)
    {
        status = native_child_status;
        if(status == EXIT_SUCCESS && failures != 0)
        {
            status = EXIT_FAILURE;
        }
    }
    else
    {
        status = failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
    }
    return status;
}
