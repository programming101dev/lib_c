/*
 * Copyright 2022-2024 D'Arcy Smith.
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

#include "p101_c/p101_math.h"
#include "p101_c_internal.h"
#include <fenv.h>
#include <math.h>

static void math_check(struct p101_error *err, int prior_exceptions);
static int  math_prepare(void);

static int math_prepare(void)
{
    int prior_exceptions;

    errno = 0;
    if((math_errhandling & MATH_ERREXCEPT) == 0)
    {
        return 0;
    }

    prior_exceptions = fetestexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);
    (void)feclearexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);
    return prior_exceptions;
}

static void math_check(struct p101_error *err, int prior_exceptions)
{
    int error_code;

    error_code = 0;

    if((math_errhandling & MATH_ERRNO) != 0 && errno != 0)
    {
        error_code = errno;
    }
    else if((math_errhandling & MATH_ERREXCEPT) != 0)
    {
        int exceptions;

        exceptions = fetestexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);
        if((exceptions & (FE_INVALID | FE_DIVBYZERO)) != 0)
        {
            error_code = EDOM;
        }
        else if((exceptions & (FE_OVERFLOW | FE_UNDERFLOW)) != 0)
        {
            error_code = ERANGE;
        }
    }

    if(prior_exceptions != 0)
    {
        (void)feraiseexcept(prior_exceptions);
    }

    if(error_code != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, error_code);
    }
}

double p101_acos(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = acos(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_acosf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = acosf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_acosh(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = acosh(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_acoshf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = acoshf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_acoshl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = acoshl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_acosl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = acosl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_asin(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = asin(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_asinf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = asinf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_asinh(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = asinh(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_asinhf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = asinhf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_asinhl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = asinhl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_asinl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = asinl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_atan(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = atan(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_atan2(const struct p101_env *env, struct p101_error *err, double y, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = atan2(y, x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_atan2f(const struct p101_env *env, struct p101_error *err, float y, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = atan2f(y, x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_atan2l(const struct p101_env *env, struct p101_error *err, long double y, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = atan2l(y, x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_atanf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = atanf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_atanh(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = atanh(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_atanhf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = atanhf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_atanhl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = atanhl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_atanl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = atanl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_cbrt(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = cbrt(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_cbrtf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = cbrtf(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_cbrtl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = cbrtl(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_ceil(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = ceil(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_ceilf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = ceilf(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_ceill(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = ceill(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_copysign(const struct p101_env *env, double x, double y)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = copysign(x, y);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_copysignf(const struct p101_env *env, float x, float y)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = copysignf(x, y);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_copysignl(const struct p101_env *env, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = copysignl(x, y);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_cos(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = cos(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_cosf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = cosf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_cosh(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = cosh(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_coshf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = coshf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_coshl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = coshl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_cosl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = cosl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_erf(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = erf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_erfc(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = erfc(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_erfcf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = erfcf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_erfcl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = erfcl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_erff(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = erff(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_erfl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = erfl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_exp(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = exp(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_exp2(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = exp2(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_exp2f(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = exp2f(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_exp2l(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = exp2l(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_expf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = expf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_expl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = expl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_expm1(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = expm1(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_expm1f(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = expm1f(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_expm1l(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = expm1l(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_fabs(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = fabs(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_fabsf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = fabsf(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_fabsl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = fabsl(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_fdim(const struct p101_env *env, struct p101_error *err, double x, double y)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = fdim(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_fdimf(const struct p101_env *env, struct p101_error *err, float x, float y)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = fdimf(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_fdiml(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = fdiml(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_floor(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = floor(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_floorf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = floorf(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_floorl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = floorl(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_fma(const struct p101_env *env, struct p101_error *err, double x, double y, double z)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = fma(x, y, z);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_fmaf(const struct p101_env *env, struct p101_error *err, float x, float y, float z)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = fmaf(x, y, z);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_fmal(const struct p101_env *env, struct p101_error *err, long double x, long double y, long double z)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = fmal(x, y, z);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_fmax(const struct p101_env *env, double x, double y)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = fmax(x, y);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_fmaxf(const struct p101_env *env, float x, float y)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = fmaxf(x, y);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_fmaxl(const struct p101_env *env, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = fmaxl(x, y);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_fmin(const struct p101_env *env, double x, double y)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = fmin(x, y);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_fminf(const struct p101_env *env, float x, float y)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = fminf(x, y);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_fminl(const struct p101_env *env, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = fminl(x, y);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_fmod(const struct p101_env *env, struct p101_error *err, double x, double y)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = fmod(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_fmodf(const struct p101_env *env, struct p101_error *err, float x, float y)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = fmodf(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_fmodl(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = fmodl(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_frexp(const struct p101_env *env, double num, int *exp)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = frexp(num, exp);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_frexpf(const struct p101_env *env, float num, int *exp)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = frexpf(num, exp);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_frexpl(const struct p101_env *env, long double num, int *exp)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = frexpl(num, exp);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_hypot(const struct p101_env *env, struct p101_error *err, double x, double y)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = hypot(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_hypotf(const struct p101_env *env, struct p101_error *err, float x, float y)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = hypotf(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_hypotl(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = hypotl(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_ilogb(const struct p101_env *env, struct p101_error *err, double x)
{
    int ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = ilogb(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_ilogbf(const struct p101_env *env, struct p101_error *err, float x)
{
    int ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = ilogbf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

int p101_ilogbl(const struct p101_env *env, struct p101_error *err, long double x)
{
    int ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = ilogbl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_ldexp(const struct p101_env *env, struct p101_error *err, double x, int exp)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = ldexp(x, exp);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_ldexpf(const struct p101_env *env, struct p101_error *err, float x, int exp)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = ldexpf(x, exp);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_ldexpl(const struct p101_env *env, struct p101_error *err, long double x, int exp)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = ldexpl(x, exp);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_lgamma(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = lgamma(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_lgammaf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = lgammaf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_lgammal(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = lgammal(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long long p101_llrint(const struct p101_env *env, struct p101_error *err, double x)
{
    long long ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = llrint(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long long p101_llrintf(const struct p101_env *env, struct p101_error *err, float x)
{
    long long ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = llrintf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long long p101_llrintl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long long ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = llrintl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long long p101_llround(const struct p101_env *env, struct p101_error *err, double x)
{
    long long ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = llround(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long long p101_llroundf(const struct p101_env *env, struct p101_error *err, float x)
{
    long long ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = llroundf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long long p101_llroundl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long long ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = llroundl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_log(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = log(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_log10(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = log10(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_log10f(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = log10f(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_log10l(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = log10l(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_log1p(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = log1p(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_log1pf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = log1pf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_log1pl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = log1pl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_log2(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = log2(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_log2f(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = log2f(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_log2l(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = log2l(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_logb(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = logb(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_logbf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = logbf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_logbl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = logbl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_logf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = logf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_logl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = logl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long p101_lrint(const struct p101_env *env, struct p101_error *err, double x)
{
    long ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = lrint(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long p101_lrintf(const struct p101_env *env, struct p101_error *err, float x)
{
    long ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = lrintf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long p101_lrintl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = lrintl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long p101_lround(const struct p101_env *env, struct p101_error *err, double x)
{
    long ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = lround(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long p101_lroundf(const struct p101_env *env, struct p101_error *err, float x)
{
    long ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = lroundf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long p101_lroundl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = lroundl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_modf(const struct p101_env *env, double x, double *iptr)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = modf(x, iptr);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_modff(const struct p101_env *env, float value, float *iptr)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = modff(value, iptr);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_modfl(const struct p101_env *env, long double value, long double *iptr)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = modfl(value, iptr);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_nan(const struct p101_env *env, const char *tagp)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = nan(tagp);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_nanf(const struct p101_env *env, const char *tagp)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = nanf(tagp);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_nanl(const struct p101_env *env, const char *tagp)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = nanl(tagp);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_nearbyint(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = nearbyint(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_nearbyintf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = nearbyintf(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_nearbyintl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = nearbyintl(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_nextafter(const struct p101_env *env, struct p101_error *err, double x, double y)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = nextafter(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_nextafterf(const struct p101_env *env, struct p101_error *err, float x, float y)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = nextafterf(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_nextafterl(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = nextafterl(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_nexttoward(const struct p101_env *env, struct p101_error *err, double x, long double y)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = nexttoward(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_nexttowardf(const struct p101_env *env, struct p101_error *err, float x, long double y)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = nexttowardf(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_nexttowardl(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = nexttowardl(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_pow(const struct p101_env *env, struct p101_error *err, double x, double y)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = pow(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_powf(const struct p101_env *env, struct p101_error *err, float x, float y)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = powf(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_powl(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = powl(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_remainder(const struct p101_env *env, struct p101_error *err, double x, double y)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = remainder(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_remainderf(const struct p101_env *env, struct p101_error *err, float x, float y)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = remainderf(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_remainderl(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = remainderl(x, y);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_remquo(const struct p101_env *env, struct p101_error *err, double x, double y, int *quo)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = remquo(x, y, quo);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_remquof(const struct p101_env *env, struct p101_error *err, float x, float y, int *quo)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = remquof(x, y, quo);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_remquol(const struct p101_env *env, struct p101_error *err, long double x, long double y, int *quo)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = remquol(x, y, quo);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_rint(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = rint(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_rintf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = rintf(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_rintl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = rintl(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_round(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = round(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_roundf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = roundf(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_roundl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = roundl(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_scalbln(const struct p101_env *env, struct p101_error *err, double x, long n)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = scalbln(x, n);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_scalblnf(const struct p101_env *env, struct p101_error *err, float x, long n)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = scalblnf(x, n);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_scalblnl(const struct p101_env *env, struct p101_error *err, long double x, long n)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = scalblnl(x, n);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_scalbn(const struct p101_env *env, struct p101_error *err, double x, int n)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = scalbn(x, n);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_scalbnf(const struct p101_env *env, struct p101_error *err, float x, int n)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = scalbnf(x, n);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_scalbnl(const struct p101_env *env, struct p101_error *err, long double x, int n)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = scalbnl(x, n);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_sin(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = sin(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_sinf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = sinf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_sinh(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = sinh(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_sinhf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = sinhf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_sinhl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = sinhl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_sinl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = sinl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_sqrt(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = sqrt(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_sqrtf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = sqrtf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_sqrtl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = sqrtl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_tan(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = tan(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_tanf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = tanf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_tanh(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = tanh(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_tanhf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = tanhf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_tanhl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = tanhl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_tanl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = tanl(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_tgamma(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = tgamma(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_tgammaf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = tgammaf(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_tgammal(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = math_prepare();
    ret_val          = tgammal(x);
    math_check(err, prior_exceptions);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_trunc(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = trunc(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_truncf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = truncf(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_truncl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = truncl(x);

    P101_TRACE_EXIT(env);

    return ret_val;
}
