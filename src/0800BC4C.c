#include "ffta.h"

typedef struct {
    u8 unknown_00[0x10];
    u16 flags;
    u8 unknown_12[0x16];
} Record0800BC4C;

extern Record0800BC4C g_records_02009000[];

void func_0800BC4C(u8 index, u8 enabled)
{
    if (enabled)
        g_records_02009000[index].flags |= 1;
    else
        g_records_02009000[index].flags &= 0xFFFE;
}
