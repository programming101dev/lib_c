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

void p101_atomic_flag_clear(const struct p101_env *env, volatile atomic_flag *object)
{
    P101_TRACE(env);
    atomic_flag_clear(object);
    P101_TRACE_EXIT(env);
}

void p101_atomic_flag_clear_explicit(const struct p101_env *env, volatile atomic_flag *object, memory_order order)
{
    P101_TRACE(env);
    atomic_flag_clear_explicit(object, order);
    P101_TRACE_EXIT(env);
}

bool p101_atomic_flag_test_and_set(const struct p101_env *env, volatile atomic_flag *object)
{
    bool ret_val;

    P101_TRACE(env);
    ret_val = atomic_flag_test_and_set(object);

    P101_TRACE_EXIT(env);

    return ret_val;
}

bool p101_atomic_flag_test_and_set_explicit(const struct p101_env *env, volatile atomic_flag *object, memory_order order)
{
    bool ret_val;

    P101_TRACE(env);
    ret_val = atomic_flag_test_and_set_explicit(object, order);

    P101_TRACE_EXIT(env);

    return ret_val;
}

void p101_atomic_signal_fence(const struct p101_env *env, memory_order order)
{
    P101_TRACE(env);
    atomic_signal_fence(order);
    P101_TRACE_EXIT(env);
}

void p101_atomic_thread_fence(const struct p101_env *env, memory_order order)
{
    P101_TRACE(env);
    atomic_thread_fence(order);
    P101_TRACE_EXIT(env);
}

// NOLINTNEXTLINE(readability-non-const-parameter) -- atomic compare/exchange updates expected on failure.
bool p101_atomic_uint_compare_exchange_strong(const struct p101_env *env, volatile atomic_uint *object, unsigned int *expected, unsigned int desired)
{
    bool ret_val;

    P101_TRACE(env);
    ret_val = atomic_compare_exchange_strong(object, expected, desired);

    P101_TRACE_EXIT(env);

    return ret_val;
}

// NOLINTNEXTLINE(readability-non-const-parameter) -- atomic compare/exchange updates expected on failure.
bool p101_atomic_uint_compare_exchange_strong_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int *expected, unsigned int desired, memory_order success, memory_order failure)
{
    bool ret_val;

    P101_TRACE(env);
    ret_val = atomic_compare_exchange_strong_explicit(object, expected, desired, success, failure);

    P101_TRACE_EXIT(env);

    return ret_val;
}

// NOLINTNEXTLINE(readability-non-const-parameter) -- atomic compare/exchange updates expected on failure.
bool p101_atomic_uint_compare_exchange_weak(const struct p101_env *env, volatile atomic_uint *object, unsigned int *expected, unsigned int desired)
{
    bool ret_val;

    P101_TRACE(env);
    ret_val = atomic_compare_exchange_weak(object, expected, desired);

    P101_TRACE_EXIT(env);

    return ret_val;
}

// NOLINTNEXTLINE(readability-non-const-parameter) -- atomic compare/exchange updates expected on failure.
bool p101_atomic_uint_compare_exchange_weak_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int *expected, unsigned int desired, memory_order success, memory_order failure)
{
    bool ret_val;

    P101_TRACE(env);
    ret_val = atomic_compare_exchange_weak_explicit(object, expected, desired, success, failure);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_exchange(const struct p101_env *env, volatile atomic_uint *object, unsigned int desired)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_exchange(object, desired);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_exchange_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int desired, memory_order order)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_exchange_explicit(object, desired, order);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_add(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_add(object, operand);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_add_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand, memory_order order)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_add_explicit(object, operand, order);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_and(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_and(object, operand);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_and_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand, memory_order order)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_and_explicit(object, operand, order);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_or(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_or(object, operand);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_or_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand, memory_order order)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_or_explicit(object, operand, order);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_sub(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_sub(object, operand);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_sub_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand, memory_order order)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_sub_explicit(object, operand, order);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_xor(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_xor(object, operand);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_fetch_xor_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand, memory_order order)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_fetch_xor_explicit(object, operand, order);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_load(const struct p101_env *env, const volatile atomic_uint *object)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_load(object);

    P101_TRACE_EXIT(env);

    return ret_val;
}

unsigned int p101_atomic_uint_load_explicit(const struct p101_env *env, const volatile atomic_uint *object, memory_order order)
{
    unsigned int ret_val;

    P101_TRACE(env);
    ret_val = atomic_load_explicit(object, order);

    P101_TRACE_EXIT(env);

    return ret_val;
}

void p101_atomic_uint_store(const struct p101_env *env, volatile atomic_uint *object, unsigned int desired)
{
    P101_TRACE(env);
    atomic_store(object, desired);
    P101_TRACE_EXIT(env);
}

void p101_atomic_uint_store_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int desired, memory_order order)
{
    P101_TRACE(env);
    atomic_store_explicit(object, desired, order);
    P101_TRACE_EXIT(env);
}
