#include "ffta.h"

typedef struct {
    u8 unknown_00[0xC];
    u16 *entries;
    u8 unknown_10[5];
    u8 width;
    u8 rows;
    u8 state;
    s16 count;
    u16 cursor;
} State08057E24;

extern void func_0814186C(const void *source, void *destination, u32 control);
extern void func_08057E98(State08057E24 *state, u8 slot, u8 value, u8 mode);

/* Complete target [0x08057E24, 0x08057E96): 114 bytes, 55 instructions. */
void func_08057E24(State08057E24 *state, const u8 *values, u8 mode)
{
    u16 fill;
    u16 slot;
    u16 index;

    state->state = 4;
    fill = 0;
    func_0814186C(&fill, state->entries,
        0x01000000 | (state->width * state->rows * 2));
    for (slot = 0, index = state->cursor;
         slot < (state->count > 2 ? 3 : state->count);
         slot++, index++) {
        func_08057E98(state, slot, values[index], mode);
    }
}
