#include "ffta.h"

typedef struct {
    u8 unknown_00[0xC];
    u16 *entries;
    u8 unknown_10[5];
    u8 width;
    u8 selection_count;
    u8 unknown_17[5];
    u16 base;
    u8 unknown_1E;
    u8 palette;
} State0806F6AC;

extern s32 func_08142950(s32 numerator, s32 denominator);
extern void func_0802ACA0(u16 *entries, u16 first, u8 second, u16 count);

/* Complete [0x0806F6AC, 0x0806F7B8): 268 bytes, 129 instructions. */
void func_0806F6AC(State0806F6AC *state, u8 position, u8 selection, u8 palette)
{
    u8 width = state->width;
    u16 start = width * position * 2;
    u16 tile = width * func_08142950(selection, state->selection_count + 1) * 2;
    u16 cursor = start;
    u16 i = 0;

    for (; i < 2; i++, cursor++) {
        state->entries[cursor] = (state->base + tile + i) | (palette << 12);
        state->entries[cursor + state->width] = (state->base + tile + (i + 2)) | (palette << 12);
    }
    cursor = start + 2;
    tile += 4;
    for (i = 0; i < state->width - 2; i++, cursor++) {
        state->entries[cursor] = (state->base + tile + i * 2) | (state->palette << 12);
        state->entries[cursor + state->width] = (state->base + tile + i * 2 + 1) | (state->palette << 12);
    }
    {
        u32 offset = start * 2 + 30;

        func_0802ACA0((u16 *)((u8 *)state->entries + offset), 0x145, 12, 1);
        func_0802ACA0((u16 *)((u8 *)state->entries + state->width * 2 + offset), 0x146, 12, 1);
    }
}
