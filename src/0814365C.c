#include "ffta.h"

/* Target: complete [0x0814365C, 0x081436AA), 78 bytes. */
typedef struct {
    u32 classification;
    u32 sign;
    s32 exponent;
    u32 fraction_low;
    u32 fraction_high;
} Number0814365C;

extern void func_08142D34(const double *value, Number0814365C *number);
extern s32 func_08143528(const Number0814365C *first,
                         const Number0814365C *second);

static inline s32 number_is_nan(const Number0814365C *number)
{
    s32 result = 0;

    if (number->classification <= 1)
        result = 1;
    return result;
}

s32 func_0814365C(double first, double second)
{
    Number0814365C first_number;
    Number0814365C second_number;

    func_08142D34(&first, &first_number);
    func_08142D34(&second, &second_number);
    if (number_is_nan(&first_number) || number_is_nan(&second_number))
        return 1;
    return func_08143528(&first_number, &second_number);
}
