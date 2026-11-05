#include "ffta.h"

typedef struct ExtendedScriptState {
    u16 current;
    u16 count;
    u16 entries[34];
    u8 unknown_48[5];
    u8 unknown_4d;
    u16 field_4e;
    u8 unknown_50;
    u8 unknown_51;
    u8 field_52;
    u8 unknown_53;
    u32 flags;
    u8 unknown_58[4];
    u32 unknown_5c;
    u8 unknown_60[4];
    u16 field_64;
    u16 field_66;
    u16 values[2];
} ExtendedScriptState;

typedef struct ScriptSignal {
    u8 unknown_00[2];
    u16 identifier;
    u16 value;
} ScriptSignal;

typedef struct ScriptInput {
    u8 flags;
    u8 unknown_01;
    u8 kind;
    u8 unknown_03[0x11D];
    u16 field_120;
    u16 field_122;
    u8 field_124;
} ScriptInput;

extern ExtendedScriptState *data_0200F450;
extern ScriptInput data_030028A0;
extern ScriptSignal data_03002890;
extern ScriptSignal data_03002B50;

void func_0806461C(void)
{
    ScriptSignal *incoming;
    ScriptSignal *outgoing;
    ExtendedScriptState *state;

    if (data_030028A0.field_120 != 0 || (data_030028A0.field_122 > 20 && data_030028A0.kind != 3)) {
        ExtendedScriptState *initial = data_0200F450;
        if (initial->flags & 0x20) {
            initial->flags &= ~0x20;
            initial->field_52 = 0xFF;
            {
                ExtendedScriptState *resume = data_0200F450;

                resume->current = resume->entries[--resume->count];
            }
            return;
        }
        initial->current = 0x44;
        initial->entries[initial->count++] = 0x44;
        initial->current = 0x34;
        initial->entries[initial->count++] = 0x34;
        initial->current = 0x36;
    }
    incoming = &data_03002890;
    state = data_0200F450;
    if (incoming->identifier == state->field_64) {
        u8 selected = data_030028A0.flags & 8;

        state->values[selected != 0] = incoming->value;
    }
    state = data_0200F450;
    if (state->values[0] == state->field_66 && state->values[1] == state->values[0]) {
        if (state->unknown_51 == 0) {
            state->values[1] = 0;
            state->values[0] = 0;
            data_03002B50.value = 0;
            data_03002B50.identifier = 0;
            incoming->value = 0;
            incoming->identifier = 0;
            state->current = state->entries[--state->count];
            state->flags &= ~0x20;
            return;
        }
        state->unknown_51--;
    }
    data_030028A0.field_124 = 0x16;
    outgoing = &data_03002B50;
    state = data_0200F450;
    outgoing->identifier = state->field_64;
    outgoing->value = state->values[!(data_030028A0.flags & 8)];
}
