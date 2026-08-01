#include <complex.h>
#include <ctype.h>
#include <fenv.h>
#include <locale.h>
#include <math.h>
#include <p101_c/p101_complex.h>
#include <p101_c/p101_ctype.h>
#include <p101_c/p101_fenv.h>
#include <p101_c/p101_locale.h>
#include <p101_c/p101_math.h>
#include <p101_c/p101_setjmp.h>
#include <p101_c/p101_stdatomic.h>
#include <p101_c/p101_stdio.h>
#include <p101_c/p101_stdlib.h>
#include <p101_c/p101_string.h>
#include <p101_c/p101_time.h>
#include <p101_c/p101_wchar.h>
#include <p101_c/p101_wctype.h>
#include <p101_env/env.h>
#include <p101_error/error.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>

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

/*
 * Each marker names one independently checked public API. The tests are
 * grouped by C facility so the fixtures stay readable.
 *
 * P101_TEST_CASE(p101_abort)
 * P101_TEST_CASE(p101_atomic_flag_clear_explicit)
 * P101_TEST_CASE(p101_atomic_flag_test_and_set_explicit)
 * P101_TEST_CASE(p101_atomic_signal_fence)
 * P101_TEST_CASE(p101_atomic_thread_fence)
 * P101_TEST_CASE(p101_atomic_uint_compare_exchange_strong_explicit)
 * P101_TEST_CASE(p101_atomic_uint_compare_exchange_weak)
 * P101_TEST_CASE(p101_atomic_uint_compare_exchange_weak_explicit)
 * P101_TEST_CASE(p101_atomic_uint_exchange_explicit)
 * P101_TEST_CASE(p101_atomic_uint_fetch_add)
 * P101_TEST_CASE(p101_atomic_uint_fetch_add_explicit)
 * P101_TEST_CASE(p101_atomic_uint_fetch_and)
 * P101_TEST_CASE(p101_atomic_uint_fetch_and_explicit)
 * P101_TEST_CASE(p101_atomic_uint_fetch_or_explicit)
 * P101_TEST_CASE(p101_atomic_uint_fetch_sub)
 * P101_TEST_CASE(p101_atomic_uint_fetch_sub_explicit)
 * P101_TEST_CASE(p101_atomic_uint_fetch_xor)
 * P101_TEST_CASE(p101_atomic_uint_fetch_xor_explicit)
 * P101_TEST_CASE(p101_atomic_uint_load_explicit)
 * P101_TEST_CASE(p101_atomic_uint_store)
 * P101_TEST_CASE(p101_atomic_uint_store_explicit)
 * P101_TEST_CASE(p101_bsearch)
 * P101_TEST_CASE(p101_btowc)
 * P101_TEST_CASE(p101_cbrt)
 * P101_TEST_CASE(p101_cbrtf)
 * P101_TEST_CASE(p101_cbrtl)
 * P101_TEST_CASE(p101_ceil)
 * P101_TEST_CASE(p101_ceilf)
 * P101_TEST_CASE(p101_ceill)
 * P101_TEST_CASE(p101_cimag)
 * P101_TEST_CASE(p101_cimagf)
 * P101_TEST_CASE(p101_cimagl)
 * P101_TEST_CASE(p101_clearerr)
 * P101_TEST_CASE(p101_conj)
 * P101_TEST_CASE(p101_conjf)
 * P101_TEST_CASE(p101_conjl)
 * P101_TEST_CASE(p101_copysign)
 * P101_TEST_CASE(p101_copysignf)
 * P101_TEST_CASE(p101_copysignl)
 * P101_TEST_CASE(p101_cproj)
 * P101_TEST_CASE(p101_cprojf)
 * P101_TEST_CASE(p101_cprojl)
 * P101_TEST_CASE(p101_creal)
 * P101_TEST_CASE(p101_crealf)
 * P101_TEST_CASE(p101_creall)
 * P101_TEST_CASE(p101_difftime)
 * P101_TEST_CASE(p101_exit)
 * P101_TEST_CASE(p101_exit_immediately)
 * P101_TEST_CASE(p101_fabs)
 * P101_TEST_CASE(p101_fabsf)
 * P101_TEST_CASE(p101_fabsl)
 * P101_TEST_CASE(p101_feof)
 * P101_TEST_CASE(p101_ferror)
 * P101_TEST_CASE(p101_fetestexcept)
 * P101_TEST_CASE(p101_floor)
 * P101_TEST_CASE(p101_floorf)
 * P101_TEST_CASE(p101_floorl)
 * P101_TEST_CASE(p101_fmax)
 * P101_TEST_CASE(p101_fmaxf)
 * P101_TEST_CASE(p101_fmaxl)
 * P101_TEST_CASE(p101_fmin)
 * P101_TEST_CASE(p101_fminf)
 * P101_TEST_CASE(p101_fminl)
 * P101_TEST_CASE(p101_frexp)
 * P101_TEST_CASE(p101_frexpf)
 * P101_TEST_CASE(p101_frexpl)
 * P101_TEST_CASE(p101_getenv)
 * P101_TEST_CASE(p101_isalnum)
 * P101_TEST_CASE(p101_isalpha)
 * P101_TEST_CASE(p101_isblank)
 * P101_TEST_CASE(p101_iscntrl)
 * P101_TEST_CASE(p101_isdigit)
 * P101_TEST_CASE(p101_isgraph)
 * P101_TEST_CASE(p101_islower)
 * P101_TEST_CASE(p101_isprint)
 * P101_TEST_CASE(p101_ispunct)
 * P101_TEST_CASE(p101_isspace)
 * P101_TEST_CASE(p101_isupper)
 * P101_TEST_CASE(p101_iswalnum)
 * P101_TEST_CASE(p101_iswalpha)
 * P101_TEST_CASE(p101_iswblank)
 * P101_TEST_CASE(p101_iswcntrl)
 * P101_TEST_CASE(p101_iswctype)
 * P101_TEST_CASE(p101_iswdigit)
 * P101_TEST_CASE(p101_iswgraph)
 * P101_TEST_CASE(p101_iswlower)
 * P101_TEST_CASE(p101_iswprint)
 * P101_TEST_CASE(p101_iswpunct)
 * P101_TEST_CASE(p101_iswspace)
 * P101_TEST_CASE(p101_iswupper)
 * P101_TEST_CASE(p101_iswxdigit)
 * P101_TEST_CASE(p101_isxdigit)
 * P101_TEST_CASE(p101_localeconv)
 * P101_TEST_CASE(p101_longjmp)
 * P101_TEST_CASE(p101_mbsinit)
 * P101_TEST_CASE(p101_memchr)
 * P101_TEST_CASE(p101_memcmp)
 * P101_TEST_CASE(p101_memcpy)
 * P101_TEST_CASE(p101_memmove)
 * P101_TEST_CASE(p101_memset)
 * P101_TEST_CASE(p101_modf)
 * P101_TEST_CASE(p101_modff)
 * P101_TEST_CASE(p101_modfl)
 * P101_TEST_CASE(p101_nan)
 * P101_TEST_CASE(p101_nanf)
 * P101_TEST_CASE(p101_nanl)
 * P101_TEST_CASE(p101_nearbyint)
 * P101_TEST_CASE(p101_nearbyintf)
 * P101_TEST_CASE(p101_nearbyintl)
 * P101_TEST_CASE(p101_qsort)
 * P101_TEST_CASE(p101_quick_exit)
 * P101_TEST_CASE(p101_rint)
 * P101_TEST_CASE(p101_rintf)
 * P101_TEST_CASE(p101_rintl)
 * P101_TEST_CASE(p101_round)
 * P101_TEST_CASE(p101_roundf)
 * P101_TEST_CASE(p101_roundl)
 * P101_TEST_CASE(p101_strchr)
 * P101_TEST_CASE(p101_strcmp)
 * P101_TEST_CASE(p101_strcspn)
 * P101_TEST_CASE(p101_strncat)
 * P101_TEST_CASE(p101_strncmp)
 * P101_TEST_CASE(p101_strncpy)
 * P101_TEST_CASE(p101_strpbrk)
 * P101_TEST_CASE(p101_strrchr)
 * P101_TEST_CASE(p101_strspn)
 * P101_TEST_CASE(p101_strstr)
 * P101_TEST_CASE(p101_tolower)
 * P101_TEST_CASE(p101_toupper)
 * P101_TEST_CASE(p101_towlower)
 * P101_TEST_CASE(p101_towupper)
 * P101_TEST_CASE(p101_trunc)
 * P101_TEST_CASE(p101_truncf)
 * P101_TEST_CASE(p101_truncl)
 * P101_TEST_CASE(p101_vfprintf)
 * P101_TEST_CASE(p101_vfscanf)
 * P101_TEST_CASE(p101_vfwprintf)
 * P101_TEST_CASE(p101_vfwscanf)
 * P101_TEST_CASE(p101_vprintf)
 * P101_TEST_CASE(p101_vscanf)
 * P101_TEST_CASE(p101_vsnprintf)
 * P101_TEST_CASE(p101_vsscanf)
 * P101_TEST_CASE(p101_vswprintf)
 * P101_TEST_CASE(p101_vswscanf)
 * P101_TEST_CASE(p101_vwprintf)
 * P101_TEST_CASE(p101_vwscanf)
 * P101_TEST_CASE(p101_wcschr)
 * P101_TEST_CASE(p101_wcscmp)
 * P101_TEST_CASE(p101_wcscspn)
 * P101_TEST_CASE(p101_wcslen)
 * P101_TEST_CASE(p101_wcsncat)
 * P101_TEST_CASE(p101_wcsncmp)
 * P101_TEST_CASE(p101_wcsncpy)
 * P101_TEST_CASE(p101_wcspbrk)
 * P101_TEST_CASE(p101_wcsrchr)
 * P101_TEST_CASE(p101_wcsspn)
 * P101_TEST_CASE(p101_wcsstr)
 * P101_TEST_CASE(p101_wcstok)
 * P101_TEST_CASE(p101_wctob)
 * P101_TEST_CASE(p101_wmemchr)
 * P101_TEST_CASE(p101_wmemcmp)
 * P101_TEST_CASE(p101_wmemcpy)
 * P101_TEST_CASE(p101_wmemmove)
 * P101_TEST_CASE(p101_wmemset)
 */

