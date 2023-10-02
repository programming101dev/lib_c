/*
 * Copyright 2022-2022 D'Arcy Smith.
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

#include "p101_c/p101_fenv.h"

int p101_feclearexcept(const struct p101_env *env, struct p101_error *err, int excepts)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = feclearexcept(excepts);

    // TODO - handle this properly
    if(ret_val != 0)
    {
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

int p101_fegetenv(const struct p101_env *env, struct p101_error *err, fenv_t *envp)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fegetenv(envp);

    // TODO - handle this properly
    if(ret_val != 0)
    {
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

int p101_fegetexceptflag(const struct p101_env *env, struct p101_error *err, fexcept_t *flagp, int excepts)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fegetexceptflag(flagp, excepts);

    // TODO - handle this properly
    if(ret_val != 0)
    {
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

int p101_fegetround(const struct p101_env *env, struct p101_error *err)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fegetround();

    // TODO - handle this properly
    if(ret_val != 0)
    {
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

int p101_feholdexcept(const struct p101_env *env, struct p101_error *err, fenv_t *envp)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = feholdexcept(envp);

    // TODO - handle this properly
    if(ret_val != 0)
    {
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

int p101_feraiseexcept(const struct p101_env *env, struct p101_error *err, int excepts)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = feraiseexcept(excepts);

    // TODO - handle this properly
    if(ret_val != 0)
    {
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

int p101_fesetenv(const struct p101_env *env, struct p101_error *err, const fenv_t *envp)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fesetenv(envp);

    // TODO - handle this properly
    if(ret_val != 0)
    {
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

int p101_fesetexceptflag(const struct p101_env *env, struct p101_error *err, const fexcept_t *flagp, int excepts)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fesetexceptflag(flagp, excepts);

    // TODO - handle this properly
    if(ret_val != 0)
    {
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

int p101_fesetround(const struct p101_env *env, struct p101_error *err, int round)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fesetround(round);

    // TODO - handle this properly
    if(ret_val != 0)
    {
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

int p101_fetestexcept(const struct p101_env *env, int excepts)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fetestexcept(excepts);

    return ret_val;
}

int p101_feupdateenv(const struct p101_env *env, struct p101_error *err, const fenv_t *envp)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = feupdateenv(envp);

    // TODO - handle this properly
    if(ret_val != 0)
    {
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}
