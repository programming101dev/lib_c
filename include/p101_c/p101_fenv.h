#ifndef LIBP101_C_P101_FENV_H
#define LIBP101_C_P101_FENV_H

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

#include <fenv.h>
#include <p101_env/env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int p101_feclearexcept(const struct p101_env *env, struct p101_error *err, int excepts);
    int p101_fegetenv(const struct p101_env *env, struct p101_error *err, fenv_t *envp);
    int p101_fegetexceptflag(const struct p101_env *env, struct p101_error *err, fexcept_t *flagp, int excepts);
    int p101_fegetround(const struct p101_env *env, struct p101_error *err);
    int p101_feholdexcept(const struct p101_env *env, struct p101_error *err, fenv_t *envp);
    int p101_feraiseexcept(const struct p101_env *env, struct p101_error *err, int excepts);
    int p101_fesetenv(const struct p101_env *env, struct p101_error *err, const fenv_t *envp);
    int p101_fesetexceptflag(const struct p101_env *env, struct p101_error *err, const fexcept_t *flagp, int excepts);
    int p101_fesetround(const struct p101_env *env, struct p101_error *err, int round);
    int p101_fetestexcept(const struct p101_env *env, int excepts);
    int p101_feupdateenv(const struct p101_env *env, struct p101_error *err, const fenv_t *envp);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_C_P101_FENV_H
