#include "ffta.h"

typedef struct {
    u8 marker;
    u8 value;
} __attribute__((packed)) EffectPair;

typedef struct EffectRecord {
    u8 count;
    u8 unknown01;
    EffectPair pairs[9];
} EffectRecord;

typedef struct {
    u8 unknown_00[0x28];
    u16 flags;
} FlaggedObject;

typedef struct {
    u8 unknown_00[6];
    u8 selected[3];
    u8 default_value;
    u8 unknown_0A[2];
    u8 levels[0];
} ActionState;

typedef struct {
    u8 unknown_00[6];
    u8 category;
    u8 group;
    u8 unknown_08[0x22];
    u16 entries[5];
    ActionState actions;
} EntryObject;

extern const EffectRecord g_table_08520080[];

s32 func_080CA7A4(u16 entry, u8 selector);
const u8 *func_080CD480(u8 first, u8 second);
u8 func_080CD1FC(const void *object, u8 index);
void func_080CD620(void *object, u8 index);
u8 func_080C8240(void *data);
u8 func_080C8260(const FlaggedObject *object);
u8 func_080C9540(u16 bitIndex);
void func_080CAB24(u16 entry, u8 increment);
void func_080CCF44(void *object, u16 entry);

/* Complete target: [0x080CAF78, 0x080CB0D6), 350 bytes. */
void func_080CAF78(EntryObject *data, u16 entry, u8 slot)
{
    u16 old = data->entries[slot];

    if (old != 0) {
        const EffectRecord *effects;
        ActionState *actions;
        s32 index;

        if (entry == old)
            return;
        effects = &g_table_08520080[func_080CA7A4(old, 0x12)];
        actions = &data->actions;
        data->entries[slot] = 0;
        for (index = 0; index < effects->count; index++) {
            u8 marker = effects->pairs[index].marker;

            if (marker != 0) {
                if (marker == data->group) {
                    u8 value = effects->pairs[index].value;
                    u8 level = data->actions.levels[value] & 0x7F;

                    if (level < func_080CD480(data->category, value)[7] &&
                        !func_080CD1FC(data, value)) {
                        if (actions->selected[2] == value)
                            actions->selected[2] = 0;
                        else if (actions->selected[1] == value)
                            actions->selected[1] = 0;
                        else if (actions->selected[0] == value)
                            actions->selected[0] = 0;
                        actions->levels[value] &= 0x7F;
                        func_080CD620(data, value);
                    }
                } else if (marker == 0xFF && func_080CA7A4(old, 3) == 0x1B) {
                    actions->default_value = 0;
                }
            }
        }
    }
    if (!func_080C8240(data) &&
        !func_080C8260((const FlaggedObject *)data) &&
        !func_080C9540(0x3E)) {
        if (old != 0)
            func_080CAB24(old, 0);
        if (entry != 0)
            func_080CAB24(entry, 1);
    }
    data->entries[slot] = entry;
    func_080CCF44(data, entry);
}