static void test_atomics(const struct p101_env *env)
{
    atomic_flag  flag = ATOMIC_FLAG_INIT;
    atomic_uint  value;
    unsigned int expected;

    atomic_init(&value, 1U);
    EXPECT(!p101_atomic_flag_test_and_set_explicit(env, &flag, memory_order_seq_cst));
    p101_atomic_flag_clear_explicit(env, &flag, memory_order_seq_cst);
    EXPECT(!p101_atomic_flag_test_and_set_explicit(env, &flag, memory_order_relaxed));

    p101_atomic_signal_fence(env, memory_order_seq_cst);
    p101_atomic_thread_fence(env, memory_order_seq_cst);

    expected = 1U;
    EXPECT(p101_atomic_uint_compare_exchange_strong_explicit(env, &value, &expected, 2U, memory_order_seq_cst, memory_order_seq_cst));
    expected = 2U;
    while(!p101_atomic_uint_compare_exchange_weak(env, &value, &expected, 3U))
    {
        expected = 2U;
    }
    expected = 3U;
    while(!p101_atomic_uint_compare_exchange_weak_explicit(env, &value, &expected, 4U, memory_order_seq_cst, memory_order_seq_cst))
    {
        expected = 3U;
    }
    EXPECT(p101_atomic_uint_exchange_explicit(env, &value, 8U, memory_order_seq_cst) == 4U);
    EXPECT(p101_atomic_uint_fetch_add(env, &value, 2U) == 8U);
    EXPECT(p101_atomic_uint_fetch_add_explicit(env, &value, 2U, memory_order_seq_cst) == 10U);
    EXPECT(p101_atomic_uint_fetch_and(env, &value, 7U) == 12U);
    EXPECT(p101_atomic_uint_fetch_and_explicit(env, &value, 6U, memory_order_seq_cst) == 4U);
    EXPECT(p101_atomic_uint_fetch_or_explicit(env, &value, 1U, memory_order_seq_cst) == 4U);
    EXPECT(p101_atomic_uint_fetch_sub(env, &value, 1U) == 5U);
    EXPECT(p101_atomic_uint_fetch_sub_explicit(env, &value, 1U, memory_order_seq_cst) == 4U);
    EXPECT(p101_atomic_uint_fetch_xor(env, &value, 3U) == 3U);
    EXPECT(p101_atomic_uint_fetch_xor_explicit(env, &value, 1U, memory_order_seq_cst) == 0U);
    EXPECT(p101_atomic_uint_load_explicit(env, &value, memory_order_seq_cst) == 1U);
    p101_atomic_uint_store(env, &value, 7U);
    EXPECT(atomic_load(&value) == 7U);
    p101_atomic_uint_store_explicit(env, &value, 9U, memory_order_seq_cst);
    EXPECT(atomic_load(&value) == 9U);
}

