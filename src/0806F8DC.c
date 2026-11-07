#include "ffta.h"

typedef struct {
    u8 state;
    u8 flag;
    u8 values[3];
    u8 unknown_05;
    u16 selection;
    u8 unknown_08[0x1EC8];
    u8 pending;
} SelectionState;

extern u8 *data_0200F428;
extern u8 func_0806FE1C(SelectionState *, u8);
extern void func_0806FABC(void *, u16);
extern void func_0806FB50(void *, u16);
extern void func_0806F994(SelectionState *);

/* Complete 182-byte selection state handler. */
u8 func_0806F8DC(SelectionState *state, u16 selection)
{
    u8 i;

    state->pending = 0;
    switch (state->state) {
    case 0:
        if (func_0806FE1C(state, 0))
            state->state = 1;
        break;
    case 1:
        if (state->selection != selection) {
            state->selection = selection;
            func_0806FABC(data_0200F428 + 0x1A88, state->selection);
            func_0806FB50(data_0200F428 + 0x1A88, state->selection);
            for (i = 0; i < 3; ++i)
                state->values[i] = 0;
        }
        func_0806F994(state);
        break;
    case 2:
        state->flag = 0;
        state->state = 3;
        break;
    case 3:
        if (func_0806FE1C(state, 1))
            state->state = 4;
        break;
    case 4:
        break;
    }
    return state->state;
}
