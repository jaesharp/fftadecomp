#include "ffta.h"

extern s32 func_0812F704(void *actor, u16 alternate);
extern u32 func_08002804(void);
extern s32 func_081426B8(s32 value, s32 divisor);
extern s32 func_08142950(s32 value, s32 divisor);

/* Complete 0813010C..08130150: 68 bytes, 30 reached instructions. */
s32 func_0813010C(s32 value, void *actor, u8 fixed)
{
    value -= func_0812F704(actor, 1) >> 1;
    if (fixed == 0) {
        s32 radius = func_081426B8(value, 10);
        if (radius < 0)
            radius = -radius;
        value += func_08142950((s16)func_08002804(), radius * 2 + 1) - radius;
    }
    return value;
}
