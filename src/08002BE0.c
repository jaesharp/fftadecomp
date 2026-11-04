#include "ffta.h"

/* Target [0x08002BE0, 0x08002C06), 38 bytes:
 * 10 b5 03 1c 0c 1c 12 04 12 0c 04 e0 18 88 11 1c 01 43 19 80 02 33 20 78 18 80 01 34 00 28 f5 d1 10 bc 01 bc 00 47
 */
void func_08002BE0(u16 *destination, const u8 *source, u16 mask)
{
    while ((*destination = *source++) != 0) {
        *destination |= mask;
        destination++;
    }
}
