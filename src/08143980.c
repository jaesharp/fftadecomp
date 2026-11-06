#include "ffta.h"

typedef unsigned long long u64;

typedef struct {
    u32 kind;
    u32 sign;
    s32 exponent;
    u64 fraction;
} DoubleParts;

void func_08142D34(const double *value, DoubleParts *parts);
float func_08144314(u32 kind, u32 sign, s32 exponent, u32 fraction);

float func_08143980(double value)
{
    DoubleParts parts;
    u32 fraction;

    func_08142D34(&value, &parts);
    fraction = parts.fraction >> 30;
    if (parts.fraction & 0x3FFFFFFFULL)
        fraction |= 1;
    return func_08144314(parts.kind, parts.sign, parts.exponent, fraction);
}
