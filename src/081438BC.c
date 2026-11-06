#include "ffta.h"

/* Target: complete [0x081438BC, 0x08143930), 116 bytes. */
typedef unsigned long long Fraction;

typedef enum {
    CLASS_SNAN,
    CLASS_QNAN,
    CLASS_ZERO,
    CLASS_NUMBER,
    CLASS_INFINITY
} NumberClass;

typedef struct {
    NumberClass class;
    u32 sign;
    s32 normal_exp;
    union {
        Fraction ll;
        u32 words[2];
    } fraction;
} NumberParts;

extern void func_08142D34(const double *source, NumberParts *parts);

static inline int iszero(NumberParts *number)
{
    return number->class == CLASS_ZERO;
}

static inline int isnan(NumberParts *number)
{
    return number->class == CLASS_SNAN || number->class == CLASS_QNAN;
}

static inline int isinf(NumberParts *number)
{
    return number->class == CLASS_INFINITY;
}

s32 func_081438BC(double value)
{
    NumberParts number;
    s32 result;

    func_08142D34(&value, &number);
    if (iszero(&number))
        return 0;
    if (isnan(&number))
        return 0;
    if (isinf(&number))
        return number.sign ? (-0x7FFFFFFF - 1) : 0x7FFFFFFF;
    if (number.normal_exp < 0)
        return 0;
    if (number.normal_exp > 30)
        return number.sign ? (-0x7FFFFFFF - 1) : 0x7FFFFFFF;

    result = number.fraction.ll >> (60 - number.normal_exp);
    return number.sign ? -result : result;
}
