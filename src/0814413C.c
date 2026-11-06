#include "ffta.h"

typedef struct {
    u32 significand : 23;
    u32 exponent : 8;
    u32 negative : 1;
} FloatRepresentation;

typedef enum {
    CLASS_SNAN,
    CLASS_QNAN,
    CLASS_ZERO,
    CLASS_NUMBER,
    CLASS_INFINITY
} fp_class_type;

typedef struct {
    fp_class_type class;
    u32 sign;
    s32 normal_exp;
    union {
        u32 ll;
        u16 l[2];
    } fraction;
} fp_number_type;

static inline int isnan(fp_number_type *value)
{
    return value->class == CLASS_SNAN || value->class == CLASS_QNAN;
}

extern void func_08143A84(const FloatRepresentation *representation,
                        fp_number_type *parts);
extern int func_08143F44(fp_number_type *first, fp_number_type *second);

int func_0814413C(FloatRepresentation first, FloatRepresentation second)
{
    fp_number_type first_parts;
    fp_number_type second_parts;

    func_08143A84(&first, &first_parts);
    func_08143A84(&second, &second_parts);
    if (isnan(&first_parts) || isnan(&second_parts))
        return -1;
    return func_08143F44(&first_parts, &second_parts);
}
