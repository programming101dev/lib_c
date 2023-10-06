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

#include "p101_c/p101_time.h"

clock_t p101_clock(const struct p101_env *env, struct p101_error *err)
{
    clock_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = clock();

    if(ret_val == (clock_t)-1)
    {
        // TODO: what is a sensible message/code?
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

double p101_difftime(const struct p101_env *env, time_t time1, time_t time0)
{
    double ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = difftime(time1, time0);

    return ret_val;
}

/*
struct tm *p101_gmtime(const struct p101_env *env, struct p101_error *err, const time_t *clock)
{
    struct tm *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = gmtime(clock);

    if(ret_val == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
*/

/*
struct tm *p101_localtime(const struct p101_env *env, struct p101_error *err, const time_t *clock)
{
    struct tm *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = localtime(clock);

    if(ret_val == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
*/

time_t p101_mktime(const struct p101_env *env, struct p101_error *err, struct tm *tm)
{
    time_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = mktime(tm);

    if(ret_val == (time_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t p101_strftime(const struct p101_env *env, struct p101_error *err, char *restrict buf, size_t maxsize, const char *restrict format, const struct tm *restrict timeptr)
{
    size_t ret_val;

    P101_TRACE(env);
    errno = 0;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
    ret_val = strftime(buf, maxsize, format, timeptr);
#pragma GCC diagnostic pop

    if(ret_val == 0)
    {
        // TODO: what is a sensible message/code?
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

time_t p101_time(const struct p101_env *env, struct p101_error *err, time_t *tloc)
{
    time_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = time(tloc);

    if(ret_val == (time_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
