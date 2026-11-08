#include "ffta.h"

extern u8 g_state_02007F40[];

/* Complete [0x0801CAE0, 0x0801CB20): 64 bytes including the literal. */
void func_0801CAE0(s16 *out)
{
    s32 left, top, right, bottom;

    left = g_state_02007F40[0x2E] << 3;
    out[0] = left;
    top = g_state_02007F40[0x2F] << 3;
    out[1] = top;
    right = (g_state_02007F40[0x30] << 3) + 8;
    out[2] = right;
    bottom = (g_state_02007F40[0x31] << 3) + 8;
    out[3] = bottom;
    out[4] = right - left;
    out[5] = bottom - top;
}
