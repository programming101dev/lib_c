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

#include "p101_c/p101_wctype.h"
#include "p101_c_internal.h"

int p101_iswalnum(const struct p101_env *env, wint_t wc)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswalnum(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iswalpha(const struct p101_env *env, wint_t wc)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswalpha(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iswblank(const struct p101_env *env, wint_t wc)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswblank(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iswcntrl(const struct p101_env *env, wint_t wc)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswcntrl(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iswctype(const struct p101_env *env, wint_t wc, wctype_t charclass)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswctype(wc, charclass);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iswdigit(const struct p101_env *env, wint_t wc)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswdigit(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iswgraph(const struct p101_env *env, wint_t wc)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswgraph(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iswlower(const struct p101_env *env, wint_t wc)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswlower(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iswprint(const struct p101_env *env, wint_t wc)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswprint(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iswpunct(const struct p101_env *env, wint_t wc)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswpunct(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iswspace(const struct p101_env *env, wint_t wc)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswspace(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iswupper(const struct p101_env *env, wint_t wc)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswupper(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_iswxdigit(const struct p101_env *env, wint_t wc)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = iswxdigit(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

wint_t p101_towctrans(const struct p101_env *env, struct p101_error *err, wint_t wc, wctrans_t desc)
{
    wint_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, WEOF);
    errno   = 0;
    ret_val = towctrans(wc, desc);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_C_DONE(env);

    return ret_val;
}

wint_t p101_towlower(const struct p101_env *env, wint_t wc)
{
    wint_t ret_val;

    P101_TRACE(env);
    ret_val = towlower(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

wint_t p101_towupper(const struct p101_env *env, wint_t wc)
{
    wint_t ret_val;

    P101_TRACE(env);
    ret_val = towupper(wc);

    P101_TRACE_EXIT(env);

    return ret_val;
}

wctrans_t p101_wctrans(const struct p101_env *env, struct p101_error *err, const char *charclass)
{
    wctrans_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, 0);
    errno   = 0;
    ret_val = wctrans(charclass);

    if(ret_val == 0)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else
        {
            P101_ERROR_RAISE_ERRNO(err, EINVAL);
        }
    }

    P101_C_DONE(env);

    return ret_val;
}

wctype_t p101_wctype(const struct p101_env *env, struct p101_error *err, const char *property)
{
    wctype_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, 0);
    errno   = 0;
    ret_val = wctype(property);

    if(ret_val == 0)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else
        {
            P101_ERROR_RAISE_ERRNO(err, EINVAL);
        }
    }

    P101_C_DONE(env);

    return ret_val;
}
