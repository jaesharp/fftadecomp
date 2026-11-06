#include "ffta.h"

typedef struct FloatParts081441D4 {
    u32 kind;
    u32 sign;
    s32 exponent;
    u32 fraction;
} FloatParts081441D4;

extern void func_08143A84(const u32 *word, FloatParts081441D4 *parts);
extern s32 func_08143F44(const FloatParts081441D4 *first,
                       const FloatParts081441D4 *second);

static inline s32 parts_are_nan(const FloatParts081441D4 *parts)
{
    return parts->kind <= 1;
}

/* Complete indexed owner: 0x081441D4..0x0814421E (74 bytes). */
s32 func_081441D4(u32 first, u32 second)
{
    FloatParts081441D4 first_parts;
    FloatParts081441D4 second_parts;

    func_08143A84(&first, &first_parts);
    func_08143A84(&second, &second_parts);
    if (parts_are_nan(&first_parts) || parts_are_nan(&second_parts))
        return 1;
    return func_08143F44(&first_parts, &second_parts);
}
