#include "ffta.h"

extern u16 func_08148384(u16 color, u16 red_scale, u16 green_scale, u16 blue_scale);

/* Complete [0x0814774C, 0x081477DC): 144 bytes, 68 instructions. */
void func_0814774C(const u16 *source, u16 *destination, u16 count)
{
    u16 i;

    for (i = 0; i < count; i++) {
        u16 color = source[i];
        u16 red = color & 0x1F;
        u16 green = (color & 0x3E0) >> 5;
        u16 blue = (color & 0x7C00) >> 10;
        u16 gray = (red + green + blue) / 3;

        destination[i] = gray | (gray << 5) | (gray << 10);
    }
    for (i = 0; i < count; i++)
        destination[i] = func_08148384(destination[i], 0x126, 0x111, 0xCC);
}
