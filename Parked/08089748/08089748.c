#include "ffta.h"

extern u8 data_08393E0F[];
extern s32 func_081426B8(s32 numerator, s32 denominator);

/* Complete [0x08089748, 0x080897C4): 124 bytes, 57 instructions.
 * Target bytes:
 * f0b509040d0c2e1c1204120c111c1b041f0c041c002a01d100210de0954201d8
 * 142109e0880040188000401a311cb8f09fff01300004010c880040180004010c
 * 381c36302080023400220a4d031c48190078c01820800234501c0004020c481c
 * 0004010c042af2d9034978182080f0bc01bc00470f3e390836040000
 */
void func_08089748(u16 *output, u16 first, u16 second, u16 third)
{
    u16 value;
    u16 index;
    u16 i;

    if (second == 0)
        value = 0;
    else if (first <= second)
        value = 20;
    else
        value = func_081426B8(second * 19, first) + 1U;

    index = value * 5;
    *output++ = third + 0x36;
    for (i = 0; i < 5; i++) {
        *output++ = third + 0x36 + data_08393E0F[index];
        index++;
    }
    *output = third + 0x436;
}
