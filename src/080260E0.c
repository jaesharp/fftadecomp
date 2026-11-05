#include "ffta.h"

extern u8 func_080C9540(u16 bit_index);
extern s32 func_080C7EA4(const void *object, u32 selector);
extern u8 func_080C8240(void *object);

/* Complete [0x080260E0, 0x080261D8): 248 bytes including switch and pools. */
u32 func_080260E0(void *object, u16 *entry)
{
    u16 bit_index;

    *entry = 0x0E;
    if (func_080C9540(2))
        return 0;
    if ((u32)func_080C7EA4(object, 0x26) <= 9)
        return 0;
    if (func_080C8240(object))
        return 0;

    switch (func_080C7EA4(object, 3)) {
    case 1:
    case 23:
        *entry = 0x50;
        bit_index = 0x23D;
        break;
    case 2:
        *entry = 0x51;
        bit_index = 0x241;
        break;
    case 3:
    case 20:
        *entry = 0x52;
        bit_index = 0x240;
        break;
    case 4:
        *entry = 0x53;
        bit_index = 0x242;
        break;
    case 5:
        *entry = 0x54;
        bit_index = 0x23F;
        break;
    default:
        return 0;
    }
    if (!func_080C9540(bit_index))
        return 0;
    return 1;
}
