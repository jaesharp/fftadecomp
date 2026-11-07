#include "ffta.h"

struct FloatParts {
    u32 classification;
    u32 sign;
    s32 exponent;
    u32 fraction;
};

extern void func_08143A84(const float *, struct FloatParts *);
extern struct FloatParts *func_08143B04(const struct FloatParts *,
                                      const struct FloatParts *,
                                      struct FloatParts *);
extern float func_081439C8(const struct FloatParts *);

float func_08143CB4(float first, float second)
{
    struct FloatParts left;
    struct FloatParts right;
    struct FloatParts result;

    func_08143A84(&first, &left);
    func_08143A84(&second, &right);
    right.sign ^= 1;
    return func_081439C8(func_08143B04(&left, &right, &result));
}
