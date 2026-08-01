#include <errno.h>
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
#include <stdio.h>
#include <stdlib.h>

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

struct fault_state
{
    int checks;
    int errnum;
};

static int fail_next_call(const struct p101_env *env, const char *call_name, void *user_data)
{
    struct fault_state *state;

    (void)env;
    (void)call_name;
    state = user_data;
    state->checks++;
    return state->errnum;
}

/* P101_TEST_CASE(p101_abs) */
static void test_p101_abs(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_abs(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_acos) */
static void test_p101_acos(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_acos(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_acosf) */
static void test_p101_acosf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_acosf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_acosh) */
static void test_p101_acosh(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_acosh(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_acoshf) */
static void test_p101_acoshf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_acoshf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_acoshl) */
static void test_p101_acoshl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_acoshl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_acosl) */
static void test_p101_acosl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_acosl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_aligned_alloc) */
static void test_p101_aligned_alloc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ENOMEM};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ENOMEM};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        void *result = p101_aligned_alloc(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_asin) */
static void test_p101_asin(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_asin(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_asinf) */
static void test_p101_asinf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_asinf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_asinh) */
static void test_p101_asinh(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_asinh(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_asinhf) */
static void test_p101_asinhf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_asinhf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_asinhl) */
static void test_p101_asinhl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_asinhl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_asinl) */
static void test_p101_asinl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_asinl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_at_quick_exit) */
static void test_p101_at_quick_exit(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_at_quick_exit(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_atan) */
static void test_p101_atan(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_atan(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_atan2) */
static void test_p101_atan2(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_atan2(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_atan2f) */
static void test_p101_atan2f(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_atan2f(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_atan2l) */
static void test_p101_atan2l(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_atan2l(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_atanf) */
static void test_p101_atanf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_atanf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_atanh) */
static void test_p101_atanh(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_atanh(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_atanhf) */
static void test_p101_atanhf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_atanhf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_atanhl) */
static void test_p101_atanhl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_atanhl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_atanl) */
static void test_p101_atanl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_atanl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_atexit) */
static void test_p101_atexit(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {ENOMEM};
#elif defined(__FreeBSD__)
    static const int errors[] = {ENOMEM, ENOSYS};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_atexit(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cabs) */
static void test_p101_cabs(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_cabs(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cabsf) */
static void test_p101_cabsf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_cabsf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cabsl) */
static void test_p101_cabsl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_cabsl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cacos) */
static void test_p101_cacos(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_cacos(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cacosf) */
static void test_p101_cacosf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_cacosf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cacosh) */
static void test_p101_cacosh(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_cacosh(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cacoshf) */
static void test_p101_cacoshf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_cacoshf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cacoshl) */
static void test_p101_cacoshl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex long double result = p101_cacoshl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cacosl) */
static void test_p101_cacosl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex long double result = p101_cacosl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_calloc) */
static void test_p101_calloc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {ENOMEM};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ENOMEM};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        void *result = p101_calloc(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_carg) */
static void test_p101_carg(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_carg(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cargf) */
static void test_p101_cargf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_cargf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cargl) */
static void test_p101_cargl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_cargl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_casin) */
static void test_p101_casin(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_casin(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_casinf) */
static void test_p101_casinf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_casinf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_casinh) */
static void test_p101_casinh(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_casinh(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_casinhf) */
static void test_p101_casinhf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_casinhf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_casinhl) */
static void test_p101_casinhl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex long double result = p101_casinhl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_casinl) */
static void test_p101_casinl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex long double result = p101_casinl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_catan) */
static void test_p101_catan(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_catan(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_catanf) */
static void test_p101_catanf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_catanf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_catanh) */
static void test_p101_catanh(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_catanh(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_catanhf) */
static void test_p101_catanhf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_catanhf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_catanhl) */
static void test_p101_catanhl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex long double result = p101_catanhl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_catanl) */
static void test_p101_catanl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex long double result = p101_catanl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ccos) */
static void test_p101_ccos(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_ccos(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ccosf) */
static void test_p101_ccosf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_ccosf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ccosh) */
static void test_p101_ccosh(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_ccosh(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ccoshf) */
static void test_p101_ccoshf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_ccoshf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cexp) */
static void test_p101_cexp(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_cexp(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cexpf) */
static void test_p101_cexpf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_cexpf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cexpl) */
static void test_p101_cexpl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex long double result = p101_cexpl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_clock) */
static void test_p101_clock(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EOVERFLOW};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        clock_t result = p101_clock(env, err);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_clog) */
static void test_p101_clog(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_clog(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_clogf) */
static void test_p101_clogf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_clogf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_clogl) */
static void test_p101_clogl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex long double result = p101_clogl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cos) */
static void test_p101_cos(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_cos(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cosf) */
static void test_p101_cosf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_cosf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cosh) */
static void test_p101_cosh(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_cosh(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_coshf) */
static void test_p101_coshf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_coshf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_coshl) */
static void test_p101_coshl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_coshl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cosl) */
static void test_p101_cosl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_cosl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cpow) */
static void test_p101_cpow(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_cpow(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cpowf) */
static void test_p101_cpowf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_cpowf(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_cpowl) */
static void test_p101_cpowl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex long double result = p101_cpowl(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_csin) */
static void test_p101_csin(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_csin(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_csinf) */
static void test_p101_csinf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_csinf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_csinh) */
static void test_p101_csinh(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_csinh(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_csinhf) */
static void test_p101_csinhf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_csinhf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_csqrt) */
static void test_p101_csqrt(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_csqrt(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_csqrtf) */
static void test_p101_csqrtf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_csqrtf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_csqrtl) */
static void test_p101_csqrtl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex long double result = p101_csqrtl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ctan) */
static void test_p101_ctan(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_ctan(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ctanf) */
static void test_p101_ctanf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_ctanf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ctanh) */
static void test_p101_ctanh(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex double result = p101_ctanh(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ctanhf) */
static void test_p101_ctanhf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        _Complex float result = p101_ctanhf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_div) */
static void test_p101_div(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        div_t result = p101_div(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_erf) */
static void test_p101_erf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_erf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_erfc) */
static void test_p101_erfc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_erfc(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_erfcf) */
static void test_p101_erfcf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_erfcf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_erfcl) */
static void test_p101_erfcl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_erfcl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_erff) */
static void test_p101_erff(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_erff(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_erfl) */
static void test_p101_erfl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_erfl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_exp) */
static void test_p101_exp(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_exp(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_exp2) */
static void test_p101_exp2(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_exp2(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_exp2f) */
static void test_p101_exp2f(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_exp2f(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_exp2l) */
static void test_p101_exp2l(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_exp2l(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_expf) */
static void test_p101_expf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_expf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_expl) */
static void test_p101_expl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_expl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_expm1) */
static void test_p101_expm1(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_expm1(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_expm1f) */
static void test_p101_expm1f(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_expm1f(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_expm1l) */
static void test_p101_expm1l(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_expm1l(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fclose) */
static void test_p101_fclose(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENOSPC, EPERM, EPIPE, EWOULDBLOCK};
#elif defined(__APPLE__)
    static const int errors[] = {EAGAIN, EBADF, ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENETDOWN, ENETUNREACH, ENOBUFS, ENOSPC, ENXIO, EOVERFLOW, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__FreeBSD__)
    static const int errors[] = {EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENOBUFS, ENOSPC, EOPNOTSUPP, EPIPE, ESPIPE};
#else
    static const int errors[] = {EAGAIN, EBADF, EFBIG, EINTR, EIO, ENOMEM, ENOSPC, ENXIO, EPIPE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fclose(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fdim) */
static void test_p101_fdim(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_fdim(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fdimf) */
static void test_p101_fdimf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_fdimf(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fdiml) */
static void test_p101_fdiml(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_fdiml(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_feclearexcept) */
static void test_p101_feclearexcept(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_feclearexcept(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fegetenv) */
static void test_p101_fegetenv(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fegetenv(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fegetexceptflag) */
static void test_p101_fegetexceptflag(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fegetexceptflag(env, err, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fegetround) */
static void test_p101_fegetround(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fegetround(env, err);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_feholdexcept) */
static void test_p101_feholdexcept(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_feholdexcept(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_feraiseexcept) */
static void test_p101_feraiseexcept(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_feraiseexcept(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fesetenv) */
static void test_p101_fesetenv(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fesetenv(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fesetexceptflag) */
static void test_p101_fesetexceptflag(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fesetexceptflag(env, err, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fesetround) */
static void test_p101_fesetround(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fesetround(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_feupdateenv) */
static void test_p101_feupdateenv(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_feupdateenv(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fflush) */
static void test_p101_fflush(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENOSPC, EPERM, EPIPE, EWOULDBLOCK};
#elif defined(__APPLE__)
    static const int errors[] = {EAGAIN, EBADF, ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENETDOWN, ENETUNREACH, ENOBUFS, ENOSPC, ENXIO, EOVERFLOW, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__FreeBSD__)
    static const int errors[] = {EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENOBUFS, ENOSPC, EPIPE, ESPIPE};
#else
    static const int errors[] = {EAGAIN, EBADF, EFBIG, EINTR, EIO, ENOMEM, ENOSPC, ENXIO, EPIPE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fflush(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fgetc) */
static void test_p101_fgetc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EAGAIN, EBADF, EINTR, EIO, ENOMEM, ENXIO, EOVERFLOW};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fgetc(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fgetpos) */
static void test_p101_fgetpos(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EACCES, EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENOENT, ENOMEM, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EPERM, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__APPLE__)
    static const int errors[] = {EACCES, EAGAIN, EBADF, ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENETDOWN, ENETUNREACH, ENOBUFS, ENOENT, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__FreeBSD__)
    static const int errors[] = {EACCES, EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENOBUFS, ENOENT, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EPIPE, ESPIPE};
#else
    static const int errors[] = {EBADF, EOVERFLOW, ESPIPE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fgetpos(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fgets) */
static void test_p101_fgets(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EACCES,   EAGAIN,      EBADF,   ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT,   EFAULT,  EFBIG, EINTR,     EINVAL, EIO,    EISDIR, ELOOP,     ENAMETOOLONG,
                                 ENETDOWN, ENETUNREACH, ENOBUFS, ENOENT,     ENOMEM,  ENOSPC,       ENOTCONN, ENOTDIR, ENXIO, EOVERFLOW, EPIPE,  ESPIPE, ESTALE, ETIMEDOUT, EWOULDBLOCK};
#elif defined(__FreeBSD__)
    static const int errors[] = {EACCES, EAGAIN, EBADF, EBUSY, ECONNRESET, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, EISDIR, ELOOP, ENAMETOOLONG, ENOBUFS, ENOENT, ENOSPC, ENOTDIR, EOPNOTSUPP, EOVERFLOW, EPIPE, ESPIPE};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        char *result = p101_fgets(env, err, NULL, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fgetwc) */
static void test_p101_fgetwc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EILSEQ};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EAGAIN, EBADF, EILSEQ, EINTR, EIO, ENOMEM, ENXIO, EOVERFLOW};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        wint_t result = p101_fgetwc(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fgetws) */
static void test_p101_fgetws(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EACCES,   EAGAIN,      EBADF,   ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT,   EFAULT,  EFBIG, EILSEQ,    EINTR, EINVAL, EIO,    EISDIR,    ELOOP,      ENAMETOOLONG,
                                 ENETDOWN, ENETUNREACH, ENOBUFS, ENOENT,     ENOMEM,  ENOSPC,       ENOTCONN, ENOTDIR, ENXIO, EOVERFLOW, EPIPE, ESPIPE, ESTALE, ETIMEDOUT, EWOULDBLOCK};
#elif defined(__FreeBSD__)
    static const int errors[] = {EACCES, EAGAIN, EBADF, EBUSY, ECONNRESET, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EILSEQ, EINTR, EINVAL, EIO, EISDIR, ELOOP, ENAMETOOLONG, ENOBUFS, ENOENT, ENOSPC, ENOTDIR, EOPNOTSUPP, EOVERFLOW, EPIPE, ESPIPE};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        wchar_t *result = p101_fgetws(env, err, NULL, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fma) */
static void test_p101_fma(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_fma(env, err, 0, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fmaf) */
static void test_p101_fmaf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_fmaf(env, err, 0, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fmal) */
static void test_p101_fmal(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_fmal(env, err, 0, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fmod) */
static void test_p101_fmod(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_fmod(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fmodf) */
static void test_p101_fmodf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_fmodf(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fmodl) */
static void test_p101_fmodl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_fmodl(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fopen) */
static void test_p101_fopen(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EACCES,       EAGAIN, EBADF,  EBUSY,  EDESTADDRREQ, EDQUOT, EEXIST,  EFAULT, EFBIG,      EINTR,     EINVAL, EIO,   EISDIR, ELOOP,   EMFILE,
                                 ENAMETOOLONG, ENFILE, ENODEV, ENOENT, ENOMEM,       ENOSPC, ENOTDIR, ENXIO,  EOPNOTSUPP, EOVERFLOW, EPERM,  EPIPE, EROFS,  ETXTBSY, EWOULDBLOCK};
#elif defined(__APPLE__)
    static const int errors[] = {EACCES,      EAGAIN, EBADF,   ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT,  EEXIST,  EFAULT, EFBIG,      EILSEQ,    EINTR, EINVAL, EIO,   EISDIR, ELOOP, EMFILE,  ENAMETOOLONG, ENETDOWN,
                                 ENETUNREACH, ENFILE, ENOBUFS, ENOENT,     ENOLCK,  ENOSPC,       ENOTDIR, ENOTSUP, ENXIO,  EOPNOTSUPP, EOVERFLOW, EPERM, EPIPE,  EROFS, ESPIPE, ESRCH, ETXTBSY, EWOULDBLOCK,  EXDEV};
#elif defined(__FreeBSD__)
    static const int errors[] = {EACCES, EAGAIN,  EBADF,  EBUSY,  EDEADLK, EDESTADDRREQ, EDQUOT, EEXIST, EFAULT,     EFBIG,     EINTR, EINVAL, EIO,   EISDIR, ELOOP, EMFILE,  EMLINK,     ENAMETOOLONG,
                                 ENFILE, ENOBUFS, ENOENT, ENOLCK, ENOSPC,  ENOTDIR,      ENOTTY, ENXIO,  EOPNOTSUPP, EOVERFLOW, EPERM, EPIPE,  EROFS, ESPIPE, ESRCH, ETXTBSY, EWOULDBLOCK};
#else
    static const int errors[] = {EACCES, EEXIST, EILSEQ, EINTR, EINVAL, EISDIR, ELOOP, EMFILE, ENAMETOOLONG, ENFILE, ENOENT, ENOMEM, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EROFS, ETXTBSY};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        FILE *result = p101_fopen(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fprintf) */
static void test_p101_fprintf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EBADF, EOVERFLOW};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, ENOMEM};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, ENOMEM, EOVERFLOW};
#else
    static const int errors[] = {EBADF, EILSEQ, ENOMEM, EOVERFLOW};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fprintf(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fputc) */
static void test_p101_fputc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EAGAIN, EBADF, EFBIG, EINTR, EIO, ENOMEM, ENOSPC, ENXIO, EPIPE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fputc(env, err, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fputs) */
static void test_p101_fputs(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EAGAIN, EBADF, ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENETDOWN, ENETUNREACH, ENOBUFS, ENOSPC, ENXIO, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__FreeBSD__)
    static const int errors[] = {EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENOBUFS, ENOSPC, EPIPE, ESPIPE};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fputs(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fputwc) */
static void test_p101_fputwc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EILSEQ};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EAGAIN, EBADF, EFBIG, EILSEQ, EINTR, EIO, ENOMEM, ENOSPC, ENXIO, EPIPE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        wint_t result = p101_fputwc(env, err, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fputws) */
static void test_p101_fputws(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EAGAIN, EBADF, ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENETDOWN, ENETUNREACH, ENOBUFS, ENOSPC, ENXIO, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__FreeBSD__)
    static const int errors[] = {EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENOBUFS, ENOSPC, EPIPE, ESPIPE};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fputws(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fread) */
static void test_p101_fread(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_fread(env, err, NULL, 0, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_freopen) */
static void test_p101_freopen(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EACCES,       EAGAIN, EBADF,  EBUSY,  EDESTADDRREQ, EDQUOT, EEXIST,  EFAULT, EFBIG,      EINTR,     EINVAL, EIO,   EISDIR, ELOOP,   EMFILE,
                                 ENAMETOOLONG, ENFILE, ENODEV, ENOENT, ENOMEM,       ENOSPC, ENOTDIR, ENXIO,  EOPNOTSUPP, EOVERFLOW, EPERM,  EPIPE, EROFS,  ETXTBSY, EWOULDBLOCK};
#elif defined(__APPLE__)
    static const int errors[] = {EACCES,      EAGAIN, EBADF,   ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT,  EEXIST,  EFAULT, EFBIG,      EILSEQ,    EINTR, EINVAL, EIO,   EISDIR, ELOOP, EMFILE,  ENAMETOOLONG, ENETDOWN,
                                 ENETUNREACH, ENFILE, ENOBUFS, ENOENT,     ENOLCK,  ENOSPC,       ENOTDIR, ENOTSUP, ENXIO,  EOPNOTSUPP, EOVERFLOW, EPERM, EPIPE,  EROFS, ESPIPE, ESRCH, ETXTBSY, EWOULDBLOCK,  EXDEV};
#elif defined(__FreeBSD__)
    static const int errors[] = {EACCES, EAGAIN,  EBADF,  EBUSY,  EDEADLK, EDESTADDRREQ, EDQUOT, EEXIST, EFAULT,     EFBIG,     EINTR, EINVAL, EIO,   EISDIR, ELOOP, EMFILE,  EMLINK,     ENAMETOOLONG,
                                 ENFILE, ENOBUFS, ENOENT, ENOLCK, ENOSPC,  ENOTDIR,      ENOTTY, ENXIO,  EOPNOTSUPP, EOVERFLOW, EPERM, EPIPE,  EROFS, ESPIPE, ESRCH, ETXTBSY, EWOULDBLOCK};
#else
    static const int errors[] = {EACCES, EBADF, EEXIST, EILSEQ, EINTR, EINVAL, EISDIR, ELOOP, EMFILE, ENAMETOOLONG, ENFILE, ENOENT, ENOMEM, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EROFS, ETXTBSY};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        FILE *result = p101_freopen(env, err, NULL, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fscanf) */
static void test_p101_fscanf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EAGAIN, EBADF, EILSEQ, EINTR, EINVAL, ENOMEM};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EILSEQ, EINVAL, ENOMEM};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fscanf(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fseek) */
static void test_p101_fseek(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EACCES, EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENOENT, ENOMEM, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EPERM, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__APPLE__)
    static const int errors[] = {EACCES, EAGAIN, EBADF, ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENETDOWN, ENETUNREACH, ENOBUFS, ENOENT, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__FreeBSD__)
    static const int errors[] = {EACCES, EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENOBUFS, ENOENT, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EPIPE, ESPIPE};
#else
    static const int errors[] = {EAGAIN, EBADF, EFBIG, EINTR, EINVAL, EIO, ENOMEM, ENOSPC, ENXIO, EOVERFLOW, EPIPE, ESPIPE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fseek(env, err, NULL, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fsetpos) */
static void test_p101_fsetpos(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EACCES, EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENOENT, ENOMEM, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EPERM, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__APPLE__)
    static const int errors[] = {EACCES, EAGAIN, EBADF, ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENETDOWN, ENETUNREACH, ENOBUFS, ENOENT, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__FreeBSD__)
    static const int errors[] = {EACCES, EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENOBUFS, ENOENT, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EPIPE, ESPIPE};
#else
    static const int errors[] = {EAGAIN, EBADF, EFBIG, EINTR, EIO, ENOMEM, ENOSPC, ENXIO, EPIPE, ESPIPE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fsetpos(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ftell) */
static void test_p101_ftell(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EACCES, EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENOENT, ENOMEM, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EPERM, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__APPLE__)
    static const int errors[] = {EACCES, EAGAIN, EBADF, ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENETDOWN, ENETUNREACH, ENOBUFS, ENOENT, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__FreeBSD__)
    static const int errors[] = {EACCES, EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENOBUFS, ENOENT, ENOSPC, ENOTDIR, ENXIO, EOVERFLOW, EPIPE, ESPIPE};
#else
    static const int errors[] = {EBADF, EOVERFLOW, ESPIPE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long result = p101_ftell(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fwide) */
static void test_p101_fwide(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EBADF};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fwide(env, err, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fwprintf) */
static void test_p101_fwprintf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {ENOMEM, EOVERFLOW};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EILSEQ, ENOMEM, EOVERFLOW};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fwprintf(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fwrite) */
static void test_p101_fwrite(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_fwrite(env, err, NULL, 0, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_fwscanf) */
static void test_p101_fwscanf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EILSEQ, EINVAL, ENOMEM};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EILSEQ, EINVAL, ENOMEM};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_fwscanf(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_getc) */
static void test_p101_getc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_getc(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_getchar) */
static void test_p101_getchar(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_getchar(env, err);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_getwc) */
static void test_p101_getwc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EILSEQ};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        wint_t result = p101_getwc(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_getwchar) */
static void test_p101_getwchar(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        wint_t result = p101_getwchar(env, err);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_hypot) */
static void test_p101_hypot(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_hypot(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_hypotf) */
static void test_p101_hypotf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_hypotf(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_hypotl) */
static void test_p101_hypotl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_hypotl(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ilogb) */
static void test_p101_ilogb(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_ilogb(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ilogbf) */
static void test_p101_ilogbf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_ilogbf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ilogbl) */
static void test_p101_ilogbl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_ilogbl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_imaxabs) */
static void test_p101_imaxabs(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        intmax_t result = p101_imaxabs(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_imaxdiv) */
static void test_p101_imaxdiv(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        imaxdiv_t result = p101_imaxdiv(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_labs) */
static void test_p101_labs(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long result = p101_labs(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ldexp) */
static void test_p101_ldexp(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_ldexp(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ldexpf) */
static void test_p101_ldexpf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_ldexpf(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ldexpl) */
static void test_p101_ldexpl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_ldexpl(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ldiv) */
static void test_p101_ldiv(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        ldiv_t result = p101_ldiv(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_lgamma) */
static void test_p101_lgamma(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_lgamma(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_lgammaf) */
static void test_p101_lgammaf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_lgammaf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_lgammal) */
static void test_p101_lgammal(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_lgammal(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_llabs) */
static void test_p101_llabs(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long long result = p101_llabs(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_lldiv) */
static void test_p101_lldiv(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        lldiv_t result = p101_lldiv(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_llrint) */
static void test_p101_llrint(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long long result = p101_llrint(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_llrintf) */
static void test_p101_llrintf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long long result = p101_llrintf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_llrintl) */
static void test_p101_llrintl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long long result = p101_llrintl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_llround) */
static void test_p101_llround(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long long result = p101_llround(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_llroundf) */
static void test_p101_llroundf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long long result = p101_llroundf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_llroundl) */
static void test_p101_llroundl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long long result = p101_llroundl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_log) */
static void test_p101_log(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_log(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_log10) */
static void test_p101_log10(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_log10(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_log10f) */
static void test_p101_log10f(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_log10f(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_log10l) */
static void test_p101_log10l(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_log10l(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_log1p) */
static void test_p101_log1p(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_log1p(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_log1pf) */
static void test_p101_log1pf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_log1pf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_log1pl) */
static void test_p101_log1pl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_log1pl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_log2) */
static void test_p101_log2(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_log2(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_log2f) */
static void test_p101_log2f(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_log2f(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_log2l) */
static void test_p101_log2l(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_log2l(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_logb) */
static void test_p101_logb(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_logb(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_logbf) */
static void test_p101_logbf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_logbf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_logbl) */
static void test_p101_logbl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_logbl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_logf) */
static void test_p101_logf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_logf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_logl) */
static void test_p101_logl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_logl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_lrint) */
static void test_p101_lrint(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long result = p101_lrint(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_lrintf) */
static void test_p101_lrintf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long result = p101_lrintf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_lrintl) */
static void test_p101_lrintl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long result = p101_lrintl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_lround) */
static void test_p101_lround(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long result = p101_lround(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_lroundf) */
static void test_p101_lroundf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long result = p101_lroundf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_lroundl) */
static void test_p101_lroundl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long result = p101_lroundl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_malloc) */
static void test_p101_malloc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {ENOMEM};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ENOMEM};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        void *result = p101_malloc(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_mblen) */
static void test_p101_mblen(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, EINVAL};
#else
    static const int errors[] = {EILSEQ};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_mblen(env, err, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_mbrlen) */
static void test_p101_mbrlen(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, EINVAL};
#else
    static const int errors[] = {EILSEQ, EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_mbrlen(env, err, NULL, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_mbrtowc) */
static void test_p101_mbrtowc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, EINVAL};
#else
    static const int errors[] = {EILSEQ, EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_mbrtowc(env, err, NULL, NULL, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_mbsrtowcs) */
static void test_p101_mbsrtowcs(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, EINVAL};
#else
    static const int errors[] = {EILSEQ, EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_mbsrtowcs(env, err, NULL, NULL, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_mbstowcs) */
static void test_p101_mbstowcs(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, EINVAL};
#else
    static const int errors[] = {EILSEQ};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_mbstowcs(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_mbtowc) */
static void test_p101_mbtowc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, EINVAL};
#else
    static const int errors[] = {EILSEQ};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_mbtowc(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_mktime) */
static void test_p101_mktime(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EOVERFLOW};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EOVERFLOW};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        time_t result = p101_mktime(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_nextafter) */
static void test_p101_nextafter(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_nextafter(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_nextafterf) */
static void test_p101_nextafterf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_nextafterf(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_nextafterl) */
static void test_p101_nextafterl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_nextafterl(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_nexttoward) */
static void test_p101_nexttoward(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_nexttoward(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_nexttowardf) */
static void test_p101_nexttowardf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_nexttowardf(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_nexttowardl) */
static void test_p101_nexttowardl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_nexttowardl(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_pow) */
static void test_p101_pow(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_pow(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_powf) */
static void test_p101_powf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_powf(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_powl) */
static void test_p101_powl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_powl(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_printf) */
static void test_p101_printf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EBADF, EOVERFLOW};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, ENOMEM};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, ENOMEM, EOVERFLOW};
#else
    static const int errors[] = {EBADF, EILSEQ, ENOMEM, EOVERFLOW};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_printf(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_putc) */
static void test_p101_putc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_putc(env, err, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_putchar) */
static void test_p101_putchar(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_putchar(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_puts) */
static void test_p101_puts(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EAGAIN, EBADF, ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENETDOWN, ENETUNREACH, ENOBUFS, ENOSPC, ENXIO, EPIPE, ESPIPE, EWOULDBLOCK};
#elif defined(__FreeBSD__)
    static const int errors[] = {EAGAIN, EBADF, EDESTADDRREQ, EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENOBUFS, ENOSPC, EPIPE, ESPIPE};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_puts(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_putwc) */
static void test_p101_putwc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EILSEQ};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        wint_t result = p101_putwc(env, err, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_putwchar) */
static void test_p101_putwchar(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        wint_t result = p101_putwchar(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_raise) */
static void test_p101_raise(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EINVAL, ENOTSUP, ESRCH};
#elif defined(__FreeBSD__)
    static const int errors[] = {EINVAL, EPERM, ESRCH};
#else
    static const int errors[] = {EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_raise(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_realloc) */
static void test_p101_realloc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {ENOMEM};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ENOMEM};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        void *result = p101_realloc(env, err, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_remainder) */
static void test_p101_remainder(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_remainder(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_remainderf) */
static void test_p101_remainderf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_remainderf(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_remainderl) */
static void test_p101_remainderl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_remainderl(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_remove) */
static void test_p101_remove(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EACCES, EBADF, EBUSY, EFAULT, EINVAL, EIO, ELOOP, ENAMETOOLONG, ENOENT, ENOTDIR, ENOTEMPTY, EOVERFLOW, EPERM, EROFS};
#elif defined(__FreeBSD__)
    static const int errors[] = {EACCES, EBADF, EBUSY, EDEADLK, EFAULT, EINVAL, EIO, EISDIR, ELOOP, ENAMETOOLONG, ENOENT, ENOSPC, ENOTDIR, ENOTEMPTY, EOVERFLOW, EPERM, EROFS};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_remove(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_remquo) */
static void test_p101_remquo(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_remquo(env, err, 0, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_remquof) */
static void test_p101_remquof(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_remquof(env, err, 0, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_remquol) */
static void test_p101_remquol(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_remquol(env, err, 0, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_rename) */
static void test_p101_rename(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EACCES, EBADF, EBUSY, EDQUOT, EEXIST, EFAULT, EINVAL, EISDIR, ELOOP, EMLINK, ENAMETOOLONG, ENOENT, ENOMEM, ENOSPC, ENOTDIR, ENOTEMPTY, EPERM, EROFS, EXDEV};
#elif defined(__APPLE__)
    static const int errors[] = {EACCES, EBADF, EDEADLK, EDQUOT, EEXIST, EFAULT, EINVAL, EIO, EISDIR, ELOOP, ENAMETOOLONG, ENOENT, ENOSPC, ENOTDIR, ENOTEMPTY, ENOTSUP, EPERM, EROFS, EXDEV};
#elif defined(__FreeBSD__)
    static const int errors[] = {EACCES, EBADF, EDQUOT, EEXIST, EFAULT, EINVAL, EIO, EISDIR, ELOOP, ENAMETOOLONG, ENOENT, ENOSPC, ENOTDIR, ENOTEMPTY, EOPNOTSUPP, EPERM, EROFS, EXDEV};
#else
    static const int errors[] = {EACCES, EBADF, EBUSY, EEXIST, EILSEQ, EINVAL, EIO, EISDIR, ELOOP, EMLINK, ENAMETOOLONG, ENOENT, ENOSPC, ENOTDIR, ENOTEMPTY, EPERM, EROFS, ETXTBSY, EXDEV};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_rename(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_scalbln) */
static void test_p101_scalbln(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_scalbln(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_scalblnf) */
static void test_p101_scalblnf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_scalblnf(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_scalblnl) */
static void test_p101_scalblnl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_scalblnl(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_scalbn) */
static void test_p101_scalbn(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_scalbn(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_scalbnf) */
static void test_p101_scalbnf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_scalbnf(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_scalbnl) */
static void test_p101_scalbnl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_scalbnl(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_scanf) */
static void test_p101_scanf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EAGAIN, EBADF, EILSEQ, EINTR, EINVAL, ENOMEM};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EILSEQ, EINVAL, ENOMEM};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_scanf(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_setlocale) */
static void test_p101_setlocale(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        char *result = p101_setlocale(env, err, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_setvbuf) */
static void test_p101_setvbuf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EBADF};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_setvbuf(env, err, NULL, NULL, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_signal) */
static void test_p101_signal(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL};
#elif defined(__APPLE__)
    static const int errors[] = {EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EINVAL};
#else
    static const int errors[] = {EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        p101_signal(env, err, 0, NULL);
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_sin) */
static void test_p101_sin(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_sin(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_sinf) */
static void test_p101_sinf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_sinf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_sinh) */
static void test_p101_sinh(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_sinh(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_sinhf) */
static void test_p101_sinhf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_sinhf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_sinhl) */
static void test_p101_sinhl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_sinhl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_sinl) */
static void test_p101_sinl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_sinl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_snprintf) */
static void test_p101_snprintf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, ENOMEM};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, ENOMEM, EOVERFLOW};
#else
    static const int errors[] = {EBADF, EILSEQ, ENOMEM, EOVERFLOW};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_snprintf(env, err, NULL, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_sqrt) */
static void test_p101_sqrt(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_sqrt(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_sqrtf) */
static void test_p101_sqrtf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_sqrtf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_sqrtl) */
static void test_p101_sqrtl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_sqrtl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_sscanf) */
static void test_p101_sscanf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EILSEQ, EINVAL, ENOMEM};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EILSEQ, EINVAL, ENOMEM};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_sscanf(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strcoll) */
static void test_p101_strcoll(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_strcoll(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strerror) */
static void test_p101_strerror(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        char *result = p101_strerror(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strftime) */
static void test_p101_strftime(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, EOVERFLOW, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_strftime(env, err, NULL, 0, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strtod) */
static void test_p101_strtod(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {ERANGE};
#elif defined(__FreeBSD__)
    static const int errors[] = {ERANGE};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_strtod(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strtof) */
static void test_p101_strtof(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {ERANGE};
#elif defined(__FreeBSD__)
    static const int errors[] = {ERANGE};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_strtof(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strtoimax) */
static void test_p101_strtoimax(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__FreeBSD__)
    static const int errors[] = {EINVAL, ERANGE};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        intmax_t result = p101_strtoimax(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strtol) */
static void test_p101_strtol(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__FreeBSD__)
    static const int errors[] = {EINVAL, ERANGE};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long result = p101_strtol(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strtold) */
static void test_p101_strtold(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {ERANGE};
#elif defined(__FreeBSD__)
    static const int errors[] = {ERANGE};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_strtold(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strtoll) */
static void test_p101_strtoll(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__FreeBSD__)
    static const int errors[] = {EINVAL, ERANGE};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long long result = p101_strtoll(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strtoul) */
static void test_p101_strtoul(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__FreeBSD__)
    static const int errors[] = {EINVAL, ERANGE};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        unsigned long result = p101_strtoul(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strtoull) */
static void test_p101_strtoull(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__FreeBSD__)
    static const int errors[] = {EINVAL, ERANGE};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        unsigned long long result = p101_strtoull(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strtoumax) */
static void test_p101_strtoumax(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__FreeBSD__)
    static const int errors[] = {EINVAL, ERANGE};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        uintmax_t result = p101_strtoumax(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_strxfrm) */
static void test_p101_strxfrm(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_strxfrm(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_swprintf) */
static void test_p101_swprintf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {ENOMEM, EOVERFLOW};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EILSEQ, ENOMEM, EOVERFLOW};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_swprintf(env, err, NULL, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_swscanf) */
static void test_p101_swscanf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EILSEQ, EINVAL, ENOMEM};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EILSEQ, EINVAL, ENOMEM};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_swscanf(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_system) */
static void test_p101_system(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EAGAIN, ECHILD, ENOMEM};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_system(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_tan) */
static void test_p101_tan(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_tan(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_tanf) */
static void test_p101_tanf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_tanf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_tanh) */
static void test_p101_tanh(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_tanh(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_tanhf) */
static void test_p101_tanhf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_tanhf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_tanhl) */
static void test_p101_tanhl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_tanhl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_tanl) */
static void test_p101_tanl(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_tanl(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_tgamma) */
static void test_p101_tgamma(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_tgamma(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_tgammaf) */
static void test_p101_tgammaf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_tgammaf(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_tgammal) */
static void test_p101_tgammal(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_tgammal(env, err, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_time) */
static void test_p101_time(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EFAULT, EOVERFLOW};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EOVERFLOW};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        time_t result = p101_time(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_timespec_get) */
static void test_p101_timespec_get(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_timespec_get(env, err, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_tmpfile) */
static void test_p101_tmpfile(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EACCES, EEXIST, EINTR, EMFILE, ENFILE, ENOSPC, EROFS};
#elif defined(__APPLE__)
    static const int errors[] = {EACCES,      EAGAIN, EBADF,   ECONNRESET, EDEADLK, EDESTADDRREQ, EDQUOT,  EEXIST,  EFAULT, EFBIG,      EILSEQ,    EINTR, EINVAL, EIO,   EISDIR, ELOOP, EMFILE,  ENAMETOOLONG, ENETDOWN,
                                 ENETUNREACH, ENFILE, ENOBUFS, ENOENT,     ENOLCK,  ENOSPC,       ENOTDIR, ENOTSUP, ENXIO,  EOPNOTSUPP, EOVERFLOW, EPERM, EPIPE,  EROFS, ESPIPE, ESRCH, ETXTBSY, EWOULDBLOCK,  EXDEV};
#elif defined(__FreeBSD__)
    static const int errors[] = {EACCES, EAGAIN,  EBADF,  EBUSY,  EDEADLK, EDESTADDRREQ, EDQUOT, EEXIST, EFAULT,     EFBIG,     EINTR, EINVAL, EIO,   EISDIR, ELOOP, EMFILE,  EMLINK,     ENAMETOOLONG,
                                 ENFILE, ENOBUFS, ENOENT, ENOLCK, ENOSPC,  ENOTDIR,      ENOTTY, ENXIO,  EOPNOTSUPP, EOVERFLOW, EPERM, EPIPE,  EROFS, ESPIPE, ESRCH, ETXTBSY, EWOULDBLOCK};
#else
    static const int errors[] = {EINTR, EMFILE, ENFILE, ENOMEM, ENOSPC};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        FILE *result = p101_tmpfile(env, err);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_towctrans) */
static void test_p101_towctrans(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EINVAL};
#else
    static const int errors[] = {EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        wint_t result = p101_towctrans(env, err, 0, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ungetc) */
static void test_p101_ungetc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_ungetc(env, err, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_ungetwc) */
static void test_p101_ungetwc(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EILSEQ};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        wint_t result = p101_ungetwc(env, err, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcrtomb) */
static void test_p101_wcrtomb(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, EINVAL};
#else
    static const int errors[] = {EILSEQ, EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_wcrtomb(env, err, NULL, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcscoll) */
static void test_p101_wcscoll(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, ENOMEM};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, ENOMEM};
#else
    static const int errors[] = {EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_wcscoll(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcsftime) */
static void test_p101_wcsftime(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_wcsftime(env, err, NULL, 0, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcsrtombs) */
static void test_p101_wcsrtombs(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, EINVAL};
#else
    static const int errors[] = {EILSEQ, EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_wcsrtombs(env, err, NULL, NULL, 0, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcstod) */
static void test_p101_wcstod(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        double result = p101_wcstod(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcstof) */
static void test_p101_wcstof(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        float result = p101_wcstof(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcstoimax) */
static void test_p101_wcstoimax(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        intmax_t result = p101_wcstoimax(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcstol) */
static void test_p101_wcstol(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long result = p101_wcstol(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcstold) */
static void test_p101_wcstold(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long double result = p101_wcstold(env, err, NULL, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcstoll) */
static void test_p101_wcstoll(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        long long result = p101_wcstoll(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcstombs) */
static void test_p101_wcstombs(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, EINVAL};
#else
    static const int errors[] = {EILSEQ};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_wcstombs(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcstoul) */
static void test_p101_wcstoul(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        unsigned long result = p101_wcstoul(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcstoull) */
static void test_p101_wcstoull(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL, ERANGE};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        unsigned long long result = p101_wcstoull(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcstoumax) */
static void test_p101_wcstoumax(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL, ERANGE};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        uintmax_t result = p101_wcstoumax(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wcsxfrm) */
static void test_p101_wcsxfrm(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EINVAL};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        size_t result = p101_wcsxfrm(env, err, NULL, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wctomb) */
static void test_p101_wctomb(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EILSEQ, EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EILSEQ, EINVAL};
#else
    static const int errors[] = {EILSEQ};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_wctomb(env, err, NULL, 0);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wctrans) */
static void test_p101_wctrans(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EINVAL};
#elif defined(__FreeBSD__)
    static const int errors[] = {EINVAL};
#else
    static const int errors[] = {EINVAL};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        wctrans_t result = p101_wctrans(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wctype) */
static void test_p101_wctype(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EIO};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EIO};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        wctype_t result = p101_wctype(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wprintf) */
static void test_p101_wprintf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {ENOMEM, EOVERFLOW};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EILSEQ, ENOMEM, EOVERFLOW};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_wprintf(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

/* P101_TEST_CASE(p101_wscanf) */
static void test_p101_wscanf(struct p101_env *env, struct p101_error *err)
{
#ifdef __linux__
    static const int errors[] = {EILSEQ, EINVAL, ENOMEM};
#elif defined(__APPLE__)
    static const int errors[] = {EIO};
#elif defined(__FreeBSD__)
    static const int errors[] = {EIO};
#else
    static const int errors[] = {EILSEQ, EINVAL, ENOMEM};
#endif

    for(size_t index = 0U; index < sizeof(errors) / sizeof(errors[0]); index++)
    {
        struct fault_state state = {0, errors[index]};

        p101_env_set_fault_injector(env, fail_next_call, &state);
        int result = p101_wscanf(env, err, NULL);
        (void)result;
        EXPECT(state.checks == 1);
        EXPECT(p101_error_is_errno(err, state.errnum));
        p101_error_reset(err);
    }
    p101_env_set_fault_injector(env, NULL, NULL);
}

int main(void)
{
    struct p101_error *err;
    struct p101_env   *env;

    err = p101_error_create(false);
    if(err == NULL)
    {
        return EXIT_FAILURE;
    }
    env = p101_env_create(err, NULL);
    if(env == NULL)
    {
        p101_error_destroy(err);
        return EXIT_FAILURE;
    }
    test_p101_abs(env, err);
    test_p101_acos(env, err);
    test_p101_acosf(env, err);
    test_p101_acosh(env, err);
    test_p101_acoshf(env, err);
    test_p101_acoshl(env, err);
    test_p101_acosl(env, err);
    test_p101_aligned_alloc(env, err);
    test_p101_asin(env, err);
    test_p101_asinf(env, err);
    test_p101_asinh(env, err);
    test_p101_asinhf(env, err);
    test_p101_asinhl(env, err);
    test_p101_asinl(env, err);
    test_p101_at_quick_exit(env, err);
    test_p101_atan(env, err);
    test_p101_atan2(env, err);
    test_p101_atan2f(env, err);
    test_p101_atan2l(env, err);
    test_p101_atanf(env, err);
    test_p101_atanh(env, err);
    test_p101_atanhf(env, err);
    test_p101_atanhl(env, err);
    test_p101_atanl(env, err);
    test_p101_atexit(env, err);
    test_p101_cabs(env, err);
    test_p101_cabsf(env, err);
    test_p101_cabsl(env, err);
    test_p101_cacos(env, err);
    test_p101_cacosf(env, err);
    test_p101_cacosh(env, err);
    test_p101_cacoshf(env, err);
    test_p101_cacoshl(env, err);
    test_p101_cacosl(env, err);
    test_p101_calloc(env, err);
    test_p101_carg(env, err);
    test_p101_cargf(env, err);
    test_p101_cargl(env, err);
    test_p101_casin(env, err);
    test_p101_casinf(env, err);
    test_p101_casinh(env, err);
    test_p101_casinhf(env, err);
    test_p101_casinhl(env, err);
    test_p101_casinl(env, err);
    test_p101_catan(env, err);
    test_p101_catanf(env, err);
    test_p101_catanh(env, err);
    test_p101_catanhf(env, err);
    test_p101_catanhl(env, err);
    test_p101_catanl(env, err);
    test_p101_ccos(env, err);
    test_p101_ccosf(env, err);
    test_p101_ccosh(env, err);
    test_p101_ccoshf(env, err);
    test_p101_cexp(env, err);
    test_p101_cexpf(env, err);
    test_p101_cexpl(env, err);
    test_p101_clock(env, err);
    test_p101_clog(env, err);
    test_p101_clogf(env, err);
    test_p101_clogl(env, err);
    test_p101_cos(env, err);
    test_p101_cosf(env, err);
    test_p101_cosh(env, err);
    test_p101_coshf(env, err);
    test_p101_coshl(env, err);
    test_p101_cosl(env, err);
    test_p101_cpow(env, err);
    test_p101_cpowf(env, err);
    test_p101_cpowl(env, err);
    test_p101_csin(env, err);
    test_p101_csinf(env, err);
    test_p101_csinh(env, err);
    test_p101_csinhf(env, err);
    test_p101_csqrt(env, err);
    test_p101_csqrtf(env, err);
    test_p101_csqrtl(env, err);
    test_p101_ctan(env, err);
    test_p101_ctanf(env, err);
    test_p101_ctanh(env, err);
    test_p101_ctanhf(env, err);
    test_p101_div(env, err);
    test_p101_erf(env, err);
    test_p101_erfc(env, err);
    test_p101_erfcf(env, err);
    test_p101_erfcl(env, err);
    test_p101_erff(env, err);
    test_p101_erfl(env, err);
    test_p101_exp(env, err);
    test_p101_exp2(env, err);
    test_p101_exp2f(env, err);
    test_p101_exp2l(env, err);
    test_p101_expf(env, err);
    test_p101_expl(env, err);
    test_p101_expm1(env, err);
    test_p101_expm1f(env, err);
    test_p101_expm1l(env, err);
    test_p101_fclose(env, err);
    test_p101_fdim(env, err);
    test_p101_fdimf(env, err);
    test_p101_fdiml(env, err);
    test_p101_feclearexcept(env, err);
    test_p101_fegetenv(env, err);
    test_p101_fegetexceptflag(env, err);
    test_p101_fegetround(env, err);
    test_p101_feholdexcept(env, err);
    test_p101_feraiseexcept(env, err);
    test_p101_fesetenv(env, err);
    test_p101_fesetexceptflag(env, err);
    test_p101_fesetround(env, err);
    test_p101_feupdateenv(env, err);
    test_p101_fflush(env, err);
    test_p101_fgetc(env, err);
    test_p101_fgetpos(env, err);
    test_p101_fgets(env, err);
    test_p101_fgetwc(env, err);
    test_p101_fgetws(env, err);
    test_p101_fma(env, err);
    test_p101_fmaf(env, err);
    test_p101_fmal(env, err);
    test_p101_fmod(env, err);
    test_p101_fmodf(env, err);
    test_p101_fmodl(env, err);
    test_p101_fopen(env, err);
    test_p101_fprintf(env, err);
    test_p101_fputc(env, err);
    test_p101_fputs(env, err);
    test_p101_fputwc(env, err);
    test_p101_fputws(env, err);
    test_p101_fread(env, err);
    test_p101_freopen(env, err);
    test_p101_fscanf(env, err);
    test_p101_fseek(env, err);
    test_p101_fsetpos(env, err);
    test_p101_ftell(env, err);
    test_p101_fwide(env, err);
    test_p101_fwprintf(env, err);
    test_p101_fwrite(env, err);
    test_p101_fwscanf(env, err);
    test_p101_getc(env, err);
    test_p101_getchar(env, err);
    test_p101_getwc(env, err);
    test_p101_getwchar(env, err);
    test_p101_hypot(env, err);
    test_p101_hypotf(env, err);
    test_p101_hypotl(env, err);
    test_p101_ilogb(env, err);
    test_p101_ilogbf(env, err);
    test_p101_ilogbl(env, err);
    test_p101_imaxabs(env, err);
    test_p101_imaxdiv(env, err);
    test_p101_labs(env, err);
    test_p101_ldexp(env, err);
    test_p101_ldexpf(env, err);
    test_p101_ldexpl(env, err);
    test_p101_ldiv(env, err);
    test_p101_lgamma(env, err);
    test_p101_lgammaf(env, err);
    test_p101_lgammal(env, err);
    test_p101_llabs(env, err);
    test_p101_lldiv(env, err);
    test_p101_llrint(env, err);
    test_p101_llrintf(env, err);
    test_p101_llrintl(env, err);
    test_p101_llround(env, err);
    test_p101_llroundf(env, err);
    test_p101_llroundl(env, err);
    test_p101_log(env, err);
    test_p101_log10(env, err);
    test_p101_log10f(env, err);
    test_p101_log10l(env, err);
    test_p101_log1p(env, err);
    test_p101_log1pf(env, err);
    test_p101_log1pl(env, err);
    test_p101_log2(env, err);
    test_p101_log2f(env, err);
    test_p101_log2l(env, err);
    test_p101_logb(env, err);
    test_p101_logbf(env, err);
    test_p101_logbl(env, err);
    test_p101_logf(env, err);
    test_p101_logl(env, err);
    test_p101_lrint(env, err);
    test_p101_lrintf(env, err);
    test_p101_lrintl(env, err);
    test_p101_lround(env, err);
    test_p101_lroundf(env, err);
    test_p101_lroundl(env, err);
    test_p101_malloc(env, err);
    test_p101_mblen(env, err);
    test_p101_mbrlen(env, err);
    test_p101_mbrtowc(env, err);
    test_p101_mbsrtowcs(env, err);
    test_p101_mbstowcs(env, err);
    test_p101_mbtowc(env, err);
    test_p101_mktime(env, err);
    test_p101_nextafter(env, err);
    test_p101_nextafterf(env, err);
    test_p101_nextafterl(env, err);
    test_p101_nexttoward(env, err);
    test_p101_nexttowardf(env, err);
    test_p101_nexttowardl(env, err);
    test_p101_pow(env, err);
    test_p101_powf(env, err);
    test_p101_powl(env, err);
    test_p101_printf(env, err);
    test_p101_putc(env, err);
    test_p101_putchar(env, err);
    test_p101_puts(env, err);
    test_p101_putwc(env, err);
    test_p101_putwchar(env, err);
    test_p101_raise(env, err);
    test_p101_realloc(env, err);
    test_p101_remainder(env, err);
    test_p101_remainderf(env, err);
    test_p101_remainderl(env, err);
    test_p101_remove(env, err);
    test_p101_remquo(env, err);
    test_p101_remquof(env, err);
    test_p101_remquol(env, err);
    test_p101_rename(env, err);
    test_p101_scalbln(env, err);
    test_p101_scalblnf(env, err);
    test_p101_scalblnl(env, err);
    test_p101_scalbn(env, err);
    test_p101_scalbnf(env, err);
    test_p101_scalbnl(env, err);
    test_p101_scanf(env, err);
    test_p101_setlocale(env, err);
    test_p101_setvbuf(env, err);
    test_p101_signal(env, err);
    test_p101_sin(env, err);
    test_p101_sinf(env, err);
    test_p101_sinh(env, err);
    test_p101_sinhf(env, err);
    test_p101_sinhl(env, err);
    test_p101_sinl(env, err);
    test_p101_snprintf(env, err);
    test_p101_sqrt(env, err);
    test_p101_sqrtf(env, err);
    test_p101_sqrtl(env, err);
    test_p101_sscanf(env, err);
    test_p101_strcoll(env, err);
    test_p101_strerror(env, err);
    test_p101_strftime(env, err);
    test_p101_strtod(env, err);
    test_p101_strtof(env, err);
    test_p101_strtoimax(env, err);
    test_p101_strtol(env, err);
    test_p101_strtold(env, err);
    test_p101_strtoll(env, err);
    test_p101_strtoul(env, err);
    test_p101_strtoull(env, err);
    test_p101_strtoumax(env, err);
    test_p101_strxfrm(env, err);
    test_p101_swprintf(env, err);
    test_p101_swscanf(env, err);
    test_p101_system(env, err);
    test_p101_tan(env, err);
    test_p101_tanf(env, err);
    test_p101_tanh(env, err);
    test_p101_tanhf(env, err);
    test_p101_tanhl(env, err);
    test_p101_tanl(env, err);
    test_p101_tgamma(env, err);
    test_p101_tgammaf(env, err);
    test_p101_tgammal(env, err);
    test_p101_time(env, err);
    test_p101_timespec_get(env, err);
    test_p101_tmpfile(env, err);
    test_p101_towctrans(env, err);
    test_p101_ungetc(env, err);
    test_p101_ungetwc(env, err);
    test_p101_wcrtomb(env, err);
    test_p101_wcscoll(env, err);
    test_p101_wcsftime(env, err);
    test_p101_wcsrtombs(env, err);
    test_p101_wcstod(env, err);
    test_p101_wcstof(env, err);
    test_p101_wcstoimax(env, err);
    test_p101_wcstol(env, err);
    test_p101_wcstold(env, err);
    test_p101_wcstoll(env, err);
    test_p101_wcstombs(env, err);
    test_p101_wcstoul(env, err);
    test_p101_wcstoull(env, err);
    test_p101_wcstoumax(env, err);
    test_p101_wcsxfrm(env, err);
    test_p101_wctomb(env, err);
    test_p101_wctrans(env, err);
    test_p101_wctype(env, err);
    test_p101_wprintf(env, err);
    test_p101_wscanf(env, err);
    p101_env_destroy(env);
    p101_error_destroy(err);
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
