#include "ffta.h"

typedef struct {
    u32 value;
    u8 unknown_04[0x0C];
} SlotRecord;

extern u8 g_state_02000000[];
extern s32 func_080C9428(const void *object);

SlotRecord *func_0812F124(const void *object)
{
    s32 index = func_080C9428(object);

    if (index >= 0) {
        u32 base = (u32)g_state_02000000;
        u32 displacement = index * sizeof(SlotRecord);

        if (*(const u32 *)(base + displacement + 0x2E78) == 0) {
            u32 table = base + 0x2E78;
            return (SlotRecord *)(displacement + table);
        }
    }
    return 0;
}
