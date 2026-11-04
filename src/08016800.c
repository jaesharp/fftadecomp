#include "ffta.h"

/* 0x08016800 .. 0x0801692A: 298 bytes. */
void func_08016800(void *destination, u8 width, u8 height, u16 flags,
                   u8 stride, u16 border_tile, u16 fill_tile, u8 palette)
{
    u16 *buffer;
    u16 tile;
    u16 right;
    u16 bottom;
    u16 offset;
    s32 index;
    u16 *top_right;
    u16 *bottom_row;

    if (width < 2 || height < 2)
        return;

    buffer = destination;
    tile = border_tile + (palette << 12);
    right = width - 1;
    bottom = stride * (height - 1);
    buffer[0] = tile;
    top_right = (u16 *)(right * sizeof(u16) + (u32)buffer);
    *top_right = tile + 1;
    bottom_row = (u16 *)(bottom * sizeof(u16) + (u32)buffer);
    *bottom_row = tile + 2;
    top_right[bottom] = tile + 3;

    for (index = 1; index < width - 1; index++) {
        buffer[index] = tile + 6;
        buffer[bottom + index] = tile + 7;
    }

    offset = 0;
    for (index = 1; index < height - 1; index++) {
        u16 *row;
        offset += stride;
        row = (u16 *)(offset * sizeof(u16) + (u32)buffer);
        row[0] = tile + 4;
        *(u16 *)((u8 *)row + right * sizeof(u16)) = tile + 5;
    }

    tile = fill_tile + (palette << 12);
    {
        u16 columns = width - 2;
        u16 rows = height - 2;
        s32 row;

        buffer += stride + 1;
        for (row = rows; row != 0; row--) {
            for (index = 0; index < columns; index++)
                buffer[index] = tile;
            buffer += stride;
        }
    }
}
