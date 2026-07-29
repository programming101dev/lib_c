#include <errno.h>
#include <fenv.h>
#include <limits.h>
#include <p101_c/p101_fenv.h>
#include <p101_c/p101_inttypes.h>
#include <p101_c/p101_math.h>
#include <p101_c/p101_stdatomic.h>
#include <p101_c/p101_stdio.h>
#include <p101_c/p101_stdlib.h>
#include <p101_c/p101_string.h>
#include <p101_c/p101_time.h>
#include <p101_c/p101_wchar.h>
#include <p101_env/env.h>
#include <p101_error/error.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int failures;

#define EXPECT(condition)                                                                                                                                                                                                                                          \
    do                                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                              \
        if(!(condition))                                                                                                                                                                                                                                           \
        {                                                                                                                                                                                                                                                          \
            fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition);                                                                                                                                                                                   \
            failures++;                                                                                                                                                                                                                                            \
        }                                                                                                                                                                                                                                                          \
    } while(0)

struct event_counts
{
    int enters;
    int exits;
    int opens;
    int closes;
    int allocations;
    int frees;
    int reallocations;
};

struct fault_state
{
    const char *target;
    int         checks;
};

static void observe_calls(const struct p101_env *env, p101_env_call_event event, const char *call_name, const char *arguments, const char *result, const char *file_name, const char *function_name, int line_number, void *user_data)
{
    struct event_counts *counts;

    (void)env;
    (void)call_name;
    (void)arguments;
    (void)result;
    (void)file_name;
    (void)function_name;
    (void)line_number;
    counts = user_data;
    if(event == P101_ENV_CALL_ENTER)
    {
        counts->enters++;
    }
    else
    {
        counts->exits++;
    }
}

static void observe_fds(const struct p101_env *env, p101_env_fd_event event, int fd, const char *file_name, const char *function_name, int line_number, void *user_data)
{
    struct event_counts *counts;

    (void)env;
    (void)fd;
    (void)file_name;
    (void)function_name;
    (void)line_number;
    counts = user_data;
    if(event == P101_ENV_FD_OPEN)
    {
        counts->opens++;
    }
    else
    {
        counts->closes++;
    }
}

static void observe_allocations(const struct p101_env *env, p101_env_alloc_event event, const void *ptr, const void *new_ptr, size_t size, const char *file_name, const char *function_name, int line_number, void *user_data)
{
    struct event_counts *counts;

    (void)env;
    (void)ptr;
    (void)new_ptr;
    (void)size;
    (void)file_name;
    (void)function_name;
    (void)line_number;
    counts = user_data;
    if(event == P101_ENV_ALLOC_ALLOC)
    {
        counts->allocations++;
    }
    else if(event == P101_ENV_ALLOC_FREE)
    {
        counts->frees++;
    }
    else
    {
        counts->reallocations++;
    }
}

static int fail_named_call(const struct p101_env *env, const char *call_name, void *user_data)
{
    struct fault_state *state;

    (void)env;
    state = user_data;
    state->checks++;

    return (strcmp(call_name, state->target) == 0) ? ENOMEM : 0;
}

static void test_stdio_contracts(struct p101_env *env, struct p101_error *err)
{
    struct event_counts counts = {0};
    FILE               *stream;

    p101_env_set_fd_observer(env, observe_fds, &counts);
    stream = p101_tmpfile(env, err);
    EXPECT(stream != NULL);
    EXPECT(p101_error_has_no_error(err));
    EXPECT(counts.opens == 1);

    if(stream != NULL)
    {
        EXPECT(p101_setvbuf(env, err, stream, NULL, _IONBF, 0) == 0);
        EXPECT(p101_error_has_no_error(err));
        EXPECT(p101_fclose(env, err, stream) == 0);
        EXPECT(counts.closes == 1);
    }
    p101_env_set_fd_observer(env, NULL, NULL);

    errno = ENOENT;
    p101_perror(env, "expected test diagnostic");
    EXPECT(errno == ENOENT);
}

static void test_time_and_fenv(struct p101_env *env, struct p101_error *err)
{
    struct tm   before_epoch = {0};
    char        output[2];
    const char *empty_format = "";

    if(fesetround(FE_DOWNWARD) == 0)
    {
        EXPECT(p101_fegetround(env, err) == FE_DOWNWARD);
        EXPECT(p101_error_has_no_error(err));
        EXPECT(fesetround(FE_TONEAREST) == 0);
    }

    if(feclearexcept(FE_ALL_EXCEPT) == 0 && feraiseexcept(FE_OVERFLOW) == 0)
    {
        EXPECT(p101_sqrt(env, err, 4.0) == 2.0);
        EXPECT(p101_error_has_no_error(err));
        EXPECT((fetestexcept(FE_OVERFLOW) & FE_OVERFLOW) != 0);
        EXPECT(feclearexcept(FE_ALL_EXCEPT) == 0);
    }
    (void)p101_sqrt(env, err, -1.0);
    EXPECT(p101_error_is_errno(err, EDOM));
    p101_error_reset(err);

    EXPECT(p101_strftime(env, err, output, sizeof(output), empty_format, &before_epoch) == 0);
    EXPECT(p101_error_has_no_error(err));

    EXPECT(setenv("TZ", "UTC0", 1) == 0);
    tzset();
    before_epoch.tm_year  = 69;
    before_epoch.tm_mon   = 11;
    before_epoch.tm_mday  = 31;
    before_epoch.tm_hour  = 23;
    before_epoch.tm_min   = 59;
    before_epoch.tm_sec   = 59;
    before_epoch.tm_isdst = -1;
    EXPECT(p101_mktime(env, err, &before_epoch) == (time_t)-1);
    EXPECT(p101_error_has_no_error(err));
}

