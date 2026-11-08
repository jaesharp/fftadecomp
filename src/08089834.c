#include "ffta.h"

/* Render a fixed-width decimal number into tile entries; target 170 bytes. */
extern const u16 data_08393D2A[];

void func_08089834(u16 *output, u16 style, u16 number, u16 digits,
                   u16 leading_zeroes, u16 tile_base)
{
    u16 *destination = output;
    u16 digit_base = 40;
    u16 leading;
    const u16 *place;
    u16 i;

    if (style == 0)
        digit_base = 30;
    leading = leading_zeroes == 1 ? digit_base : 0;
    place = &data_08393D2A[digits];

    for (i = 0; i < digits - 1; i++, place--) {
        u16 digit = (u32)number % place[0];
        digit = (s32)digit / (s32)place[3];
        if (digit != 0) {
            *destination++ = digit + digit_base + tile_base;
            leading = digit_base;
        } else {
            *destination++ = leading + tile_base;
        }
    }
    *destination = (u32)number % 10 + digit_base + tile_base;
}
