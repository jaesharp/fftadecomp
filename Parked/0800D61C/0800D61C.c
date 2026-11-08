#include "ffta.h"

/* 0x0800D61C..0x0800D664: 72 bytes (64 code + literals 0x0800DEC1, 0x04000052). */
extern void func_0800DEC0(void *object);
extern void *func_0800C3CC(void (*callback)(void *), u32 size, u32 type,
                          u16 *destination);
extern u8 *func_0800C614(void *object);

void *func_0800D61C(u8 eva, u8 evb)
{
    void *object = func_0800C3CC(func_0800DEC0, 0x140, 2,
                                (u16 *)0x04000052);
    u8 *blend = func_0800C614(object);
    s32 i;

    for (i = 159; i >= 0; i--) {
        blend[0] = eva;
        blend[1] = evb;
        blend += 2;
    }
    return object;
}
