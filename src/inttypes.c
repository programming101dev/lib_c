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
#include "p101_c_internal.h"

intmax_t p101_imaxabs(const struct p101_env *env, struct p101_error *err, intmax_t j)
{
    intmax_t value;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, value, 0);
    errno = 0;
    if(j == INTMAX_MIN)
    {
        P101_ERROR_RAISE_ERRNO(err, ERANGE);
        value = j;
    }
    else
    {
        value = imaxabs(j);
    }

    P101_C_DONE(env);

    return value;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"

imaxdiv_t p101_imaxdiv(const struct p101_env *env, struct p101_error *err, intmax_t numer, intmax_t denom)
{
    imaxdiv_t p101_single_result_;
    imaxdiv_t value;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, "imaxdiv", value, ((imaxdiv_t){0, 0}));

    if(denom == 0)
    {
        P101_ERROR_RAISE_ERRNO(err, EDOM);
        value.quot = 0;
        value.rem  = 0;
        P101_C_DONE(env);

        p101_single_result_ = value;
        goto p101_single_exit_;
    }
    if(numer == INTMAX_MIN && denom == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, ERANGE);
        value.quot = 0;
        value.rem  = 0;
        P101_TRACE_EXIT(env);

        p101_single_result_ = value;
        goto p101_single_exit_;
    }

    errno = 0;
    value = imaxdiv(numer, denom);

    P101_TRACE_EXIT(env);

    p101_single_result_ = value;
    goto p101_single_exit_;

p101_single_exit_:
    return p101_single_result_;
}

#pragma GCC diagnostic pop

intmax_t p101_strtoimax(const struct p101_env *env, struct p101_error *err, const char *restrict nptr, char **restrict endptr, int base)
{
    intmax_t value;
    char    *temp_endptr;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, value, 0);
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

    P101_C_DONE(env);

    return value;
}

uintmax_t p101_strtoumax(const struct p101_env *env, struct p101_error *err, const char *restrict nptr, char **restrict endptr, int base)
{
    uintmax_t value;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, value, 0);
    errno = 0;
    value = strtoumax(nptr, endptr, base);

    if(value == 0 || value == UINTMAX_MAX)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
    }

    P101_C_DONE(env);

    return value;
}

intmax_t p101_wcstoimax(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base)
{
    intmax_t value;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, value, 0);
    errno = 0;
    value = wcstoimax(nptr, endptr, base);

    if(value == 0 || value == INTMAX_MIN || value == INTMAX_MAX)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
    }

    P101_C_DONE(env);

    return value;
}

uintmax_t p101_wcstoumax(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base)
{
    uintmax_t value;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, value, 0);
    errno = 0;
    value = wcstoumax(nptr, endptr, base);

    if(value == 0 || value == UINTMAX_MAX)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
    }

    P101_C_DONE(env);

    return value;
}
