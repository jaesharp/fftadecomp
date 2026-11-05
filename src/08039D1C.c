#include "ffta.h"

/* Complete 0x08039D1C..0x08039DF4: 216 bytes. */
typedef struct {
    u8 unknown_00[0x90];
    u16 *second_resource;
    u16 *first_resource;
} Resources08039D1C;

typedef struct {
    u8 unknown_00[0x18];
    u16 *first_plane;
    u16 *second_plane;
    u8 unknown_20[8];
    u8 stride;
    u8 rows;
    u8 unknown_2A[0x22];
} Window08039D1C;

extern Resources08039D1C *g_state_03002810;
extern u8 *data_03002740[];
extern Window08039D1C data_030009E0[];
extern u16 data_0600AFE0[];

extern void *func_0808A268(s32 index, u8 mode,
    u16 *first_resource, u16 *second_resource,
    u8 *first_tiles, u8 *second_tiles, u8 *first_text, u8 *second_text,
    u8 x, u8 y, u8 width, u8 height,
    u8 source_x, u8 source_y, u8 source_width, u8 source_height,
    u8 stride, u8 rows);
extern void func_08016344(u16 *, u8, u8, u16, u8, u16, u8);
extern void func_08016560(u16 *, u8, u8, u16, u8, u16, u8);
extern void func_0814186C(const void *, void *, u32);
extern u16 *func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
extern void func_0808B7C0(s32 index, u16 *, u16 tile, u16 count, u16 flags);
extern u32 func_0808A604(s32 index, u16 mode);

void func_08039D1C(void)
{
    u16 clear;

    func_0808A268(5, 12, g_state_03002810->first_resource,
        g_state_03002810->second_resource,
        data_03002740[5], data_03002740[5] + 0x78, 0, 0,
        9, 9, 12, 5, 9, 9, 12, 5, 12, 5);
    func_08016344(data_030009E0[5].second_plane,
        data_030009E0[5].stride, data_030009E0[5].rows,
        0xc0, data_030009E0[5].stride, 5, 12);
    func_08016560(data_030009E0[5].first_plane, 12, 5, 0xc0, 12, 1, 12);
    clear = 0;
    func_0814186C(&clear, data_0600AFE0, 0x01000180);
    func_0808B7C0(5, func_0808B8E4(5, 1, 1, 2), 0x185, 10, 0xc000);
    func_0808A604(5, 2);
}
