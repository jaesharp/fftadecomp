#include "ffta.h"

typedef struct {
    u32 field_00;
    u8 unknown_04[4];
    u8 active;
    u8 unknown_09[3];
} ActiveRecord;

/* 0x080BA7FC..0x080BA816: 26 bytes. */
void func_080BA7FC(ActiveRecord *records)
{
    s32 index = 12;

    records[0].field_00 = 0;
    do {
        records[index].active = 0;
        index--;
    } while ((s32)((u32)records + index * sizeof(ActiveRecord)) >= (s32)records);
}
