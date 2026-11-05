#include "ffta.h"

typedef struct {
    u8 unknown_00[0x12];
    u8 width;
    u8 height;
    u8 unknown_14[0x24];
    u16 *tiles;
    u8 unknown_3C[0x0A];
    u16 counter;
    u8 unknown_48[3];
    u8 kind;
} Window08053BE0;

typedef struct {
    u8 unknown_00[0x14];
    u32 value;
} Resource08053BE0;

extern Resource08053BE0 data_030008B0;
extern Resource08053BE0 data_03000990;
extern void func_08017424(void *object, u32 first, u32 second,
    u8 x, u8 y, u8 width, u8 height, u16 attributes, u8 style,
    u16 first_tile, u16 second_tile, u8 kind);
extern void func_08016210(void *object, const void *content, u16 first, u16 second);
extern void func_0814186C(const void *source, void *destination, u32 control);
extern void func_08016C90(void *object, u8 mode);

/* Complete target [0x08053BE0, 0x08053C74): 148 bytes, 66 instructions. */
void func_08053BE0(Window08053BE0 *window, const void *content,
                  u16 value, u8 x, u8 y)
{
    u16 clear;
    func_08017424(window, data_030008B0.value, data_03000990.value,
                 x, y, 11, 4, 0x800, 32, 13, 3, 11);
    func_08016210(window, content, value, 2);
    window->kind = 11;
    window->counter = 0;
    clear = 0;
    func_0814186C(&clear, window->tiles,
                  (window->width * window->height) | 0x01000000);
    func_08016C90(window, 1);
}
