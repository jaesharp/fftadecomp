#include "ffta.h"

typedef struct {
    u8 unknown_00[0x14];
    u32 flags;
} Object080C7E94;

/* Target [0x080C7E94, 0x080C7EA2): 4169022252421140416101207047. */
int func_080C7E94(Object080C7E94 *object)
{
    object->flags &= ~1u;
    return 1;
}
