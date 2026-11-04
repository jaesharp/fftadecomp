#include "ffta.h"

/* 0x08089E1C..0x08089EB4: 152 bytes. */
typedef struct {
    u8 unknown_00[0x1C];
    u16 *tiles;
    u8 unknown_20[8];
    u8 stride;
} TileSurface;

typedef struct {
    s8 x;
    s8 y;
} TilePoint;

typedef struct {
    s32 x : 8;
    s32 y : 8;
    s32 width : 8;
    s32 height : 8;
} TileRect;

static inline void copy_row(const u16 *source, u16 *destination, s8 width)
{
    s32 column;

    for (column = 0; column < width; ++column)
        destination[column] = source[column];
}

void func_08089E1C(TileSurface *source, TileSurface *destination,
                   TilePoint point, TileRect rect)
{
    s32 row;

    for (row = 0; row < rect.height; ++row) {
        const u16 *source_row = source->tiles + point.x
            + (point.y + row) * source->stride;
        u16 *destination_row = destination->tiles + rect.x
            + (rect.y + row) * destination->stride;
        s32 width = rect.width;

        copy_row(source_row, destination_row, width);
    }
}
