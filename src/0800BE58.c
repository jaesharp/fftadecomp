#include "ffta.h"

typedef struct {
    u16 unknown_00;
    u16 flags;
} Object0800BE58;

/* Complete 0800BE58..0800BE78, 32 bytes. Target:
00b5021c002903d051888020084302e0518802480840508001bc00477fff0000 */
void func_0800BE58(Object0800BE58 *object, s32 enabled)
{
    if (enabled)
        object->flags |= 0x80;
    else
        object->flags &= ~0x80;
}
