#include "ffta.h"

extern void func_080A92E4(s32 mode, s32 x, s32 height, s32 y, s32 effect);

/* Complete [0x080DD304, 0x080DD33C): 56 bytes.
 * Target: 30b583b06c46063402ad01a9221c2b1cfef722fd01a80022815e2288
 *         38321204121400202b5e152000900020cbf7d8ff03b030bc01bc0047
 */
void func_080DD304(void *object)
{
    s16 x;
    s16 y;
    s16 z;

    func_080DBD5C(object, &x, &y, &z);
    func_080A92E4(0, x, (s16)(y + 0x38), z, 0x15);
}
