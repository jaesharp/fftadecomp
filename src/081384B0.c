#include "ffta.h"

typedef struct {
    u8 unknown_00[0x10];
    const void *second;
    const void *first;
} Sources081384B0;

typedef struct {
    u8 unknown_00[0x10];
    u16 *tiles;
} Buffers081384B0;

typedef struct {
    u8 unknown_00[0x0e];
    u16 tile;
    u8 unknown_10[8];
    u16 *first_plane;
    u16 *second_plane;
    u8 unknown_20[8];
    u8 stride;
    u8 height;
    u8 unknown_2a[10];
    u8 x;
    u8 y;
    u8 unknown_36[22];
} Window081384B0;

extern Sources081384B0 *data_030027D8;
extern Buffers081384B0 data_03002740;
extern Window081384B0 data_030009E0[];
extern u8 data_02003CB0[];
extern u8 data_0600C120[];

void *func_0808A268(s32 index, u8 kind, const void *first,
    const void *second, u16 *first_tiles, u16 *second_tiles,
    void *third, void *fourth, u8 left, u8 top, u8 width, u8 height,
    u8 x, u8 y, u8 first_width, u8 first_height, u8 second_width,
    u8 second_height);
void func_0814186C(const void *source, void *destination, u32 control);
void func_08016344(u16 *tiles, u8 width, u8 height, u16 flags,
                   u8 stride, u16 tile, u8 palette);
void func_08016560(u16 *tiles, u8 width, u8 height, u16 flags,
                   u8 stride, u16 tile, u8 palette);
u16 *func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
u32 func_08018524(u8 *buffer, u16 tile, u8 variant);
void func_08035678(u16 value, u16 *destination, u32 count, u16 step);

void func_081384B0(u32 enabled)
{
    u8 *buffer = data_02003CB0;
    u16 zero;
    u16 *destination;
    u32 count;

    func_0808A268(4, 12, data_030027D8->first, data_030027D8->second,
                  data_03002740.tiles, data_03002740.tiles + 182, 0, 0,
                  2, 5, 13, 14, 2, 5, 13, 14, 13, 14);
    data_030009E0[4].x = 2;
    data_030009E0[4].y = 5;
    data_030009E0[4].tile = 521;
    zero = 0;
    func_0814186C(&zero, data_0600C120, 0x01000600);
    func_08016344(data_030009E0[4].second_plane,
                  data_030009E0[4].stride, data_030009E0[4].height,
                  0xc0, data_030009E0[4].stride, 5, 12);
    func_08016560(data_030009E0[4].first_plane, 13, 14,
                  0xc0, 13, 1, 12);
    if (enabled) {
        u16 value = 0xc03e;
        destination = func_0808B8E4(4, 1, 1, 1);
        count = func_08018524(buffer, 0x3e, 0x1f);
        func_08035678(value, destination, count, 1);
    }
}
