#ifndef LIBP101_C_P101_MATH_H
#define LIBP101_C_P101_MATH_H

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

#include <p101_env/env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    double      p101_acos(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_acosf(const struct p101_env *env, struct p101_error *err, float x);
    double      p101_acosh(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_acoshf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_acoshl(const struct p101_env *env, struct p101_error *err, long double x);
    long double p101_acosl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_asin(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_asinf(const struct p101_env *env, struct p101_error *err, float x);
    double      p101_asinh(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_asinhf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_asinhl(const struct p101_env *env, struct p101_error *err, long double x);
    long double p101_asinl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_atan(const struct p101_env *env, struct p101_error *err, double x);
    double      p101_atan2(const struct p101_env *env, struct p101_error *err, double y, double x);
    float       p101_atan2f(const struct p101_env *env, struct p101_error *err, float y, float x);
    long double p101_atan2l(const struct p101_env *env, struct p101_error *err, long double y, long double x);
    float       p101_atanf(const struct p101_env *env, struct p101_error *err, float x);
    double      p101_atanh(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_atanhf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_atanhl(const struct p101_env *env, struct p101_error *err, long double x);
    long double p101_atanl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_cbrt(const struct p101_env *env, double x);
    float       p101_cbrtf(const struct p101_env *env, float x);
    long double p101_cbrtl(const struct p101_env *env, long double x);
    double      p101_ceil(const struct p101_env *env, double x);
    float       p101_ceilf(const struct p101_env *env, float x);
    long double p101_ceill(const struct p101_env *env, long double x);
    double      p101_copysign(const struct p101_env *env, double x, double y);
    float       p101_copysignf(const struct p101_env *env, float x, float y);
    long double p101_copysignl(const struct p101_env *env, long double x, long double y);
    double      p101_cos(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_cosf(const struct p101_env *env, struct p101_error *err, float x);
    double      p101_cosh(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_coshf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_coshl(const struct p101_env *env, struct p101_error *err, long double x);
    long double p101_cosl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_erf(const struct p101_env *env, struct p101_error *err, double x);
    double      p101_erfc(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_erfcf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_erfcl(const struct p101_env *env, struct p101_error *err, long double x);
    float       p101_erff(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_erfl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_exp(const struct p101_env *env, struct p101_error *err, double x);
    double      p101_exp2(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_exp2f(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_exp2l(const struct p101_env *env, struct p101_error *err, long double x);
    float       p101_expf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_expl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_expm1(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_expm1f(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_expm1l(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_fabs(const struct p101_env *env, double x);
    float       p101_fabsf(const struct p101_env *env, float x);
    long double p101_fabsl(const struct p101_env *env, long double x);
    double      p101_fdim(const struct p101_env *env, struct p101_error *err, double x, double y);
    float       p101_fdimf(const struct p101_env *env, struct p101_error *err, float x, float y);
    long double p101_fdiml(const struct p101_env *env, struct p101_error *err, long double x, long double y);
    double      p101_floor(const struct p101_env *env, double x);
    float       p101_floorf(const struct p101_env *env, float x);
    long double p101_floorl(const struct p101_env *env, long double x);
    double      p101_fma(const struct p101_env *env, struct p101_error *err, double x, double y, double z);
    float       p101_fmaf(const struct p101_env *env, struct p101_error *err, float x, float y, float z);
    long double p101_fmal(const struct p101_env *env, struct p101_error *err, long double x, long double y, long double z);
    double      p101_fmax(const struct p101_env *env, double x, double y);
    float       p101_fmaxf(const struct p101_env *env, float x, float y);
    long double p101_fmaxl(const struct p101_env *env, long double x, long double y);
    double      p101_fmin(const struct p101_env *env, double x, double y);
    float       p101_fminf(const struct p101_env *env, float x, float y);
    long double p101_fminl(const struct p101_env *env, long double x, long double y);
    double      p101_fmod(const struct p101_env *env, struct p101_error *err, double x, double y);
    float       p101_fmodf(const struct p101_env *env, struct p101_error *err, float x, float y);
    long double p101_fmodl(const struct p101_env *env, struct p101_error *err, long double x, long double y);
    double      p101_frexp(const struct p101_env *env, double num, int *exp);
    float       p101_frexpf(const struct p101_env *env, float num, int *exp);
    long double p101_frexpl(const struct p101_env *env, long double num, int *exp);
    double      p101_hypot(const struct p101_env *env, struct p101_error *err, double x, double y);
    float       p101_hypotf(const struct p101_env *env, struct p101_error *err, float x, float y);
    long double p101_hypotl(const struct p101_env *env, struct p101_error *err, long double x, long double y);
    int         p101_ilogb(const struct p101_env *env, struct p101_error *err, double x);
    int         p101_ilogbf(const struct p101_env *env, struct p101_error *err, float x);
    int         p101_ilogbl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_ldexp(const struct p101_env *env, struct p101_error *err, double x, int exp);
    float       p101_ldexpf(const struct p101_env *env, struct p101_error *err, float x, int exp);
    long double p101_ldexpl(const struct p101_env *env, struct p101_error *err, long double x, int exp);
    double      p101_lgamma(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_lgammaf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_lgammal(const struct p101_env *env, struct p101_error *err, long double x);
    long long   p101_llrint(const struct p101_env *env, struct p101_error *err, double x);
    long long   p101_llrintf(const struct p101_env *env, struct p101_error *err, float x);
    long long   p101_llrintl(const struct p101_env *env, struct p101_error *err, long double x);
    long long   p101_llround(const struct p101_env *env, struct p101_error *err, double x);
    long long   p101_llroundf(const struct p101_env *env, struct p101_error *err, float x);
    long long   p101_llroundl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_log(const struct p101_env *env, struct p101_error *err, double x);
    double      p101_log10(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_log10f(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_log10l(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_log1p(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_log1pf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_log1pl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_log2(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_log2f(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_log2l(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_logb(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_logbf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_logbl(const struct p101_env *env, struct p101_error *err, long double x);
    float       p101_logf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_logl(const struct p101_env *env, struct p101_error *err, long double x);
    long        p101_lrint(const struct p101_env *env, struct p101_error *err, double x);
    long        p101_lrintf(const struct p101_env *env, struct p101_error *err, float x);
    long        p101_lrintl(const struct p101_env *env, struct p101_error *err, long double x);
    long        p101_lround(const struct p101_env *env, struct p101_error *err, double x);
    long        p101_lroundf(const struct p101_env *env, struct p101_error *err, float x);
    long        p101_lroundl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_modf(const struct p101_env *env, double x, double *iptr);
    float       p101_modff(const struct p101_env *env, float value, float *iptr);
    long double p101_modfl(const struct p101_env *env, long double value, long double *iptr);
    double      p101_nan(const struct p101_env *env, const char *tagp);
    float       p101_nanf(const struct p101_env *env, const char *tagp);
    long double p101_nanl(const struct p101_env *env, const char *tagp);
    double      p101_nearbyint(const struct p101_env *env, double x);
    float       p101_nearbyintf(const struct p101_env *env, float x);
    long double p101_nearbyintl(const struct p101_env *env, long double x);
    double      p101_nextafter(const struct p101_env *env, struct p101_error *err, double x, double y);
    float       p101_nextafterf(const struct p101_env *env, struct p101_error *err, float x, float y);
    long double p101_nextafterl(const struct p101_env *env, struct p101_error *err, long double x, long double y);
    double      p101_nexttoward(const struct p101_env *env, struct p101_error *err, double x, long double y);
    float       p101_nexttowardf(const struct p101_env *env, struct p101_error *err, float x, long double y);
    long double p101_nexttowardl(const struct p101_env *env, struct p101_error *err, long double x, long double y);
    double      p101_pow(const struct p101_env *env, struct p101_error *err, double x, double y);
    float       p101_powf(const struct p101_env *env, struct p101_error *err, float x, float y);
    long double p101_powl(const struct p101_env *env, struct p101_error *err, long double x, long double y);
    double      p101_remainder(const struct p101_env *env, struct p101_error *err, double x, double y);
    float       p101_remainderf(const struct p101_env *env, struct p101_error *err, float x, float y);
    long double p101_remainderl(const struct p101_env *env, struct p101_error *err, long double x, long double y);
    double      p101_remquo(const struct p101_env *env, struct p101_error *err, double x, double y, int *quo);
    float       p101_remquof(const struct p101_env *env, struct p101_error *err, float x, float y, int *quo);
    long double p101_remquol(const struct p101_env *env, struct p101_error *err, long double x, long double y, int *quo);
    double      p101_rint(const struct p101_env *env, double x);
    float       p101_rintf(const struct p101_env *env, float x);
    long double p101_rintl(const struct p101_env *env, long double x);
    double      p101_round(const struct p101_env *env, double x);
    float       p101_roundf(const struct p101_env *env, float x);
    long double p101_roundl(const struct p101_env *env, long double x);
    double      p101_scalbln(const struct p101_env *env, struct p101_error *err, double x, long n);
    float       p101_scalblnf(const struct p101_env *env, struct p101_error *err, float x, long n);
    long double p101_scalblnl(const struct p101_env *env, struct p101_error *err, long double x, long n);
    double      p101_scalbn(const struct p101_env *env, struct p101_error *err, double x, int n);
    float       p101_scalbnf(const struct p101_env *env, struct p101_error *err, float x, int n);
    long double p101_scalbnl(const struct p101_env *env, struct p101_error *err, long double x, int n);
    double      p101_sin(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_sinf(const struct p101_env *env, struct p101_error *err, float x);
    double      p101_sinh(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_sinhf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_sinhl(const struct p101_env *env, struct p101_error *err, long double x);
    long double p101_sinl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_sqrt(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_sqrtf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_sqrtl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_tan(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_tanf(const struct p101_env *env, struct p101_error *err, float x);
    double      p101_tanh(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_tanhf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_tanhl(const struct p101_env *env, struct p101_error *err, long double x);
    long double p101_tanl(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_tgamma(const struct p101_env *env, struct p101_error *err, double x);
    float       p101_tgammaf(const struct p101_env *env, struct p101_error *err, float x);
    long double p101_tgammal(const struct p101_env *env, struct p101_error *err, long double x);
    double      p101_trunc(const struct p101_env *env, double x);
    float       p101_truncf(const struct p101_env *env, float x);
    long double p101_truncl(const struct p101_env *env, long double x);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_C_P101_MATH_H
