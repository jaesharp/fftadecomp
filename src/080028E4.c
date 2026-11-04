#include "ffta.h"

/* Complete target [0x080028E4, 0x08002950): 108 bytes. */
s16 func_080028E4(const u8 *text)
{
    s16 negative = 0;
    s16 value = 0;
    const u16 digit_bias = -'0';

    while (*text == '\t' || *text == ' ')
        text++;
    if (*text == '-') {
        negative = 1;
        text++;
    }
    while ((u8)(*text - '0') <= 9) {
        value = value * 10 + (*text + digit_bias);
        text++;
    }
    if (negative)
        return -value;
    return value;
}
