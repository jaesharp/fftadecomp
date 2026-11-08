#include "ffta.h"

typedef struct {
    u8 unknown_00[0x2c];
    u16 flags;
} State0801AE58;

extern State0801AE58 g_state_02007F40;

void func_0801AE58(u8 enabled)
{
    if (enabled)
        g_state_02007F40.flags |= 0x1000;
    else
        g_state_02007F40.flags &= 0xefff;
}
