#include "ffta.h"

typedef struct {
    u32 classification;
    u32 sign;
    s32 exponent;
    u32 fraction_low;
    u32 fraction_high;
} Number0814374C;

extern void func_08142D34(const double *source, Number0814374C *parts);
extern s32 func_08143528(const Number0814374C *first,
                         const Number0814374C *second);

static inline s32 number_is_nan(const Number0814374C *number)
{
    s32 result = 0;

    if (number->classification <= 1)
        result = 1;
    return result;
}

s32 func_0814374C(double first, double second)
{
    Number0814374C first_parts;
    Number0814374C second_parts;

    func_08142D34(&first, &first_parts);
    func_08142D34(&second, &second_parts);
    if (number_is_nan(&first_parts) || number_is_nan(&second_parts))
        return -1;
    return func_08143528(&first_parts, &second_parts);
}
