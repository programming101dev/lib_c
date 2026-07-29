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

#include "p101_c/p101_ctype.h"
#include <ctype.h>

int p101_isalnum(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = isalnum(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_isalpha(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = isalpha(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_isblank(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = isblank(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iscntrl(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iscntrl(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_isdigit(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = isdigit(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_isgraph(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = isgraph(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_islower(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = islower(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_isprint(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = isprint(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_ispunct(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = ispunct(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_isspace(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = isspace(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_isupper(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = isupper(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_isxdigit(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = isxdigit(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_tolower(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = tolower(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_toupper(const struct p101_env *env, int c)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = toupper(c);

    P101_TRACE_EXIT(env);

    return ret_val;
}
