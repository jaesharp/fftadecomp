#include "ffta.h"

typedef struct {
    u8 unknown_00[0x0C];
    u16 *base;
    u8 unknown_10[5];
    u8 unknown_15;
    u8 unknown_16;
    u8 unknown_17[5];
    u16 unknown_1C;
    u8 unknown_1E;
    u8 unknown_1F;
} State08053674;

extern u8 func_080CB99C(u32 value);
extern s32 func_08142950(s32 first, s32 second);
extern void func_0802AB64(State08053674 *state, u16 index, u16 value,
                         u8 offset, u8 count, u16 tag, u8 flag);

/* Complete [0x08053674, 0x08053714): 160 bytes, 73 instructions.
 * f0b5474680b483b0071c09060d0e1206140e1b041b0c552b02d9c520400000e0
 * 1e4878f081f90d300006000e80467e7d75436d042d0cb97d0131201ceff04ef9
 * 041c74436400b88b24182404240c022000904046019000200290381c291c221c
 * 331cd7f745fa02352d042d0c04342404240c7b7d981e0006000e0090f87f0190
 * 01200290381c291c221cd7f731fa03b008bc9846f0bc01bc0047000089010000
 */
void func_08053674(State08053674 *state, u8 row, u8 selection, u16 entry)
{
    u8 palette;
    u8 width;
    u16 first;
    u32 remainder;
    u16 value;

    if (entry > 0x55)
        palette = func_080CB99C(0x18A) + 13;
    else
        palette = func_080CB99C(0x189) + 13;

    width = state->unknown_15;
    first = row * width * 2;
    remainder = (u32)func_08142950(selection, state->unknown_16 + 1);
    value = remainder * width * 2 + state->unknown_1C;

    func_0802AB64(state, first, value, width, 2, palette, 0);
    first += 2;
    value += 4;
    func_0802AB64(state, first, value, state->unknown_15,
                  (u8)(state->unknown_15 - 2), state->unknown_1F, 1);
}
