#include "ffta.h"

struct State0813F1D8 {
    u8 unknown_00[0x10];
    const u8 *field_10;
};

extern const u8 data_083A92E0[];
extern const u8 data_083A92FA[];
extern const u8 data_083A9302[];
extern const u8 data_083A930A[];

/* Complete [0x0813F1D8, 0x0813F22C), 84 bytes, 21 instructions. */
void func_0813F1D8(struct State0813F1D8 *state, u8 mode)
{
    switch (mode) {
    case 0:
        state->field_10 = data_083A92E0;
        break;
    case 1:
        state->field_10 = data_083A92FA;
        break;
    case 2:
        state->field_10 = data_083A9302;
        break;
    case 3:
        state->field_10 = data_083A930A;
        break;
    case 4:
        state->field_10 = data_083A9302;
        break;
    }
}
