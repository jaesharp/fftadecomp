#include "ffta.h"

/* 08002C08..08002C36: 46 bytes.
 * 10b5031c0c1c1204120c04e01888111c0143198002332078188001340028f5d1023300201880181c10bc02bc0847
 */
u16 *func_08002C08(u16 *destination, const u8 *source, u16 mask)
{
    while ((*destination = *source++) != 0) {
        *destination |= mask;
        destination++;
    }

    destination++;
    *destination = 0;
    return destination;
}
