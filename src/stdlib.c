/*
 * Copyright 2021-2022 D'Arcy Smith.
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


void p101__Exit(const struct p101_env *env, int status)
{
    P101_TRACE(env);
    errno = 0;
    _Exit(status);
}

_Noreturn void p101_abort(const struct p101_env *env)
{
    P101_TRACE(env);
    errno = 0;
    abort();
}

int p101_abs(const struct p101_env *env, __attribute__((unused)) struct p101_error *err, int i)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;

    // TODO: handle if INT_MIN not working
    ret_val = abs(i);

    return ret_val;
}

int p101_atexit(const struct p101_env *env, struct p101_error *err, void (*func)(void))
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;

    ret_val = atexit(func);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void *p101_bsearch(const struct p101_env *env,
                 const void                *key,
                 const void                *base,
                 size_t                     nel,
                 size_t                     width,
                 int (*compar)(const void *, const void *))
{
    void *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = bsearch(key, base, nel, width, compar);

    return ret_val;
}

void *p101_calloc(const struct p101_env *env, struct p101_error *err, size_t nelem, size_t elsize)
{
    void *memory;

    P101_TRACE(env);
    errno  = 0;
    memory = calloc(nelem, elsize);

    if(memory == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return memory;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
div_t p101_div(const struct p101_env *env, int numer, int denom)
{
    div_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = div(numer, denom);

    return ret_val;
}
#pragma GCC diagnostic pop

_Noreturn void p101_exit(const struct p101_env *env, int status)
{
    P101_TRACE(env);
    errno = 0;
    exit(status);
}

void p101_free(const struct p101_env *env, void *ptr)
{
    P101_TRACE(env);
    errno = 0;
    free(ptr);
}

char *p101_getenv(const struct p101_env *env, const char *name)
{
    char *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = getenv(name);

    return ret_val;
}

long p101_labs(const struct p101_env *env, __attribute__((unused)) struct p101_error *err, long i)
{
    long ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = labs(i);

    // TODO: handle the case that i can't be handled

    return ret_val;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
ldiv_t p101_ldiv(const struct p101_env *env, long numer, long denom)
{
    ldiv_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = ldiv(numer, denom);

    return ret_val;
}
#pragma GCC diagnostic pop

long long p101_llabs(const struct p101_env *env, __attribute__((unused)) struct p101_error *err, long long i)
{
    long long ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = llabs(i);

    // TODO: handle if i cannot be represented

    return ret_val;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
lldiv_t p101_lldiv(const struct p101_env *env, long long numer, long long denom)
{
    lldiv_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = lldiv(numer, denom);

    return ret_val;
}
#pragma GCC diagnostic pop

void *p101_malloc(const struct p101_env *env, struct p101_error *err, size_t size)
{
    void *memory;

    P101_TRACE(env);
    errno  = 0;
    memory = malloc(size);

    if(memory == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return memory;
}

int p101_mblen(const struct p101_env *env, struct p101_error *err, const char *s, size_t n)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = mblen(s, n);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t p101_mbstowcs(const struct p101_env *env,
                   struct p101_error *err,
                   wchar_t * restrict pwcs,
                   const char * restrict s,
                   size_t n)
{
    size_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = mbstowcs(pwcs, s, n);

    if(ret_val == (size_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_mbtowc(const struct p101_env *env,
              struct p101_error *err,
              wchar_t * restrict pwc,
              const char * restrict s,
              size_t n)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = mbtowc(pwc, s, n);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void p101_qsort(const struct p101_env *env,
              void                      *base,
              size_t                     nel,
              size_t                     width,
              int (*compar)(const void *, const void *))
{
    P101_TRACE(env);
    errno = 0;
    qsort(base, nel, width, compar);
}

void *p101_realloc(const struct p101_env *env, struct p101_error *err, void *ptr, size_t size)
{
    void *memory;

    P101_TRACE(env);
    errno  = 0;
    memory = realloc(ptr, size);

    if(memory == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return memory;
}

double
p101_strtod(const struct p101_env *env, struct p101_error *err, const char * restrict nptr, char ** restrict endptr)
{
    double ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = strtod(nptr, endptr);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_strtof(const struct p101_env *env,
                struct p101_error           *err,
                const char * restrict nptr,
                char ** restrict endptr)
{
    float ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = strtof(nptr, endptr);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long p101_strtol(const struct p101_env *env,
               struct p101_error           *err,
               const char * restrict nptr,
               char ** restrict endptr,
               int base)
{
    long ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = strtol(nptr, endptr, base);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double
p101_strtold(const struct p101_env *env, struct p101_error *err, const char * restrict nptr, char ** restrict endptr)
{
    long double ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = strtold(nptr, endptr);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long long p101_strtoll(const struct p101_env *env,
                     struct p101_error           *err,
                     const char * restrict nptr,
                     char ** restrict endptr,
                     int base)
{
    long long ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = strtoll(nptr, endptr, base);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

unsigned long p101_strtoul(const struct p101_env *env,
                         struct p101_error           *err,
                         const char * restrict str,
                         char ** restrict endptr,
                         int base)
{
    unsigned long ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = strtoul(str, endptr, base);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

unsigned long long p101_strtoull(const struct p101_env *env,
                               struct p101_error           *err,
                               const char * restrict str,
                               char ** restrict endptr,
                               int base)
{
    unsigned long long ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = strtoull(str, endptr, base);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_system(const struct p101_env *env, struct p101_error *err, const char *command)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = system(command);  // NOLINT(cert-env33-c)

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t p101_wcstombs(const struct p101_env *env,
                   struct p101_error           *err,
                   char * restrict s,
                   const wchar_t * restrict pwcs,
                   size_t n)
{
    size_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcstombs(s, pwcs, n);

    if(ret_val == (size_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_wctomb(const struct p101_env *env, struct p101_error *err, char *s, wchar_t wchar)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wctomb(s, wchar);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
