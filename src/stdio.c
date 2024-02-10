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

#include "p101_c/p101_stdio.h"

void p101_clearerr(const struct p101_env *env, FILE *stream)
{
    P101_TRACE(env);
    errno = 0;
    clearerr(stream);
}

int p101_fclose(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fclose(stream);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_feof(const struct p101_env *env, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = feof(stream);

    return ret_val;
}

int p101_ferror(const struct p101_env *env, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = ferror(stream);

    return ret_val;
}

int p101_fflush(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fflush(stream);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_fgetc(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    int     ret_val;
    errno_t actual_error;

    P101_TRACE(env);
    errno        = 0;
    ret_val      = fgetc(stream);
    actual_error = errno;

    if(p101_ferror(env, stream))
    {
        P101_ERROR_RAISE_ERRNO(err, actual_error);
    }

    return ret_val;
}

int p101_fgetpos(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, fpos_t *restrict pos)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fgetpos(stream, pos);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *p101_fgets(const struct p101_env *env, struct p101_error *err, char *restrict s, int n, FILE *restrict stream)
{
    char *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fgets(s, n, stream);

    if(ret_val == NULL)
    {
        errno_t temp_errno;

        temp_errno = errno;

        if(p101_ferror(env, stream))
        {
            P101_ERROR_RAISE_ERRNO(err, temp_errno);
        }
    }

    return ret_val;
}

FILE *p101_fopen(const struct p101_env *env, struct p101_error *err, const char *restrict pathname, const char *restrict mode)
{
    FILE *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fopen(pathname, mode);

    if(ret_val == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_fputc(const struct p101_env *env, struct p101_error *err, int c, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fputc(c, stream);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_fputs(const struct p101_env *env, struct p101_error *err, const char *restrict s, FILE *restrict stream)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fputs(s, stream);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t p101_fread(const struct p101_env *env, struct p101_error *err, void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
    size_t  ret_val;
    errno_t actual_error;

    P101_TRACE(env);
    errno        = 0;
    ret_val      = fread(ptr, size, nitems, stream);
    actual_error = errno;

    if(p101_ferror(env, stream))
    {
        P101_ERROR_RAISE_ERRNO(err, actual_error);
    }

    return ret_val;
}

FILE *p101_freopen(const struct p101_env *env, struct p101_error *err, const char *restrict pathname, const char *restrict mode, FILE *restrict stream)
{
    FILE *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = freopen(pathname, mode, stream);

    if(ret_val == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_fseek(const struct p101_env *env, struct p101_error *err, FILE *stream, long offset, int whence)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fseek(stream, offset, whence);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_fsetpos(const struct p101_env *env, struct p101_error *err, FILE *stream, const fpos_t *pos)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = fsetpos(stream, pos);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long p101_ftell(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    long ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = ftell(stream);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t p101_fwrite(const struct p101_env *env, struct p101_error *err, const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
    size_t  ret_val;
    errno_t actual_error;

    P101_TRACE(env);
    errno        = 0;
    ret_val      = fwrite(ptr, size, nitems, stream);
    actual_error = errno;

    if(p101_ferror(env, stream))
    {
        P101_ERROR_RAISE_ERRNO(err, actual_error);
    }

    return ret_val;
}

int p101_getc(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    int     ret_val;
    errno_t actual_error;

    P101_TRACE(env);
    errno        = 0;
    ret_val      = getc(stream);
    actual_error = errno;

    if(p101_ferror(env, stream))
    {
        P101_ERROR_RAISE_ERRNO(err, actual_error);
    }

    return ret_val;
}

int p101_getchar(const struct p101_env *env, struct p101_error *err)
{
    int     ret_val;
    errno_t actual_error;

    P101_TRACE(env);
    errno        = 0;
    ret_val      = getchar();
    actual_error = errno;

    if(p101_ferror(env, stdin))
    {
        P101_ERROR_RAISE_ERRNO(err, actual_error);
    }

    return ret_val;
}

void p101_perror(const struct p101_env *env, const char *s)
{
    P101_TRACE(env);
    errno = 0;
    perror(s);
}

int p101_putc(const struct p101_env *env, struct p101_error *err, int c, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = putc(c, stream);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_putchar(const struct p101_env *env, struct p101_error *err, int c)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = putchar(c);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_puts(const struct p101_env *env, struct p101_error *err, const char *s)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = puts(s);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_remove(const struct p101_env *env, struct p101_error *err, const char *path)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = remove(path);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_rename(const struct p101_env *env, struct p101_error *err, const char *old_name, const char *new_name)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = rename(old_name, new_name);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_setvbuf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, char *restrict buf, int type, size_t size)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = setvbuf(stream, buf, type, size);

    if(ret_val == 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

FILE *p101_tmpfile(const struct p101_env *env, struct p101_error *err)
{
    FILE *ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = tmpfile();

    if(ret_val == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_ungetc(const struct p101_env *env, int c, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = ungetc(c, stream);

    return ret_val;
}

int p101_vfprintf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const char *restrict format, va_list ap)
{
    int ret_val;

    P101_TRACE(env);
    errno = 0;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic ignored "-Wsuggest-attribute=format"
#endif
    ret_val = vfprintf(stream, format, ap);
#pragma GCC diagnostic pop

    // TODO there is the error indicator of the stream too maybe?
    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_vfscanf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const char *restrict format, va_list ap)
{
    int ret_val;

    P101_TRACE(env);
    errno = 0;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic ignored "-Wsuggest-attribute=format"
#endif
    ret_val = vfscanf(stream, format, ap);
#pragma GCC diagnostic pop

    // TODO there is the error indicator of the stream too maybe?
    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_vprintf(const struct p101_env *env, struct p101_error *err, const char *restrict format, va_list ap)
{
    int ret_val;

    P101_TRACE(env);
    errno = 0;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic ignored "-Wsuggest-attribute=format"
#endif
    ret_val = vprintf(format, ap);
#pragma GCC diagnostic pop

    // TODO there is the error indicator of the stream too maybe?
    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_vscanf(const struct p101_env *env, struct p101_error *err, const char *restrict format, va_list ap)
{
    int ret_val;

    P101_TRACE(env);
    errno = 0;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic ignored "-Wsuggest-attribute=format"
#endif
    ret_val = vscanf(format, ap);
#pragma GCC diagnostic pop

    // TODO there is the error indicator of the stream too maybe?
    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_vsnprintf(const struct p101_env *env, struct p101_error *err, char *restrict s, size_t n, const char *restrict format, va_list ap)
{
    int ret_val;

    P101_TRACE(env);
    errno = 0;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic ignored "-Wsuggest-attribute=format"
#endif
    ret_val = vsnprintf(s, n, format, ap);
#pragma GCC diagnostic pop

    // TODO there is the error indicator of the stream too maybe?
    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_vsscanf(const struct p101_env *env, struct p101_error *err, const char *restrict s, const char *restrict format, va_list ap)
{
    int ret_val;

    P101_TRACE(env);
    errno = 0;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic ignored "-Wsuggest-attribute=format"
#endif
    ret_val = vsscanf(s, format, ap);
#pragma GCC diagnostic pop

    // TODO there is the error indicator of the stream too maybe?
    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
