#include "ffta.h"

typedef enum
{
    CLASS_SNAN,
    CLASS_QNAN,
    CLASS_ZERO,
    CLASS_NUMBER,
    CLASS_INFINITY
} FloatCategory;

typedef struct
{
    FloatCategory category;
    u32 negative;
    s32 exponent;
    u32 significand;
} FloatParts;

void func_08143A84(const float *representation, FloatParts *parts);
int func_08143F44(FloatParts *left, FloatParts *right);

static inline int is_nan(FloatParts *parts)
{
    return parts->category == CLASS_SNAN || parts->category == CLASS_QNAN;
}

/* Complete target: 0x081440F0..0x0814413C, 76 bytes. */
int func_081440F0(float left, float right)
{
    FloatParts left_parts;
    FloatParts right_parts;

    func_08143A84(&left, &left_parts);
    func_08143A84(&right, &right_parts);
    if (is_nan(&left_parts) || is_nan(&right_parts))
        return -1;
    return func_08143F44(&left_parts, &right_parts);
}
