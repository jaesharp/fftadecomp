#include "ffta.h"

extern u8 data_02009160;

/* Complete target [0x0800FFF8, 0x08010004): 12 bytes. */
void func_0800FFF8(u8 value)
{
    data_02009160 = value;
}
