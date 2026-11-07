#include "ffta.h"

/* Target: 0x080035F8, complete 40-byte Thumb function. */
extern const u8 g_object_08149558[];

void *func_081443FC(void *destination, const void *source, u32 byte_count);

u16 func_080035F8(u8 index)
{
    u16 values[4];

    func_081443FC(values, g_object_08149558, sizeof(values));
    return values[index];
}
