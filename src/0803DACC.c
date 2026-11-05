#include "ffta.h"

/* Complete 0x0803DACC..0x0803DC1C: 336 bytes. */
typedef struct {
    u8 unknown_00[0x0b];
    u8 position;
} MenuWindow;

typedef struct {
    void *owner;
    MenuWindow *window;
    u8 unknown_08[0x88];
    u16 *second_resource;
    u16 *first_resource;
} MenuContext;

typedef struct {
    u8 unknown_00[0x10];
    u16 *tiles;
} TileStorage;

typedef struct {
    u8 unknown_00[0x18];
    u16 *first_plane;
    u16 *second_plane;
    u8 unknown_20[8];
    u8 width;
    u8 height;
    u8 unknown_2a[0x22];
} TileWindow;

extern u8 data_02003CB0[];
extern MenuContext *g_state_03002810;
extern TileStorage data_03002740;
extern u16 data_06009960[];
extern TileWindow data_030009E0[];
extern void *func_0808A268(u32, u8, u16 *, u16 *, u16 *, u16 *,
    u16 *, u16 *, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8);
extern void func_0814186C(const void *, void *, u32);
extern void func_08016344(void *, u8, u8, u16, u8, u16, u8);
extern void func_08016560(void *, u8, u8, u16, u8, u16, u8);
extern u16 *func_0808B8E4(u32, u32, s32, s32);
extern void func_0808B7C0(s32, u16 *, u16, u16, u16);
extern u32 func_08018524(u8 *, u16, u8);
extern void func_08035678(u16, u16 *, u32, u16);

void func_0803DACC(u32 mode)
{
    u8 *buffer = data_02003CB0;
    u8 height;
    u8 color;
    u16 fill;
    u16 tile;
    u16 *destination;

    if (g_state_03002810->window->position > 80) {
        height = 1;
    } else {
        height = 14;
        if (mode == 2)
            height = 13;
    }
    func_0808A268(4, 12, g_state_03002810->first_resource,
        g_state_03002810->second_resource, data_03002740.tiles,
        data_03002740.tiles + 0xb6, 0, 0,
        2, height, 26, mode * 2 + 3, 2, height, 26, mode * 2 + 3,
        26, color = mode * 2 + 3);
    fill = 0;
    func_0814186C(&fill, data_06009960, 0x01000c00);
    func_08016344(data_030009E0[4].second_plane,
        data_030009E0[4].width, data_030009E0[4].height, 0xc0,
        data_030009E0[4].width, 5, 12);
    func_08016560(data_030009E0[4].first_plane, 26, color, 0xc0, 26, 1, 12);
    func_0808B7C0(4, func_0808B8E4(4, 1, 1, 2), 0xcb, 24, 0xc000);
    if (mode == 2)
        func_0808B7C0(4, func_0808B8E4(4, 1, 1, 4), 0xfb, 24, 0xc000);
    tile = 0xc03e;
    destination = func_0808B8E4(4, 1, 1, 1);
    func_08035678(tile, destination, func_08018524(buffer, 0x3e, 0x12), 1);
}