static void test_math(const struct p101_env *env)
{
    int         exponent;
    double      integral;
    float       integral_f;
    long double integral_l;

    EXPECT(p101_cbrt(env, 8.0) == 2.0);
    EXPECT(p101_cbrtf(env, 8.0F) == 2.0F);
    EXPECT(p101_cbrtl(env, 8.0L) == 2.0L);
    EXPECT(p101_ceil(env, 1.25) == 2.0);
    EXPECT(p101_ceilf(env, 1.25F) == 2.0F);
    EXPECT(p101_ceill(env, 1.25L) == 2.0L);
    EXPECT(p101_copysign(env, 2.0, -1.0) == -2.0);
    EXPECT(p101_copysignf(env, 2.0F, -1.0F) == -2.0F);
    EXPECT(p101_copysignl(env, 2.0L, -1.0L) == -2.0L);
    EXPECT(p101_fabs(env, -2.0) == 2.0);
    EXPECT(p101_fabsf(env, -2.0F) == 2.0F);
    EXPECT(p101_fabsl(env, -2.0L) == 2.0L);
    EXPECT(p101_floor(env, 1.75) == 1.0);
    EXPECT(p101_floorf(env, 1.75F) == 1.0F);
    EXPECT(p101_floorl(env, 1.75L) == 1.0L);
    EXPECT(p101_fmax(env, 1.0, 2.0) == 2.0);
    EXPECT(p101_fmaxf(env, 1.0F, 2.0F) == 2.0F);
    EXPECT(p101_fmaxl(env, 1.0L, 2.0L) == 2.0L);
    EXPECT(p101_fmin(env, 1.0, 2.0) == 1.0);
    EXPECT(p101_fminf(env, 1.0F, 2.0F) == 1.0F);
    EXPECT(p101_fminl(env, 1.0L, 2.0L) == 1.0L);
    EXPECT(p101_frexp(env, 8.0, &exponent) == 0.5 && exponent == 4);
    EXPECT(p101_frexpf(env, 8.0F, &exponent) == 0.5F && exponent == 4);
    EXPECT(p101_frexpl(env, 8.0L, &exponent) == 0.5L && exponent == 4);
    EXPECT(p101_modf(env, 1.5, &integral) == 0.5 && integral == 1.0);
    EXPECT(p101_modff(env, 1.5F, &integral_f) == 0.5F && integral_f == 1.0F);
    EXPECT(p101_modfl(env, 1.5L, &integral_l) == 0.5L && integral_l == 1.0L);
    EXPECT(isnan(p101_nan(env, "")));
    EXPECT(isnan(p101_nanf(env, "")));
    EXPECT(isnan(p101_nanl(env, "")));
    EXPECT(p101_nearbyint(env, 2.0) == 2.0);
    EXPECT(p101_nearbyintf(env, 2.0F) == 2.0F);
    EXPECT(p101_nearbyintl(env, 2.0L) == 2.0L);
    EXPECT(p101_rint(env, 2.0) == 2.0);
    EXPECT(p101_rintf(env, 2.0F) == 2.0F);
    EXPECT(p101_rintl(env, 2.0L) == 2.0L);
    EXPECT(p101_round(env, 1.5) == 2.0);
    EXPECT(p101_roundf(env, 1.5F) == 2.0F);
    EXPECT(p101_roundl(env, 1.5L) == 2.0L);
    EXPECT(p101_trunc(env, 1.75) == 1.0);
    EXPECT(p101_truncf(env, 1.75F) == 1.0F);
    EXPECT(p101_truncl(env, 1.75L) == 1.0L);
}

