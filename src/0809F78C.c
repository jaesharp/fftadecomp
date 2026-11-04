#include "ffta.h"

typedef struct Context Context;

typedef struct {
    u8 unknown_00[0xD0];
    u16 field_D0;
    u16 unknown_D2;
    u16 field_D4;
    u8 unknown_D6[0x108 - 0xD6];
} Record0809F78C;

typedef struct {
    Record0809F78C *record;
} Entry0809F78C;

typedef struct {
    s32 count;
    Record0809F78C records[13];
    Entry0809F78C *entries[43];
    Context *context;
} Output0809F78C;

void *func_08022840(u32 size);
void func_08022854(u8 *object);
void func_0809DE94(Output0809F78C *output, Context *context);
u32 func_0809E1E0(Output0809F78C *output);

/* Complete target [0x0809F78C, 0x0809F7F0): 100 bytes. */
u32 func_0809F78C(Context *context, Entry0809F78C **entries, u16 steps)
{
    Output0809F78C *output = func_08022840(sizeof(*output));
    s32 remaining;

    func_0809DE94(output, context);
    remaining = (s16)steps;
    if (remaining > 0) {
      do {
        u32 index = func_0809E1E0(output);
        u8 *record_base = (u8 *)(
            index * sizeof(Record0809F78C) + (u32)output);
        *(u16 *)(record_base + 0xD8) = 0;
        *(u16 *)(record_base + 0xD4) = 0;
        *entries++ = output->entries[index];
        remaining--;
      } while (remaining != 0);
    }
    func_08022854((u8 *)output);
    return 1;
}
