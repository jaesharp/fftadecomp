#include "ffta.h"

typedef struct {
    u8 value;
} ObjectFlagByte;

typedef struct {
    u8 unknown_00[0xE8];
    ObjectFlagByte flags;
} ObjectFlags;

u8 func_080CD92C(const ObjectFlags *object)
{
    const ObjectFlagByte *flags = &object->flags;
    u8 mask = 0x40;

    if (!(flags->value & mask))
        return 0;
    return 1;
}
