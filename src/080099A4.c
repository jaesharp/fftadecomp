#include "ffta.h"

extern u32 g_state_03000890[][2];

u8 func_080099A4(u32 handle)
{
    u8 result = 0;

    if (g_state_03000890[handle][1] == 0)
        result = 1;
    return result;
}
