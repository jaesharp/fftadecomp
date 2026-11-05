#include "ffta.h"

typedef struct {
    u8 unknown_00[0x14];
    u16 *second_plane;
    u16 *first_plane;
    u8 unknown_1c[0x2d50 - 0x1c];
    void *resource_2d50;
} ResourceContext;

typedef struct {
    u8 unknown_00[0x14];
    u16 *first_tiles;
} TileStorage;

typedef struct {
    u8 unknown_00;
    u8 mode;
    u8 unknown_02[0x0c];
    u16 attributes;
    u8 unknown_10[8];
    u16 *second_text;
    u16 *first_text;
    u8 unknown_20[8];
    u8 text_x;
    u8 text_y;
    u8 unknown_2a[0x0a];
    u8 x;
    u8 y;
    u8 unknown_36[0x12];
    u8 source_x;
    u8 source_y;
    u8 width;
    u8 height;
} TileRenderer;

extern ResourceContext *data_03002818;
extern TileStorage data_03002740;
extern TileRenderer data_030009E0[];
extern u8 data_02003CB0[];
extern u8 data_0600C520[];

extern void *func_0808A268(u32 index, u8 mode, u16 *first_resource,
    u16 *second_resource, u16 *first_tiles, u16 *second_tiles,
    u32 first_offset, u32 second_offset, u8 x, u8 y, u8 width, u8 height,
    u8 source_x, u8 source_y, u8 source_width, u8 source_height,
    u8 stride, u8 rows);
extern void func_0808136C(u32 slot, void *resource, u32 renderer,
    u32 column, u32 row, u8 mode);
extern void func_08016344(u16 *, u8, u8, u16, u8, u16, u8);
extern void func_08016560(u16 *, u8, u8, u16, u8, u16, u8);
extern u16 *func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
extern void func_0808B858(int index, u16 *destination, u16 tile, u16 count);
extern u32 func_08018524(u8 *buffer, u16 tile, u8 variant);
extern void func_08035678(u16 value, u16 *destination, u32 count, u16 step);
extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete 404-byte owner, including both literal pools. */
void func_0807DC24(int mode)
{
    u8 *buffer = data_02003CB0;
    u16 fill;
    int row;

    if (mode == 2) {
        for (row = 0; row < 5; row++)
            func_0808B858(5, func_0808B8E4(5, 1, 0, 2 + row * 2), 0, 14);
    } else {
        func_0808A268(5, 12, data_03002818->first_plane,
            data_03002818->second_plane, data_03002740.first_tiles,
            data_03002740.first_tiles + 0xb6, 0, 0,
            2, 6, 14, 13, 2, 6, 14, 13, 14, 13);
        data_030009E0[5].x = 2;
        data_030009E0[5].y = 6;
        if (mode == 0) {
            fill = 0;
            func_0814186C(&fill, data_0600C520, 0x01000900);
        }
        data_030009E0[5].attributes = 0x229;
        data_030009E0[5].mode = 0;
        data_030009E0[5].source_x = 1;
        data_030009E0[5].source_y = 1;
        data_030009E0[5].width = 12;
        data_030009E0[5].height = 12;
        if (mode == 0)
            func_0808136C(0, data_03002818->resource_2d50, 5, 0, 0, 0);
        func_08016344(data_030009E0[5].first_text,
            data_030009E0[5].text_x, data_030009E0[5].text_y,
            0xc0, data_030009E0[5].text_x, 5, 12);
        func_08016560(data_030009E0[5].second_text, 14, 13, 0xc0, 14, 1, 12);
        func_08035678(0xc044, func_0808B8E4(5, 1, 1, 1),
            func_08018524(buffer, 0x44, 4), 1);
    }
}
