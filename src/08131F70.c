#include "ffta.h"

typedef struct {
    u8 unknown_00[0x1F64];
    u32 value;
} AdjustmentState;

extern AdjustmentState g_state_02000000;

typedef struct {
    u8 unknown_00[8];
    void *record;
    u8 unknown_0C[0x14];
    s16 values[0];
} AdjustmentObject;

u8 func_08131BB8(void *record);

/* 08131F70..08131FD4: 100 bytes. */
void func_08131F70(AdjustmentObject *object)
{
    u8 *bytes = (u8 *)object;
    u16 flags = *(u16 *)(bytes + 0x26) & 0x10;
    s32 amount;
    u32 remaining;

    if (flags == 0) {
        amount = object->values[bytes[0x28]];
        if (amount < 0)
            amount = -amount;
        if (func_08131BB8(object->record)) {
            if (func_08131BB8(object->record)) {
                remaining = g_state_02000000.value - amount;
                if ((s32)remaining <= 0)
                    g_state_02000000.value = 0;
                else
                    g_state_02000000.value = remaining;
            }
        }
    }
}
