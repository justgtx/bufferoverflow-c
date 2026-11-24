#ifndef SECRET_H
#define SECRET_H

#include <stdint.h>
#include <stddef.h>

#define KEY_MAX 100

// 0b0110101010111110101000101111111  xor key /
static const uint32_t hash = 0x355F517FU;
    
static const char original_key[] = "Flag:two_wrongs_don't_m@ke_@_";

/* XOR each byte of `in` with the bytes of `h`, cycling. `out` must hold
 * at least strlen(in)+1 bytes. Applying it twice returns the original. */
static void xor_hash(const char *in, uint32_t h, char *out, size_t n)
{
    size_t i;
    for (i = 0; i < n; i++) {
        out[i] = (char)((unsigned char)in[i] ^ (unsigned char)(h >> (8 * (i % 4))));
    }
    out[n] = '\0';
}

#endif