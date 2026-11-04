#include "ffta.h"

typedef struct {
    u8 unknown_000[0x312];
    u8 name[18];
} NameState;

extern const u8 data_083A8306[];
extern void func_08001CF0(const void *, s32, s32, u8, u8, u8, u8,
                          u8, u32, u8, u32);
extern u32 func_08013A5C(u16 glyph);

/* Complete 0x0812ADDC..0x0812AE8C: 176 bytes, 75 instructions. */
void func_0812ADDC(NameState *state, s16 x, s16 y)
{
    u8 i = 0;
    u16 advance = 0;

    for (; i < 9; i++) {
        func_08001CF0(data_083A8306, x + advance, y, 0, 0, 0, 0, 0,
                      i * 4, 0, 0);
        {
        const u8 *name = state->name;
        u16 offset = i * 2;
        if (name[offset] == 0x40 && name[(u16)(offset + 1)] == 0x73)
            advance += 6;
        else
            advance += func_08013A5C(((((const u8 *)state)[offset + 0x312] << 8) |
                                        ((const u8 *)state)[offset + 0x313]) & 0x7fff);
        }
    }
}
