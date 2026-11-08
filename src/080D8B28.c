#include "ffta.h"

extern int func_0801BB94(s16 x, s16 y, int first, int second, int third);

int func_080D8B28(s16 x, s16 y)
{
    u32 result = (u16)func_0801BB94(x, y, 4, 0x10, 4);

    return -result >> 31;
}
