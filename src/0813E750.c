#include "ffta.h"

/* Target: 0x0813E750, complete 82-byte Thumb function. */
typedef struct {
    u8 unknown_00[0x18];
    u8 selection;
    u8 unknown_19;
    u16 span;
    u16 progress;
    u16 selected;
} SelectionState;

extern u32 func_08002804(void);

void func_0813E750(SelectionState *state, u8 mode)
{
    switch (mode) {
    case 0:
        state->selected = state->span;
        state->progress = 0;
        state->selection = 0;
        break;
    case 1:
        state->selected = (state->span >> 1)
            + (((s16)func_08002804() % state->span) >> 1);
        state->progress = 0;
        state->selection = (s16)func_08002804() % 2;
        break;
    }
}
