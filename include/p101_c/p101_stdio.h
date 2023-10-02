#ifndef LIBP101_C_P101_STDIO_H
#define LIBP101_C_P101_STDIO_H


/*
 * Copyright 2021-2022 D'Arcy Smith.
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


#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * @param env
 * @param stream
 */
void p101_clearerr(const struct p101_env *env, FILE *stream);

/**
 *
 * @param env
 * @param err
 * @param stream
 * @return
 */
int p101_fclose(const struct p101_env *env, struct p101_error *err,
              FILE *stream);

/**
 *
 * @param env
 * @param stream
 * @return
 */
int p101_feof(const struct p101_env *env, FILE *stream);

/**
 *
 * @param env
 * @param stream
 * @return
 */
int p101_ferror(const struct p101_env *env, FILE *stream);

/**
 *
 * @param env
 * @param err
 * @param stream
 * @return
 */
int p101_fflush(const struct p101_env *env, struct p101_error *err,
              FILE *stream);

/**
 *
 * @param env
 * @param err
 * @param stream
 * @return
 */
int p101_fgetc(const struct p101_env *env, struct p101_error *err,
             FILE *stream);

/**
 *
 * @param env
 * @param err
 * @param stream
 * @param pos
 * @return
 */
int p101_fgetpos(const struct p101_env *env, struct p101_error *err,
               FILE *restrict stream, fpos_t *restrict pos);

/**
 *
 * @param env
 * @param err
 * @param s
 * @param n
 * @param stream
 * @return
 */
char *p101_fgets(const struct p101_env *env, struct p101_error *err,
               char *restrict s, int n, FILE *restrict stream);

/**
 *
 * @param env
 * @param err
 * @param pathname
 * @param mode
 * @return
 */
FILE *p101_fopen(const struct p101_env *env, struct p101_error *err,
               const char *restrict pathname, const char *restrict mode);

/**
 *
 * @param env
 * @param err
 * @param c
 * @param stream
 * @return
 */
int p101_fputc(const struct p101_env *env, struct p101_error *err, int c,
             FILE *stream);

/**
 *
 * @param env
 * @param err
 * @param s
 * @param stream
 * @return
 */
int p101_fputs(const struct p101_env *env, struct p101_error *err,
             const char *restrict s, FILE *restrict stream);

/**
 *
 * @param env
 * @param err
 * @param ptr
 * @param size
 * @param nitems
 * @param stream
 * @return
 */
size_t p101_fread(const struct p101_env *env, struct p101_error *err,
                void *restrict ptr, size_t size, size_t nitems,
                FILE *restrict stream);

/**
 *
 * @param env
 * @param err
 * @param pathname
 * @param mode
 * @param stream
 * @return
 */
FILE *p101_freopen(const struct p101_env *env, struct p101_error *err,
                 const char *restrict pathname, const char *restrict mode,
                 FILE *restrict stream);

/**
 *
 * @param env
 * @param err
 * @param stream
 * @param offset
 * @param whence
 * @return
 */
int p101_fseek(const struct p101_env *env, struct p101_error *err, FILE *stream,
             long offset, int whence);


/**
 *
 * @param env
 * @param err
 * @param stream
 * @param pos
 * @return
 */
int p101_fsetpos(const struct p101_env *env, struct p101_error *err,
               FILE *stream, const fpos_t *pos);

/**
 *
 * @param env
 * @param err
 * @param stream
 * @return
 */
long p101_ftell(const struct p101_env *env, struct p101_error *err,
              FILE *stream);

/**
 *
 * @param env
 * @param err
 * @param ptr
 * @param size
 * @param nitems
 * @param stream
 * @return
 */
size_t p101_fwrite(const struct p101_env *env, struct p101_error *err,
                 const void *restrict ptr, size_t size, size_t nitems,
                 FILE *restrict stream);

/**
 *
 * @param env
 * @param err
 * @param stream
 * @return
 */
int p101_getc(const struct p101_env *env, struct p101_error *err, FILE *stream);

/**
 *
 * @param env
 * @param err
 * @return
 */
int p101_getchar(const struct p101_env *env, struct p101_error *err);

/**
 *
 * @param env
 * @param s
 */
void p101_perror(const struct p101_env *env, const char *s);

/**
 *
 * @param env
 * @param err
 * @param c
 * @param stream
 * @return
 */
int p101_putc(const struct p101_env *env, struct p101_error *err, int c,
            FILE *stream);

/**
 *
 * @param env
 * @param err
 * @param c
 * @return
 */
int p101_putchar(const struct p101_env *env, struct p101_error *err, int c);

/**
 *
 * @param env
 * @param err
 * @param s
 * @return
 */
int p101_puts(const struct p101_env *env, struct p101_error *err,
            const char *s);

/**
 *
 * @param env
 * @param err
 * @param path
 * @return
 */
int p101_remove(const struct p101_env *env, struct p101_error *err,
              const char *path);

/**
 *
 * @param env
 * @param err
 * @param old
 * @param new
 * @return
 */
int p101_rename(const struct p101_env *env, struct p101_error *err,
              const char *old_name, const char *new_name);

/**
 *
 * @param env
 * @param err
 * @param stream
 */
void p101_rewind(const struct p101_env *env, struct p101_error *err,
               FILE *stream);

/**
 *
 * @param env
 * @param err
 * @param stream
 * @param buf
 */
void p101_setbuf(const struct p101_env *env, struct p101_error *err,
               FILE *restrict stream, char *restrict buf);

/**
 *
 * @param env
 * @param err
 * @param stream
 * @param buf
 * @param type
 * @param size
 * @return
 */
int p101_setvbuf(const struct p101_env *env, struct p101_error *err,
               FILE *restrict stream, char *restrict buf, int type,
               size_t size);

/**
 *
 * @param env
 * @param err
 * @return
 */
FILE *p101_tmpfile(const struct p101_env *env, struct p101_error *err);

/**
 *
 * @param env
 * @param c
 * @param stream
 * @return
 */
int p101_ungetc(const struct p101_env *env, int c, FILE *stream);

/**
 *
 * @param env
 * @param err
 * @param stream
 * @param format
 * @param ap
 * @return
 */
int p101_vfprintf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const char *restrict format, va_list ap);

/**
 *
 * @param env
 * @param err
 * @param stream
 * @param format
 * @param ap
 * @return
 */
int p101_vfscanf(const struct p101_env *env, struct p101_error *err, FILE *restrict stream, const char *restrict format, va_list ap);

/**
 *
 * @param env
 * @param err
 * @param format
 * @param ap
 * @return
 */
int p101_vprintf(const struct p101_env *env, struct p101_error *err, const char *restrict format, va_list ap);

/**
 *
 * @param env
 * @param err
 * @param format
 * @param ap
 * @return
 */
int p101_vscanf(const struct p101_env *env, struct p101_error *err, const char *restrict format, va_list ap);

/**
 *
 * @param env
 * @param err
 * @param s
 * @param n
 * @param format
 * @param ap
 * @return
 */
int p101_vsnprintf(const struct p101_env *env, struct p101_error *err, char *restrict s, size_t n, const char *restrict format, va_list ap);

/**
 *
 * @param env
 * @param err
 * @param s
 * @param format
 * @param ap
 * @return
 */
int p101_vsscanf(const struct p101_env *env, struct p101_error *err, const char *restrict s, const char *restrict format, va_list ap);


#ifdef __cplusplus
}
#endif


// deprecated
// int p101_vsprintf(const struct p101_env *env, struct p101_error *err, char *restrict s, const char *restrict format, va_list ap);


#endif // LIBP101_C_P101_STDIO_H
