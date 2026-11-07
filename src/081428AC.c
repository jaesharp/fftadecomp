#include "ffta.h"

/* Target: 56 bytes. */
u32 func_081428AC(float value)
{
    u32 result;

    if (value < 2147483648.0f)
        result = (s32)value;
    else
        result = (u32)(s32)(value + -2147483648.0f) + 0x80000000u;
    return result;
}
