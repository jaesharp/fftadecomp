#include "ffta.h"

extern u8 func_080CDA4C(const void *object);
extern s32 func_0812FE38(const void *, const void *, u16, u16, u16, u8, u8);
extern s32 func_080C7EA4(const void *, u32);
extern u32 func_08142AB0(u32, u32);
extern u32 func_08002804(void);
extern s32 func_08142950(s32, s32);

/* Complete [0x0813054C, 0x08130620): 212 bytes, 98 instructions.
 * Calls use conditional structural ABI views from the saved complete entries. */
s32 func_0813054C(const void *source, const void *target, u32 unused,
                  u16 selection, u8 flags)
{
    s32 value;
    s32 adjustment;
    u8 mode;

    if (func_080CDA4C(target))
        return 0;
    mode = 2;
    value = func_0812FE38(source, target, 0, selection, 0, mode, 0);
    adjustment = func_08142AB0(func_080C7EA4(source, 6), 10);
    if (adjustment <= 0)
        adjustment = 1;
    if (value == 0)
        adjustment = 0;
    if (value < 0)
        adjustment = -adjustment;
    if (!(flags & mode)) {
        if (value > 0)
            adjustment += (s16)func_08142950((s16)func_08002804(), 11);
        else if (value < 0)
            adjustment -= (s16)func_08142950((s16)func_08002804(), 11);
    }
    if (adjustment < -(value < 0 ? -value : value))
        adjustment = -(value < 0 ? -value : value);
    if (adjustment > (value < 0 ? -value : value))
        adjustment = value < 0 ? -value : value;
    return adjustment;
}
