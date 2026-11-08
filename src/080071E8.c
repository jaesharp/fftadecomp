#include "ffta.h"

extern const s16 g_table_08149568[];

/* Complete target [0x080071E8, 0x08007234), 76 bytes. */
s16 func_080071E8(s16 degrees)
{
    s32 angle = degrees;

    while ((u32)angle > 359) {
        if (angle < 0)
            angle += 360;
        if (angle > 359)
            angle -= 360;
    }
    angle = (angle << 8) / 360;
    return g_table_08149568[angle];
}
