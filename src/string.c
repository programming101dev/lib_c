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

#include "p101_c/p101_stdlib.h"
#include "p101_c/p101_string.h"
#include "p101_c_internal.h"
#include <string.h>

const void *p101_memchr(const struct p101_env *env, const void *s, int c, size_t n)
{
    const void *ret_val;

    P101_TRACE(env);
    ret_val = memchr(s, c, n);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_memcmp(const struct p101_env *env, const void *s1, const void *s2, size_t n)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = memcmp(s1, s2, n);

    P101_TRACE_EXIT(env);

    return ret_val;
}

void *p101_memcpy(const struct p101_env *env, void *restrict s1, const void *restrict s2, size_t n)
{
    void *ret_val;

    P101_TRACE(env);
    ret_val = memcpy(s1, s2, n);

    P101_TRACE_EXIT(env);

    return ret_val;
}

void *p101_memmove(const struct p101_env *env, void *s1, const void *s2, size_t n)
{
    void *ret_val;

    P101_TRACE(env);
    ret_val = memmove(s1, s2, n);

    P101_TRACE_EXIT(env);

    return ret_val;
}

void *p101_memset(const struct p101_env *env, void *s, int c, size_t n)
{
    void *ret_val;

    P101_TRACE(env);
    ret_val = memset(s, c, n);

    P101_TRACE_EXIT(env);

    return ret_val;
}

const char *p101_strchr(const struct p101_env *env, const char *s, int c)
{
    const char *ret_val;

    P101_TRACE(env);
    ret_val = strchr(s, c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_strcmp(const struct p101_env *env, const char *s1, const char *s2)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = strcmp(s1, s2);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_strcoll(const struct p101_env *env, struct p101_error *err, const char *s1, const char *s2)
{
    int ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, "strcoll", 0);
    errno   = 0;
    ret_val = strcoll(s1, s2);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}

size_t p101_strcspn(const struct p101_env *env, const char *s1, const char *s2)
{
    size_t ret_val;

    P101_TRACE(env);
    ret_val = strcspn(s1, s2);

    P101_TRACE_EXIT(env);

    return ret_val;
}

#ifdef __apple_build_version__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wallocator-wrappers"
#endif
char *p101_strerror(const struct p101_env *env, struct p101_error *err, int errnum)
{
    const char *ret_val;
    size_t      len;
    char       *copy;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, NULL);
    errno   = 0;
    ret_val = strerror(errnum);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
        P101_TRACE_EXIT(env);

        return NULL;
    }

    len  = p101_strlen(env, ret_val);
    copy = (char *)p101_malloc(env, err, len + 1U);

    if(copy == NULL || p101_error_has_error(err))
    {
        P101_TRACE_EXIT(env);

        return NULL;
    }

    p101_memcpy(env, copy, ret_val, len + 1U);

    P101_TRACE_EXIT(env);

    return copy;
}
#ifdef __apple_build_version__
    #pragma clang diagnostic pop
#endif

size_t p101_strlen(const struct p101_env *env, const char *s)
{
    size_t ret_val;

    P101_TRACE(env);
    ret_val = strlen(s);

    P101_TRACE_EXIT(env);

    return ret_val;
}

char *p101_strncat(const struct p101_env *env, char *restrict s1, const char *restrict s2, size_t n)
{
    char *ret_val;

    P101_TRACE(env);
    ret_val = strncat(s1, s2, n);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_strncmp(const struct p101_env *env, const char *s1, const char *s2, size_t n)
{
    int ret_val;

    P101_TRACE(env);
    ret_val = strncmp(s1, s2, n);

    P101_TRACE_EXIT(env);

    return ret_val;
}

char *p101_strncpy(const struct p101_env *env, char *restrict s1, const char *restrict s2, size_t n)
{
    char *ret_val;

    P101_TRACE(env);
    ret_val = strncpy(s1, s2, n);

    P101_TRACE_EXIT(env);

    return ret_val;
}

const char *p101_strpbrk(const struct p101_env *env, const char *s1, const char *s2)
{
    const char *ret_val;

    P101_TRACE(env);
    ret_val = strpbrk(s1, s2);

    P101_TRACE_EXIT(env);

    return ret_val;
}

const char *p101_strrchr(const struct p101_env *env, const char *s, int c)
{
    const char *ret_val;

    P101_TRACE(env);
    ret_val = strrchr(s, c);

    P101_TRACE_EXIT(env);

    return ret_val;
}

size_t p101_strspn(const struct p101_env *env, const char *s1, const char *s2)
{
    size_t ret_val;

    P101_TRACE(env);
    ret_val = strspn(s1, s2);

    P101_TRACE_EXIT(env);

    return ret_val;
}

const char *p101_strstr(const struct p101_env *env, const char *s1, const char *s2)
{
    const char *ret_val;

    P101_TRACE(env);
    ret_val = strstr(s1, s2);

    P101_TRACE_EXIT(env);

    return ret_val;
}

size_t p101_strxfrm(const struct p101_env *env, struct p101_error *err, char *restrict s1, const char *restrict s2, size_t n)
{
    size_t ret_val;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    errno   = 0;
    ret_val = strxfrm(s1, s2, n);

    if(errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);

    return ret_val;
}
