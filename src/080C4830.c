#include "ffta.h"

typedef struct {
    u32 value;
    u8 unknown_04[0x324];
} Record080C4830;

/* Complete [0x080C4830, 0x080C486C): 60 bytes, 26 instructions. */
s16 func_080C4830(void *object, u32 *output)
{
    u32 base = (u32)object;
    s32 index;

    for (index = 0; index < *(u16 *)(base + 0x5270); index++) {
        u32 displacement = index * sizeof(Record080C4830);
        u32 records = base + 0x2968;

        *output++ = *(u32 *)(displacement + records);
    }
    return *(s16 *)(base + 0x5270);
}
