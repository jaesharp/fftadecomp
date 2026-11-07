#include "ffta.h"

struct Object;

extern u8 data_030008B0[];
extern u8 data_03000990[];

extern void func_0801174C(void *context, u8 kind, u16 selection,
                          void *first, void *second, u32 field5, s32 field6,
                          u32 width, u32 height, u32 tile);
extern struct Object *func_080C83CC(u8 category);
extern void func_080132B8(struct Object *object, u8 alternate);
extern void func_0802A2C0(u8 x, u8 y, u8 width, u8 height);
extern void func_0801339C(u16 value);

/* 0x08061028: 206 bytes, including literals and the switch table. */
void func_08061028(void *context, u8 entry)
{
    func_0801174C(context, 4, entry, data_030008B0, data_03000990,
                  -1, 0, 22, 6, 0x100);
    func_080132B8(func_080C83CC(0x35), 1);
    func_0802A2C0(0, 0, 30, 10);

    switch (entry) {
    case 0x40:
    case 0x43:
    case 0x44:
    case 0x4C:
    case 0x52:
    case 0x53:
    case 0x55:
    case 0x56:
        func_0801339C(2);
        break;
    default:
        break;
    }
}
