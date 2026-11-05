#include "ffta.h"

/* Complete [0x080CD9A4, 0x080CD9BC): 24 bytes. */
typedef struct {
    u8 unknown_00[0xE9];
    u8 flags;
} ObjectFlags;

u8 func_080CD9A4(const ObjectFlags *object)
{
    const u8 *flags = &object->flags;
    u8 mask = 0x08;

    if (!(*flags & mask))
        return 0;
    return 1;
}
