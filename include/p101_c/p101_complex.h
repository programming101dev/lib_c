#ifndef LIBP101_C_P101_COMPLEX_H
#define LIBP101_C_P101_COMPLEX_H

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

#include <complex.h>
#include <p101_env/env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    double              p101_cabs(const struct p101_env *env, double complex z);
    float               p101_cabsf(const struct p101_env *env, float complex z);
    long double         p101_cabsl(const struct p101_env *env, long double complex z);
    double complex      p101_cacos(const struct p101_env *env, double complex z);
    float complex       p101_cacosf(const struct p101_env *env, float complex z);
    double complex      p101_cacosh(const struct p101_env *env, double complex z);
    float complex       p101_cacoshf(const struct p101_env *env, float complex z);
    long double complex p101_cacoshl(const struct p101_env *env, long double complex z);
    long double complex p101_cacosl(const struct p101_env *env, long double complex z);
    double              p101_carg(const struct p101_env *env, double complex z);
    float               p101_cargf(const struct p101_env *env, float complex z);
    long double         p101_cargl(const struct p101_env *env, long double complex z);
    double complex      p101_casin(const struct p101_env *env, double complex z);
    float complex       p101_casinf(const struct p101_env *env, float complex z);
    double complex      p101_casinh(const struct p101_env *env, double complex z);
    float complex       p101_casinhf(const struct p101_env *env, float complex z);
    long double complex p101_casinhl(const struct p101_env *env, long double complex z);
    long double complex p101_casinl(const struct p101_env *env, long double complex z);
    double complex      p101_catan(const struct p101_env *env, double complex z);
    float complex       p101_catanf(const struct p101_env *env, float complex z);
    double complex      p101_catanh(const struct p101_env *env, double complex z);
    float complex       p101_catanhf(const struct p101_env *env, float complex z);
    long double complex p101_catanhl(const struct p101_env *env, long double complex z);
    long double complex p101_catanl(const struct p101_env *env, long double complex z);
    double complex      p101_ccos(const struct p101_env *env, double complex z);
    float complex       p101_ccosf(const struct p101_env *env, float complex z);
    double complex      p101_ccosh(const struct p101_env *env, double complex z);
    float complex       p101_ccoshf(const struct p101_env *env, float complex z);
    double complex      p101_cexp(const struct p101_env *env, double complex z);
    float complex       p101_cexpf(const struct p101_env *env, float complex z);
    long double complex p101_cexpl(const struct p101_env *env, long double complex z);
    double              p101_cimag(const struct p101_env *env, double complex z);
    float               p101_cimagf(const struct p101_env *env, float complex z);
    long double         p101_cimagl(const struct p101_env *env, long double complex z);
    double complex      p101_clog(const struct p101_env *env, double complex z);
    float complex       p101_clogf(const struct p101_env *env, float complex z);
    long double complex p101_clogl(const struct p101_env *env, long double complex z);
    double complex      p101_conj(const struct p101_env *env, double complex z);
    float complex       p101_conjf(const struct p101_env *env, float complex z);
    long double complex p101_conjl(const struct p101_env *env, long double complex z);
    double complex      p101_cpow(const struct p101_env *env, double complex x, double complex z);
    float complex       p101_cpowf(const struct p101_env *env, float complex x, float complex z);
    long double complex p101_cpowl(const struct p101_env *env, long double complex x, long double complex z);
    double complex      p101_cproj(const struct p101_env *env, double complex z);
    float complex       p101_cprojf(const struct p101_env *env, float complex z);
    long double complex p101_cprojl(const struct p101_env *env, long double complex z);
    double              p101_creal(const struct p101_env *env, double complex z);
    float               p101_crealf(const struct p101_env *env, float complex z);
    long double         p101_creall(const struct p101_env *env, long double complex z);
    double complex      p101_csin(const struct p101_env *env, double complex z);
    float complex       p101_csinf(const struct p101_env *env, float complex z);
    double complex      p101_csinh(const struct p101_env *env, double complex z);
    float complex       p101_csinhf(const struct p101_env *env, float complex z);
    double complex      p101_csqrt(const struct p101_env *env, double complex z);
    float complex       p101_csqrtf(const struct p101_env *env, float complex z);
    long double complex p101_csqrtl(const struct p101_env *env, long double complex z);
    double complex      p101_ctan(const struct p101_env *env, double complex z);
    float complex       p101_ctanf(const struct p101_env *env, float complex z);
    double complex      p101_ctanh(const struct p101_env *env, double complex z);
    float complex       p101_ctanhf(const struct p101_env *env, float complex z);

#ifdef __cplusplus
}
#endif

// Not on FreeBSD
// long double complex p101_ccoshl(const struct p101_env *env, long double complex z);
// long double complex p101_ccosl(const struct p101_env *env, long double complex z);
// long double complex p101_csinhl(const struct p101_env *env, long double complex z);
// long double complex p101_csinl(const struct p101_env *env, long double complex z);
// long double complex p101_ctanhl(const struct p101_env *env, long double complex z);
// long double complex p101_ctanl(const struct p101_env *env, long double complex z);

#endif    // LIBP101_C_P101_COMPLEX_H
