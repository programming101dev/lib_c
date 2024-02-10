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

#include "p101_c/p101_inttypes.h"

intmax_t p101_imaxabs(const struct p101_env *env, intmax_t j)
{
    intmax_t value;

    P101_TRACE(env);
    errno = 0;
    value = imaxabs(j);

    return value;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"

imaxdiv_t p101_imaxdiv(const struct p101_env *env, intmax_t numer, intmax_t denom)
{
    imaxdiv_t value;

    P101_TRACE(env);
    errno = 0;
    value = imaxdiv(numer, denom);

    return value;
}

#pragma GCC diagnostic pop

intmax_t p101_strtoimax(const struct p101_env *env, struct p101_error *err, const char *restrict nptr, char **restrict endptr, int base)
{
    intmax_t value;
    char    *temp_endptr;

    P101_TRACE(env);
    errno = 0;
    value = strtoimax(nptr, &temp_endptr, base);

    if(value == 0 && errno != 0)
    {
        // Error condition: no digits found
        P101_ERROR_RAISE_ERRNO(err, errno);
    }
    else if(value == INTMAX_MIN && errno == ERANGE)
    {
        // Error condition: underflow
        P101_ERROR_RAISE_ERRNO(err, errno);
    }
    else if(value == INTMAX_MAX && errno == ERANGE)
    {
        // Error condition: overflow
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    if(endptr != NULL)
    {
        *endptr = temp_endptr;
    }

    return value;
}

uintmax_t p101_strtoumax(const struct p101_env *env, struct p101_error *err, const char *restrict nptr, char **restrict endptr, int base)
{
    uintmax_t value;

    P101_TRACE(env);
    errno = 0;
    value = strtoumax(nptr, endptr, base);

    if(value == 0 || value == UINTMAX_MAX)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
    }

    return value;
}

intmax_t p101_wcstoimax(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base)
{
    intmax_t value;

    P101_TRACE(env);
    errno = 0;
    value = wcstoimax(nptr, endptr, base);

    if(value == 0 || value == INTMAX_MIN || value == INTMAX_MAX)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
    }

    return value;
}

uintmax_t p101_wcstoumax(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base)
{
    uintmax_t value;

    P101_TRACE(env);
    errno = 0;
    value = wcstoumax(nptr, endptr, base);

    if(value == 0 || value == UINTMAX_MAX)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
    }

    return value;
}
