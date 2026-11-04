#include "ffta.h"

typedef struct Context Context;

typedef struct {
    u8 unknown_00[0xD0];
    u16 field_D0;
    u16 unknown_D2;
    u16 field_D4;
    u8 unknown_D6[0x108 - 0xD6];
} Record0809F7F0;

typedef struct {
    Record0809F7F0 *record;
} Entry0809F7F0;

typedef struct {
    s32 count;
    Record0809F7F0 records[13];
    Entry0809F7F0 *entries[43];
    Context *context;
} Output0809F7F0;

void *func_08022840(u32 size);
void func_08022854(u8 *object);
void func_0809DE94(Output0809F7F0 *output, Context *context);
u32 func_0809E1E0(Output0809F7F0 *output);

/* Complete target [0x0809F7F0, 0x0809F850): 96 bytes. */
Entry0809F7F0 *func_0809F7F0(Context *context, u16 steps)
{
    Output0809F7F0 *output = func_08022840(sizeof(*output));
    Entry0809F7F0 *entry;
    s32 i;

    func_0809DE94(output, context);
    entry = 0;
    for (i = 0; i < (s16)steps; i++) {
        u32 index = func_0809E1E0(output);
        u8 *record_base = (u8 *)(
            index * sizeof(Record0809F7F0) + (u32)output);
        *(u16 *)(record_base + 0xD8) = 0;
        *(u16 *)(record_base + 0xD4) = 0;
        entry = output->entries[index];
    }
    func_08022854((u8 *)output);
    return entry;
}
