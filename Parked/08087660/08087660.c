#include "ffta.h"

extern s16 func_08007A60(u8 index);
extern s32 func_081426B8(s32 numerator, s32 denominator);

/* Target 0x08087660..0x080876F4, 148 bytes:
 * f0b5474680b4061c8846111c1c1c0906090e2406240e4020bbf01ef860430006
 * 000e80f7edf90004c0142021091a0904090c00271f2084462020451a31881f20
 * 084068434446a21c9046002800da1f3043110a04500d614608406843002800da
 * 1f30401141011943900e624610406843002800da1f304011800201432180781c
 * 0004070c02360f2fd8d908bc9846f0bc01bc0047
 */
void func_08087660(const u16 *source, u16 *destination, u8 divisor, u8 multiplier)
{
    u16 inverse;
    s32 scale;
    u16 index;

    inverse = 32 - (func_08007A60((u8)(func_081426B8(64, divisor) * multiplier)) >> 3);
    scale = 32 - inverse;
    for (index = 0; index < 16; index++) {
        u16 value = *source++;
        s32 low = (value & 31) * scale / 32;
        s32 middle = ((value >> 5) & 31) * scale / 32;
        s32 high = ((value >> 10) & 31) * scale / 32;

        *destination++ = low | (middle << 5) | (high << 10);
    }
}