static void test_complex(const struct p101_env *env)
{
    double complex      z  = 2.0 + csqrt(-9.0);
    float complex       zf = 2.0F + csqrtf(-9.0F);
    long double complex zl = 2.0L + csqrtl(-9.0L);

    EXPECT(p101_cimag(env, z) == 3.0);
    EXPECT(p101_cimagf(env, zf) == 3.0F);
    EXPECT(p101_cimagl(env, zl) == 3.0L);
    EXPECT(creal(p101_conj(env, z)) == 2.0 && cimag(p101_conj(env, z)) == -3.0);
    EXPECT(crealf(p101_conjf(env, zf)) == 2.0F && cimagf(p101_conjf(env, zf)) == -3.0F);
    EXPECT(creall(p101_conjl(env, zl)) == 2.0L && cimagl(p101_conjl(env, zl)) == -3.0L);
    EXPECT(creal(p101_cproj(env, z)) == 2.0 && cimag(p101_cproj(env, z)) == 3.0);
    EXPECT(crealf(p101_cprojf(env, zf)) == 2.0F && cimagf(p101_cprojf(env, zf)) == 3.0F);
    EXPECT(creall(p101_cprojl(env, zl)) == 2.0L && cimagl(p101_cprojl(env, zl)) == 3.0L);
    EXPECT(p101_creal(env, z) == 2.0);
    EXPECT(p101_crealf(env, zf) == 2.0F);
    EXPECT(p101_creall(env, zl) == 2.0L);
}