static void test_validation_and_ownership(struct p101_env *env, struct p101_error *err)
{
    struct event_counts counts = {0};
    atomic_flag         flag   = ATOMIC_FLAG_INIT;
    atomic_uint         value;
    div_t               division;
    unsigned int        expected;
    char               *message;
    void               *memory;
    int                 frees_before_null;

    p101_env_set_alloc_observer(env, observe_allocations, &counts);

    division = p101_div(env, err, 1, 0);
    EXPECT(division.quot == 0);
    EXPECT(p101_error_is_errno(err, EDOM));
    p101_error_reset(err);

    EXPECT(p101_imaxabs(env, err, INTMAX_MIN) == INTMAX_MIN);
    EXPECT(p101_error_is_errno(err, ERANGE));
    p101_error_reset(err);

    message = p101_strerror(env, err, ENOENT);
    EXPECT(message != NULL);
    EXPECT(p101_error_has_no_error(err));
    p101_free(env, message);

    memory = p101_malloc(env, err, 16);
    EXPECT(memory != NULL);
    EXPECT(p101_realloc(env, err, memory, 0) == NULL);
    EXPECT(p101_error_is_errno(err, EINVAL));
    p101_error_reset(err);
    p101_free(env, memory);

    EXPECT(p101_malloc(env, err, 0) == NULL);
    EXPECT(p101_error_is_errno(err, EINVAL));
    p101_error_reset(err);
    frees_before_null = counts.frees;
    p101_free(env, NULL);
    EXPECT(counts.frees == frees_before_null);
    EXPECT(counts.allocations == counts.frees);
    p101_env_set_alloc_observer(env, NULL, NULL);

    atomic_init(&value, 1U);
    EXPECT(p101_atomic_uint_exchange(env, &value, 2U) == 1U);
    expected = 2U;
    EXPECT(p101_atomic_uint_compare_exchange_strong(env, &value, &expected, 3U));
    EXPECT(p101_atomic_uint_fetch_or(env, &value, 4U) == 3U);
    EXPECT(p101_atomic_uint_load(env, &value) == 7U);
    EXPECT(!p101_atomic_flag_test_and_set(env, &flag));
    EXPECT(p101_atomic_flag_test_and_set(env, &flag));
    p101_atomic_flag_clear(env, &flag);
}

static void test_faults_and_balanced_trace(struct p101_env *env, struct p101_error *err)
{
    struct event_counts counts = {0};
    struct fault_state  fault  = {"malloc", 0};
    char                output[8];
    char               *message;

    p101_env_set_call_observer(env, observe_calls, &counts);
    EXPECT(p101_strlen(env, "abc") == 3U);
    EXPECT(counts.enters == 1);
    EXPECT(counts.exits == 1);
    counts.enters = 0;
    counts.exits  = 0;
    message       = p101_strerror(env, err, ENOENT);
    EXPECT(message != NULL);
    EXPECT(counts.enters == 1);
    EXPECT(counts.exits == 1);
    p101_free(env, message);
    counts.enters = 0;
    counts.exits  = 0;
    EXPECT(p101_snprintf(env, err, output, sizeof(output), "%s", "ok") == 2);
    EXPECT(counts.enters == 1);
    EXPECT(counts.exits == 1);
    p101_env_set_call_observer(env, NULL, NULL);

    p101_env_set_fault_injector(env, fail_named_call, &fault);
    EXPECT(p101_malloc(env, err, 8) == NULL);
    EXPECT(p101_error_is_errno(err, ENOMEM));
    EXPECT(fault.checks == 1);
    p101_error_reset(err);
    fault.target = "snprintf";
    fault.checks = 0;
    EXPECT(p101_snprintf(env, err, output, sizeof(output), "%s", "ok") == -1);
    EXPECT(p101_error_is_errno(err, ENOMEM));
    EXPECT(fault.checks == 1);
    p101_error_reset(err);
    p101_env_set_fault_injector(env, NULL, NULL);
}

int main(void)
{
    struct p101_error *err;
    struct p101_env   *env;

    err = p101_error_create(false);
    env = p101_env_create(err, NULL);
    EXPECT(err != NULL);
    EXPECT(env != NULL);
    EXPECT(p101_error_has_no_error(err));

    if(env != NULL && err != NULL)
    {
        test_stdio_contracts(env, err);
        test_time_and_fenv(env, err);
        test_validation_and_ownership(env, err);
        test_faults_and_balanced_trace(env, err);
    }

    p101_env_destroy(env);
    p101_error_destroy(err);

    if(failures != 0)
    {
        fprintf(stderr, "%d lib_c test(s) failed\n", failures);
        return 1;
    }

    return 0;
}
