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
#include "p101_c_internal.h"

static int stdio_error_code(int err_code);
static int vfprintf_checked(struct p101_error *err, FILE *restrict stream, const char *restrict format, va_list ap) P101_ATTR_PRINTF(3, 0);
static int vfscanf_checked(struct p101_error *err, FILE *restrict stream, const char *restrict format, va_list ap) P101_ATTR_SCANF(3, 0);
static int vprintf_checked(struct p101_error *err, const char *restrict format, va_list ap) P101_ATTR_PRINTF(2, 0);
static int vscanf_checked(struct p101_error *err, const char *restrict format, va_list ap) P101_ATTR_SCANF(2, 0);
static int vsnprintf_checked(struct p101_error *err, char *restrict s, size_t n, const char *restrict format, va_list ap) P101_ATTR_PRINTF(4, 0);
static int vsscanf_checked(struct p101_error *err, const char *restrict s, const char *restrict format, va_list ap) P101_ATTR_SCANF(3, 0);

static int stdio_error_code(int err_code)
{
    if(err_code == 0)
    {
        err_code = EIO;
    }

    return err_code;
}

static int vfprintf_checked(struct p101_error *err, FILE *restrict stream, const char *restrict format, va_list ap)
{
    int ret_val;

    errno = 0;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
    ret_val = vfprintf(stream, format, ap);
#pragma GCC diagnostic pop
    if(ret_val < 0)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    return ret_val;
}

static int vfscanf_checked(struct p101_error *err, FILE *restrict stream, const char *restrict format, va_list ap)
{
    int ret_val;
    int actual_error;

    errno = 0;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
    ret_val      = vfscanf(stream, format, ap);
    actual_error = errno;
#pragma GCC diagnostic pop
    if(ret_val == EOF && ferror(stream))
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(actual_error));
    }

    return ret_val;
}

static int vprintf_checked(struct p101_error *err, const char *restrict format, va_list ap)
{
    return vfprintf_checked(err, stdout, format, ap);
}

static int vscanf_checked(struct p101_error *err, const char *restrict format, va_list ap)
{
    return vfscanf_checked(err, stdin, format, ap);
}

static int vsnprintf_checked(struct p101_error *err, char *restrict s, size_t n, const char *restrict format, va_list ap)
{
    int ret_val;

    errno = 0;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
    ret_val = vsnprintf(s, n, format, ap);
#pragma GCC diagnostic pop
    if(ret_val < 0)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    return ret_val;
}

