#include "ffta.h"

typedef struct {
    u16 unknown_00;
    u16 attributes;
} Attributes0800BF04;

/* Complete target [0x0800BF04, 0x0800BF50): 76 bytes, 32 instructions. */
/* Target bytes: 10b509061206120e031c002905d059888024e401201c084302e05988054808405880002a08d0598880221202101c084305e00000ffbf0000598803480840588010bc01bc00470000ff7f0000 */
void func_0800BF04(void *opaque, u8 first, u8 second)
{
    Attributes0800BF04 *object = opaque;

    if (first)
        object->attributes |= 0x4000;
    else
        object->attributes &= 0xBFFF;
    if (second)
        object->attributes |= 0x8000;
    else
        object->attributes &= 0x7FFF;
}
