#include "ffta.h"

typedef struct {
    u8 unknown_00[0x0c];
    u16 *first_resource;
    u8 unknown_10[4];
    u16 *second_resource;
} ResourceContext0808C16C;

typedef struct {
    u8 unknown_00[0x18];
    u16 *tiles;
} TileStorage0808C16C;

typedef struct {
    u8 unknown_00;
    u8 field_01;
    u8 unknown_02[12];
    u16 border_tile;
    u8 unknown_10[8];
    u16 *first_plane;
    u8 unknown_1c[12];
    u8 width;
    u8 height;
    u8 unknown_2a[10];
    u8 x;
    u8 y;
    u8 unknown_36[18];
    u8 field_48;
    u8 field_49;
    u8 field_4a;
    u8 field_4b;
} TileWindow0808C16C;

extern ResourceContext0808C16C *data_03002818;
extern TileStorage0808C16C data_03002740;
extern TileWindow0808C16C data_030009E0[];
extern TileWindow0808C16C *func_0808A268(s32, u8, u16 *, u16 *,
                         u16 *, u16 *, u16 *, u16 *, u8, u8, u8, u8,
                         u8, u8, u8, u8, u8, u8);
extern void func_0808AA18(u32);
extern void func_08016800(void *, u8, u8, u16, u8, u16, u16, u8);
extern u16 *func_0808B8E4(u32, u32, s32, s32);
extern void func_0808B7C0(s32, u16 *, u16, u16, u16);
extern void func_0808B80C(s32, u16 *, u16, u16, u16);

/* Complete [0x0808C16C,0x0808C354): 488 bytes including literal pools. */
void func_0808C16C(void)
{
    func_0808A268(6, 12, data_03002818->first_resource,
        data_03002818->second_resource, data_03002740.tiles,
        data_03002740.tiles + 0xea, data_03002740.tiles + 0x1d4,
        data_03002740.tiles + 0x2be, 17, 1, 13, 18,
        17, 1, 13, 18, 13, 18);
    func_0808AA18(6);
    data_030009E0[6].x = 31;
    data_030009E0[6].y = 1;
    data_030009E0[6].border_tile = 0x30d;
    data_030009E0[6].field_01 = 0;
    data_030009E0[6].field_48 = 1;
    data_030009E0[6].field_49 = 1;
    data_030009E0[6].field_4a = 11;
    data_030009E0[6].field_4b = 8;
    func_08016800(data_030009E0[6].first_plane,
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
