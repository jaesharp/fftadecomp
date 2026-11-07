#include "ffta.h"

/* Target: 080035D0, complete 40-byte Thumb function. */
extern const u16 g_object_08149558[];
extern void *func_081443FC(void *destination, const void *source, u32 bytes);

u16 func_080035D0(u8 index)
{
    u16 values[4];

    func_081443FC(values, g_object_08149558, sizeof(values));
    return values[index];
}
