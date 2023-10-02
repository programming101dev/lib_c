#ifndef LIBP101_C_P101_STDLIB_H
#define LIBP101_C_P101_STDLIB_H


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


#include <p101_env/env.h>
#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * @param env
 * @param status
 */
_Noreturn void p101__Exit(const struct p101_env *env, int status);

/**
 *
 * @param env
 */
_Noreturn void p101_abort(const struct p101_env *env);

/**
 *
 * @param env
 * @param err
 * @param i
 * @return
 */
int p101_abs(const struct p101_env *env, struct p101_error *err, int i);

/**
 *
 * @param env
 * @param err
 * @param func
 * @return
 */
int p101_atexit(const struct p101_env *env, struct p101_error *err,
              void (*func)(void));

/**
 *
 * @param env
 * @param key
 * @param base
 * @param nel
 * @param width
 * @param compar
 * @return
 */
void *p101_bsearch(const struct p101_env *env, const void *key,
                 const void *base, size_t nel, size_t width,
                 int (*compar)(const void *, const void *));

/**
 *
 * @param env
 * @param err
 * @param nelem
 * @param elsize
 * @return
 */
void *p101_calloc(const struct p101_env *env, struct p101_error *err,
                size_t nelem, size_t elsize);

/**
 *
 * @param env
 * @param numer
 * @param denom
 * @return
 */
div_t p101_div(const struct p101_env *env, int numer, int denom);

/**
 *
 * @param env
 * @param status
 */
_Noreturn void p101_exit(const struct p101_env *env, int status);

/**
 *
 * @param env
 * @param ptr
 */
void p101_free(const struct p101_env *env, void *ptr);

/**
 *
 * @param env
 * @param name
 * @return
 */
char *p101_getenv(const struct p101_env *env, const char *name);

/**
 *
 * @param env
 * @param err
 * @param i
 * @return
 */
long p101_labs(const struct p101_env *env, struct p101_error *err, long i);

/**
 *
 * @param env
 * @param numer
 * @param denom
 * @return
 */
ldiv_t p101_ldiv(const struct p101_env *env, long numer, long denom);

/**
 *
 * @param env
 * @param err
 * @param i
 * @return
 */
long long p101_llabs(const struct p101_env *env, struct p101_error *err,
                   long long i);

/**
 *
 * @param env
 * @param numer
 * @param denom
 * @return
 */
lldiv_t p101_lldiv(const struct p101_env *env, long long numer,
                 long long denom);

/**
 *
 * @param env
 * @param err
 * @param size
 * @return
 */
void *p101_malloc(const struct p101_env *env, struct p101_error *err,
                size_t size);

/**
 *
 * @param env
 * @param err
 * @param s
 * @param n
 * @return
 */
int p101_mblen(const struct p101_env *env, struct p101_error *err,
             const char *s, size_t n);

/**
 *
 * @param env
 * @param err
 * @param pwcs
 * @param s
 * @param n
 * @return
 */
size_t p101_mbstowcs(const struct p101_env *env, struct p101_error *err,
                   wchar_t *restrict pwcs, const char *restrict s, size_t n);

/**
 *
 * @param env
 * @param err
 * @param pwc
 * @param s
 * @param n
 * @return
 */
int p101_mbtowc(const struct p101_env *env, struct p101_error *err,
              wchar_t *restrict pwc, const char *restrict s, size_t n);

/**
 *
 * @param env
 * @param base
 * @param nel
 * @param width
 * @param compar
 */
void p101_qsort(const struct p101_env *env, void *base, size_t nel,
              size_t width, int (*compar)(const void *, const void *));

/**
 *
 * @param env
 * @param err
 * @param ptr
 * @param size
 * @return
 */
void *p101_realloc(const struct p101_env *env, struct p101_error *err,
                 void *ptr, size_t size);

/**
 *
 * @param env
 * @param err
 * @param nptr
 * @param endptr
 * @return
 */
double p101_strtod(const struct p101_env *env, struct p101_error *err,
                 const char *restrict nptr, char **restrict endptr);

/**
 *
 * @param env
 * @param err
 * @param nptr
 * @param endptr
 * @return
 */
float p101_strtof(const struct p101_env *env, struct p101_error *err,
                const char *restrict nptr, char **restrict endptr);

/**
 *
 * @param env
 * @param err
 * @param nptr
 * @param endptr
 * @param base
 * @return
 */
long p101_strtol(const struct p101_env *env, struct p101_error *err,
               const char *restrict nptr, char **restrict endptr, int base);

/**
 *
 * @param env
 * @param err
 * @param nptr
 * @param endptr
 * @return
 */
long double p101_strtold(const struct p101_env *env, struct p101_error *err,
                       const char *restrict nptr, char **restrict endptr);

/**
 *
 * @param env
 * @param err
 * @param nptr
 * @param endptr
 * @param base
 * @return
 */
long long p101_strtoll(const struct p101_env *env, struct p101_error *err,
                     const char *restrict nptr, char **restrict endptr,
                     int base);

/**
 *
 * @param env
 * @param err
 * @param str
 * @param endptr
 * @param base
 * @return
 */
unsigned long p101_strtoul(const struct p101_env *env, struct p101_error *err,
                         const char *restrict str, char **restrict endptr,
                         int base);

/**
 *
 * @param env
 * @param err
 * @param str
 * @param endptr
 * @param base
 * @return
 */
unsigned long long p101_strtoull(const struct p101_env *env,
                               struct p101_error *err, const char *restrict str,
                               char **restrict endptr, int base);

/**
 *
 * @param env
 * @param err
 * @param command
 * @return
 */
int p101_system(const struct p101_env *env, struct p101_error *err,
              const char *command);

/**
 *
 * @param env
 * @param err
 * @param s
 * @param pwcs
 * @param n
 * @return
 */
size_t p101_wcstombs(const struct p101_env *env, struct p101_error *err,
                   char *restrict s, const wchar_t *restrict pwcs, size_t n);

/**
 *
 * @param env
 * @param err
 * @param s
 * @param wchar
 * @return
 */
int p101_wctomb(const struct p101_env *env, struct p101_error *err, char *s,
              wchar_t wchar);


#ifdef __cplusplus
}
#endif


// obsolete
// int p101_rand(const struct p101_env *env);
// void p101_srand(const struct p101_env *env, unsigned seed);

// better functions
// double p101_atof(const char *);
// int p101_atoi(const char *);
// long p101_atol(const char *);
// long long p101_atoll(const char *);


#endif // LIBP101_C_P101_STDLIB_H
