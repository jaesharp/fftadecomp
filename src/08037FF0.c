#include "ffta.h"

typedef struct {
    u16 *primary;
    u16 *secondary;
    u8 unknown_08[8];
    u8 x;
    u8 y;
    u8 outerWidth;
    u8 unknown_13;
    u16 value;
    u8 stride;
    u8 mode;
    u16 first;
    u16 last;
    u8 flags;
    u8 unknown_1D[2];
    u8 alignment;
    u16 width;
    u16 height;
    s16 expectedWidth;
    s16 expectedHeight;
} TileRegion;

typedef struct {
    u8 unknown_00[0x4C];
    TileRegion region;
    u8 unknown_74[0x58];
} RegionRecord08037FF0;

typedef struct {
    u8 unknown_000[0x954];
    RegionRecord08037FF0 records[0];
} Context08037FF0;

extern Context08037FF0 *g_state_03002810;
extern u8 func_08017180(TileRegion *region);

/* Target: complete [0x08037FF0, 0x08038014), 36 bytes. */
u8 func_08037FF0(u32 index)
{
    return func_08017180(&g_state_03002810->records[index].region);
}
