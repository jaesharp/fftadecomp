#include "ffta.h"

struct DoubleParts {
    u32 kind;
    u32 sign;
    s32 exponent;
    u32 fraction[2];
};

extern void func_08142D34(const double *, struct DoubleParts *);
extern s32 func_08143528(const struct DoubleParts *, const struct DoubleParts *);

static inline int is_nan(const struct DoubleParts *parts)
{
    return parts->kind == 0 || parts->kind == 1;
}

s32 func_081436AC(double first, double second)
{
    struct DoubleParts first_parts;
    struct DoubleParts second_parts;

    func_08142D34(&first, &first_parts);
    func_08142D34(&second, &second_parts);
    if (is_nan(&first_parts) || is_nan(&second_parts))
        return 1;
    return func_08143528(&first_parts, &second_parts);
}
