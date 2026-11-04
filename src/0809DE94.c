#include "ffta.h"

typedef struct Context Context;

typedef struct {
    u8 unknown_000[0x104];
    u8 order;
    u8 unknown_105[3];
} Record0809DE94;

typedef struct {
    Record0809DE94 *record;
} Entry0809DE94;

typedef struct {
    s32 count;
    Record0809DE94 records[13];
    Entry0809DE94 *entries[43];
    Context *context;
} Output;

typedef void (*BufferInitializer)(void *destination, u32 size);
typedef void (*BufferCopier)(void *destination, const void *source, u32 size);
extern BufferInitializer g_callbacks_0836D4B8[];
extern BufferCopier data_0836D4BC;
extern s32 func_08099CDC(Context *context, Entry0809DE94 **entries);

/* Complete target [0x0809DE94, 0x0809DF7C): 232 bytes, 102 instructions. */
void func_0809DE94(Output *output, Context *context)
{
    s32 i;
    s32 j;

    g_callbacks_0836D4B8[0](output, sizeof(*output));
    output->context = context;
    output->count = func_08099CDC(context, output->entries);
    for (i = 0; i < output->count - 1; i++) {
        for (j = i + 1; j < output->count; j++) {
            if (output->entries[i]->record->order >
                output->entries[j]->record->order) {
                Entry0809DE94 *entry = output->entries[i];
                output->entries[i] = output->entries[j];
                output->entries[j] = entry;
            }
        }
    }
    for (i = 0; i < output->count; i++) {
        data_0836D4BC(&output->records[i], output->entries[i]->record,
                      sizeof(output->records[i]));
    }
}
