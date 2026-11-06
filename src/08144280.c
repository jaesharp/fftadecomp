#include "ffta.h"

typedef struct {
    u32 significand : 23;
    u32 exponent : 8;
    u32 negative : 1;
} FloatRepresentation;

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
        u32 ll;
        u16 words[2];
    } fraction;
} FloatParts;

extern void func_08143A84(const FloatRepresentation *source, FloatParts *parts);

static inline int iszero(FloatParts *number)
{
    return number->class == CLASS_ZERO;
}

static inline int isnan(FloatParts *number)
{
    return number->class == CLASS_SNAN || number->class == CLASS_QNAN;
}

static inline int isinf(FloatParts *number)
{
    return number->class == CLASS_INFINITY;
}

s32 func_08144280(FloatRepresentation value)
{
    FloatParts number;
    s32 result;

    func_08143A84(&value, &number);
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
    result = number.fraction.ll >> (30 - number.normal_exp);
    return number.sign ? -result : result;
}