static int vsscanf_checked(struct p101_error *err, const char *restrict s, const char *restrict format, va_list ap)
{
    int ret_val;

    errno = 0;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
    ret_val = vsscanf(s, format, ap);
#pragma GCC diagnostic pop
    if(ret_val == EOF && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void p101_clearerr(const struct p101_env *env, FILE *stream)
{
    P101_TRACE(env);
    clearerr(stream);
    P101_TRACE_EXIT(env);
}

int p101_fclose(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    int fd;
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    fd    = fileno(stream);
    errno = 0;
    P101_TRACK_POINTER_RESOURCE_RELEASE(env, "stdio-stream", stream, NULL);
    ret_val = fclose(stream);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }
    else if(fd >= 0)
    {
        P101_TRACK_CLOSE(env, fd);
    }
    P101_C_DONE(env);

    return ret_val;
}

int p101_feof(const struct p101_env *env, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = feof(stream);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_ferror(const struct p101_env *env, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = ferror(stream);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_fflush(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = fflush(stream);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_fgetc(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    int     ret_val;
    errno_t actual_error;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno        = 0;
    ret_val      = fgetc(stream);
    actual_error = errno;

    if(ferror(stream))
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(actual_error));
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_fgetpos(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, fpos_t *restrict pos)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = fgetpos(stream, pos);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

char *p101_fgets(const struct p101_env *env, struct p101_error *err, char *restrict s, int n, FILE *restrict stream)
{
    char *ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, NULL);
    errno   = 0;
    ret_val = fgets(s, n, stream);

    if(ret_val == NULL)
    {
        errno_t temp_errno;

        temp_errno = errno;

        if(ferror(stream))
        {
            P101_ERROR_RAISE_ERRNO(err, stdio_error_code(temp_errno));
        }
    }

    P101_C_DONE(env);

    return ret_val;
}

FILE *p101_fopen(const struct p101_env *env, struct p101_error *err, const char *restrict pathname, const char *restrict mode)
{
    FILE *ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, NULL);
    errno   = 0;
    ret_val = fopen(pathname, mode);

    if(ret_val == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }
    else
    {
        int fd;

        P101_TRACK_POINTER_RESOURCE_ACQUIRE(env, "stdio-stream", ret_val, 0U, pathname);
        fd = fileno(ret_val);
        if(fd >= 0)
        {
            P101_TRACK_OPEN(env, fd);
        }
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_fputc(const struct p101_env *env, struct p101_error *err, int c, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = fputc(c, stream);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_fputs(const struct p101_env *env, struct p101_error *err, const char *restrict s, FILE *restrict stream)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = fputs(s, stream);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

size_t p101_fread(const struct p101_env *env, struct p101_error *err, void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
    size_t  ret_val;
    errno_t actual_error;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, 0);
    errno        = 0;
    ret_val      = fread(ptr, size, nitems, stream);
    actual_error = errno;

    if(ferror(stream))
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(actual_error));
    }

    P101_C_DONE(env);

    return ret_val;
}

FILE *p101_freopen(const struct p101_env *env, struct p101_error *err, const char *restrict pathname, const char *restrict mode, FILE *restrict stream)
{
    int   old_fd;
    FILE *ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, NULL);
    old_fd = fileno(stream);
    errno  = 0;
    P101_TRACK_POINTER_RESOURCE_RELEASE(env, "stdio-stream", stream, "freopen");
    ret_val = freopen(pathname, mode, stream);

    if(old_fd >= 0)
    {
        P101_TRACK_CLOSE(env, old_fd);
    }

    if(ret_val == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }
    else
    {
        int new_fd;

        P101_TRACK_POINTER_RESOURCE_ACQUIRE(env, "stdio-stream", ret_val, 0U, pathname);
        new_fd = fileno(ret_val);
        if(new_fd >= 0)
        {
            P101_TRACK_OPEN(env, new_fd);
        }
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_fseek(const struct p101_env *env, struct p101_error *err, FILE *stream, long offset, int whence)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = fseek(stream, offset, whence);

    if(ret_val != 0)
    {
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_fsetpos(const struct p101_env *env, struct p101_error *err, FILE *stream, const fpos_t *pos)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = fsetpos(stream, pos);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

long p101_ftell(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    long ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1L);
    errno   = 0;
    ret_val = ftell(stream);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

size_t p101_fwrite(const struct p101_env *env, struct p101_error *err, const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
    size_t  ret_val;
    errno_t actual_error;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, 0);
    errno        = 0;
    ret_val      = fwrite(ptr, size, nitems, stream);
    actual_error = errno;

    if(ferror(stream))
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(actual_error));
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_getc(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    int     ret_val;
    errno_t actual_error;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno        = 0;
    ret_val      = getc(stream);
    actual_error = errno;

    if(ferror(stream))
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(actual_error));
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_getchar(const struct p101_env *env, struct p101_error *err)
{
    int     ret_val;
    errno_t actual_error;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno        = 0;
    ret_val      = getchar();
    actual_error = errno;

    if(ferror(stdin))
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(actual_error));
    }

    P101_C_DONE(env);

    return ret_val;
}

void p101_perror(const struct p101_env *env, const char *s)
{
    errno_t actual_error;

    actual_error = errno;
    P101_TRACE(env);
    errno = actual_error;
    perror(s);
    P101_TRACE_EXIT(env);
    errno = actual_error;
}

int p101_putc(const struct p101_env *env, struct p101_error *err, int c, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = putc(c, stream);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_putchar(const struct p101_env *env, struct p101_error *err, int c)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = putchar(c);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_puts(const struct p101_env *env, struct p101_error *err, const char *s)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = puts(s);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_remove(const struct p101_env *env, struct p101_error *err, const char *path)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = remove(path);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_rename(const struct p101_env *env, struct p101_error *err, const char *old_name, const char *new_name)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = rename(old_name, new_name);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_setvbuf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, char *restrict buf, int type, size_t size)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = setvbuf(stream, buf, type, size);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

FILE *p101_tmpfile(const struct p101_env *env, struct p101_error *err)
{
    FILE *ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, NULL);
    errno   = 0;
    ret_val = tmpfile();

    if(ret_val == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }
    else
    {
        int fd;

        P101_TRACK_POINTER_RESOURCE_ACQUIRE(env, "stdio-stream", ret_val, 0U, "tmpfile");
        fd = fileno(ret_val);
        if(fd >= 0)
        {
            P101_TRACK_OPEN(env, fd);
        }
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_ungetc(const struct p101_env *env, struct p101_error *err, int c, FILE *stream)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    errno   = 0;
    ret_val = ungetc(c, stream);

    if(ret_val == EOF)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }

    P101_C_DONE(env);

    return ret_val;
}

