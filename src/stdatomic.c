/*
 * Copyright 2026 D'Arcy Smith.
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

#include "p101_c/p101_stdatomic.h"

unsigned int p101_atomic_uint_fetch_add(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_add(object, operand);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_add_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand, memory_order order)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_add_explicit(object, operand, order);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_sub(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_sub(object, operand);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_sub_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand, memory_order order)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_sub_explicit(object, operand, order);

    return ret_val;
}

unsigned int p101_atomic_uint_load(const struct p101_env *env, const volatile atomic_uint *object)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_load(object);

    return ret_val;
}

unsigned int p101_atomic_uint_load_explicit(const struct p101_env *env, const volatile atomic_uint *object, memory_order order)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_load_explicit(object, order);

    return ret_val;
}

void p101_atomic_uint_store(const struct p101_env *env, volatile atomic_uint *object, unsigned int desired)
{
    P101_TRACE(env);
    atomic_store(object, desired);
}

void p101_atomic_uint_store_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int desired, memory_order order)
{
    P101_TRACE(env);
    atomic_store_explicit(object, desired, order);
}
