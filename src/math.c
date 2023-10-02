/*
 * Copyright 2022-2022 D'Arcy Smith.
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
#include <math.h>


double p101_acos(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = acos(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_acosf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = acosf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_acosh(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = acosh(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_acoshf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = acoshf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_acoshl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = acoshl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_acosl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = acosl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_asin(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = asin(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_asinf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = asinf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_asinh(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = asinh(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_asinhf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = asinhf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_asinhl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = asinhl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_asinl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = asinl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_atan(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = atan(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_atan2(const struct p101_env *env, struct p101_error *err, double y, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = atan2(y, x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_atan2f(const struct p101_env *env, struct p101_error *err, float y, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = atan2f(y, x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_atan2l(const struct p101_env *env, struct p101_error *err, long double y, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = atan2l(y, x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_atanf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = atanf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_atanh(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = atanh(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_atanhf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = atanhf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_atanhl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = atanhl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_atanl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = atanl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_cbrt(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = cbrt(x);

    return ret_val;
}

float p101_cbrtf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = cbrtf(x);

    return ret_val;
}

long double p101_cbrtl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = cbrtl(x);

    return ret_val;
}

double p101_ceil(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = ceil(x);

    return ret_val;
}

float p101_ceilf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = ceilf(x);

    return ret_val;
}

long double p101_ceill(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = ceill(x);

    return ret_val;
}

double p101_copysign(const struct p101_env *env, double x, double y)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = copysign(x, y);

    return ret_val;
}

float p101_copysignf(const struct p101_env *env, float x, float y)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = copysignf(x, y);

    return ret_val;
}

long double p101_copysignl(const struct p101_env *env, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = copysignl(x, y);

    return ret_val;
}

double p101_cos(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = cos(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_cosf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = cosf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_cosh(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = cosh(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_coshf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = coshf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_coshl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = coshl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_cosl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = cosl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_erf(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = erf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_erfc(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = erfc(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_erfcf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = erfcf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_erfcl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = erfcl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_erff(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = erff(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_erfl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = erfl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_exp(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = exp(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_exp2(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = exp2(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_exp2f(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = exp2f(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_exp2l(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = exp2l(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_expf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = expf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_expl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = expl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_expm1(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = expm1(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_expm1f(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = expm1f(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_expm1l(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = expm1l(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_fabs(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fabs(x);

    return ret_val;
}

float p101_fabsf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fabsf(x);

    return ret_val;
}

long double p101_fabsl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fabsl(x);

    return ret_val;
}

double p101_fdim(const struct p101_env *env, struct p101_error *err, double x, double y)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fdim(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_fdimf(const struct p101_env *env, struct p101_error *err, float x, float y)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fdimf(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_fdiml(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fdiml(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_floor(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = floor(x);

    return ret_val;
}

float p101_floorf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = floorf(x);

    return ret_val;
}

long double p101_floorl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = floorl(x);

    return ret_val;
}

double p101_fma(const struct p101_env *env, struct p101_error *err, double x, double y, double z)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fma(x, y, z);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_fmaf(const struct p101_env *env, struct p101_error *err, float x, float y, float z)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fmaf(x, y, z);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_fmal(const struct p101_env *env, struct p101_error *err, long double x, long double y, long double z)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fmal(x, y, z);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_fmax(const struct p101_env *env, double x, double y)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fmax(x, y);

    return ret_val;
}

float p101_fmaxf(const struct p101_env *env, float x, float y)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fmaxf(x, y);

    return ret_val;
}

long double p101_fmaxl(const struct p101_env *env, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fmaxl(x, y);

    return ret_val;
}

double p101_fmin(const struct p101_env *env, double x, double y)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fmin(x, y);

    return ret_val;
}

float p101_fminf(const struct p101_env *env, float x, float y)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fminf(x, y);

    return ret_val;
}

long double p101_fminl(const struct p101_env *env, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fminl(x, y);

    return ret_val;
}

double p101_fmod(const struct p101_env *env, struct p101_error *err, double x, double y)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fmod(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_fmodf(const struct p101_env *env, struct p101_error *err, float x, float y)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fmodf(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_fmodl(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = fmodl(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_frexp(const struct p101_env *env, double num, int *exp)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = frexp(num, exp);

    return ret_val;
}

float p101_frexpf(const struct p101_env *env, float num, int *exp)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = frexpf(num, exp);

    return ret_val;
}

long double p101_frexpl(const struct p101_env *env, long double num, int *exp)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = frexpl(num, exp);

    return ret_val;
}

double p101_hypot(const struct p101_env *env, struct p101_error *err, double x, double y)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = hypot(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_hypotf(const struct p101_env *env, struct p101_error *err, float x, float y)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = hypotf(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_hypotl(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = hypotl(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_ilogb(const struct p101_env *env, struct p101_error *err, double x)
{
    int ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = ilogb(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_ilogbf(const struct p101_env *env, struct p101_error *err, float x)
{
    int ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = ilogbf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int p101_ilogbl(const struct p101_env *env, struct p101_error *err, long double x)
{
    int ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = ilogbl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_ldexp(const struct p101_env *env, struct p101_error *err, double x, int exp)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = ldexp(x, exp);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_ldexpf(const struct p101_env *env, struct p101_error *err, float x, int exp)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = ldexpf(x, exp);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_ldexpl(const struct p101_env *env, struct p101_error *err, long double x, int exp)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = ldexpl(x, exp);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_lgamma(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = lgamma(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_lgammaf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = lgammaf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_lgammal(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = lgammal(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long long p101_llrint(const struct p101_env *env, struct p101_error *err, double x)
{
    long long ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = llrint(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long long p101_llrintf(const struct p101_env *env, struct p101_error *err, float x)
{
    long long ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = llrintf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long long p101_llrintl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long long ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = llrintl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long long p101_llround(const struct p101_env *env, struct p101_error *err, double x)
{
    long long ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = llround(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long long p101_llroundf(const struct p101_env *env, struct p101_error *err, float x)
{
    long long ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = llroundf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long long p101_llroundl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long long ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = llroundl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_log(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = log(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_log10(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = log10(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_log10f(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = log10f(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_log10l(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = log10l(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_log1p(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = log1p(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_log1pf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = log1pf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_log1pl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = log1pl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_log2(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = log2(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_log2f(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = log2f(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_log2l(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = log2l(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_logb(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = logb(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_logbf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = logbf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_logbl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = logbl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_logf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = logf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_logl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = logl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long p101_lrint(const struct p101_env *env, struct p101_error *err, double x)
{
    long ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = lrint(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long p101_lrintf(const struct p101_env *env, struct p101_error *err, float x)
{
    long ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = lrintf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long p101_lrintl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = lrintl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long p101_lround(const struct p101_env *env, struct p101_error *err, double x)
{
    long ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = lround(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long p101_lroundf(const struct p101_env *env, struct p101_error *err, float x)
{
    long ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = lroundf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long p101_lroundl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = lroundl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_modf(const struct p101_env *env, double x, double *iptr)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = modf(x, iptr);

    return ret_val;
}

float p101_modff(const struct p101_env *env, float value, float *iptr)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = modff(value, iptr);

    return ret_val;
}

long double p101_modfl(const struct p101_env *env, long double value, long double *iptr)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = modfl(value, iptr);

    return ret_val;
}

double p101_nan(const struct p101_env *env, const char *tagp)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = nan(tagp);

    return ret_val;
}

float p101_nanf(const struct p101_env *env, const char *tagp)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = nanf(tagp);

    return ret_val;
}

long double p101_nanl(const struct p101_env *env, const char *tagp)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = nanl(tagp);

    return ret_val;
}

double p101_nearbyint(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = nearbyint(x);

    return ret_val;
}

float p101_nearbyintf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = nearbyintf(x);

    return ret_val;
}

long double p101_nearbyintl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = nearbyintl(x);

    return ret_val;
}

double p101_nextafter(const struct p101_env *env, struct p101_error *err, double x, double y)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = nextafter(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_nextafterf(const struct p101_env *env, struct p101_error *err, float x, float y)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = nextafterf(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_nextafterl(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = nextafterl(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_nexttoward(const struct p101_env *env, struct p101_error *err, double x, long double y)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = nexttoward(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_nexttowardf(const struct p101_env *env, struct p101_error *err, float x, long double y)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = nexttowardf(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_nexttowardl(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = nexttowardl(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_pow(const struct p101_env *env, struct p101_error *err, double x, double y)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = pow(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_powf(const struct p101_env *env, struct p101_error *err, float x, float y)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = powf(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_powl(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = powl(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_remainder(const struct p101_env *env, struct p101_error *err, double x, double y)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = remainder(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_remainderf(const struct p101_env *env, struct p101_error *err, float x, float y)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = remainderf(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_remainderl(const struct p101_env *env, struct p101_error *err, long double x, long double y)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = remainderl(x, y);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_remquo(const struct p101_env *env, struct p101_error *err, double x, double y, int *quo)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = remquo(x, y, quo);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_remquof(const struct p101_env *env, struct p101_error *err, float x, float y, int *quo)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = remquof(x, y, quo);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_remquol(const struct p101_env *env, struct p101_error *err, long double x, long double y, int *quo)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = remquol(x, y, quo);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_rint(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = rint(x);

    return ret_val;
}

float p101_rintf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = rintf(x);

    return ret_val;
}

long double p101_rintl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = rintl(x);

    return ret_val;
}

double p101_round(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = round(x);

    return ret_val;
}

float p101_roundf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = roundf(x);

    return ret_val;
}

long double p101_roundl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = roundl(x);

    return ret_val;
}

double p101_scalbln(const struct p101_env *env, struct p101_error *err, double x, long n)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = scalbln(x, n);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_scalblnf(const struct p101_env *env, struct p101_error *err, float x, long n)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = scalblnf(x, n);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_scalblnl(const struct p101_env *env, struct p101_error *err, long double x, long n)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = scalblnl(x, n);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_scalbn(const struct p101_env *env, struct p101_error *err, double x, int n)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = scalbn(x, n);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_scalbnf(const struct p101_env *env, struct p101_error *err, float x, int n)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = scalbnf(x, n);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_scalbnl(const struct p101_env *env, struct p101_error *err, long double x, int n)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = scalbnl(x, n);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_sin(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = sin(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_sinf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = sinf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_sinh(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = sinh(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_sinhf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = sinhf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_sinhl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = sinhl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_sinl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = sinl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_sqrt(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = sqrt(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_sqrtl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = sqrtl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_tan(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = tan(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_tanf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = tanf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_tanh(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = tanh(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_tanhf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = tanhf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_tanhl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = tanhl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_tanl(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = tanl(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_tgamma(const struct p101_env *env, struct p101_error *err, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = tgamma(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

float p101_tgammaf(const struct p101_env *env, struct p101_error *err, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = tgammaf(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long double p101_tgammal(const struct p101_env *env, struct p101_error *err, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = tgammal(x);

    // TODO - handle this properly
    if((math_errhandling & MATH_ERRNO) && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double p101_trunc(const struct p101_env *env, double x)
{
    double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = trunc(x);

    return ret_val;
}

float p101_truncf(const struct p101_env *env, float x)
{
    float ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = truncf(x);

    return ret_val;
}

long double p101_truncl(const struct p101_env *env, long double x)
{
    long double ret_val;

    P101_TRACE(env);
    errno = 0;
    ret_val = truncl(x);

    return ret_val;
}
