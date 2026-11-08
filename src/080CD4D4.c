#include "ffta.h"

extern const u8 *const g_table_0851BA84[];

/* Complete target [0x080CD4D4, 0x080CD50A), 54 bytes. */
u32 func_080CD4D4(const u8 *object)
{
    u32 has_index;

    if (object)
        has_index = object[0x3a];
    else
        has_index = 0;
    if (!has_index)
        return 0;
    {
        u32 kind = object[6];
        u32 index = object[0x3a];
        u32 table_base = (u32)g_table_0851BA84;
        const u32 *entry_address = (const u32 *)(table_base + kind * sizeof(g_table_0851BA84[0]));
        u32 entry_offset = index * 8;

        return *(const u8 *)(*entry_address + entry_offset + 4);
    }
}
