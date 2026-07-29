/*
 * Copyright 2021-2024 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "p101_c/p101_stdlib.h"
#include "p101_c_internal.h"
#include <limits.h>
#include <stdint.h>

static const void *p101_pointer_value_for_log(uintptr_t ptr_value);
static int         multibyte_error_code(void);

static const void *p101_pointer_value_for_log(uintptr_t ptr_value)
{
#ifdef __clang_analyzer__
    (void)ptr_value;

    return NULL;
#else
    return (const void *)ptr_value;    // NOLINT(clang-analyzer-unix.Malloc,performance-no-int-to-ptr)
#endif
}

static int multibyte_error_code(void)
{
    return (errno == 0) ? EILSEQ : errno;
}

P101_ATTR_NORETURN void p101_exit_immediately(const struct p101_env *env, int status)
{
    P101_TRACE(env);
    P101_TRACE_EXIT(env);

    _Exit(status);
}

P101_ATTR_NORETURN void p101_abort(const struct p101_env *env)
{
    P101_TRACE(env);
    P101_TRACE_EXIT(env);

    abort();
}

int p101_abs(const struct p101_env *env, struct p101_error *err, int i)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, -1);
    errno = 0;

    if(i == INT_MIN)
    {
        P101_ERROR_RAISE_ERRNO(err, ERANGE);
        ret_val = i;
    }
    else
    {
        ret_val = abs(i);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_atexit(const struct p101_env *env, struct p101_error *err, void (*func)(void))
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, -1);
    errno = 0;

    ret_val = atexit(func);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, (errno == 0) ? EAGAIN : errno);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

#ifdef __apple_build_version__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wallocator-wrappers"
#endif
void *p101_aligned_alloc(const struct p101_env *env, struct p101_error *err, size_t alignment, size_t size)
{
    void *memory;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, "aligned_alloc", NULL);

    if(alignment == 0 || size == 0 || (alignment & (alignment - 1U)) != 0 || (size % alignment) != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, EINVAL);
        P101_TRACE_EXIT(env);

        return NULL;
    }

    errno  = 0;
    memory = aligned_alloc(alignment, size);

    if(memory == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, (errno == 0) ? ENOMEM : errno);
    }
    else
    {
        P101_TRACK_ALLOC(env, memory, size);
    }

    P101_TRACE_EXIT(env);

    return memory;
}
#ifdef __apple_build_version__
    #pragma clang diagnostic pop
#endif

int p101_at_quick_exit(const struct p101_env *env, struct p101_error *err, void (*func)(void))
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, "at_quick_exit", -1);
    errno   = 0;
    ret_val = at_quick_exit(func);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, (errno == 0) ? EAGAIN : errno);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

const void *p101_bsearch(const struct p101_env *env, const void *key, const void *base, size_t nel, size_t width, int (*compar)(const void *, const void *))
{
    const void *ret_val;

    P101_TRACE(env);
    ret_val = bsearch(key, base, nel, width, compar);

    P101_TRACE_EXIT(env);

    return ret_val;
}

#ifdef __apple_build_version__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wallocator-wrappers"
#endif
void *p101_calloc(const struct p101_env *env, struct p101_error *err, size_t nelem, size_t elsize)
{
    void  *memory;
    size_t requested_size;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, "calloc", NULL);

    if(nelem == 0 || elsize == 0)
    {
        P101_ERROR_RAISE_ERRNO(err, EINVAL);
        P101_TRACE_EXIT(env);

        return NULL;
    }

    if(nelem > (SIZE_MAX / elsize))
    {
        P101_ERROR_RAISE_ERRNO(err, EOVERFLOW);
        P101_TRACE_EXIT(env);

        return NULL;
    }

    requested_size = nelem * elsize;
    errno          = 0;
    memory         = calloc(nelem, elsize);

    if(memory == NULL && requested_size != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, (errno == 0) ? ENOMEM : errno);
    }
    else
    {
        P101_TRACK_ALLOC(env, memory, requested_size);
    }

    P101_TRACE_EXIT(env);

    return memory;
}
#ifdef __apple_build_version__
    #pragma clang diagnostic pop
#endif

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"

div_t p101_div(const struct p101_env *env, struct p101_error *err, int numer, int denom)
{
    div_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, "div", ((div_t){0, 0}));

    if(denom == 0)
    {
        P101_ERROR_RAISE_ERRNO(err, EDOM);
        ret_val.quot = 0;
        ret_val.rem  = 0;
        P101_TRACE_EXIT(env);

        return ret_val;
    }
    if(numer == INT_MIN && denom == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, ERANGE);
        ret_val.quot = 0;
        ret_val.rem  = 0;
        P101_TRACE_EXIT(env);

        return ret_val;
    }

    errno   = 0;
    ret_val = div(numer, denom);

    P101_TRACE_EXIT(env);

    return ret_val;
}

#pragma GCC diagnostic pop

P101_ATTR_NORETURN void p101_exit(const struct p101_env *env, int status)
{
    P101_TRACE(env);
    P101_TRACE_EXIT(env);

    exit(status);
}

void p101_free(const struct p101_env *env, void *ptr)
{
    P101_TRACE(env);
    if(ptr != NULL)
    {
        P101_TRACK_FREE(env, ptr);
    }
    free(ptr);
    P101_TRACE_EXIT(env);
}

char *p101_getenv(const struct p101_env *env, const char *name)
{
    char *ret_val;

    P101_TRACE(env);
    ret_val = getenv(name);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long p101_labs(const struct p101_env *env, struct p101_error *err, long i)
{
    long ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    errno = 0;

    if(i == LONG_MIN)
    {
        P101_ERROR_RAISE_ERRNO(err, ERANGE);
        ret_val = i;
    }
    else
    {
        ret_val = labs(i);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"

ldiv_t p101_ldiv(const struct p101_env *env, struct p101_error *err, long numer, long denom)
{
    ldiv_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, "ldiv", ((ldiv_t){0, 0}));

    if(denom == 0)
    {
        P101_ERROR_RAISE_ERRNO(err, EDOM);
        ret_val.quot = 0;
        ret_val.rem  = 0;
        P101_TRACE_EXIT(env);

        return ret_val;
    }
    if(numer == LONG_MIN && denom == -1L)
    {
        P101_ERROR_RAISE_ERRNO(err, ERANGE);
        ret_val.quot = 0;
        ret_val.rem  = 0;
        P101_TRACE_EXIT(env);

        return ret_val;
    }

    errno   = 0;
    ret_val = ldiv(numer, denom);

    P101_TRACE_EXIT(env);

    return ret_val;
}

#pragma GCC diagnostic pop

long long p101_llabs(const struct p101_env *env, struct p101_error *err, long long i)
{
    long long ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    errno = 0;

    if(i == LLONG_MIN)
    {
        P101_ERROR_RAISE_ERRNO(err, ERANGE);
        ret_val = i;
    }
    else
    {
        ret_val = llabs(i);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"

lldiv_t p101_lldiv(const struct p101_env *env, struct p101_error *err, long long numer, long long denom)
{
    lldiv_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, "lldiv", ((lldiv_t){0, 0}));

    if(denom == 0)
    {
        P101_ERROR_RAISE_ERRNO(err, EDOM);
        ret_val.quot = 0;
        ret_val.rem  = 0;
        P101_TRACE_EXIT(env);

        return ret_val;
    }
    if(numer == LLONG_MIN && denom == -1LL)
    {
        P101_ERROR_RAISE_ERRNO(err, ERANGE);
        ret_val.quot = 0;
        ret_val.rem  = 0;
        P101_TRACE_EXIT(env);

        return ret_val;
    }

    errno   = 0;
    ret_val = lldiv(numer, denom);

    P101_TRACE_EXIT(env);

    return ret_val;
}

#pragma GCC diagnostic pop

#ifdef __apple_build_version__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wallocator-wrappers"
#endif
void *p101_malloc(const struct p101_env *env, struct p101_error *err, size_t size)
{
    void *memory;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, "malloc", NULL);

    if(size == 0)
    {
        P101_ERROR_RAISE_ERRNO(err, EINVAL);
        P101_TRACE_EXIT(env);

        return NULL;
    }

    errno  = 0;
    memory = malloc(size);

    if(memory == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, (errno == 0) ? ENOMEM : errno);
    }
    else
    {
        P101_TRACK_ALLOC(env, memory, size);
    }

    P101_TRACE_EXIT(env);

    return memory;
}
#ifdef __apple_build_version__
    #pragma clang diagnostic pop
#endif

int p101_mblen(const struct p101_env *env, struct p101_error *err, const char *s, size_t n)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, -1);
    errno   = 0;
    ret_val = mblen(s, n);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, multibyte_error_code());
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

size_t p101_mbstowcs(const struct p101_env *env, struct p101_error *err, wchar_t *restrict pwcs, const char *restrict s, size_t n)
{
    size_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, (size_t)-1);
    errno   = 0;
    ret_val = mbstowcs(pwcs, s, n);

    if(ret_val == (size_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, multibyte_error_code());
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_mbtowc(const struct p101_env *env, struct p101_error *err, wchar_t *restrict pwc, const char *restrict s, size_t n)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, -1);
    errno   = 0;
    ret_val = mbtowc(pwc, s, n);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, multibyte_error_code());
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

void p101_qsort(const struct p101_env *env, void *base, size_t nel, size_t width, int (*compar)(const void *, const void *))
{
    P101_TRACE(env);
    qsort(base, nel, width, compar);
    P101_TRACE_EXIT(env);
}

P101_ATTR_NORETURN void p101_quick_exit(const struct p101_env *env, int status)
{
    P101_TRACE(env);
    P101_TRACE_EXIT(env);

    quick_exit(status);
}

#ifdef __apple_build_version__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wallocator-wrappers"
#endif
void *p101_realloc(const struct p101_env *env, struct p101_error *err, void *ptr, size_t size)
{
    void     *memory;
    uintptr_t old_ptr_value;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, "realloc", NULL);

    if(size == 0)
    {
        P101_ERROR_RAISE_ERRNO(err, EINVAL);
        P101_TRACE_EXIT(env);

        return NULL;
    }

    errno         = 0;
    old_ptr_value = (uintptr_t)ptr;
    memory        = realloc(ptr, size);

    if(memory == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, (errno == 0) ? ENOMEM : errno);
    }
    else
    {
        P101_TRACK_REALLOC(env, p101_pointer_value_for_log(old_ptr_value), memory, size);
    }

    P101_TRACE_EXIT(env);

    return memory;
}
#ifdef __apple_build_version__
    #pragma clang diagnostic pop
#endif

double p101_strtod(const struct p101_env *env, struct p101_error *err, const char *restrict nptr, char **restrict endptr)
{
    double ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    errno   = 0;
    ret_val = strtod(nptr, endptr);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_strtof(const struct p101_env *env, struct p101_error *err, const char *restrict nptr, char **restrict endptr)
{
    float ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    errno   = 0;
    ret_val = strtof(nptr, endptr);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

long p101_strtol(const struct p101_env *env, struct p101_error *err, const char *restrict nptr, char **restrict endptr, int base)
{
    long ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    errno   = 0;
    ret_val = strtol(nptr, endptr, base);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_strtold(const struct p101_env *env, struct p101_error *err, const char *restrict nptr, char **restrict endptr)
{
    long double ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    errno   = 0;
    ret_val = strtold(nptr, endptr);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

long long p101_strtoll(const struct p101_env *env, struct p101_error *err, const char *restrict nptr, char **restrict endptr, int base)
{
    long long ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    errno   = 0;
    ret_val = strtoll(nptr, endptr, base);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned long p101_strtoul(const struct p101_env *env, struct p101_error *err, const char *restrict str, char **restrict endptr, int base)
{
    unsigned long ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    errno   = 0;
    ret_val = strtoul(str, endptr, base);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned long long p101_strtoull(const struct p101_env *env, struct p101_error *err, const char *restrict str, char **restrict endptr, int base)
{
    unsigned long long ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    errno   = 0;
    ret_val = strtoull(str, endptr, base);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_system(const struct p101_env *env, struct p101_error *err, const char *command)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, -1);
    errno   = 0;
    ret_val = system(command);    // NOLINT(cert-env33-c, bugprone-command-processor)

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, (errno == 0) ? EIO : errno);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

size_t p101_wcstombs(const struct p101_env *env, struct p101_error *err, char *restrict s, const wchar_t *restrict pwcs, size_t n)
{
    size_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, (size_t)-1);
    errno   = 0;
    ret_val = wcstombs(s, pwcs, n);

    if(ret_val == (size_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, multibyte_error_code());
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_wctomb(const struct p101_env *env, struct p101_error *err, char *s, wchar_t wchar)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, -1);
    errno   = 0;
    ret_val = wctomb(s, wchar);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, multibyte_error_code());
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}
