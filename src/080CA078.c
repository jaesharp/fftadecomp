#include "ffta.h"

extern u8 g_state_02000080[];

/* Complete target [0x080CA078, 0x080CA0BC), 68 bytes. */
u8 func_080CA078(void)
{
    s32 total = 0;
    s32 count = 0;
    u32 state = (u32)g_state_02000080;
    const u8 *record = (const u8 *)(state + 4);
    s32 remaining;

    for (remaining = 0; remaining < 24; remaining++) {
        if (record[0] != 0) {
            total += record[5];
            count++;
        }
        record += 0x108;
    }
    {
        s32 result;

        if (count != 0) {
            result = total / count;
            if (result == 0)
                result = 1;
        } else {
            result = 1;
        }
        return result;
    }
}
