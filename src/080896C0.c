#include "ffta.h"

extern u8 data_08393D44[];
extern s32 func_081426B8(s32 numerator, s32 divisor);

/* Complete [0x080896C0, 0x08089748): 136 bytes, 65 instructions.
 * Target bytes:
 * f0b509040d0c2e1c1204120c111c1b041f0c041c002a01d100210de0954201d8
 * 1c2109e0c800401a8000401a311cb8f0e3ff01300004010cc800401a0004010c
 * e0252d02002f01d1d0252d02281c58302080023400220b4e031c88190078c018
 * 20800234501c0004020c481c0004010c062af2d98b21c900081c28182080f0bc
 * 01bc0047443d3908
 */
void func_080896C0(void *buffer, u16 first, u16 second, u16 third)
{
    s32 denominator = first;
    u16 *output = buffer;
    const u8 *tiles;
    u32 tile;
    u16 value;
    u16 index;
    u16 base;
    u16 i;

    if (second == 0)
        value = 0;
    else if (first <= second)
        value = 28;
    else
        value = func_081426B8(second * 27, denominator) + 1U;

    index = value * 7;
    base = 0xE000;
    if (third == 0)
        base = 0xD000;

    *output++ = base + 0x58;
    i = 0;
    tiles = data_08393D44;
    tile = base + 0x58;
    for (; i < 7; i++, index++) {
        *output++ = *(const u8 *)(index + (u32)tiles) + tile;
    }
    *output = base + 0x458;
}
