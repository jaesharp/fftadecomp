#include "ffta.h"

/* 080088D8..08008938: 96 bytes, including its two literal words. */
typedef struct {
    u8 value;
    u8 count;
    u8 width;
    u8 enabled;
} OptionEntry;

typedef struct {
    u8 unknown_00[0x338];
    OptionEntry entries[10];
} OptionState;

typedef struct {
    u16 count;
    u16 width;
    u16 unknown_04[8];
} OptionDefinition;

extern OptionState *data_02009188;
extern const OptionDefinition g_table_0836D4D4[];
extern u8 func_080094BC(u8 index, u8 read_value);

void func_080088D8(void)
{
    OptionEntry *entry = data_02009188->entries;
    s32 index = 0;
    u8 empty_value = 0;
    const OptionDefinition *definition = g_table_0836D4D4;

    do {
        entry->count = definition->count;
        entry->width = definition->width;
        if (index == 9) {
            entry->value = empty_value;
            entry->enabled = !func_080094BC((u8)index, 1);
        } else {
            entry->value = func_080094BC((u8)index, 1);
            entry->enabled = 1;
        }
        definition++;
        index++;
        entry++;
    } while (index <= 9);
}
