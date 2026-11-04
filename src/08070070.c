#include "ffta.h"

struct TileRegion {
    u8 unknown_00[0xC];
    u16 *source;
    u8 unknown_10[3];
    u8 destination_x;
    u8 destination_y;
    u8 source_stride;
    u8 unknown_16[8];
    u8 destination_stride;
};

void func_08070070(struct TileRegion *region, u16 *destination, u8 x, u8 y, u8 width, u8 height)
{
    u16 row;
    u16 column;

    for (row = 0; row < height; row++) {
        u32 destination_stride = region->destination_stride;
        u16 destination_row = (row + region->destination_y + y) * destination_stride;
        u32 source_stride = region->source_stride;
        u16 source_row = (row + y) * source_stride;

        for (column = 0; column < width; column++)
            destination[destination_row + column + region->destination_x + x] = region->source[source_row + column + x];
    }
}
