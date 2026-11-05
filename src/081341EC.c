#include "ffta.h"

typedef struct {
    u8 unknown_00[0x35];
    u8 override_1;
    u8 override_2;
    u8 override_3;
} Record081341EC;

typedef struct {
    u8 unknown_00[4];
    u16 identifier;
    u8 category;
    u8 unknown_07;
} Entry081341EC;

extern u8 func_080C8298(const void *object);
extern const u8 *func_080CCE60(Record081341EC *record, u8 mode,
                              u8 *first, u8 *last);
extern u8 func_080CD560(const void *object, u8 index);

/* Complete [0x081341EC, 0x081342A8): 188 bytes. */
u8 func_081341EC(Record081341EC *record)
{
    u32 override = 0;
    s32 group;
    u8 first, last;

    if (func_080C8298(record))
        return 0;
    for (group = 0; group < 3; group++) {
        const Entry081341EC *entries =
            (const Entry081341EC *)func_080CCE60(record, group + 1, &first, &last);
        const Entry081341EC *entry;
        s32 index;

        switch (group) {
        case 0:
            override = record->override_1;
            break;
        case 1:
            override = record->override_2;
            break;
        case 2:
            override = record->override_3;
            break;
        }
        if (override != 0) {
            entry = entries + first;
            for (index = first; index <= last; index++, entry++) {
                if ((entry->category == 1 || entry->category == 4) &&
                    override != 1 && func_080CD560(record, index) &&
                    entry->identifier == 0x21)
                    return 1;
            }
        }
    }
    return 0;
}
