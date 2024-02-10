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

#include "p101_c/p101_locale.h"
#include <locale.h>

struct lconv *p101_localeconv(const struct p101_env *env)
{
    struct lconv *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = localeconv();

    return ret_val;
}

char *p101_setlocale(const struct p101_env *env, struct p101_error *err, int category, const char *locale)
{
    char *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = setlocale(category, locale);

    // TODO - handle this properly
    if(ret_val == NULL)
    {
        P101_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}
