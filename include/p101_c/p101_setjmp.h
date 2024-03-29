#ifndef LIBP101_C_P101_SETJMP_H
#define LIBP101_C_P101_SETJMP_H

/*
 * Copyright 2022-2024 D'Arcy Smith.
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
#include <setjmp.h>

#ifdef __cplusplus
extern "C"
{
#endif

    _Noreturn void p101_longjmp(const struct p101_env *env, jmp_buf buf, int val);
    int            p101_setjmp(const struct p101_env *env, jmp_buf buf);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_C_P101_SETJMP_H
