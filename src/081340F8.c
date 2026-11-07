#include "ffta.h"

/* 0x081340F8: complete 68-byte indexed-record search. */
typedef struct {
    u8 unknown_00[0x34];
    u8 count;
} SearchObject081340F8;

typedef struct {
    u8 unknown_00[4];
    u16 key;
} SearchEntry081340F8;

extern s32 func_080C7EA4(const void *object, u32 selector);
extern const u8 *func_080CD480(u8 first, u8 second);

u16 func_081340F8(const SearchObject081340F8 *object, u16 key)
{
    int index;

    for (index = 1; index < object->count; index++) {
        const SearchEntry081340F8 *entry = (const SearchEntry081340F8 *)
            func_080CD480((u8)func_080C7EA4(object, 3), (u8)index);
        if (entry->key == key)
            return index;
    }
    return 65535;
}
