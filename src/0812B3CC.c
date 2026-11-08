#include "ffta.h"

extern s32 func_081426B8(s32 numerator, s32 denominator);
extern s16 func_08007A60(u8 angle);

/* Complete target [0x0812B3CC, 0x0812B41A), 78 bytes. */
s16 func_0812B3CC(u16 time, u16 duration, u16 start, u16 end)
{
    s16 from = start;
    s16 to = end;
    s16 weight;

    if (time >= duration)
        return to;
    weight = func_08007A60(func_081426B8(time << 6, duration));
    return from + (((to - from) * (0x100 - weight)) >> 8);
}
