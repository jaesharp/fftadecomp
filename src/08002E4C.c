#include "ffta.h"

/* Complete [0x08002E4C, 0x08002ECA): 126 bytes. */
void func_08002E4C(s16 value, u16 *output, u16 flags)
{
    u8 sign;
    s32 remaining;

    if (value < 0) {
        value = -value;
        sign = '-';
    } else {
        sign = ' ';
    }
    output += 6;
    *output-- = 0;
    remaining = 6;
    do {
        *output-- = (value % 10 + '0') | flags;
        remaining--;
        value /= 10;
    } while (value);
    *output-- = sign | flags;
    remaining--;
    while (remaining) {
        *output-- = ' ' | flags;
        remaining--;
    }
}
