#include "ffta.h"

typedef struct {
    u8 unknown_00[0x90];
    u16 *second_resource;
    u16 *first_resource;
} ResourceContext;

typedef struct {
    u8 unknown_00[0x14];
    u16 *tiles;
} WindowBuffers;

typedef struct {
    u8 unknown_00[0x0e];
    u16 tile;
    u8 unknown_10[8];
    u16 *first_plane;
    u16 *second_plane;
    u8 unknown_20[8];
    u8 width;
    u8 height;
    u8 unknown_2a[2];
    u8 columns;
    u8 rows;
    u8 unknown_2e[0x1e];
} Window;

extern ResourceContext *g_state_03002810;
extern WindowBuffers data_03002740;
extern Window data_030009E0[];
extern u8 data_02003CB0[];
extern u8 data_0600AFE0[];

extern void func_0808A268(u32 index, u32 mode, u16 *first_resource,
    u16 *second_resource, u16 *first_tiles, u16 *second_tiles,
    u32 first_offset, u32 second_offset, u32 x, u32 y, u32 width, u32 height,
    u32 source_x, u32 source_y, u32 source_width, u32 source_height,
    u32 stride, u32 rows);
extern void func_08016344(u16 *destination, u8 width, u8 height, u16 flags,
    u8 stride, u16 tile, u8 palette);
extern void func_08016560(u16 *destination, u8 width, u8 height, u16 flags,
    u8 stride, u16 tile, u8 palette);
extern u16 *func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
extern u32 func_08018524(u8 *buffer, u16 tile, u8 variant);
extern void func_08035678(u16 value, u16 *destination, u32 count, u16 step);
extern void func_0808B7C0(int index, u16 *destination, u16 tile, u16 count,
    u16 flags);
extern void func_0814186C(const void *source, void *destination, u32 control);

void func_08045668(void)
{
    u8 *buffer = data_02003CB0;
    u16 *destination;
    u32 count;
    int row;
    u16 tile;
    u16 fill;
    u16 *source;

    func_0808A268(5, 12, g_state_03002810->first_resource,
        g_state_03002810->second_resource, data_03002740.tiles,
        data_03002740.tiles + 0x134, 0, 0,
        1, 9, 28, 11, 1, 9, 28, 11, 28, 11);
    func_08016344(data_030009E0[5].second_plane,
        data_030009E0[5].width, data_030009E0[5].height, 0xc0,
        data_030009E0[5].width, 5, 12);
    func_08016560(data_030009E0[5].first_plane, 28, 11, 0xc0, 28, 1, 12);
    tile = 0xc03e;
    destination = func_0808B8E4(5, 1, 1, 1);
    count = func_08018524(buffer, 0x3e, 0x11);
    func_08035678(tile, destination, count, 1);
    data_030009E0[5].tile = 0x17f;
    data_030009E0[5].columns = 26;
    data_030009E0[5].rows = 8;
    for (row = 0; row < 8; row += 2)
        func_0808B7C0(5, func_0808B8E4(5, 1, 1, row + 2),
            row * 26 + 0x17f, 26, 0xc000);
    source = &fill;
    *source = 0;
    func_0814186C(source, data_0600AFE0, 0x01000d00);
}
