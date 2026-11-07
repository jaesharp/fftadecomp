#include "ffta.h"

typedef struct {
    u32 classification;
    u32 sign;
    s32 exponent;
    u32 fraction_low;
    u32 fraction_high;
} Number081430B4;

/* Conditional interfaces from the complete unpack, combine and pack entries. */
extern void func_08142D34(const double *value, Number081430B4 *number);
extern const Number081430B4 *func_08142E10(const Number081430B4 *first,
                                        const Number081430B4 *second,
                                        Number081430B4 *result);
extern double func_08142BE8(const Number081430B4 *number);

double func_081430B4(double first, double second)
{
    Number081430B4 first_number;
    Number081430B4 second_number;
    Number081430B4 result;

    func_08142D34(&first, &first_number);
    func_08142D34(&second, &second_number);
    second_number.sign ^= 1;
    return func_08142BE8(func_08142E10(&first_number, &second_number, &result));
}
