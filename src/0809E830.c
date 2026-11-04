#include "ffta.h"

typedef struct Context Context;
typedef struct {
    u8 unknown_00[0xEA];
    u8 flags;
} Unit;
typedef struct {
    u8 unknown_00[0xD0];
    u16 field_D0;
    u16 unknown_D2;
    u16 field_D4;
    u8 unknown_D6[0x108 - 0xD6];
} Record0809E830;
typedef struct {
    Unit *record;
} Entry0809E830;
typedef struct {
    s32 count;
    Record0809E830 records[13];
    Entry0809E830 *entries[43];
    Context *context;
} Output0809E830;

void *func_08022840(u32 size);
void func_08022854(u8 *object);
void func_0809DE94(Output0809E830 *output, Context *context);
u32 func_0809E1E0(Output0809E830 *output);
u8 func_080CDADC(Unit *unit);
u8 func_080CDB24(const void *object);
u8 func_0812E4A8(const void *object);

/* Complete target [0x0809E830, 0x0809E8F8): 200 bytes. */
s32 func_0809E830(Context *context, Entry0809E830 *entry, u16 steps)
{
    Output0809E830 *output;
    s32 i;
    u32 index;

    if (entry == 0)
        return -1;
    if (!func_0812E4A8(entry->record) ||
        func_080CDB24(entry->record) || func_080CDADC(entry->record))
        return -1;
    output = func_08022840(sizeof(*output));
    func_0809DE94(output, context);
    for (i = 0; i < (s16)steps; i++) {
        u8 *record_base;
        index = func_0809E1E0(output);
        record_base = (u8 *)(
            index * sizeof(Record0809E830) + (u32)output);
        *(u16 *)(record_base + 0xD8) = 0;
        *(u16 *)(record_base + 0xD4) = 0;
    }
    for (;;) {
        u8 *record_base;
        index = func_0809E1E0(output);
        record_base = (u8 *)(
            index * sizeof(Record0809E830) + (u32)output);
        *(u16 *)(record_base + 0xD8) = 0;
        *(u16 *)(record_base + 0xD4) = 0;
        if (entry == output->entries[index])
            break;
        i++;
    }
    func_08022854((u8 *)output);
    return i;
}
