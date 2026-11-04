// func_08031698 - 0x08031698, 32 bytes of code plus a 24-byte literal pool.
//
// Re-arms the display state that func_080316D0 tears down again: it raises
// the "blend control pending" flag on the display state object, reloads the
// buffered blend value (BLDCNT, 0x1346) that func_08031624 copies into the
// hardware register, and installs the HBlank wait routine as the callback.

#include "ffta.h"

// The display state object: the halfword at +6 holds the flags that
// func_080316D0 clears with 0xFFFB again.
typedef struct {
    u8 unknown_00[6];
    u16 flags_06;
} DisplayState08031698;

// The callback table the HBlank routine is installed into: the word at +0x10
// is the routine to run.
typedef struct {
    u8 unknown_00[0x10];
    u32 callback_10;
} DisplayCallbacks08031698;

extern u8 data_030027A4;
extern u16 data_030027F0;
extern DisplayState08031698 data_03000EA0;

void func_08031698(void)
{
    data_030027A4 = 0xFF;
    data_030027F0 = 0x1346;
    // plausible: the slot holds func_08031624 with the Thumb bit set
    ((DisplayCallbacks08031698 *)0x030008D0)->callback_10 = 0x08031625;
    data_03000EA0.flags_06 |= 4;
}
