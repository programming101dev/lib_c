/*
 * libFuzzer harness for lib_c's checked contracts.
 *
 * The wrappers themselves are compiled into this target, so ASan and UBSan
 * instrument the code under test rather than only the harness. Arbitrary input
 * exercises numeric conversion, multibyte conversion, checked division,
 * allocation ownership, formatting, and strerror ownership.
 */
#include <limits.h>
#include <p101_c/p101_inttypes.h>
#include <p101_c/p101_stdatomic.h>
#include <p101_c/p101_stdio.h>
#include <p101_c/p101_stdlib.h>
#include <p101_c/p101_string.h>
#include <p101_c/p101_wchar.h>
#include <p101_env/env.h>
#include <p101_error/error.h>
#include <stdatomic.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

enum
{
    MAX_FUZZ_TEXT = 4096
};

static int bytes_to_int(const uint8_t *data, size_t size)
{
    unsigned int value;

    value = 0;
    if(size > 0)
    {
        value = data[0];
    }
    if(size > 1)
    {
        value |= (unsigned int)data[1] << 8U;
    }

    return (int)(value & (unsigned int)INT_MAX);
}

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    struct p101_error *err;
    struct p101_env   *env;
    atomic_uint        atomic_value;
    mbstate_t          conversion_state;
    char               formatted[64];
    char               text[MAX_FUZZ_TEXT + 1];
    char              *end;
    char              *message;
    void              *memory;
    size_t             allocation_size;
    int                numerator;
    int                denominator;

    if(size > MAX_FUZZ_TEXT)
    {
        return 0;
    }

    memcpy(text, data, size);
    text[size] = '\0';
    err        = p101_error_create(false);
    if(err == NULL)
    {
        return 0;
    }
    env = p101_env_create(err, NULL);
    if(env == NULL)
    {
        p101_error_destroy(err);
        return 0;
    }

    (void)p101_strtol(env, err, text, &end, 0);
    p101_error_reset(err);
    (void)p101_strtoumax(env, err, text, &end, 0);
    p101_error_reset(err);
    (void)p101_wcstol(env, err, L"123", NULL, 10);
    p101_error_reset(err);

    numerator   = bytes_to_int(data, size);
    denominator = (size > 2) ? (int)(int8_t)data[2] : 0;
    (void)p101_div(env, err, numerator, denominator);
    p101_error_reset(err);
    (void)p101_imaxdiv(env, err, numerator, denominator);
    p101_error_reset(err);

    memset(&conversion_state, 0, sizeof(conversion_state));
    (void)p101_mbrlen(env, err, text, size, &conversion_state);
    p101_error_reset(err);

    allocation_size = (size % 256U) + 1U;
    memory          = p101_malloc(env, err, allocation_size);
    if(memory != NULL)
    {
        memset(memory, 0xA5, allocation_size);
        p101_free(env, memory);
    }
    p101_error_reset(err);

    message = p101_strerror(env, err, numerator);
    if(message != NULL)
    {
        p101_free(env, message);
    }
    p101_error_reset(err);

    (void)p101_snprintf(env, err, formatted, sizeof(formatted), "%s", text);
    p101_error_reset(err);

    atomic_init(&atomic_value, (unsigned int)numerator);
    (void)p101_atomic_uint_fetch_xor(env, &atomic_value, (unsigned int)denominator);

    p101_env_destroy(env);
    p101_error_destroy(err);

    return 0;
}
