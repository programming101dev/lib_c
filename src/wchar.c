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

#include "p101_c/p101_wchar.h"

wint_t p101_btowc(const struct p101_env *env, int c)
{
    wint_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = btowc(c);

    return ret_val;
}

wint_t p101_fgetwc(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    wint_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fgetwc(stream);

    if(ret_val == WEOF)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else if(ferror(stream))
        {
            // TODO - how to handle?
            P101_ERROR_RAISE_SYSTEM(err, "", 0);
        }
    }

    return ret_val;
}

wchar_t *p101_fgetws(const struct p101_env *env, struct p101_error *err, wchar_t *restrict ws, int n, FILE *restrict stream)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fgetws(ws, n, stream);

    if(ret_val == NULL)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else if(ferror(stream))
        {
            // TODO - how to handle?
            P101_ERROR_RAISE_SYSTEM(err, "", 0);
        }
    }

    return ret_val;
}

wint_t p101_fputwc(const struct p101_env *env, struct p101_error *err, wchar_t wc, FILE *stream)
{
    wint_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fputwc(wc, stream);

    if(ret_val == WEOF)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else if(ferror(stream))
        {
            // TODO - how to handle?
            P101_ERROR_RAISE_SYSTEM(err, "", 0);
        }
    }

    return ret_val;
}

int p101_fputws(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict ws, FILE *restrict stream)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fputws(ws, stream);

    if(ret_val == -1)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else if(ferror(stream))
        {
            // TODO - how to handle?
            P101_ERROR_RAISE_SYSTEM(err, "", 0);
        }
    }

    return ret_val;
}

int p101_fwide(const struct p101_env *env, struct p101_error *err, FILE *stream, int mode)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fwide(stream, mode);

    // TODO: this is with POSIX, what about just straight C?
    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

wint_t p101_getwc(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    wint_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = getwc(stream);

    if(ret_val == WEOF)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else if(ferror(stream))
        {
            // TODO - how to handle?
            P101_ERROR_RAISE_SYSTEM(err, "", 0);
        }
    }

    return ret_val;
}

wint_t p101_getwchar(const struct p101_env *env, struct p101_error *err)
{
    wint_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = getwchar();

    if(ret_val == WEOF)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else if(ferror(stdin))
        {
            // TODO - how to handle?
            P101_ERROR_RAISE_SYSTEM(err, "", 0);
        }
    }

    return ret_val;
}

size_t p101_mbrlen(const struct p101_env *env, struct p101_error *err, const char *restrict s, size_t n, mbstate_t *restrict ps)
{
    size_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = mbrlen(s, n, ps);

    if(ret_val == (size_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t p101_mbrtowc(const struct p101_env *env, struct p101_error *err, wchar_t *restrict pwc, const char *restrict s, size_t n, mbstate_t *restrict ps)
{
    size_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = mbrtowc(pwc, s, n, ps);

    if(ret_val == (size_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_mbsinit(const struct p101_env *env, const mbstate_t *ps)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = mbsinit(ps);

    return ret_val;
}

size_t p101_mbsrtowcs(const struct p101_env *env, struct p101_error *err, wchar_t *restrict dst, const char **restrict src, size_t len, mbstate_t *restrict ps)
{
    size_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = mbsrtowcs(dst, src, len, ps);

    if(ret_val == (size_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

wint_t p101_putwc(const struct p101_env *env, struct p101_error *err, wchar_t wc, FILE *stream)
{
    wint_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = putwc(wc, stream);

    if(ret_val == WEOF)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else if(ferror(stream))
        {
            // TODO - how to handle?
            P101_ERROR_RAISE_SYSTEM(err, "", 0);
        }
    }

    return ret_val;
}

wint_t p101_putwchar(const struct p101_env *env, struct p101_error *err, wchar_t wc)
{
    wint_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = putwchar(wc);

    if(ret_val == WEOF)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        else if(ferror(stdout))
        {
            // TODO - how to handle?
            P101_ERROR_RAISE_SYSTEM(err, "", 0);
        }
    }

    return ret_val;
}

wint_t p101_ungetwc(const struct p101_env *env, struct p101_error *err, wint_t wc, FILE *stream)
{
    wint_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = ungetwc(wc, stream);

    if(ret_val == WEOF)
    {
        if(errno != 0)
        {
            P101_ERROR_RAISE_ERRNO(err, errno);
        }
        // TODO - how to handle?
    }

    return ret_val;
}

int p101_vfwprintf(const struct p101_env *env, FILE *restrict stream, const wchar_t *restrict format, va_list arg)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = vfwprintf(stream, format, arg);

    return ret_val;
}

int p101_vfwscanf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const wchar_t *restrict format, va_list arg)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = vfwscanf(stream, format, arg);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_vswprintf(const struct p101_env *env, struct p101_error *err, wchar_t *restrict ws, size_t n, const wchar_t *restrict format, va_list arg)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = vswprintf(ws, n, format, arg);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_vswscanf(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict ws, const wchar_t *restrict format, va_list arg)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = vswscanf(ws, format, arg);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_vwprintf(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict format, va_list arg)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = vwprintf(format, arg);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_vwscanf(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict format, va_list arg)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = vwscanf(format, arg);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t p101_wcrtomb(const struct p101_env *env, struct p101_error *err, char *restrict s, wchar_t wc, mbstate_t *restrict ps)
{
    size_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcrtomb(s, wc, ps);

    if(ret_val == (size_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

wchar_t *p101_wcscat(const struct p101_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcscat(ws1, ws2);

    return ret_val;
}

wchar_t *p101_wcschr(const struct p101_env *env, const wchar_t *ws, wchar_t wc)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcschr(ws, wc);

    return ret_val;
}

int p101_wcscmp(const struct p101_env *env, const wchar_t *ws1, const wchar_t *ws2)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcscmp(ws1, ws2);

    return ret_val;
}

int p101_wcscoll(const struct p101_env *env, struct p101_error *err, const wchar_t *ws1, const wchar_t *ws2)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcscoll(ws1, ws2);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

wchar_t *p101_wcscpy(const struct p101_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcscpy(ws1, ws2);

    return ret_val;
}

size_t p101_wcscspn(const struct p101_env *env, const wchar_t *ws1, const wchar_t *ws2)
{
    size_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcscspn(ws1, ws2);

    return ret_val;
}

size_t p101_wcsftime(const struct p101_env *env, wchar_t *restrict wcs, size_t maxsize, const wchar_t *restrict format, const struct tm *restrict timeptr)
{
    size_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcsftime(wcs, maxsize, format, timeptr);

    return ret_val;
}

size_t p101_wcslen(const struct p101_env *env, const wchar_t *ws)
{
    size_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcslen(ws);

    return ret_val;
}

wchar_t *p101_wcsncat(const struct p101_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2, size_t n)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcsncat(ws1, ws2, n);

    return ret_val;
}

int p101_wcsncmp(const struct p101_env *env, const wchar_t *ws1, const wchar_t *ws2, size_t n)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcsncmp(ws1, ws2, n);

    return ret_val;
}

wchar_t *p101_wcsncpy(const struct p101_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2, size_t n)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcsncpy(ws1, ws2, n);

    return ret_val;
}

wchar_t *p101_wcspbrk(const struct p101_env *env, const wchar_t *ws1, const wchar_t *ws2)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcspbrk(ws1, ws2);

    return ret_val;
}

wchar_t *p101_wcsrchr(const struct p101_env *env, const wchar_t *ws, wchar_t wc)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcsrchr(ws, wc);

    return ret_val;
}

