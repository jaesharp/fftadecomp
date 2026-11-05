#include "ffta.h"

extern s32 func_080C7EA4(const void *actor, u32 selector);
extern u32 func_08142AB0(u32 value, u32 divisor);
extern u32 func_08133F70(u16 *list, void *actor, u8 selector);

/* Complete 08134094..081340F6: 98 bytes, 43 reached instructions. */
u16 func_08134094(u16 *list, void *actor)
{
    u16 count = 0;
    u32 current = func_080C7EA4(actor, 0x13);
    u32 maximum = func_080C7EA4(actor, 0x14);

    if (func_08142AB0(current * 100, maximum) <= 25)
        count = func_08133F70(list, actor, 3);
    count += func_08133F70((u16 *)(count * sizeof(*list) + (u32)list), actor, 2);
    count += func_08133F70((u16 *)(count * sizeof(*list) + (u32)list), actor, 1);
    return count;
}
