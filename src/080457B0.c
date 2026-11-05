#include "ffta.h"

typedef struct {
    u8 unknown_00[0x90];
    void *buffer_90;
    void *buffer_94;
} MenuState;

typedef struct {
    u8 unknown_00[0x18];
    u8 *buffers;
} MenuBuffers;

typedef struct {
    u8 unknown_00[0x18];
    u16 *first_plane;
    u16 *second_plane;
    u8 unknown_20[8];
    u8 width;
    u8 height;
    u8 unknown_2A[0x22];
} TileRenderer;

extern MenuState *g_state_03002810;
extern MenuBuffers data_03002740;
extern TileRenderer data_030009E0[];
extern u16 data_0600C9E0[];
extern u16 data_0600CA20[];
extern const u8 *data_085668B0[];

/* Conditional call views follow the actual root and complete helper entries. */
extern void *func_0808A268(s32, u8, void *, void *, void *, void *, void *, void *,
                          u8, u8, u8, u8, u8, u8, u8, u8, u8, u8);
extern void func_0808AA18(s32);
extern void func_08016800(void *, u8, u8, u16, u8, u16, u16, u8);
extern u16 *func_0808B8E4(u32, u32, s32, s32);
extern void func_0808B7C0(int, u16 *, u16, u16, u16);
extern void func_0814186C(const void *, void *, u32);
extern u16 func_08015110(void *, void *, const u8 *, u8, u8);

/* 0x080457B0 .. 0x080458A4: complete 244-byte target. */
void func_080457B0(void)
{
    func_0808A268(6, 12, g_state_03002810->buffer_94,
                 g_state_03002810->buffer_90,
                 data_03002740.buffers, data_03002740.buffers + 120,
                 data_03002740.buffers + 240, data_03002740.buffers + 360,
                 7, 7, 15, 4, 7, 7, 15, 4, 15, 4);
    func_0808AA18(6);
    func_08016800(data_030009E0[6].first_plane,
                  data_030009E0[6].width, data_030009E0[6].height,
                  0x800, data_030009E0[6].width, 13, 3, 11);
    func_0808B7C0(6, func_0808B8E4(6, 1, 1, 1), 0x24F, 13, 0xB000);
    {
        u16 fill;
        u16 *source = &fill;
        *source = 0;
        func_0814186C(source, data_0600C9E0, 0x010001E0);
    }
    func_08015110((u8 *)g_state_03002810 + 0xC4C,
                  data_0600CA20, data_085668B0[15], 5, 1);
}
