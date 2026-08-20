#ifndef LIBP101_C_P101_STDIO_H
#define LIBP101_C_P101_STDIO_H

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

#include <p101_env/env.h>
#include <p101_error/attributes.h>
#include <stdarg.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

    void   p101_clearerr(const struct p101_env *env, FILE *stream);
    int    p101_fclose(const struct p101_env *env, struct p101_error *err, FILE *stream);
    int    p101_feof(const struct p101_env *env, FILE *stream);
    int    p101_ferror(const struct p101_env *env, FILE *stream);
    int    p101_fflush(const struct p101_env *env, struct p101_error *err, FILE *stream);
    int    p101_fgetc(const struct p101_env *env, struct p101_error *err, FILE *stream);
    int    p101_fgetpos(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, fpos_t *restrict pos);
    char  *p101_fgets(const struct p101_env *env, struct p101_error *err, char *restrict s, int n, FILE *restrict stream);
    FILE  *p101_fopen(const struct p101_env *env, struct p101_error *err, const char *restrict pathname, const char *restrict mode) P101_ATTR_WARN_UNUSED_RESULT P101_ATTR_SEMANTIC_ROLE("p101:filesystem:path-use");
    int    p101_fprintf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const char *restrict format, ...) P101_ATTR_PRINTF(4, 5);
    int    p101_fputc(const struct p101_env *env, struct p101_error *err, int c, FILE *stream);
    int    p101_fputs(const struct p101_env *env, struct p101_error *err, const char *restrict s, FILE *restrict stream);
    size_t p101_fread(const struct p101_env *env, struct p101_error *err, void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
    FILE  *p101_freopen(const struct p101_env *env, struct p101_error *err, const char *restrict pathname, const char *restrict mode, FILE *restrict stream) P101_ATTR_WARN_UNUSED_RESULT;
    int    p101_fscanf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const char *restrict format, ...) P101_ATTR_SCANF(4, 5);
    int    p101_fseek(const struct p101_env *env, struct p101_error *err, FILE *stream, long offset, int whence);
    int    p101_fsetpos(const struct p101_env *env, struct p101_error *err, FILE *stream, const fpos_t *pos);
    long   p101_ftell(const struct p101_env *env, struct p101_error *err, FILE *stream);
    size_t p101_fwrite(const struct p101_env *env, struct p101_error *err, const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
    int    p101_getc(const struct p101_env *env, struct p101_error *err, FILE *stream);
    int    p101_getchar(const struct p101_env *env, struct p101_error *err);
    void   p101_perror(const struct p101_env *env, const char *s);
    int    p101_printf(const struct p101_env *env, struct p101_error *err, const char *restrict format, ...) P101_ATTR_PRINTF(3, 4);
    int    p101_putc(const struct p101_env *env, struct p101_error *err, int c, FILE *stream);
    int    p101_putchar(const struct p101_env *env, struct p101_error *err, int c);
    int    p101_puts(const struct p101_env *env, struct p101_error *err, const char *s);
    int    p101_remove(const struct p101_env *env, struct p101_error *err, const char *path);
    int    p101_rename(const struct p101_env *env, struct p101_error *err, const char *old_name, const char *new_name) P101_ATTR_SEMANTIC_ROLE("p101:filesystem:path-use");
    int    p101_scanf(const struct p101_env *env, struct p101_error *err, const char *restrict format, ...) P101_ATTR_SCANF(3, 4);
    int    p101_setvbuf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, char *restrict buf, int type, size_t size);
    int    p101_snprintf(const struct p101_env *env, struct p101_error *err, char *restrict s, size_t n, const char *restrict format, ...) P101_ATTR_PRINTF(5, 6);
    int    p101_sscanf(const struct p101_env *env, struct p101_error *err, const char *restrict s, const char *restrict format, ...) P101_ATTR_SCANF(4, 5);
    FILE  *p101_tmpfile(const struct p101_env *env, struct p101_error *err) P101_ATTR_WARN_UNUSED_RESULT;
    int    p101_ungetc(const struct p101_env *env, struct p101_error *err, int c, FILE *stream);
    int    p101_vfprintf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const char *restrict format, va_list ap) P101_ATTR_PRINTF(4, 0);
    int    p101_vfscanf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const char *restrict format, va_list ap) P101_ATTR_SCANF(4, 0);
    int    p101_vprintf(const struct p101_env *env, struct p101_error *err, const char *restrict format, va_list ap) P101_ATTR_PRINTF(3, 0);
    int    p101_vscanf(const struct p101_env *env, struct p101_error *err, const char *restrict format, va_list ap) P101_ATTR_SCANF(3, 0);
    int    p101_vsnprintf(const struct p101_env *env, struct p101_error *err, char *restrict s, size_t n, const char *restrict format, va_list ap) P101_ATTR_PRINTF(5, 0);
    int    p101_vsscanf(const struct p101_env *env, struct p101_error *err, const char *restrict s, const char *restrict format, va_list ap) P101_ATTR_SCANF(4, 0);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_C_P101_STDIO_H
