#include "ffta.h"

typedef enum {
    FP_SNAN,
    FP_QNAN,
    FP_ZERO,
    FP_NUMBER,
    FP_INFINITY
} FloatClass;

typedef struct {
    FloatClass classification;
    u32 sign;
    s32 exponent;
    u32 fraction;
} UnpackedFloat;

extern void func_08143A84(const float *value, UnpackedFloat *parts);
extern float func_081439C8(const UnpackedFloat *parts);
extern UnpackedFloat data_03005E68;

static inline int is_nan(const UnpackedFloat *number)
{
    return number->classification == FP_SNAN || number->classification == FP_QNAN;
}

static inline int is_infinity(const UnpackedFloat *number)
{
    return number->classification == FP_INFINITY;
}

static inline int is_zero(const UnpackedFloat *number)
{
    return number->classification == FP_ZERO;
}

static inline UnpackedFloat *divide_parts(UnpackedFloat *numerator,
                                         UnpackedFloat *denominator)
{
    u32 dividend;
    u32 divisor;
    u32 bit;
    u32 quotient;

    if (is_nan(numerator))
        return numerator;
    if (is_nan(denominator))
        return denominator;

    numerator->sign ^= denominator->sign;
    if (is_infinity(numerator) || is_zero(numerator)) {
        if (numerator->classification == denominator->classification)
            return &data_03005E68;
        return numerator;
    }
    if (is_infinity(denominator)) {
        numerator->fraction = 0;
        numerator->exponent = 0;
        return numerator;
    }
    if (is_zero(denominator)) {
        numerator->classification = FP_INFINITY;
        return numerator;
    }

    numerator->exponent -= denominator->exponent;
    dividend = numerator->fraction;
    divisor = denominator->fraction;
    if (dividend < divisor) {
        dividend <<= 1;
        numerator->exponent--;
    }
    bit = 0x40000000;
    quotient = 0;
    while (bit != 0) {
        if (dividend >= divisor) {
            quotient |= bit;
            dividend -= divisor;
        }
        bit >>= 1;
        dividend <<= 1;
    }
    if ((quotient & 0x7F) == 0x40) {
        if ((quotient & 0x80) != 0 || dividend != 0)
            quotient += 0x40;
    }
    numerator->fraction = quotient;
    return numerator;
}

float func_08143E54(float left, float right)
{
    UnpackedFloat numerator;
    UnpackedFloat denominator;

    func_08143A84(&left, &numerator);
    func_08143A84(&right, &denominator);
    return func_081439C8(divide_parts(&numerator, &denominator));
}
