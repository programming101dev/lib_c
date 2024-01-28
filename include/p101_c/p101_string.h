#ifndef LIBP101_C_P101_STRING_H
#define LIBP101_C_P101_STRING_H

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

#ifdef __cplusplus
extern "C"
{
#endif

    void  *p101_memchr(const struct p101_env *env, const void *s, int c, size_t n);
    int    p101_memcmp(const struct p101_env *env, const void *s1, const void *s2, size_t n);
    void  *p101_memcpy(const struct p101_env *env, void *restrict s1, const void *restrict s2, size_t n);
    void  *p101_memmove(const struct p101_env *env, void *s1, const void *s2, size_t n);
    void  *p101_memset(const struct p101_env *env, void *s, int c, size_t n);
    char  *p101_strchr(const struct p101_env *env, const char *s, int c);
    int    p101_strcmp(const struct p101_env *env, const char *s1, const char *s2);
    int    p101_strcoll(const struct p101_env *env, const char *s1, const char *s2);
    size_t p101_strcspn(const struct p101_env *env, const char *s1, const char *s2);
    char  *p101_strerror(const struct p101_env *env, struct p101_error *err, int errnum);
    size_t p101_strlen(const struct p101_env *env, const char *s);
    char  *p101_strncat(const struct p101_env *env, char *restrict s1, const char *restrict s2, size_t n);
    int    p101_strncmp(const struct p101_env *env, const char *s1, const char *s2, size_t n);
    char  *p101_strncpy(const struct p101_env *env, char *restrict s1, const char *restrict s2, size_t n);
    char  *p101_strpbrk(const struct p101_env *env, const char *s1, const char *s2);
    char  *p101_strrchr(const struct p101_env *env, const char *s, int c);
    size_t p101_strspn(const struct p101_env *env, const char *s1, const char *s2);
    char  *p101_strstr(const struct p101_env *env, const char *s1, const char *s2);
    size_t p101_strxfrm(const struct p101_env *env, struct p101_error *err, char *restrict s1, const char *restrict s2, size_t n);

#ifdef __cplusplus
}
#endif

// unsafe
// char *p101_strtok(const struct p101_env *env, char *restrict s, const char *restrict sep);
// char *p101_strcat(const struct p101_env *env, char *restrict s1, const char *restrict s2);
// char *p101_strcpy(const struct p101_env *env, char *restrict s1, const char *restrict s2);

#endif    // LIBP101_C_P101_STRING_H
