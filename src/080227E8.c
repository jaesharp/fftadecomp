#include "ffta.h"

typedef void (*BufferInitializer080227E8)(void *destination, u32 size);

extern u8 g_state_02000000[];
extern u8 *data_0200F434;
extern BufferInitializer080227E8 const g_callbacks_0836D4B8[];
extern u8 *func_080070C8(u8 *storage, u32 byte_count);

/* Complete [0x080227E8, 0x0802282C): 68 bytes, 26 instructions. */
void func_080227E8(void)
{
    u32 start = (u32)(g_state_02000000 + 0x159D0);
    u32 size;

    if (start & 3) {
        start &= ~3;
        start += 4;
    }
    size = 0x02040000 - start;
    g_callbacks_0836D4B8[0]((void *)start, size);
    data_0200F434 = func_080070C8((u8 *)start, size);
}
