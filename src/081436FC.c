#include "ffta.h"

typedef struct
{
    u32 classification;
    u32 sign;
    s32 exponent;
    u32 fraction_low;
    u32 fraction_high;
} DoubleParts;

void func_08142D34(const double *representation, DoubleParts *parts);
s32 func_08143528(const DoubleParts *first, const DoubleParts *second);

static inline s32 number_is_nan(const DoubleParts *number)
{
    s32 result = 0;

    if (number->classification <= 1)
        result = 1;
    return result;
}

/* Complete target: 0x081436FC..0x0814374C, 80 bytes. */
s32 func_081436FC(double first, double second)
{
    DoubleParts first_parts;
    DoubleParts second_parts;

    func_08142D34(&first, &first_parts);
    func_08142D34(&second, &second_parts);
    if (number_is_nan(&first_parts) || number_is_nan(&second_parts))
        return -1;
    return func_08143528(&first_parts, &second_parts);
}