static void test_character_classes(const struct p101_env *env)
{
    EXPECT(!!p101_isalnum(env, 'A') == !!isalnum('A'));
    EXPECT(!!p101_isalpha(env, 'A') == !!isalpha('A'));
    EXPECT(!!p101_isblank(env, ' ') == !!isblank(' '));
    EXPECT(!!p101_iscntrl(env, '\n') == !!iscntrl('\n'));
    EXPECT(!!p101_isdigit(env, '7') == !!isdigit('7'));
    EXPECT(!!p101_isgraph(env, 'A') == !!isgraph('A'));
    EXPECT(!!p101_islower(env, 'a') == !!islower('a'));
    EXPECT(!!p101_isprint(env, 'A') == !!isprint('A'));
    EXPECT(!!p101_ispunct(env, '!') == !!ispunct('!'));
    EXPECT(!!p101_isspace(env, ' ') == !!isspace(' '));
    EXPECT(!!p101_isupper(env, 'A') == !!isupper('A'));
    EXPECT(!!p101_isxdigit(env, 'f') == !!isxdigit('f'));
    EXPECT(p101_tolower(env, 'A') == 'a');
    EXPECT(p101_toupper(env, 'a') == 'A');

    EXPECT(!!p101_iswalnum(env, L'A') == !!iswalnum(L'A'));
    EXPECT(!!p101_iswalpha(env, L'A') == !!iswalpha(L'A'));
    EXPECT(!!p101_iswblank(env, L' ') == !!iswblank(L' '));
    EXPECT(!!p101_iswcntrl(env, L'\n') == !!iswcntrl(L'\n'));
    EXPECT(!!p101_iswdigit(env, L'7') == !!iswdigit(L'7'));
    EXPECT(!!p101_iswgraph(env, L'A') == !!iswgraph(L'A'));
    EXPECT(!!p101_iswlower(env, L'a') == !!iswlower(L'a'));
    EXPECT(!!p101_iswprint(env, L'A') == !!iswprint(L'A'));
    EXPECT(!!p101_iswpunct(env, L'!') == !!iswpunct(L'!'));
    EXPECT(!!p101_iswspace(env, L' ') == !!iswspace(L' '));
    EXPECT(!!p101_iswupper(env, L'A') == !!iswupper(L'A'));
    EXPECT(!!p101_iswxdigit(env, L'f') == !!iswxdigit(L'f'));
    EXPECT(!!p101_iswctype(env, L'A', wctype("alpha")) == !!iswctype(L'A', wctype("alpha")));
    EXPECT(p101_towlower(env, L'A') == L'a');
    EXPECT(p101_towupper(env, L'a') == L'A');
}

