#include "ffta.h"

typedef struct
{
    u32 significand : 23;
    u32 exponent : 8;
    u32 negative : 1;
} FloatRepresentation;

typedef enum
{
    CLASS_SNAN,
    CLASS_QNAN,
    CLASS_ZERO,
    CLASS_NUMBER,
    CLASS_INFINITY
} FloatClass;

typedef struct
{
    FloatClass category;
    u32 negative;
    s32 exponent;
    u32 significand;
} FloatParts;

void func_08143A84(const FloatRepresentation *, FloatParts *);
int func_08143F44(FloatParts *, FloatParts *);

static inline int is_nan(FloatParts *parts)
{
    return parts->category == CLASS_SNAN || parts->category == CLASS_QNAN;
}

/* Complete target: 0x08144058..0x081440A2, 74 bytes. */
int func_08144058(FloatRepresentation a, FloatRepresentation b)
{
    FloatParts a_parts;
    FloatParts b_parts;

    func_08143A84(&a, &a_parts);
    func_08143A84(&b, &b_parts);
    if (is_nan(&a_parts) || is_nan(&b_parts))
        return 1;
    return func_08143F44(&a_parts, &b_parts);
}
