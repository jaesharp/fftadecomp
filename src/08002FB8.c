#include "ffta.h"

/* Six right-aligned decimal characters followed by a zero terminator. */
void func_08002FB8(s16 value, u8 *text)
{
    s32 remaining;

    text += 6;
    *text-- = 0;
    remaining = 6;
    do {
        s32 low_bit = value & 1;
        s32 half = (u16)value >> 1;
        *text-- = half % 5 * 2 + low_bit + '0';
        remaining--;
        value = half / 5;
    } while (value != 0);
    while (--remaining != -1)
        *text-- = ' ';
}