static void test_memory_and_strings(const struct p101_env *env)
{
    char          bytes[16]      = "abc";
    char          other[16]      = "abc";
    wchar_t       wide[16]       = L"abc";
    wchar_t       wide_other[16] = L"abc";
    wchar_t      *context;
    const wchar_t token_input[] = L"a,b";

    EXPECT(p101_memchr(env, bytes, 'b', 3) == &bytes[1]);
    EXPECT(p101_memcmp(env, bytes, other, 3) == 0);
    EXPECT(p101_memcpy(env, other, "xyz", 4) == other && strcmp(other, "xyz") == 0);
    EXPECT(p101_memmove(env, other + 1, other, 3) == other + 1);
    EXPECT(p101_memset(env, other, 'q', 2) == other && other[0] == 'q' && other[1] == 'q');
    EXPECT(p101_strchr(env, bytes, 'b') == &bytes[1]);
    EXPECT(p101_strcmp(env, "a", "a") == 0);
    EXPECT(p101_strcspn(env, "abc", "c") == 2);
    bytes[0] = 'a';
    bytes[1] = '\0';
    EXPECT(p101_strncat(env, bytes, "bc", 2) == bytes && strcmp(bytes, "abc") == 0);
    EXPECT(p101_strncmp(env, "abc", "abd", 2) == 0);
    EXPECT(p101_strncpy(env, other, "ab", sizeof(other)) == other && strcmp(other, "ab") == 0);
    EXPECT(p101_strpbrk(env, "abc", "xby") == &"abc"[1]);
    EXPECT(p101_strrchr(env, "abca", 'a') == &"abca"[3]);
    EXPECT(p101_strspn(env, "abc", "ab") == 2);
    EXPECT(p101_strstr(env, "abcd", "bc") == &"abcd"[1]);

    EXPECT(p101_wcschr(env, wide, L'b') == &wide[1]);
    EXPECT(p101_wcscmp(env, L"a", L"a") == 0);
    EXPECT(p101_wcscspn(env, L"abc", L"c") == 2);
    EXPECT(p101_wcslen(env, L"abc") == 3);
    wide[0] = L'a';
    wide[1] = L'\0';
    EXPECT(p101_wcsncat(env, wide, L"bc", 2) == wide && wcscmp(wide, L"abc") == 0);
    EXPECT(p101_wcsncmp(env, L"abc", L"abd", 2) == 0);
    EXPECT(p101_wcsncpy(env, wide_other, L"ab", 16) == wide_other && wcscmp(wide_other, L"ab") == 0);
    EXPECT(p101_wcspbrk(env, L"abc", L"xby") == &L"abc"[1]);
    EXPECT(p101_wcsrchr(env, L"abca", L'a') == &L"abca"[3]);
    EXPECT(p101_wcsspn(env, L"abc", L"ab") == 2);
    EXPECT(p101_wcsstr(env, L"abcd", L"bc") == &L"abcd"[1]);
    p101_wmemcpy(env, wide, token_input, 4);
    EXPECT(wcscmp(p101_wcstok(env, wide, L",", &context), L"a") == 0);
    EXPECT(p101_wmemchr(env, wide_other, L'b', 3) == &wide_other[1]);
    EXPECT(p101_wmemcmp(env, L"abc", L"abc", 3) == 0);
    EXPECT(p101_wmemcpy(env, wide, L"xyz", 4) == wide && wcscmp(wide, L"xyz") == 0);
    EXPECT(p101_wmemmove(env, wide + 1, wide, 3) == wide + 1);
    EXPECT(p101_wmemset(env, wide, L'q', 2) == wide && wide[0] == L'q' && wide[1] == L'q');
}

static int compare_ints(const void *left, const void *right)
{
    const int *a = left;
    const int *b = right;
    return (*a > *b) - (*a < *b);
}

