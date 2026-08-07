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

#include "p101_c/p101_time.h"
#include "p101_c_internal.h"

/*
 * clock_t is an int on FreeBSD and a long or unsigned long elsewhere, so
 * (clock_t)-1 — the sentinel these functions must return and compare against —
 * is a redundant cast on one platform and a required one on the others. No
 * single spelling satisfies every platform, so GCC's redundant-cast report is
 * disabled for this function alone. The guard is narrow: clang has no such
 * diagnostic, and GCC before 16 rejects the pragma outright because the
 * option was C++-only there.
 */
#if defined(__GNUC__) && !defined(__clang__) && __GNUC__ >= 16
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
clock_t p101_clock(const struct p101_env *env, struct p101_error *err)
{
    clock_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, (clock_t)-1);
    errno   = 0;
    ret_val = clock();

    if(ret_val == (clock_t)-1)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else
        {
            P101_ERROR_RAISE_ERRNO(err, ENOTSUP);
        }
    }

    P101_C_DONE(env);

    return ret_val;
}
#if defined(__GNUC__) && !defined(__clang__) && __GNUC__ >= 16
#pragma GCC diagnostic pop
#endif

double p101_difftime(const struct p101_env *env, time_t time1, time_t time0)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = difftime(time1, time0);

    P101_TRACE_EXIT(env);

    return ret_val;
}

time_t p101_mktime(const struct p101_env *env, struct p101_error *err, struct tm *tm)
{
    time_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, (time_t)-1);
    errno   = 0;
    ret_val = mktime(tm);

    if(ret_val == (time_t)-1 && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_C_DONE(env);

    return ret_val;
}

size_t p101_strftime(const struct p101_env *env, struct p101_error *err, char *restrict buf, size_t maxsize, const char *restrict format, const struct tm *restrict timeptr)
{
    size_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, 0);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
    ret_val = strftime(buf, maxsize, format, timeptr);
#pragma GCC diagnostic pop

    /*
     * A zero result is ambiguous: it can mean that the formatted result is
     * empty or that it did not fit.  The C and POSIX contracts do not define
     * errno as a discriminator, and FreeBSD may set it for the empty-format
     * case.  Preserve the native return contract; injected failures still use
     * err through P101_C_FAULT_RETURN above.
     */

    P101_C_DONE(env);

    return ret_val;
}

time_t p101_time(const struct p101_env *env, struct p101_error *err, time_t *tloc)
{
    time_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, (time_t)-1);
    errno   = 0;
    ret_val = time(tloc);

    if(ret_val == (time_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, (errno == 0) ? EOVERFLOW : errno);
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_timespec_get(const struct p101_env *env, struct p101_error *err, struct timespec *ts, int base)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, "timespec_get", ret_val, 0);
    errno   = 0;
    ret_val = timespec_get(ts, base);

    if(ret_val == 0)
    {
        P101_ERROR_RAISE_ERRNO(err, (errno == 0) ? EINVAL : errno);
    }

    P101_C_DONE(env);

    return ret_val;
}
