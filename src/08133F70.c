#include "ffta.h"

typedef struct {
    u8 unknown_00[0x35];
    u8 mode_1;
    u8 mode_2;
    u8 mode_3;
} AbilityRecord;

typedef struct {
    u8 unknown_00[4];
    u16 identifier;
    u8 kind;
    u8 unknown_07;
} AbilityEntry;

extern u8 func_080C8298(const void *);
extern const AbilityEntry *func_080CCE60(AbilityRecord *, u8, u8 *, u8 *);
extern u8 func_08133BC4(void *);
extern u32 func_080CB388(u32);
extern u8 func_080CB2B4(u32);
extern u8 func_080CD560(const void *, u8);
extern u32 func_08133F48(u16, const u16 *, s32);
extern u8 func_08133E18(void *, u16, s8);

/* The record view and conditional call widths describe the actual accesses.
 * The callee entries establish transport, not a capacity or effect premise. */
u32 func_08133F70(u16 *output, AbilityRecord *record, u8 filter)
{
    u8 first;
    u8 last;
    u32 count = 0;
    u32 mode = 0;
    s32 group;

    if (func_080C8298(record))
        return 0;

    for (group = 0; group < 3; group++) {
        const AbilityEntry *entries = func_080CCE60(record, group + 1, &first, &last);

        switch (group) {
        case 0:
            mode = record->mode_1;
            break;
        case 1:
            mode = record->mode_2;
            break;
        case 2:
            mode = record->mode_3;
            break;
        }

        if (mode != 0) {
            const AbilityEntry *entry = entries + first;
            s32 index;

            for (index = first; index <= last; index++, entry++) {
                if (entry->kind != 1 && entry->kind != 4)
                    continue;

                if (mode == 1) {
                    if (func_08133BC4(record) == 1 &&
                        !func_080CB2B4((u16)func_080CB388((u8)index)))
                        continue;
                } else if (!func_080CD560(record, index)) {
                    continue;
                }

                if ((u8)func_08133F48(entry->identifier, output, count))
                    continue;
                if (!func_08133E18(record, entry->identifier, (s8)filter))
                    continue;
                output[count++] = entry->identifier;
            }
        }
    }
    return count;
}
