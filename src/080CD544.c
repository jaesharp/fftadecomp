#include "ffta.h"

typedef struct {
    u8 unknown_00[0x40];
    u8 flags[0];
} FlagObject;

void func_080CD544(FlagObject *object, u8 index)
{
    if (object != 0) {
        object->flags[index] |= 0x80;
    }
}
