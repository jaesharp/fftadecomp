#include "ffta.h"

typedef struct {
    u8 unknown_00[0x0c];
    u16 *large_second;
    u16 *large_first;
    u16 *small_second;
    u16 *small_first;
} ResourceContext;

typedef struct {
    u8 unknown_00[8];
    u16 *first;
    u32 unknown_0c;
    u16 *second;
} WindowBuffers;

typedef struct {
    u8 unknown_00[0x18];
    u16 *first_plane;
    u16 *second_plane;
    u8 unknown_20[8];
    u8 stride;
    u8 unknown_29[7];
    u8 x;
    u8 y;
    u8 right;
    u8 bottom;
    u8 source_x;
    u8 source_y;
    u8 unknown_36[0x16];
} Window;

extern ResourceContext *data_03002818;
extern WindowBuffers data_03002740;
extern Window data_030009E0[];
extern const u16 data_0894FB1C[];
extern const u16 data_0894FC18[];

extern void func_0808A268(u32 index, u32 mode, u16 *first_resource,
    u16 *second_resource, u16 *first_tiles, u16 *second_tiles,
    u32 first_offset, u32 second_offset, u32 x, u32 y, u32 width, u32 height,
    u32 source_x, u32 source_y, u32 source_width, u32 source_height,
    u32 stride, u32 rows);
extern u16 *func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
extern void func_0808B7C0(int index, u16 *destination, u16 tile, u16 count,
                        u16 flags);
extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete owner: 292 bytes including pools, 124 reached instructions. */
void func_080735E0(void)
{
    u16 zero;

    func_0808A268(2, 12, data_03002818->small_first,
        data_03002818->small_second, data_03002740.first,
        data_03002740.first + 0x7e, 0, 0,
        0, 2, 18, 7, 0, 2, 18, 7, 18, 7);
    data_030009E0[2].source_x = 0xee;
    data_030009E0[2].source_y = 2;
    data_030009E0[2].x = 0;
    data_030009E0[2].y = 2;
    data_030009E0[2].right = 18;
    data_030009E0[2].bottom = 9;
    func_0814186C(data_0894FB1C, data_030009E0[2].second_plane, 0x7e);
    func_0814186C(data_0894FC18, data_030009E0[2].first_plane, 0x7e);
    func_0808B7C0(2, func_0808B8E4(2, 1, 6, 0), 0x177, 12, 0xc000);
    func_0808A268(4, 12, data_03002818->small_first,
        data_03002818->small_second, data_03002740.second,
        data_03002740.second + 0x1e, 0, 0,
        0, 0, 30, 1, 0, 0, 30, 1, 30, 1);
    data_030009E0[4].source_x = 0;
    data_030009E0[4].source_y = 0;
    zero = 0;
    func_0814186C(&zero, data_030009E0[4].first_plane, 0x0100000f);
}
