#include "ffta.h"

typedef struct NumberParts08143930 {
    u32 kind;
    u32 sign;
    s32 exponent;
    u32 fraction_low;
    u32 fraction_high;
} NumberParts08143930;

extern void func_08142D34(const double *, NumberParts08143930 *);
extern double func_08142BE8(const NumberParts08143930 *);

/* Complete indexed owner:0x08143930..0x08143958. */
double func_08143930(double value)
{
    NumberParts08143930 parts;

    func_08142D34(&value, &parts);
    parts.sign = !parts.sign;
    return func_08142BE8(&parts);
}
