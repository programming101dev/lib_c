#ifndef LIBP101_C_P101_STDATOMIC_H
#define LIBP101_C_P101_STDATOMIC_H

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

#include <p101_env/env.h>
#include <stdatomic.h>

#ifdef __cplusplus
extern "C"
{
#endif

    void         p101_atomic_flag_clear(const struct p101_env *env, volatile atomic_flag *object);
    void         p101_atomic_flag_clear_explicit(const struct p101_env *env, volatile atomic_flag *object, memory_order order);
    bool         p101_atomic_flag_test_and_set(const struct p101_env *env, volatile atomic_flag *object);
    bool         p101_atomic_flag_test_and_set_explicit(const struct p101_env *env, volatile atomic_flag *object, memory_order order);
    void         p101_atomic_signal_fence(const struct p101_env *env, memory_order order);
    void         p101_atomic_thread_fence(const struct p101_env *env, memory_order order);
    bool         p101_atomic_uint_compare_exchange_strong(const struct p101_env *env, volatile atomic_uint *object, unsigned int *expected, unsigned int desired);
    bool         p101_atomic_uint_compare_exchange_strong_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int *expected, unsigned int desired, memory_order success, memory_order failure);
    bool         p101_atomic_uint_compare_exchange_weak(const struct p101_env *env, volatile atomic_uint *object, unsigned int *expected, unsigned int desired);
    bool         p101_atomic_uint_compare_exchange_weak_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int *expected, unsigned int desired, memory_order success, memory_order failure);
    unsigned int p101_atomic_uint_exchange(const struct p101_env *env, volatile atomic_uint *object, unsigned int desired);
    unsigned int p101_atomic_uint_exchange_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int desired, memory_order order);
    unsigned int p101_atomic_uint_fetch_add(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand);
    unsigned int p101_atomic_uint_fetch_add_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand, memory_order order);
    unsigned int p101_atomic_uint_fetch_and(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand);
    unsigned int p101_atomic_uint_fetch_and_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand, memory_order order);
    unsigned int p101_atomic_uint_fetch_or(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand);
    unsigned int p101_atomic_uint_fetch_or_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand, memory_order order);
    unsigned int p101_atomic_uint_fetch_sub(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand);
    unsigned int p101_atomic_uint_fetch_sub_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand, memory_order order);
    unsigned int p101_atomic_uint_fetch_xor(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand);
    unsigned int p101_atomic_uint_fetch_xor_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int operand, memory_order order);
    unsigned int p101_atomic_uint_load(const struct p101_env *env, const volatile atomic_uint *object);
    unsigned int p101_atomic_uint_load_explicit(const struct p101_env *env, const volatile atomic_uint *object, memory_order order);
    void         p101_atomic_uint_store(const struct p101_env *env, volatile atomic_uint *object, unsigned int desired);
    void         p101_atomic_uint_store_explicit(const struct p101_env *env, volatile atomic_uint *object, unsigned int desired, memory_order order);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_C_P101_STDATOMIC_H
