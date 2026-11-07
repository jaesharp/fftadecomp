#include "ffta.h"

/* Complete target 0x0814339C..0x08143528, 396 bytes.
 * The two helper entries establish two-word value transport and the decoded
 * fields at offsets 0, 4, 8, 12 and 16. Their numerical correctness and the
 * contents of the selected exceptional-value record are not assumed here.
 */
typedef unsigned long long Fraction0814339C;

enum Class0814339C {
    SignalingNaN0814339C,
    QuietNaN0814339C,
    Zero0814339C,
    Number0814339C,
    Infinity0814339C
};

typedef struct Decoded0814339C {
    enum Class0814339C kind;
    u32 sign;
    s32 exponent;
    Fraction0814339C fraction;
} Decoded0814339C;

extern const Decoded0814339C data_03005E50;
extern void func_08142D34(const double *value, Decoded0814339C *decoded);
extern double func_08142BE8(const Decoded0814339C *decoded);

static inline int is_nan_0814339C(const Decoded0814339C *value)
{
    return value->kind == SignalingNaN0814339C ||
           value->kind == QuietNaN0814339C;
}

static inline int is_infinite_0814339C(const Decoded0814339C *value)
{
    return value->kind == Infinity0814339C;
}

static inline int is_zero_0814339C(const Decoded0814339C *value)
{
    return value->kind == Zero0814339C;
}

/* The decoded calculation selects the record passed to the common pack call. */
static inline const Decoded0814339C *divide_parts_0814339C(
    Decoded0814339C *first, Decoded0814339C *second)
{
    Fraction0814339C dividend;
    Fraction0814339C divisor;
    Fraction0814339C bit;
    Fraction0814339C quotient;

    if (is_nan_0814339C(first))
        return first;
    if (is_nan_0814339C(second))
        return second;

    first->sign ^= second->sign;
    if (is_infinite_0814339C(first) || is_zero_0814339C(first)) {
        if (first->kind == second->kind)
            return &data_03005E50;
        return first;
    }
    if (is_infinite_0814339C(second)) {
        first->fraction = 0;
        first->exponent = 0;
        return first;
    }
    if (is_zero_0814339C(second)) {
        first->kind = Infinity0814339C;
        return first;
    }

    first->exponent -= second->exponent;
    dividend = first->fraction;
    divisor = second->fraction;
    if (dividend < divisor) {
        dividend <<= 1;
        first->exponent--;
    }
    bit = (Fraction0814339C)1 << 60;
    quotient = 0;
    while (bit != 0) {
        if (dividend >= divisor) {
            quotient |= bit;
            dividend -= divisor;
        }
        bit >>= 1;
        dividend <<= 1;
    }

    if ((quotient & 0xFF) == 0x80 &&
        ((quotient & 0x100) != 0 || dividend != 0))
        quotient += 0x80;
    first->fraction = quotient;
    return first;
}

double func_0814339C(double numerator, double denominator)
{
    Decoded0814339C first;
    Decoded0814339C second;

    func_08142D34(&numerator, &first);
    func_08142D34(&denominator, &second);
    return func_08142BE8(divide_parts_0814339C(&first, &second));
}
