#include "ffta.h"

typedef struct {
    u8 unknown00[0x24];
    u32 flags;
} FlagObject;

/* 0x0809A0D4, 30 bytes. */
void func_0809A0D4(FlagObject *object, s32 enabled)
{
    if (enabled)
        object->flags &= ~2;
    else
        object->flags |= 2;
}
