#include "ffta.h"

typedef struct Context Context;

typedef struct {
    u8 unknown_000[0x104];
    u8 order;
    u8 unknown_105[3];
} Record0809F850;

typedef struct {
    Record0809F850 *record;
    u8 unknown_04[0x24];
    u32 field_28;
} Entry0809F850;

typedef struct {
    s32 count;
    Record0809F850 records[13];
    Entry0809F850 *entries[26];
    u32 saved_values[17];
    Context *context;
} Output0809F850;

typedef void (*BufferCopier)(void *, const void *, u32);
extern BufferCopier data_0836D4BC;
extern void *func_08022840(u32);
extern void func_08022854(u8 *);
extern void func_0809DE94(Output0809F850 *, Context *);
extern u32 func_0809E1E0(Output0809F850 *);

/* Complete target [0x0809F850, 0x0809F8EC), 156 bytes. */
Entry0809F850 *func_0809F850(Context *context)
{
    Output0809F850 *output = func_08022840(sizeof(*output));
    u32 selected;
    s32 i;
    Entry0809F850 *entry;

    func_0809DE94(output, context);
    selected = func_0809E1E0(output);
    for (i = 0; i < output->count; i++) {
        data_0836D4BC(output->entries[i]->record, &output->records[i],
                      sizeof(output->records[i]));
        output->entries[i]->field_28 = output->saved_values[i];
    }
    entry = output->entries[selected];
    func_08022854((u8 *)output);
    return entry;
}
