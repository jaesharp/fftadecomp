#include "ffta.h"

typedef struct {
    u8 unknown_00[0x90];
    void *field_90;
    void *field_94;
} ScreenState;

typedef struct {
    u8 unknown_00[0x18];
    u8 *buffer;
} ScreenBuffers;

typedef struct {
    u8 unknown_00[0x18];
    u16 *first_plane;
    u16 *second_plane;
    u8 unknown_20[8];
    u8 width;
    u8 height;
    u8 unknown_2A[0x22];
} TileRenderer;

typedef struct {
    u8 unknown_00[0xAC];
    const u8 *text;
} TextResources;

extern ScreenState *g_state_03002810;
extern ScreenBuffers data_03002740;
extern TileRenderer data_030009E0[];
extern TextResources data_085668B0;
extern u16 data_0600C9E0[];
extern u16 data_0600CA20[];

extern void *func_0808A268(s32 index, u8 mode, void *first_grid,
    void *second_grid, void *first_plane, void *second_plane,
    void *first_buffer, void *second_buffer, u8 x, u8 y, u8 width,
    u8 height, u8 saved_x, u8 saved_y, u8 saved_width,
    u8 saved_height, u8 stride, u8 rows);
extern void func_0808AA18(u32 index);
extern void func_08016800(void *destination, u8 width, u8 height, u16 flags,
    u8 stride, u16 border_tile, u16 fill_tile, u8 palette);
extern u16 *func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
extern void func_0808B7C0(int index, u16 *destination, u16 tile,
    u16 count, u16 flags);
extern void func_0814186C(const void *source, void *destination, u32 control);
extern u16 func_08015110(void *object, void *destination,
    const u8 *text, u8 mode, u8 reset);

/* 0x08045B04 .. 0x08045BFC: 248 bytes. */
void func_08045B04(void)
{
    func_0808A268(6, 12, g_state_03002810->field_94,
        g_state_03002810->field_90, data_03002740.buffer,
        data_03002740.buffer + 0x78,
        data_03002740.buffer + 0xF0, data_03002740.buffer + 0x168,
        7, 7, 15, 4, 7, 7, 15, 4, 15, 4);
    func_0808AA18(6);
    func_08016800(data_030009E0[6].first_plane,
        data_030009E0[6].width, data_030009E0[6].height, 0x800,
        data_030009E0[6].width, 13, 3, 11);
    func_0808B7C0(6, func_0808B8E4(6, 1, 1, 1), 0x24F, 13, 0xB000);
    {
        u16 fill;
        u16 *source = &fill;
        *source = 0;
        func_0814186C(source, data_0600C9E0, 0x010001E0);
    }
    func_08015110((u8 *)g_state_03002810 + 0xC4C,
        data_0600CA20, data_085668B0.text, 5, 1);
}
