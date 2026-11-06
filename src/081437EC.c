#include "ffta.h"

typedef struct {
    u32 classification;
    u32 sign;
    s32 exponent;
    u32 fraction_low;
    u32 fraction_high;
} Number081437EC;

/* Conditional interfaces from the complete incoming accesses of both helpers. */
extern void func_08142D34(const double *value, Number081437EC *number);
extern s32 func_08143528(const Number081437EC *first,
                         const Number081437EC *second);

/* Shared classification predicate from the published comparison family. */
static inline s32 number_is_nan(const Number081437EC *number)
{
    s32 result = 0;

    if (number->classification <= 1)
        result = 1;
    return result;
}

/* Complete [0x081437EC,0x0814383A): 78 bytes.
 * Each incoming eight-byte value is passed by address to the unpack helper.
 * The five observed output words form each20-byte comparison record.
 * Conditional transport only, no numeric result or complete initialization,
 * helper effects, readability, bounds or termination theorem asserted.
 */
s32 func_081437EC(double first, double second)
{
    Number081437EC first_number;
    Number081437EC second_number;

    func_08142D34(&first, &first_number);
    func_08142D34(&second, &second_number);
    if (number_is_nan(&first_number) || number_is_nan(&second_number))
        return 1;
    return func_08143528(&first_number, &second_number);
}
