#include "ffta.h"

typedef struct EffectPair {
    u8 marker;
    u8 value;
} __attribute__((packed)) EffectPair;

typedef struct EffectRecord {
    u8 count;
    u8 unknown01;
    EffectPair pairs[9];
} EffectRecord;

typedef struct EffectObject {
    u8 unknown_00[7];
    u8 category;
    u8 unknown_08[0x35];
    u8 default_value;
    u8 unknown_3E[2];
    u8 flags[0];
} EffectObject;

extern const EffectRecord g_table_08520080[];

s32 func_080CA7A4(u16 entry, u8 selector);
void func_080CD620(void *object, u8 index);

/* 0x080CCF44: complete 116-byte target, including the table literal. */
void func_080CCF44(EffectObject *record, u16 entry)
{
    const EffectRecord *effects;
    s32 index;

    if (entry == 0)
        return;

    effects = &g_table_08520080[func_080CA7A4(entry, 0x12)];
    for (index = 0; index < effects->count; index++) {
        if (record->category == effects->pairs[index].marker) {
            u8 value = effects->pairs[index].value;

            if (record != 0) {
                record->flags[value] |= 0x80;
            }
            func_080CD620(record, effects->pairs[index].value);
        } else if (effects->pairs[index].marker == 0xFF) {
            record->default_value = effects->pairs[index].value;
        }
    }
}
