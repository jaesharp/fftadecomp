#include "ffta.h"

extern u16 data_08393D36[];
extern u32 func_08142B28(u32, u32);
extern s32 func_081426B8(s32, s32);

/* Complete 080899AC..08089AAC: 256 bytes, 122 instructions. */
void func_080899AC(u32 address, u16 stride, u16 base, u16 value,
                   u16 digits, u16 alignment, u16 attributes)
{
    u16 *destination = (u16 *)address;
    u16 blank_top = alignment == 1 ? base : 0;
    u16 blank_bottom = alignment == 1 ? base + 1 : 0;
    u16 *place = data_08393D36 + digits;
    u16 index;
    u16 pair;

    index = 0;
    if (index < digits - 1) {
        do {
        pair = func_081426B8((u16)func_08142B28(value, place[0]), place[3]) * 2;
        if (pair != 0) {
            *destination = base + pair + attributes;
            destination[stride] = base + (u16)(pair + 1) + attributes;
            ++destination;
            blank_top = base;
            blank_bottom = base + 1;
        } else {
            *destination = blank_top + attributes;
            destination[stride] = blank_bottom + attributes;
            ++destination;
        }
        ++index;
        --place;
        } while (index < digits - 1);
    }
    {
        u32 last = func_08142B28(value, 10) * 2;
        *destination = base + last + attributes;
        destination[stride] = base + (u16)(last + 1) + attributes;
    }
}
