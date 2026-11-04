#include "ffta.h"

extern ScriptState *data_0200F450;

void func_080648A0(void)
{
    u8 *control = (u8 *)0x03000ED0;
    ScriptState *state;

    control[5] = 1;
    if (data_0200F450->unknown_52[0] == 0) {
        Record *record = (Record *)0x020020D0;

        record->field_0c = 0x1C;
    } else {
        Record *record = (Record *)0x020020D0;

        record->field_0c = 0x1B;
    }
    data_0200F450->unknown_4d = 0x0B;
    data_0200F450->unknown_51 = 0x5A;
    state = data_0200F450;
    state->current = 0x3F;
    state->entries[state->count++] = 0x3F;
    state->current = 0x37;
    state->entries[state->count++] = 0x37;
    state->current = 0x31;
}
