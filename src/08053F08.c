#include "ffta.h"

typedef struct {
    u8 unknown_00[0x0C];
    u16 *tiles;
    u8 unknown_10[5];
    u8 width;
    u8 unknown_16[4];
    u8 position;
    u8 unknown_1B;
    u16 tile;
    u8 unknown_1E;
    u8 palette;
} TileRun08053F08;

extern u8 func_080543CC(TileRun08053F08 *, u8);
extern u8 func_080CB99C(u16);
extern u8 func_080CCA20(u16);
extern void func_0802AB64(TileRun08053F08 *, u16, u16, u8, u8, u16, u8);
extern void func_0802ACA0(u16 *, u16, u8, u16);
extern void func_08029730(u16 *, u32, u8);

/* Complete [0x08053F08, 0x08053FE0): 216 bytes, 98 instructions. */
void func_08053F08(TileRun08053F08 *state, u8 row, u16 entry)
{
    u8 selected = func_080543CC(state, row);
    u8 width = state->width;
    u16 first = (row * 2 + row) * width;
    u16 value;
    u16 palette;

    value = (u8)((u32)selected % 5) * (u16)(width * 2) + state->tile;
    if (entry > 0x55)
        palette = func_080CB99C(0x18A) + 13;
    else
        palette = func_080CB99C(0x189) + 13;
    func_0802AB64(state, first, value, state->width, 2, palette, 0);
    func_0802AB64(state, first + 2, value + 4, state->width,
                  (u8)(state->width - 2), state->palette, 1);
    func_0802ACA0(&state->tiles[first + state->width * 2 + 3], 0x81, 13, 4);
    func_08029730(&state->tiles[first + state->width * 2 + 7], 1,
                  func_080CCA20(entry));
}
