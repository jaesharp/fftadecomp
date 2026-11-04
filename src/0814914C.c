#include "ffta.h"

typedef void (*BufferInitializer14914C)(void *destination, u32 size);
extern u8 *data_0300616C;
extern u8 data_03006168;
extern BufferInitializer14914C g_callbacks_0836D4B8[];
extern void func_0814224C(void *destination, u32 size,
                         BufferInitializer14914C callback);

/* Complete [0x0814914C, 0x08149194): 72 bytes, 26 instructions. */
void func_0814914C(u8 *records, s32 count)
{
    u8 *record;
    s32 i;

    data_0300616C = records;
    data_03006168 = count;
    record = records;
    for (i = 0; i < data_03006168; i++, record += 0x98A)
        func_0814224C(record + 0x980, 8, g_callbacks_0836D4B8[0]);
}
