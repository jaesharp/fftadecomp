#include "ffta.h"

typedef struct {
    u8 unknown_00[0x28];
    u16 flags;
    u8 unknown_2A[0xD9];
    u8 field_103;
    u8 field_104;
} Unit1337F4;

typedef struct {
    u32 unknown_00;
    Unit1337F4 *unit;
    u8 unknown_08[0x1E];
    u16 flags;
} State1337F4;

typedef struct {
    u8 unknown_0000[0x3C33];
    u8 count;
    u8 entries[0][2];
} Global1337F4;

extern Global1337F4 g_state_02000000;
extern u32 func_08002804(void);
extern s32 func_08142950(s32 numerator, s32 denominator);
extern void func_0802DC60(u8 first, u8 second, u32 third);
extern u8 func_080C95A8(u16 index);

/* Complete [0x081337F4, 0x0813388C): 152 bytes, 62 instructions. */
void func_081337F4(State1337F4 *state)
{
    if (!(state->flags & 0x10)) {
        if (g_state_02000000.count == 0) {
            state->flags |= 0x100;
        } else {
            u8 id;
            s32 selected;

            state->unit->flags |= 0x40;
            id = state->unit->field_104;
            selected = func_08142950((s16)func_08002804(), g_state_02000000.count);
            func_0802DC60(id, g_state_02000000.entries[selected][0], 0);
            if (state->unit->field_103 <= 8 && func_080C95A8(13) != 1)
                state->unit->field_103++;
        }
    }
}
