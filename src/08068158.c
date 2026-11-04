#include "ffta.h"

/* Complete [0x08068158, 0x080681C4): 108 bytes, 51 instructions. */
typedef struct {
    u8 unknown_00[0xb];
    s8 selected;
    u8 count;
    u8 unknown_0d[0xa7];
    u8 tiles[1];
} MenuState;

typedef struct {
    u8 unknown_00[0x14];
    u16 *tiles;
} GraphicsState;

extern GraphicsState data_030008B0;

void func_08068158(MenuState *state)
{
    u16 (*rows)[32] = (u16 (*)[32])(data_030008B0.tiles + 3);
    s32 i = 0;

    if (i < state->count) {
        do {
            s32 palette = state->selected == i ? 15 : 9;
            u16 tile = state->tiles[i] * 4 + 0xa0;

            palette <<= 12;
            rows[0][i * 2] = tile++ + palette;
            rows[0][i * 2 + 1] = tile++ + palette;
            rows[1][i * 2] = tile++ + palette;
            rows[1][i * 2 + 1] = tile + palette;
            ++i;
        } while (i < state->count);
    }
}
