#include "ffta.h"

/* Five observed words shared by the unpack and comparison interfaces. */
typedef struct {
    u32 classification;
    u32 sign;
    s32 exponent;
    u32 fraction_low;
    u32 fraction_high;
} Number0814362C;

/* Conditional views from the complete entries and the by-value root transport. */
extern void func_08142D34(const double *value, Number0814362C *number);
extern s32 func_08143528(const Number0814362C *first,
                         const Number0814362C *second);

s32 func_0814362C(double first, double second)
{
    Number0814362C first_number;
    Number0814362C second_number;

    func_08142D34(&first, &first_number);
    func_08142D34(&second, &second_number);
    return func_08143528(&first_number, &second_number);
}
