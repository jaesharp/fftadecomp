#include "ffta.h"

typedef enum {
    CLASS_SNAN,
    CLASS_QNAN,
    CLASS_ZERO,
    CLASS_NUMBER,
    CLASS_INFINITY
} FloatClass08144188;

typedef struct {
    FloatClass08144188 category;
    u32 negative;
    s32 exponent;
    u32 significand;
} FloatParts08144188;

extern void func_08143A84(const u32 *representation, FloatParts08144188 *parts);
extern s32 func_08143F44(FloatParts08144188 *first, FloatParts08144188 *second);

static inline int is_nan_08144188(FloatParts08144188 *parts)
{
    return parts->category == CLASS_SNAN || parts->category == CLASS_QNAN;
}

/* Complete target [0x08144188, 0x081441D2): 74 bytes. */
s32 func_08144188(u32 first, u32 second)
{
    FloatParts08144188 first_parts, second_parts;

    func_08143A84(&first, &first_parts);
    func_08143A84(&second, &second_parts);
    if (is_nan_08144188(&first_parts) || is_nan_08144188(&second_parts))
        return 1;
    return func_08143F44(&first_parts, &second_parts);
}
