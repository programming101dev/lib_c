#ifndef LIBP101_C_P101_INTTYPES_H
#define LIBP101_C_P101_INTTYPES_H

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

#include <inttypes.h>
#include <p101_env/env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     *
     * @param env
     * @param j
     * @return
     */
    intmax_t p101_imaxabs(const struct p101_env *env, intmax_t j);

    /**
     *
     * @param env
     * @param numer
     * @param denom
     * @return
     */
    imaxdiv_t p101_imaxdiv(const struct p101_env *env, intmax_t numer, intmax_t denom);

    /**
     *
     * @param env
     * @param err
     * @param nptr
     * @param endptr
     * @param base
     * @return
     */
    intmax_t p101_strtoimax(const struct p101_env *env, struct p101_error *err, const char *restrict nptr, char **restrict endptr, int base);

    /**
     *
     * @param env
     * @param err
     * @param nptr
     * @param endptr
     * @param base
     * @return
     */
    uintmax_t p101_strtoumax(const struct p101_env *env, struct p101_error *err, const char *restrict nptr, char **restrict endptr, int base);

    /**
     *
     * @param env
     * @param err
     * @param nptr
     * @param endptr
     * @param base
     * @return
     */
    intmax_t p101_wcstoimax(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base);

    /**
     *
     * @param env
     * @param err
     * @param nptr
     * @param endptr
     * @param base
     * @return
     */
    uintmax_t p101_wcstoumax(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_C_P101_INTTYPES_H
