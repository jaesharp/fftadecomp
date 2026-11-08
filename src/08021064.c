#include "ffta.h"

typedef struct __attribute__((packed)) {
    u8 data0;
    u8 shape;
    u8 data2;
    u8 size;
    u8 data4;
    u8 data5;
} SpriteEntry;

typedef struct __attribute__((packed)) {
    u16 count;
    SpriteEntry entries[0];
} SpriteList;

s32 func_08021064(SpriteList *list)
{
    SpriteEntry *entry = list->entries;
    s32 total = 0;
    s32 index = 0;

    if (index < list->count) {
        do {
        if ((entry->shape >> 6) == 0) {
            switch (entry->size >> 6) {
            case 0:
                total += 1;
                break;
            case 1:
                total += 4;
                break;
            case 2:
                total += 16;
                break;
            default:
                total += 64;
                break;
            }
        } else {
            switch (entry->size >> 6) {
            case 0:
                total += 2;
                break;
            case 1:
                total += 4;
                break;
            case 2:
                total += 8;
                break;
            default:
                total += 32;
                break;
            }
        }
            index++;
            entry++;
        } while (index < list->count);
    }
    return total;
}
