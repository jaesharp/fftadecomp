#include "ffta.h"

/* Complete [0x08002ECC, 0x08002F34): 104 bytes. */
void func_08002ECC(s16 value, u8 *output, u8 width)
{
    u8 sign;
    s32 remaining;

    if (value < 0) {
        value = -value;
        sign = '-';
    } else {
        sign = ' ';
    }
    output += width;
    *output-- = 0;
    remaining = width;
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
