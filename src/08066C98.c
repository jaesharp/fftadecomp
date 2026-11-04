#include "ffta.h"

typedef struct {
    u8 x, y, width, height;
    u16 count, flags;
    u8 appearance;
    u8 unknown_09[3];
    u16 blocks, tile;
} Layout08066C98;

typedef struct {
    const u16 *first_source, *second_source;
    u16 *first_buffer, *second_buffer;
    u8 x, y, width, height;
    u16 value_14;
    u8 value_16, appearance;
    u16 value_18, value_1A;
    u8 flags, value_1D, value_1E, value_1F;
    u16 value_20, value_22, value_24, value_26, value_28, value_2A;
} Window08066C98;

typedef struct {
    u8 unknown_00[0x0A];
    u16 count;
    u8 value_0C, value_0D, value_0E;
    u8 unknown_0F[9];
    Layout08066C98 layout;
    Window08066C98 window;
    u8 unknown_54[0x68];
    void *child;
    u16 buffer[0];
} Context08066C98;

typedef struct {
    u8 unknown_00[0x10];
    u8 *tiles;
} Graphics08066C98;

extern u8 data_02003CB0[];
extern Graphics08066C98 data_030008B0;
extern const u8 data_083B4214[];
extern const Layout08066C98 data_08393AA4;
extern void (*const data_0836D4BC)(void *, const void *, u32);
extern u8 *func_0800543C(void *, const void *);
extern void func_0814186C(const void *, void *, u32);
extern u16 func_08013B50(Layout08066C98 *);
extern void *func_08005B28(u32);
extern void func_08017490(Window08066C98 *, u8, u8, u8, u8, u16, u16, u16, u8);
extern void func_08016BD8(Window08066C98 *, u16 *);
extern void func_08013A88(void *, u32);

/* Complete target [0x08066C98, 0x08066D74): 220 bytes including literal pools. */
void func_08066C98(Context08066C98 *context)
{
    Layout08066C98 *layout = &context->layout;
    Window08066C98 *window = &context->window;
    u8 *scratch = data_02003CB0;

    func_0800543C(scratch, data_083B4214);
    func_0814186C(scratch + 0x1880, data_030008B0.tiles + 0x4600, 0x1F0);
    func_0814186C(scratch + 0x1700, data_030008B0.tiles + 0x49E0, 0x20);
    data_0836D4BC(layout, &data_08393AA4, 16);
    func_08013B50(layout);
    context->child = func_08005B28(0x1D4);
    func_08017490(window, layout->x, layout->y, layout->width, layout->height,
                  layout->flags, 13, 3, 11);
    func_08016BD8(window, context->buffer);
    func_08013A88(data_030008B0.tiles + (layout->tile + 0x100) * 32, 0x68);
    context->count = 0;
    context->value_0E = 0;
    context->value_0D = 0;
    context->value_0C = 0;
}
