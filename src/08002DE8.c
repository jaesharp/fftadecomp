#include "ffta.h"

/* Complete [0x08002DE8, 0x08002E4C): 100 bytes. */
void func_08002DE8(s16 value, u8 *output)
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
        *output-- = value % 10 + '0';
        remaining--;
        value /= 10;
    } while (value);
    *output-- = sign;
    remaining--;
    while (remaining) {
        *output-- = ' ';
        remaining--;
    }
}
