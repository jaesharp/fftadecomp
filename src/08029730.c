#include "ffta.h"

extern u32 func_08142AB0(u32, u32);
extern u32 func_08142B28(u32, u32);

/* Complete 08029730..0802979A: 106 bytes, 49 instructions. */
void func_08029730(u16 *buffer, u8 width, u16 value)
{
    s8 index;

    for (index = width - 1; index >= 0; --index) {
        u32 byte_offset = index * 2;
        u16 *digit = (u16 *)(byte_offset + (u32)buffer);
        s32 tile = func_08142B28(value, 10) + 30;
        *digit = tile | -0x4000;
        value = func_08142AB0(value, 10);
        if (value == 0) {
            for (--index; index >= 0; --index)
                buffer[index] = 0;
            break;
        }
    }
}
