#include "ffta.h"

extern void func_080A92E4(s32 mode, s32 x, s32 height, s32 y, s32 effect);

/* Complete [0x080DD248, 0x080DD288): 64 bytes.
 * Target: 70b583b00c04240c6d46063502ae01a92a1c331cfef77efd24042414
 *         01a80022815e2a883832120412140020335e00200090201cccf732f8
 *         03b070bc01bc0047
 */
void func_080DD248(void *object, s16 value)
{
    s16 x;
    s16 y;
    s16 z;

    func_080DBD5C(object, &x, &y, &z);
    func_080A92E4(value, x, (s16)(y + 0x38), z, 0);
}
