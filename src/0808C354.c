#include "ffta.h"

/* Complete 0x0808C354..0x0808C53C: 488 bytes. */
typedef struct {
    u8 unknown_00[0x0c];
    u16 *first_resource;
    u8 unknown_10[4];
    u16 *second_resource;
} ResourceContext;

typedef struct {
    u8 unknown_00[0x18];
    u16 *tiles;
} TileStorage;

typedef struct {
    u8 unknown_00;
    u8 mode;
    u8 unknown_02[0x0c];
    u16 attributes;
    u8 unknown_10[8];
    u16 *second_plane;
    u16 *first_plane;
    u8 unknown_20[8];
    u8 width;
    u8 height;
    u8 unknown_2a[0x0a];
    u8 x;
    u8 y;
    u8 unknown_36[0x12];
    u8 source_x;
    u8 source_y;
    u8 source_width;
    u8 source_height;
} TileRenderer;

extern ResourceContext *data_03002818;
extern TileStorage data_03002740;
extern TileRenderer data_030009E0[];
extern void *func_0808A268(u32 index, u32 mode, u16 *first_resource,
    u16 *second_resource, u16 *first_tiles, u16 *second_tiles,
    u16 *first_buffer, u16 *second_buffer, u32 x, u32 y, u32 width,
    u32 height, u32 source_x, u32 source_y, u32 source_width,
    u32 source_height, u32 stride, u32 rows);
extern void func_0808AA18(u32 index);
extern void func_08016800(void *, u8, u8, u16, u8, u16, u16, u8);
extern u16 *func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
extern void func_0808B7C0(s32 index, u16 *, u16 tile, u16 count, u16 flags);
extern void func_0808B80C(s32 index, u16 *, u16 tile, u16 count, u16 flags);

void func_0808C354(void)
{
    func_0808A268(6, 12, data_03002818->first_resource,
        data_03002818->second_resource, data_03002740.tiles,
        data_03002740.tiles + 0xea, data_03002740.tiles + 0x1d4,
        data_03002740.tiles + 0x2be,
        0, 1, 13, 18, 0, 1, 13, 18, 13, 18);
    func_0808AA18(6);
    data_030009E0[6].x = 0xf4;
    data_030009E0[6].y = 1;
    data_030009E0[6].attributes = 0x30d;
    data_030009E0[6].mode = 0;
    data_030009E0[6].source_x = 1;
    data_030009E0[6].source_y = 1;
    data_030009E0[6].source_width = 11;
    data_030009E0[6].source_height = 8;
    func_08016800(data_030009E0[6].second_plane,
        data_030009E0[6].width, data_030009E0[6].height, 0x800,
        data_030009E0[6].width, 13, 3, 11);
    func_0808B7C0(6, func_0808B8E4(6, 1, 1, 1), 0x30d, 11, 0xb000);
    func_0808B7C0(6, func_0808B8E4(6, 1, 1, 5), 0x323, 11, 0xb000);
    func_0808B7C0(6, func_0808B8E4(6, 1, 1, 9), 0x339, 11, 0xb000);
    func_0808B7C0(6, func_0808B8E4(6, 1, 1, 13), 0x34f, 11, 0xb000);
    func_0808B80C(6, func_0808B8E4(6, 1, 1, 7), 0x365, 4, 0xc000);
    func_0808B80C(6, func_0808B8E4(6, 1, 1, 11), 0x36d, 4, 0xc000);
    func_0808B80C(6, func_0808B8E4(6, 1, 1, 15), 0x375, 4, 0xc000);
    func_0808B7C0(6, func_0808B8E4(6, 1, 7, 3), 0x37d, 5, 0xe000);
}
