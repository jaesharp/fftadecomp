#include "ffta.h"

typedef struct {
    u32 category;
    u32 sign;
    s32 exponent;
    u32 fraction[2];
} ExpandedNumber;

extern void func_08142D34(const double *value, ExpandedNumber *expanded);
extern ExpandedNumber *func_08142E10(ExpandedNumber *first,
                                    ExpandedNumber *second,
                                    ExpandedNumber *result);
extern double func_08142BE8(const ExpandedNumber *expanded);

/* Target 0x08143080, 52 bytes: 10b593b00f901091119212930fa86946fff750fe11a805ac211cfff74bfe0aaa6846211cfff7b4fefff79efd13b010bc04bc1047 */
double func_08143080(double first, double second)
{
    ExpandedNumber first_expanded;
    ExpandedNumber second_expanded;
    ExpandedNumber result;

    func_08142D34(&first, &first_expanded);
    func_08142D34(&second, &second_expanded);
    return func_08142BE8(func_08142E10(&first_expanded,
                                     &second_expanded, &result));
}