static void test_stdlib_and_misc(const struct p101_env *env, struct p101_error *err)
{
    int           values[] = {3, 1, 2};
    int           key      = 2;
    mbstate_t     state    = {0};
    jmp_buf       jump;
    struct lconv *locale;

    p101_qsort(env, values, 3, sizeof(values[0]), compare_ints);
    EXPECT(values[0] == 1 && values[1] == 2 && values[2] == 3);
    EXPECT(p101_bsearch(env, &key, values, 3, sizeof(values[0]), compare_ints) == &values[1]);
    EXPECT(p101_getenv(env, err, "PATH") == getenv("PATH"));
    locale = p101_localeconv(env);
    EXPECT(locale != NULL && locale->decimal_point != NULL);
    EXPECT(p101_difftime(env, (time_t)4, (time_t)1) == 3.0);
    EXPECT(p101_mbsinit(env, &state) != 0);
    EXPECT(p101_btowc(env, 'A') == L'A');
    EXPECT(p101_wctob(env, L'A') == 'A');
    EXPECT(p101_fetestexcept(env, FE_ALL_EXCEPT) == fetestexcept(FE_ALL_EXCEPT));

    if(setjmp(jump) == 0)
    {
        p101_longjmp(env, jump, 7);
    }
    else
    {
        EXPECT(true);
    }
}

static int call_vfprintf(const struct p101_env *env, struct p101_error *err, FILE *stream, const char *format, ...)
{
    int     result;
    va_list arguments;
    va_start(arguments, format);
    result = p101_vfprintf(env, err, stream, format, arguments);
    va_end(arguments);
    return result;
}

static int call_vfscanf(const struct p101_env *env, struct p101_error *err, FILE *stream, const char *format, ...)
{
    int     result;
    va_list arguments;
    va_start(arguments, format);
    result = p101_vfscanf(env, err, stream, format, arguments);
    va_end(arguments);
    return result;
}

static int call_vprintf(const struct p101_env *env, struct p101_error *err, const char *format, ...)
{
    int     result;
    va_list arguments;
    va_start(arguments, format);
    result = p101_vprintf(env, err, format, arguments);
    va_end(arguments);
    return result;
}

static int call_vscanf(const struct p101_env *env, struct p101_error *err, const char *format, ...)
{
    int     result;
    va_list arguments;
    va_start(arguments, format);
    result = p101_vscanf(env, err, format, arguments);
    va_end(arguments);
    return result;
}

static int call_vsnprintf(const struct p101_env *env, struct p101_error *err, char *buffer, size_t size, const char *format, ...)
{
    int     result;
    va_list arguments;
    va_start(arguments, format);
    result = p101_vsnprintf(env, err, buffer, size, format, arguments);
    va_end(arguments);
    return result;
}

static int call_vsscanf(const struct p101_env *env, struct p101_error *err, const char *input, const char *format, ...)
{
    int     result;
    va_list arguments;
    va_start(arguments, format);
    result = p101_vsscanf(env, err, input, format, arguments);
    va_end(arguments);
    return result;
}

static int call_vfwprintf(const struct p101_env *env, struct p101_error *err, FILE *stream, const wchar_t *format, ...)
{
    int     result;
    va_list arguments;
    va_start(arguments, format);
    result = p101_vfwprintf(env, err, stream, format, arguments);
    va_end(arguments);
    return result;
}

static int call_vfwscanf(const struct p101_env *env, struct p101_error *err, FILE *stream, const wchar_t *format, ...)
{
    int     result;
    va_list arguments;
    va_start(arguments, format);
    result = p101_vfwscanf(env, err, stream, format, arguments);
    va_end(arguments);
    return result;
}

static int call_vswprintf(const struct p101_env *env, struct p101_error *err, wchar_t *buffer, size_t size, const wchar_t *format, ...)
{
    int     result;
    va_list arguments;
    va_start(arguments, format);
    result = p101_vswprintf(env, err, buffer, size, format, arguments);
    va_end(arguments);
    return result;
}

static int call_vswscanf(const struct p101_env *env, struct p101_error *err, const wchar_t *input, const wchar_t *format, ...)
{
    int     result;
    va_list arguments;
    va_start(arguments, format);
    result = p101_vswscanf(env, err, input, format, arguments);
    va_end(arguments);
    return result;
}

static int call_vwprintf(const struct p101_env *env, struct p101_error *err, const wchar_t *format, ...)
{
    int     result;
    va_list arguments;
    va_start(arguments, format);
    result = p101_vwprintf(env, err, format, arguments);
    va_end(arguments);
    return result;
}

static int call_vwscanf(const struct p101_env *env, struct p101_error *err, const wchar_t *format, ...)
{
    int     result;
    va_list arguments;
    va_start(arguments, format);
    result = p101_vwscanf(env, err, format, arguments);
    va_end(arguments);
    return result;
}

