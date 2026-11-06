/* 0x0814432C: unpack a single-precision value for double-precision packing. */
#include "ffta.h"

typedef unsigned long long u64;

typedef struct FloatParts {
    u32 classification;
    u32 sign;
    s32 exponent;
    u32 fraction;
} FloatParts;

extern void func_08143A84(const float *, FloatParts *);
extern double func_08143958(u32, u32, s32, u64);

double func_0814432C(float value)
{
    FloatParts parts;

    func_08143A84(&value, &parts);
    return func_08143958(parts.classification, parts.sign, parts.exponent,
                         (u64)parts.fraction << 30);
}
