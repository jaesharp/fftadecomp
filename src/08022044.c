#include "ffta.h"

typedef struct {
    u8 unknown_00[8];
    void *entries;
} Owner08022044;

int func_08022194(void *entry, u8 *result);
void func_080C7CC0(void *entries, int (*callback)(void *, u8 *), u8 *result);

/* 0x08022044: 36 bytes, including alignment and the callback literal. */
u8 func_08022044(Owner08022044 *owner)
{
    u8 result = 1;

    func_080C7CC0(owner->entries, func_08022194, &result);
    return result;
}
