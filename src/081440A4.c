#include "ffta.h"

typedef struct {
    u32 kind;
    u32 sign;
    s32 exponent;
    u32 fraction;
} FloatParts081440A4;

void func_08143A84(const u32 *word, FloatParts081440A4 *parts);
s32 func_08143F44(const FloatParts081440A4 *first, const FloatParts081440A4 *second);

static inline s32 parts_are_nan(const FloatParts081440A4 *parts)
{
    return parts->kind <= 1;
}

/* 0x081440A4: complete 74-byte Thumb target. */
s32 func_081440A4(u32 first, u32 second)
{
    FloatParts081440A4 first_parts;
    FloatParts081440A4 second_parts;

    func_08143A84(&first, &first_parts);
    func_08143A84(&second, &second_parts);
    if (parts_are_nan(&first_parts) || parts_are_nan(&second_parts))
        return 1;
    return func_08143F44(&first_parts, &second_parts);
}
