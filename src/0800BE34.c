#include "ffta.h"

/* 0x0800BE34..0x0800BE58: 36 bytes, including the clear mask. */
typedef struct {
    u8 unknown_00[2];
    u16 flags;
} Object0800BE34;

void func_0800BE34(Object0800BE34 *object, u32 enabled)
{
    if (enabled != 0)
        object->flags |= 0x0800;
    else
        object->flags &= 0xf7ff;
}
