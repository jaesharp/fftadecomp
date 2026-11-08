#include "ffta.h"

/* Right-aligned signed decimal tiles with a fixed-width sign field. */
void func_08002F34(s16 value, u16 *text, u16 attributes, u8 width)
{
    u8 sign;
    u16 sign_tile;
    s32 remaining;

    if (value < 0) {
        value = -value;
        sign = '-';
    } else {
        sign = ' ';
    }
    text += width;
    *text-- = 0;
    remaining = width;
    sign_tile = sign | attributes;
    do {
        *text-- = (value % 10 + '0') | attributes;
        remaining--;
        value /= 10;
    } while (value != 0);
    *text-- = sign_tile;
    while (--remaining != 0)
        *text-- = ' ' | attributes;
}
