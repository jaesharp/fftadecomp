#include "ffta.h"

/* Complete [0x08085678, 0x08085770): 248 bytes, 102 instructions. */
typedef struct {
    u8 unknown_00[12];
    const void *first;
    u32 unknown_10;
    const void *second;
} Sources08085678;

typedef struct {
    u8 unknown_00[16];
    u16 *tiles;
} Buffers08085678;

typedef struct {
    u8 unknown_00;
    u8 unknown_01;
    u8 unknown_02[12];
    u16 tile;
    u8 unknown_10[36];
    s8 x;
    s8 y;
    u8 unknown_36[18];
    u8 unknown_48;
    u8 unknown_49;
    u8 unknown_4a;
    u8 unknown_4b;
} Window08085678;

extern Sources08085678 *data_03002818;
extern Buffers08085678 data_03002740;
extern Window08085678 data_030009E0[];
extern u8 data_0600B4E0[];
extern void *func_0808A268(s32 index, u8 kind, const void *first,
    const void *second, u16 *first_tiles, u16 *second_tiles,
    void *third, void *fourth, u8 left, u8 top, u8 width, u8 height,
    u8 x, u8 y, u8 first_width, u8 first_height, u8 second_width,
    u8 second_height);
extern u16 *func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
extern void func_0808B858(s32 index, u16 *destination, u16 tile, u16 count);
extern void func_0808B7C0(s32 index, u16 *destination, u16 tile,
                          u16 count, u16 flags);
extern void func_0814186C(const void *source, void *destination, u32 control);

void func_08085678(u32 x)
{
    u16 zero;

    func_0808A268(4, 12, data_03002818->first, data_03002818->second,
                  data_03002740.tiles, data_03002740.tiles + 26, 0, 0,
                  16, 18, 13, 2, 16, 18, 13, 2, 13, 2);
    data_030009E0[4].x = x;
    data_030009E0[4].y = 18;
    data_030009E0[4].tile = 399;
    data_030009E0[4].unknown_01 = 0;
    data_030009E0[4].unknown_48 = 1;
    data_030009E0[4].unknown_49 = 1;
    data_030009E0[4].unknown_4a = 12;
    data_030009E0[4].unknown_4b = 2;
    func_0808B858(4, func_0808B8E4(4, 1, 0, 0), 0, 12);
    zero = 0;
    func_0814186C(&zero, data_0600B4E0, 0x010002c0);
    func_0808B7C0(4, func_0808B8E4(4, 1, 0, 0), 423, 12, 0xc000);
}
