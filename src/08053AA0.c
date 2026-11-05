#include "ffta.h"

typedef struct {
    u8 unknown_00[0x14];
    u32 value;
} Graphics08053AA0;

typedef struct {
    u8 unknown_00[0x12];
    u8 width;
    u8 height;
    u8 unknown_14[0x24];
    u16 *tiles;
    u8 unknown_3c[0xa];
    u16 counter;
    u8 unknown_48[3];
    u8 tag;
} Menu08053AA0;

extern Graphics08053AA0 data_030008B0;
extern Graphics08053AA0 data_03000990;
extern void func_08017424(void *, u32, u32, u8, u8, u8, u8,
                          u16, u8, u16, u16, u8);
extern void func_08016210(void *, const void *, u16, u16);
extern void func_0814186C(const void *, void *, u32);
extern void func_08016C90(void *, u8);

/* Complete target: [0x08053AA0, 0x08053B34), 148 bytes. */
void func_08053AA0(Menu08053AA0 *menu, const void *content, u16 first,
                   u8 x, u8 y)
{
    u16 zero;

    func_08017424(menu, data_030008B0.value, data_03000990.value,
                   x, y, 11, 2, 0x800, 0x20, 13, 3, 11);
    func_08016210(menu, content, first, 1);
    menu->tag = 11;
    menu->counter = 0;
    zero = 0;
    func_0814186C(&zero, menu->tiles,
                   (menu->width * menu->height) | 0x01000000);
    func_08016C90(menu, 1);
}