int p101_fprintf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const char *restrict format, ...)
{
    va_list ap;
    int     ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    va_start(ap, format);
    ret_val = vfprintf_checked(err, stream, format, ap);
    va_end(ap);

    P101_C_DONE(env);

    return ret_val;
}

int p101_fscanf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const char *restrict format, ...)
{
    va_list ap;
    int     ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    va_start(ap, format);
    ret_val = vfscanf_checked(err, stream, format, ap);
    va_end(ap);

    P101_C_DONE(env);

    return ret_val;
}

int p101_printf(const struct p101_env *env, struct p101_error *err, const char *restrict format, ...)
{
    va_list ap;
    int     ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    va_start(ap, format);
    ret_val = vprintf_checked(err, format, ap);
    va_end(ap);

    P101_C_DONE(env);

    return ret_val;
}

int p101_scanf(const struct p101_env *env, struct p101_error *err, const char *restrict format, ...)
{
    va_list ap;
    int     ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    va_start(ap, format);
    ret_val = vscanf_checked(err, format, ap);
    va_end(ap);

    P101_C_DONE(env);

    return ret_val;
}

int p101_snprintf(const struct p101_env *env, struct p101_error *err, char *restrict s, size_t n, const char *restrict format, ...)
{
    va_list ap;
    int     ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    va_start(ap, format);
    ret_val = vsnprintf_checked(err, s, n, format, ap);
    va_end(ap);

    P101_C_DONE(env);

    return ret_val;
}

int p101_sscanf(const struct p101_env *env, struct p101_error *err, const char *restrict s, const char *restrict format, ...)
{
    va_list ap;
    int     ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    va_start(ap, format);
    ret_val = vsscanf_checked(err, s, format, ap);
    va_end(ap);

    P101_C_DONE(env);

    return ret_val;
}

int p101_vfprintf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const char *restrict format, va_list ap)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    ret_val = vfprintf_checked(err, stream, format, ap);

    P101_C_DONE(env);

    return ret_val;
}

int p101_vfscanf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const char *restrict format, va_list ap)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    ret_val = vfscanf_checked(err, stream, format, ap);

    P101_C_DONE(env);

    return ret_val;
}

int p101_vprintf(const struct p101_env *env, struct p101_error *err, const char *restrict format, va_list ap)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    ret_val = vprintf_checked(err, format, ap);

    P101_C_DONE(env);

    return ret_val;
}

int p101_vscanf(const struct p101_env *env, struct p101_error *err, const char *restrict format, va_list ap)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    ret_val = vscanf_checked(err, format, ap);

    P101_C_DONE(env);

    return ret_val;
}

int p101_vsnprintf(const struct p101_env *env, struct p101_error *err, char *restrict s, size_t n, const char *restrict format, va_list ap)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    ret_val = vsnprintf_checked(err, s, n, format, ap);

    P101_C_DONE(env);

    return ret_val;
}

int p101_vsscanf(const struct p101_env *env, struct p101_error *err, const char *restrict s, const char *restrict format, va_list ap)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, ret_val, -1);
    ret_val = vsscanf_checked(err, s, format, ap);

    P101_C_DONE(env);

    return ret_val;
}
