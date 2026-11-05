#include "ffta.h"

typedef struct {
    u16 identifier;
    u8 quantity;
    u8 unknown_03;
} InventoryRecord;

extern InventoryRecord *func_080CB210(u32 identifier, s32 *count);

/* Complete [0x080CC86C, 0x080CC8B4): 72 bytes. */
u16 func_080CC86C(u16 identifier)
{
    s32 count;
    InventoryRecord *records = func_080CB210(identifier, &count);
    u16 i;

    for (i = 0; i < count; i++) {
        if (records[i].identifier == identifier && records[i].quantity != 0)
            return i;
    }
    return 0xFFFF;
}
