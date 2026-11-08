#include "ffta.h"

/* 0x08002C50..0x08002C6C: 28 bytes, 14 instructions. */
u16 func_08002C50(const u16 *text)
{
    u16 length = 0;

    while (*text++)
        ++length;
    return length;
}
