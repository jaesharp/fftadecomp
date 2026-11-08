#include "ffta.h"

typedef struct {
    u8 unknown_00[0x14];
    u16 *tiles;
} DecimalTileWindow;

void func_08029688(DecimalTileWindow *window, u8 x, u8 y, u8 width,
                   u32 number, u8 palette)
{
    u8 i;

    for (i = 0; i < width; i++) {
        window->tiles[y * 32 + x + (width - i)] =
            (number % 10 + 30) | (palette << 12);
        number /= 10;
        if (number == 0) {
            for (i++; i < width; i++)
                window->tiles[y * 32 + x + (width - i)] = 0;
            break;
        }
    }
}
