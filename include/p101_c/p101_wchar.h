#ifndef LIBP101_C_P101_WCHAR_H
#define LIBP101_C_P101_WCHAR_H


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
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>


#ifdef __cplusplus
extern "C" {
#endif


wint_t p101_btowc(const struct p101_env *env, int c);
wint_t p101_fgetwc(const struct p101_env *env, struct p101_error *err, FILE *stream);
wchar_t *p101_fgetws(const struct p101_env *env, struct p101_error *err, wchar_t *restrict ws, int n, FILE *restrict stream);
wint_t p101_fputwc(const struct p101_env *env, struct p101_error *err, wchar_t wc, FILE *stream);
int p101_fputws(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict ws, FILE *restrict stream);
int p101_fwide(const struct p101_env *env, struct p101_error *err, FILE *stream, int mode);
wint_t p101_getwc(const struct p101_env *env, struct p101_error *err, FILE *stream);
wint_t p101_getwchar(const struct p101_env *env, struct p101_error *err);
size_t p101_mbrlen(const struct p101_env *env, struct p101_error *err, const char *restrict s, size_t n, mbstate_t *restrict ps);
size_t p101_mbrtowc(const struct p101_env *env, struct p101_error *err, wchar_t *restrict pwc, const char *restrict s, size_t n, mbstate_t *restrict ps);
int p101_mbsinit(const struct p101_env *env, const mbstate_t *ps);
size_t p101_mbsrtowcs(const struct p101_env *env, struct p101_error *err, wchar_t *restrict dst, const char **restrict src, size_t len, mbstate_t *restrict ps);
wint_t p101_putwc(const struct p101_env *env, struct p101_error *err, wchar_t wc, FILE *stream);
wint_t p101_putwchar(const struct p101_env *env, struct p101_error *err, wchar_t wc);
wint_t p101_ungetwc(const struct p101_env *env, struct p101_error *err, wint_t wc, FILE *stream);
int p101_vfwprintf(const struct p101_env *env, FILE *restrict stream, const wchar_t *restrict format, va_list arg);
int p101_vfwscanf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const wchar_t *restrict format, va_list arg);
int p101_vswprintf(const struct p101_env *env, struct p101_error *err, wchar_t *restrict ws, size_t n, const wchar_t *restrict format, va_list arg);
int p101_vswscanf(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict ws, const wchar_t *restrict format, va_list arg);
int p101_vwprintf(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict format, va_list arg);
int p101_vwscanf(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict format, va_list arg);
size_t p101_wcrtomb(const struct p101_env *env, struct p101_error *err, char *restrict s, wchar_t wc, mbstate_t *restrict ps);
wchar_t *p101_wcscat(const struct p101_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2);
wchar_t *p101_wcschr(const struct p101_env *env, const wchar_t *ws, wchar_t wc);
int p101_wcscmp(const struct p101_env *env, const wchar_t *ws1, const wchar_t *ws2);
int p101_wcscoll(const struct p101_env *env, struct p101_error *err, const wchar_t *ws1, const wchar_t *ws2);
wchar_t *p101_wcscpy(const struct p101_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2);
size_t p101_wcscspn(const struct p101_env *env, const wchar_t *ws1, const wchar_t *ws2);
size_t p101_wcsftime(const struct p101_env *env, wchar_t *restrict wcs, size_t maxsize, const wchar_t *restrict format, const struct tm *restrict timeptr);
size_t p101_wcslen(const struct p101_env *env, const wchar_t *ws);
wchar_t *p101_wcsncat(const struct p101_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2, size_t n);
int p101_wcsncmp(const struct p101_env *env, const wchar_t *ws1, const wchar_t *ws2, size_t n);
wchar_t *p101_wcsncpy(const struct p101_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2, size_t n);
wchar_t *p101_wcspbrk(const struct p101_env *env, const wchar_t *ws1, const wchar_t *ws2);
wchar_t *p101_wcsrchr(const struct p101_env *env, const wchar_t *ws, wchar_t wc);
size_t p101_wcsrtombs(const struct p101_env *env, struct p101_error *err, char *restrict dst, const wchar_t **restrict src, size_t len, mbstate_t *restrict ps);
size_t p101_wcsspn(const struct p101_env *env, const wchar_t *ws1, const wchar_t *ws2);
wchar_t *p101_wcsstr(const struct p101_env *env, const wchar_t *restrict ws1, const wchar_t *restrict ws2);
double p101_wcstod(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr);
float p101_wcstof(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr);
wchar_t *p101_wcstok(const struct p101_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2, wchar_t **restrict ptr);
long p101_wcstol(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base);
long double p101_wcstold(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr);
long long p101_wcstoll(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base);
unsigned long p101_wcstoul(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base);
unsigned long long p101_wcstoull(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base);
size_t p101_wcsxfrm(const struct p101_env *env, struct p101_error *err, wchar_t *restrict ws1, const wchar_t *restrict ws2, size_t n);
int p101_wctob(const struct p101_env *env, wint_t c);
wchar_t *p101_wmemchr(const struct p101_env *env, const wchar_t *ws, wchar_t wc, size_t n);
int p101_wmemcmp(const struct p101_env *env, const wchar_t *ws1, const wchar_t *ws2, size_t n);
wchar_t *p101_wmemcpy(const struct p101_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2, size_t n);
wchar_t *p101_wmemmove(const struct p101_env *env, wchar_t *ws1, const wchar_t *ws2, size_t n);
wchar_t *p101_wmemset(const struct p101_env *env, wchar_t *ws, wchar_t wc, size_t n);


#ifdef __cplusplus
}
#endif


#endif // LIBP101_C_P101_WCHAR_H
