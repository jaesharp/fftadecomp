#include "ffta.h"

extern void func_0802979C(void *context, void *tiles, u32 number,
                          u8 digits, u8 style);
extern void func_08013A88(void *destination, u16 count);

void func_0805862C(void *context, u8 *tiles, u8 value)
{
    u8 digit = value / 10U;

    if (digit)
        func_0802979C(context, tiles, digit, 1, 0);
    else
        func_08013A88(tiles, 2);

    tiles += 0x40;
    func_0802979C(context, tiles, (u8)(value % 10U), 1, 0);
}
