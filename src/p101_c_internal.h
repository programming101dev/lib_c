#ifndef LIBP101_C_INTERNAL_H
#define LIBP101_C_INTERNAL_H

#include <p101_env/env.h>
#include <p101_error/error.h>

/*
 * Fault injection is test-only policy carried by p101_env. Keep the mechanics
 * here so every fallible C wrapper converges on one exit point.
 */
// clang-format off
#define P101_C_FAULT_RETURN(env, err, call_name, result, failure_value) \
    do                                                                 \
    {                                                                  \
        int p101_c_fault_code_;                                        \
                                                                       \
        p101_c_fault_code_ = p101_env_check_fault((env), (call_name)); \
        if(p101_c_fault_code_ != 0)                                    \
        {                                                              \
            P101_ERROR_RAISE_ERRNO((err), p101_c_fault_code_);         \
            (result) = (failure_value);                                \
            goto p101_c_done_;                                         \
        }                                                              \
    } while(0)

#define P101_C_DONE(env)                                                \
    p101_c_done_:                                                       \
    P101_TRACE_EXIT(env)
// clang-format on

#endif
