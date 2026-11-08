#include "ffta.h"

typedef void (*BufferCallback)(void *destination, const void *source, u32 size);

extern BufferCallback data_0836D4BC;
extern u8 g_state_02000000[];
extern void *func_08022840(u32 size);

/* 081351D8..0813522C: 84 bytes, including the three reached literal words. */
u32 func_081351D8(void)
{
    void *buffers[2];
    s32 i;

    for (i = 0; i < 2; i++) {
        buffers[i] = func_08022840(0x3CA8);
        data_0836D4BC(buffers[i], g_state_02000000, 0x3CA8);
    }
    for (i = 0; i < 2; i++)
        data_0836D4BC(g_state_02000000, buffers[i], 0x3CA8);
    return 0;
}
