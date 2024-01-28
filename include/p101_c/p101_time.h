#ifndef LIBP101_C_P101_TIME_H
#define LIBP101_C_P101_TIME_H

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
#include <time.h>

#ifdef __cplusplus
extern "C"
{
#endif

    clock_t p101_clock(const struct p101_env *env, struct p101_error *err);
    double  p101_difftime(const struct p101_env *env, time_t time1, time_t time0);
    time_t  p101_mktime(const struct p101_env *env, struct p101_error *err, struct tm *tm);
    size_t  p101_strftime(const struct p101_env *env, struct p101_error *err, char *restrict buf, size_t maxsize, const char *restrict format, const struct tm *restrict timeptr);
    time_t  p101_time(const struct p101_env *env, struct p101_error *err, time_t *tloc);

#ifdef __cplusplus
}
#endif

// unsafe
// struct tm *p101_gmtime(const struct p101_env *env, struct p101_error *err, const time_t *clock);
// struct tm *p101_localtime(const struct p101_env *env, struct p101_error *err, const time_t *clock);

#endif    // LIBP101_C_P101_TIME_H
