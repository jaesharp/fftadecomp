#include "ffta.h"

/* 080116DC..08011710: complete 52-byte target, 26 instructions.
 * 00b5031c1868026802e0d26b002a0ed0507f002806d0012804d0918a802008400028
 * 01d0012000e000200028edd15a6001bc0047
 */
typedef struct Entry080116DC Entry080116DC;
struct Entry080116DC {
    u8 unknown_00[0x14];
    u16 field_14;
    u8 unknown_16[7];
    u8 field_1D;
    u8 unknown_1E[0x1E];
    Entry080116DC *next;
};

typedef struct {
    Entry080116DC **source;
    Entry080116DC *value;
} Snapshot080116DC;

static inline u8 should_skip(Entry080116DC *entry)
{
    if (entry->field_1D == 0)
        return 1;
    if (entry->field_1D == 1)
        return 1;
    if (entry->field_14 & 0x80)
        return 1;
    return 0;
}

void func_080116DC(Snapshot080116DC *snapshot)
{
    Entry080116DC *entry = *snapshot->source;

    while (should_skip(entry)) {
        entry = entry->next;
        if (entry == 0)
            break;
    }
    snapshot->value = entry;
}
