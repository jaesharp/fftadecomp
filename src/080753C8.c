#include "ffta.h"

typedef struct {
    u8 unknown_00[0x0C];
    u16 *first_resource;
    u8 unknown_10[4];
    u16 *second_resource;
    u16 *third_resource;
} ResourceContext;

typedef struct {
    u8 unknown_00[8];
    u16 *first_tiles;
    u16 *second_tiles;
} TileStorage;

typedef struct {
    u8 unknown_00[0x18];
    u16 *first_plane;
    u16 *second_plane;
    u8 unknown_20[8];
    u8 width;
    u8 height;
    u8 unknown_2A[6];
    u8 left, top, right, bottom;
    u8 x, y;
    u8 unknown_36[0x16];
} TileWindow;

extern ResourceContext *data_03002818;
extern TileStorage data_03002740;
extern TileWindow data_030009E0[];
extern const u16 data_0894FD14[];

void *func_0808A268(s32 index, u8 priority, u16 *first_resource,
                    u16 *second_resource, u16 *first_tiles,
                    u16 *second_tiles, u16 *first_buffer,
                    u16 *second_buffer, u8 x, u8 y, u8 width,
                    u8 height, u8 source_x, u8 source_y,
                    u8 source_width, u8 source_height,
                    u8 stride, u8 rows);
void func_0814186C(const void *source, void *destination, u32 control);
u16 *func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
void func_0808B7C0(s32 index, u16 *destination, u16 tile,
                   u16 count, u16 flags);
void func_08035678(u16 value, u16 *destination, u32 count, u16 step);

/* Complete target: [0x080753C8, 0x08075574), 428 bytes. */
void func_080753C8(void)
{
    func_0808A268(2, 3, data_03002818->first_resource,
                  data_03002818->first_resource,
                  data_03002740.first_tiles, data_03002740.first_tiles,
                  0, 0, 0, 0, 32, 9, 0, 0, 32, 9, 32, 9);
    data_030009E0[2].x = 0;
    data_030009E0[2].y = 0xF8;
    data_030009E0[2].left = 0;
    data_030009E0[2].top = 0;
    data_030009E0[2].right = 32;
    data_030009E0[2].bottom = 9;
    func_0814186C(data_0894FD14, data_030009E0[2].second_plane, 0x120);
    func_0808B7C0(2, func_0808B8E4(2, 1, 6, 2), 0x177, 12, 0xC000);
    func_0808B7C0(2, func_0808B8E4(2, 1, 6, 4), 0x18F, 12, 0xC000);
    func_08035678(0xF14E, func_0808B8E4(2, 1, 9, 0), 2, 1);
    func_08035678(0xF150, func_0808B8E4(2, 1, 9, 1), 2, 1);
    func_08035678(0xE09E, func_0808B8E4(2, 1, 13, 0), 2, 1);
    func_08035678(0xE0A0, func_0808B8E4(2, 1, 13, 1), 2, 1);

    func_0808A268(3, 12, data_03002818->third_resource,
                  data_03002818->second_resource,
                  data_03002740.second_tiles,
                  data_03002740.second_tiles + 0xC0,
                  0, 0, 0, 7, 16, 12, 0, 7, 16, 12, 16, 12);
    data_030009E0[3].x = 0;
    data_030009E0[3].y = 7;
    data_030009E0[3].left = 0;
    data_030009E0[3].top = 7;
    data_030009E0[3].right = 16;
    data_030009E0[3].bottom = 19;
}
