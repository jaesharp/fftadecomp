#include "ffta.h"

typedef struct {
    u8 unknown_00[0x35];
    u8 first;
    u8 second;
    u8 third;
} Record08133D78;

typedef struct {
    u16 id;
    u8 kind;
    u8 unknown_03[5];
} Entry08133D78;

extern const u8 *func_080CCE60(Record08133D78 *record, u8 mode,
                               u8 *first, u8 *last);

/* Complete target [0x08133D78, 0x08133E16), 158 bytes. */
u32 func_08133D78(Record08133D78 *record, u16 id)
{
    u32 value = 0;
    s32 mode;
    u8 first;
    u8 last;

    for (mode = 0; mode < 3; mode++) {
        const u8 *table = func_080CCE60(record, mode + 1, &first, &last);

        switch (mode) {
        case 0:
            value = record->first;
            break;
        case 1:
            value = record->second;
            break;
        case 2:
            value = record->third;
            break;
        }
        if (value != 0) {
            s32 index;

            for (index = first; index <= last; index++) {
                const Entry08133D78 *entry =
                    (const Entry08133D78 *)(table + 4) + index;

                if ((entry->kind == 1 || entry->kind == 4) && entry->id == id)
                    return value;
            }
        }
    }
    return 0;
}
