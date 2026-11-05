// 0x080098F4..0x08009920: four two-word registration slots.
#include "ffta.h"

extern u32 g_object_03000890[][2];

s32 func_080098F4(u32 callback, u32 context)
{
    s32 index = 0;
    u32 (*record)[2];

    for (record = g_object_03000890; index < 4; ++record, ++index) {
        if ((*record)[1] == 0) {
            (*record)[1] = callback;
            (*record)[0] = context;
            return index;
        }
    }
    return 0;
}
