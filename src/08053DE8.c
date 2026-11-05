#include "ffta.h"

typedef struct {
    u8 unknown_00[0x0C];
    u16 *tiles;
    u8 unknown_10[5];
    u8 width;
    u8 height;
    u8 mode;
    s16 count;
    u16 position;
} TileRun08053DE8;

extern void func_0814186C(const void *source, void *destination, u32 control);
extern void func_08053F08(TileRun08053DE8 *state, u8 row, u16 entry);

/* Complete target: [0x08053DE8, 0x08053E4C), 100 bytes. */
void func_08053DE8(TileRun08053DE8 *state, const u16 *entries)
{
    u16 zero;
    u16 row;
    u16 position;

    state->mode = 5;
    zero = 0;
    func_0814186C(&zero, state->tiles,
                  (state->width * state->height * 2) | 0x01000000);
    row = 0;
    position = state->position;
    while (row < (state->count > 3 ? 4 : state->count)) {
        func_08053F08(state, row, entries[position]);
        row++;
        position++;
    }
}
