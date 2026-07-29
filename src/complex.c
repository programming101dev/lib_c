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

#include "p101_c/p101_complex.h"
#include "p101_c_internal.h"
#include <fenv.h>
#include <math.h>

static void complex_check(struct p101_error *err, int prior_exceptions);
static int  complex_prepare(void);

static int complex_prepare(void)
{
    int prior_exceptions;

    errno            = 0;
    prior_exceptions = 0;

    if((math_errhandling & MATH_ERREXCEPT) != 0)
    {
        prior_exceptions = fetestexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);
        (void)feclearexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);
    }

    return prior_exceptions;
}

static void complex_check(struct p101_error *err, int prior_exceptions)
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

double p101_cabs(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cabs(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_cabsf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cabsf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_cabsl(const struct p101_env *env, struct p101_error *err, long double complex z)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cabsl(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_cacos(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cacos(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_cacosf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cacosf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_cacosh(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cacosh(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_cacoshf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cacoshf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

long double complex p101_cacoshl(const struct p101_env *env, struct p101_error *err, long double complex z)
{
    long double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cacoshl(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

long double complex p101_cacosl(const struct p101_env *env, struct p101_error *err, long double complex z)
{
    long double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cacosl(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_carg(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = carg(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_cargf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cargf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_cargl(const struct p101_env *env, struct p101_error *err, long double complex z)
{
    long double ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cargl(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_casin(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = casin(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_casinf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = casinf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_casinh(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = casinh(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_casinhf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = casinhf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

long double complex p101_casinhl(const struct p101_env *env, struct p101_error *err, long double complex z)
{
    long double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = casinhl(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

long double complex p101_casinl(const struct p101_env *env, struct p101_error *err, long double complex z)
{
    long double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = casinl(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_catan(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = catan(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_catanf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = catanf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_catanh(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = catanh(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_catanhf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = catanhf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

long double complex p101_catanhl(const struct p101_env *env, struct p101_error *err, long double complex z)
{
    long double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = catanhl(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

long double complex p101_catanl(const struct p101_env *env, struct p101_error *err, long double complex z)
{
    long double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = catanl(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_ccos(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = ccos(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_ccosf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = ccosf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_ccosh(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = ccosh(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_ccoshf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = ccoshf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_cexp(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cexp(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_cexpf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cexpf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

long double complex p101_cexpl(const struct p101_env *env, struct p101_error *err, long double complex z)
{
    long double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cexpl(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_cimag(const struct p101_env *env, double complex z)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = cimag(z);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_cimagf(const struct p101_env *env, float complex z)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = cimagf(z);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_cimagl(const struct p101_env *env, long double complex z)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = cimagl(z);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_clog(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = clog(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_clogf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = clogf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

long double complex p101_clogl(const struct p101_env *env, struct p101_error *err, long double complex z)
{
    long double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = clogl(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_conj(const struct p101_env *env, double complex z)
{
    double complex ret_val;

    P101_TRACE(env);
    ret_val = conj(z);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_conjf(const struct p101_env *env, float complex z)
{
    float complex ret_val;

    P101_TRACE(env);
    ret_val = conjf(z);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double complex p101_conjl(const struct p101_env *env, long double complex z)
{
    long double complex ret_val;

    P101_TRACE(env);
    ret_val = conjl(z);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_cpow(const struct p101_env *env, struct p101_error *err, double complex x, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cpow(x, z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_cpowf(const struct p101_env *env, struct p101_error *err, float complex x, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cpowf(x, z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

long double complex p101_cpowl(const struct p101_env *env, struct p101_error *err, long double complex x, long double complex z)
{
    long double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = cpowl(x, z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_cproj(const struct p101_env *env, double complex z)
{
    double complex ret_val;

    P101_TRACE(env);
    ret_val = cproj(z);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_cprojf(const struct p101_env *env, float complex z)
{
    float complex ret_val;

    P101_TRACE(env);
    ret_val = cprojf(z);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double complex p101_cprojl(const struct p101_env *env, long double complex z)
{
    long double complex ret_val;

    P101_TRACE(env);
    ret_val = cprojl(z);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double p101_creal(const struct p101_env *env, double complex z)
{
    double ret_val;

    P101_TRACE(env);
    ret_val = creal(z);

    P101_TRACE_EXIT(env);

    return ret_val;
}

float p101_crealf(const struct p101_env *env, float complex z)
{
    float ret_val;

    P101_TRACE(env);
    ret_val = crealf(z);

    P101_TRACE_EXIT(env);

    return ret_val;
}

long double p101_creall(const struct p101_env *env, long double complex z)
{
    long double ret_val;

    P101_TRACE(env);
    ret_val = creall(z);

    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_csin(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = csin(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_csinf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = csinf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_csinh(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = csinh(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_csinhf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = csinhf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_csqrt(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = csqrt(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_csqrtf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = csqrtf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

long double complex p101_csqrtl(const struct p101_env *env, struct p101_error *err, long double complex z)
{
    long double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = csqrtl(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_ctan(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = ctan(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_ctanf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = ctanf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

double complex p101_ctanh(const struct p101_env *env, struct p101_error *err, double complex z)
{
    double complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = ctanh(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}

float complex p101_ctanhf(const struct p101_env *env, struct p101_error *err, float complex z)
{
    float complex ret_val;

    int prior_exceptions;

    P101_TRACE(env);
    P101_C_FAULT_RETURN(env, err, __func__ + 5, 0);
    prior_exceptions = complex_prepare();
    ret_val          = ctanhf(z);

    complex_check(err, prior_exceptions);
    P101_TRACE_EXIT(env);

    return ret_val;
}
