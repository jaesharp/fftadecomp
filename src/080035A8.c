#include "ffta.h"

extern const u8 g_object_08149550[];
extern void *func_081443FC(void *, const void *, u32);

u16 func_080035A8(u8 index)
{
    u16 values[4];

    func_081443FC(values, g_object_08149550, sizeof(values));
    return values[index];
}
