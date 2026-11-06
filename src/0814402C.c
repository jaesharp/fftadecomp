#include "ffta.h"

typedef struct {
    u32 kind;
    u32 sign;
    s32 exponent;
    u32 fraction;
} FloatParts0814402C;

void func_08143A84(const u32 *word, FloatParts0814402C *parts);
s32 func_08143F44(const FloatParts0814402C *first, const FloatParts0814402C *second);

/* 0x0814402C: complete 42-byte Thumb target. */
s32 func_0814402C(u32 first, u32 second)
{
    FloatParts0814402C first_parts;
    FloatParts0814402C second_parts;

    func_08143A84(&first, &first_parts);
    func_08143A84(&second, &second_parts);
    return func_08143F44(&first_parts, &second_parts);
}
