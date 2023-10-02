#ifndef LIBP101_C_P101_WCTYPE_H
#define LIBP101_C_P101_WCTYPE_H


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


#include <p101_env/env.h>
#include <wctype.h>


#ifdef __cplusplus
extern "C" {
#endif


int p101_iswalnum(const struct p101_env *env, wint_t wc);
int p101_iswalpha(const struct p101_env *env, wint_t wc);
int p101_iswblank(const struct p101_env *env, wint_t wc);
int p101_iswcntrl(const struct p101_env *env, wint_t wc);
int p101_iswctype(const struct p101_env *env, wint_t wc, wctype_t charclass);
int p101_iswdigit(const struct p101_env *env, wint_t wc);
int p101_iswgraph(const struct p101_env *env, wint_t wc);
int p101_iswlower(const struct p101_env *env, wint_t wc);
int p101_iswprint(const struct p101_env *env, wint_t wc);
int p101_iswpunct(const struct p101_env *env, wint_t wc);
int p101_iswspace(const struct p101_env *env, wint_t wc);
int p101_iswupper(const struct p101_env *env, wint_t wc);
int p101_iswxdigit(const struct p101_env *env, wint_t wc);
wint_t p101_towctrans(const struct p101_env *env, struct p101_error *err, wint_t wc, wctrans_t desc);
wint_t p101_towlower(const struct p101_env *env, wint_t wc);
wint_t p101_towupper(const struct p101_env *env, wint_t wc);
wctrans_t p101_wctrans(const struct p101_env *env, struct p101_error *err, const char *charclass);
wctype_t p101_wctype(const struct p101_env *env, struct p101_error *err, const char *property);


#ifdef __cplusplus
}
#endif


#endif // LIBP101_C_P101_WCTYPE_H
