#include "ffta.h"

extern void func_080A92E4(s32 mode, s32 x, s32 height, s32 y, s32 effect);

/* Complete [0x080DD2C8, 0x080DD302): 58 bytes. */
void func_080DD2C8(void *object, u8 effect)
{
    s16 x;
    s16 y;
    s16 z;

    func_080DBD5C(object, &x, &y, &z);
    func_080A92E4(0, x, (s16)(y + 0x38), z, effect);
}
