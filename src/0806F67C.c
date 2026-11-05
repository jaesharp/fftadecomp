#include "ffta.h"

typedef struct {
    u8 unknown_00[0xC];
    u16 *entries;
    u8 unknown_10[5];
    u8 width;
    u8 selection_count;
    u8 next_selection;
    u8 unknown_18[2];
    u16 cursor;
} State0806F67C;

extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete target [0x0806F67C, 0x0806F6AA): 46 bytes, 22 instructions. */
void func_0806F67C(State0806F67C *state)
{
    u16 fill;

    state->next_selection = state->selection_count + 1;
    state->cursor = 0;
    fill = 0;
    func_0814186C(&fill, state->entries,
        0x01000000 | (state->width * state->selection_count * 2));
}
