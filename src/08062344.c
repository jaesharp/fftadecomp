#include "ffta.h"

extern u8 g_state_02000000[];
extern ScriptState *data_0200F450;

/* Complete [0x08062344, 0x080623C8), 132 bytes. */
void func_08062344(void)
{
    if (g_state_02000000[0x72]) {
        ScriptState *state = data_0200F450;
        state->field_4e = 0xCA;
        state->current = 2;
        state->entries[state->count++] = state->current;
        state->current = 0x31;
        state->entries[state->count++] = state->current;
        state->current = 0x34;
        state->entries[state->count++] = state->current;
        state->current = 0x33;
    } else {
        ScriptState *state = data_0200F450;
        state->field_4e = 0xC9;
        state->current = 1;
        state->entries[state->count++] = state->current;
        state->current = 0x34;
        state->entries[state->count++] = state->current;
        state->current = 0x33;
    }
}