static void test_wide_standard_io(const struct p101_env *env, struct p101_error *err)
{
    pid_t child;
    int   status;

    /*
     * A standard stream becomes permanently byte- or wide-oriented after its
     * first I/O operation. Exercise the wide standard-stream wrappers in a
     * pristine child before the parent performs narrow I/O.
     */
    child = fork();
    EXPECT(child >= 0);
    if(child == 0)
    {
        bool succeeded;

        succeeded = call_vwprintf(env, err, L"") == 0;
        succeeded = call_vwscanf(env, err, L"") == 0 && succeeded;
        succeeded = !p101_error_has_error(err) && succeeded;
        _Exit(succeeded ? EXIT_SUCCESS : EXIT_FAILURE);
    }
    if(child > 0)
    {
        EXPECT(waitpid(child, &status, 0) == child);
        EXPECT(WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS);
    }
}

static void test_stdio(const struct p101_env *env, struct p101_error *err)
{
    FILE   *stream;
    char    buffer[32];
    wchar_t wide_buffer[32];
    int     value;

    stream = tmpfile();
    EXPECT(stream != NULL);
    if(stream == NULL)
    {
        return;
    }
    EXPECT(call_vfprintf(env, err, stream, "%d", 7) == 1);
    rewind(stream);
    value = 0;
    EXPECT(call_vfscanf(env, err, stream, "%d", &value) == 1 && value == 7);
    EXPECT(fgetc(stream) == EOF);
    EXPECT(p101_feof(env, stream) != 0);
    EXPECT(p101_ferror(env, stream) == 0);
    p101_clearerr(env, stream);
    EXPECT(p101_feof(env, stream) == 0);
    fclose(stream);

    EXPECT(call_vprintf(env, err, "") == 0);
    EXPECT(call_vscanf(env, err, "") == 0);
    EXPECT(call_vsnprintf(env, err, buffer, sizeof(buffer), "%d", 7) == 1 && strcmp(buffer, "7") == 0);
    value = 0;
    EXPECT(call_vsscanf(env, err, "7", "%d", &value) == 1 && value == 7);

    stream = tmpfile();
    EXPECT(stream != NULL);
    if(stream != NULL)
    {
        EXPECT(call_vfwprintf(env, err, stream, L"%ls", L"x") == 1);
        fclose(stream);
    }
    stream = tmpfile();
    EXPECT(stream != NULL);
    if(stream != NULL)
    {
        EXPECT(call_vfwscanf(env, err, stream, L"") == 0);
        fclose(stream);
    }
    EXPECT(call_vswprintf(env, err, wide_buffer, 32, L"%ls", L"x") == 1 && wcscmp(wide_buffer, L"x") == 0);
    value = 0;
    EXPECT(call_vswscanf(env, err, L"7", L"%d", &value) == 1 && value == 7);
    EXPECT(!p101_error_has_error(err));
}

static void test_termination(const struct p101_env *env)
{
    pid_t child;
    int   status;

    child = fork();
    EXPECT(child >= 0);
    if(child == 0)
    {
        p101_exit_immediately(env, 31);
    }
    EXPECT(waitpid(child, &status, 0) == child && WIFEXITED(status) && WEXITSTATUS(status) == 31);

    child = fork();
    EXPECT(child >= 0);
    if(child == 0)
    {
        p101_exit(env, 32);
    }
    EXPECT(waitpid(child, &status, 0) == child && WIFEXITED(status) && WEXITSTATUS(status) == 32);

    child = fork();
    EXPECT(child >= 0);
    if(child == 0)
    {
        p101_quick_exit(env, 33);
    }
    EXPECT(waitpid(child, &status, 0) == child && WIFEXITED(status) && WEXITSTATUS(status) == 33);

    child = fork();
    EXPECT(child >= 0);
    if(child == 0)
    {
        p101_abort(env);
    }
    EXPECT(waitpid(child, &status, 0) == child && WIFSIGNALED(status));
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

    test_wide_standard_io(env, err);
    test_atomics(env);
    test_math(env);
    test_complex(env);
    test_character_classes(env);
    test_memory_and_strings(env);
    test_stdlib_and_misc(env, err);
    test_stdio(env, err);
    test_termination(env);

    p101_env_destroy(env);
    p101_error_destroy(err);
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