size_t p101_wcsrtombs(const struct p101_env *env, struct p101_error *err, char *restrict dst, const wchar_t **restrict src, size_t len, mbstate_t *restrict ps)
{
    size_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcsrtombs(dst, src, len, ps);

    if(ret_val == (size_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t p101_wcsspn(const struct p101_env *env, const wchar_t *ws1, const wchar_t *ws2)
{
    size_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcsspn(ws1, ws2);

    return ret_val;
}

wchar_t *p101_wcsstr(const struct p101_env *env, const wchar_t *restrict ws1, const wchar_t *restrict ws2)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcsstr(ws1, ws2);

    return ret_val;
}

double p101_wcstod(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr)
{
    double ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcstod(nptr, endptr);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_wcstof(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr)
{
    float ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcstof(nptr, endptr);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

wchar_t *p101_wcstok(const struct p101_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2, wchar_t **restrict ptr)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcstok(ws1, ws2, ptr);

    return ret_val;
}

long p101_wcstol(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base)
{
    long ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcstol(nptr, endptr, base);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_wcstold(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr)
{
    long double ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcstold(nptr, endptr);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long long p101_wcstoll(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base)
{
    long long ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcstoll(nptr, endptr, base);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

unsigned long p101_wcstoul(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base)
{
    unsigned long ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcstoul(nptr, endptr, base);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

unsigned long long p101_wcstoull(const struct p101_env *env, struct p101_error *err, const wchar_t *restrict nptr, wchar_t **restrict endptr, int base)
{
    unsigned long long ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcstoull(nptr, endptr, base);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t p101_wcsxfrm(const struct p101_env *env, struct p101_error *err, wchar_t *restrict ws1, const wchar_t *restrict ws2, size_t n)
{
    size_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wcsxfrm(ws1, ws2, n);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_wctob(const struct p101_env *env, wint_t c)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wctob(c);

    return ret_val;
}

wchar_t *p101_wmemchr(const struct p101_env *env, const wchar_t *ws, wchar_t wc, size_t n)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wmemchr(ws, wc, n);

    return ret_val;
}

int p101_wmemcmp(const struct p101_env *env, const wchar_t *ws1, const wchar_t *ws2, size_t n)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wmemcmp(ws1, ws2, n);

    return ret_val;
}

wchar_t *p101_wmemcpy(const struct p101_env *env, wchar_t *restrict ws1, const wchar_t *restrict ws2, size_t n)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wmemcpy(ws1, ws2, n);

    return ret_val;
}

wchar_t *p101_wmemmove(const struct p101_env *env, wchar_t *ws1, const wchar_t *ws2, size_t n)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wmemmove(ws1, ws2, n);

    return ret_val;
}

wchar_t *p101_wmemset(const struct p101_env *env, wchar_t *ws, wchar_t wc, size_t n)
{
    wchar_t *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = wmemset(ws, wc, n);

    return ret_val;
}
