#include "ffta.h"

/* Complete [0x080501CC, 0x080502EA): 286 bytes. */
typedef struct {
    u8 unknown_00[4];
    u16 count;
    u8 unknown_06[0x55A];
    u8 page;
} Root080501CC;

typedef struct {
    u8 unknown_00[8];
    u16 *destination;
    u16 *row;
    u8 unknown_10[5];
    u8 width;
    u8 height;
    u8 unknown_17[7];
    u8 stride;
} Menu080501CC;

typedef struct {
    Root080501CC *root;
    u8 unknown_04[0x44];
    Menu080501CC menu;
} State080501CC;

typedef struct RequestNode080501CC RequestNode080501CC;
extern u32 func_0804FDF4(State080501CC *, u32, u32, u16);
extern void func_0804FFB8(Menu080501CC *, u32, u32, u16, u32);
extern void func_0804FF48(Menu080501CC *, u32, u32);
extern u16 func_080161A0(u8, u8, u8);
extern RequestNode080501CC *func_0804CA8C(void);
extern void func_08000BAC(RequestNode080501CC *, u32, u32,
                         u16, u16, u16, u16);
extern void func_0804FD24(u16 *, u16);

void func_080501CC(State080501CC *state)
{
    Menu080501CC *menu = &state->menu;
    s32 selection = state->root->page * 18 + 1;
    s32 x, y;
    u16 *source, *destination;

    for (y = 3; y <= 11; y += 4) {
        for (x = 2; x <= 22; x += 4) {
            if (selection <= state->root->count) {
                u8 flag = func_0804FDF4(state, (s16)x, (s16)y, selection);
                func_0804FFB8(menu, (s16)(x - 1), (s16)(y + 2),
                             selection, flag);
                selection++;
            } else {
                func_0804FF48(menu, (s16)x, (s16)y);
            }
        }
    }
    source = menu->row + func_080161A0(0, 3, menu->stride);
    destination = menu->destination + func_080161A0(0, 3, 32);
    func_08000BAC(func_0804CA8C(), (u32)source, (u32)destination,
                  menu->width, (u16)(menu->height - 3), menu->width * 2, 64);
    destination = menu->destination + func_080161A0(20, 1, 32);
    func_0804FD24(destination, state->root->page + 1);
}
