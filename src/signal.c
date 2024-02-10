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

#include "p101_c/p101_signal.h"
#include <signal.h>

int p101_raise(const struct p101_env *env, struct p101_error *err, int sig)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = raise(sig);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void (*p101_signal(const struct p101_env *env, struct p101_error *err, int sig, void (*func)(int)))(int)
{
    void (*ret_val)(int);

    P101_TRACE(env);
    errno   = 0;
    ret_val = signal(sig, func);

    // NOLINTNEXTLINE(performance-no-int-to-ptr)
    if(ret_val == SIG_ERR)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
