#include "ffta.h"

typedef struct {
    u16 identifier;
    u8 quantity;
    u8 unknown_03;
} InventoryRecord08067F14;

extern u8 data_08393ACA[];
extern InventoryRecord08067F14 *func_080CB210(u32 identifier, s32 *count);
extern u8 func_080CBD34(u16 identifier);

/* Complete [0x08067F14, 0x08067FB0): 156 bytes. */
u32 func_08067F14(InventoryRecord08067F14 **output, u8 key)
{
    u8 category = data_08393ACA[key];
    s32 count;
    InventoryRecord08067F14 *record;
    s32 written;
    s32 i;

    if (category != 5)
        record = func_080CB210(1, &count);
    else
        record = func_080CB210(0x16a, &count);
    written = 0;
    for (i = 0; i < count; i++, record++) {
        if (record->identifier == 0x33 || record->identifier == 0x94 ||
            record->identifier == 0x11e || record->identifier == 0x12e)
            continue;
        if (func_080CBD34(record->identifier) == category && record->quantity != 0) {
            if (output == 0)
                return 1;
            output[written] = record;
            written++;
        }
    }
    return written;
}
