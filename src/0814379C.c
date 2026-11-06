#include "ffta.h"

/* Target: complete [0x0814379C, 0x081437EA), 78 bytes. */
typedef struct {
    u32 classification;
    u32 sign;
    s32 exponent;
    u32 fraction_low;
    u32 fraction_high;
} Number;

extern void func_08142D34(const double *value, Number *number);
extern s32 func_08143528(const Number *first, const Number *second);

static inline s32 number_is_nan(const Number *number)
{
    s32 result = 0;

    if (number->classification <= 1)
        result = 1;
    return result;
}

s32 func_0814379C(double first, double second)
{
    Number first_number;
    Number second_number;

    func_08142D34(&first, &first_number);
    func_08142D34(&second, &second_number);
    if (number_is_nan(&first_number) || number_is_nan(&second_number))
        return 1;
    return func_08143528(&first_number, &second_number);
}
