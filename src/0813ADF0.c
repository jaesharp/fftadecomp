#include "ffta.h"

extern const u32 g_table_08393318[256];

/* Complete [0x0813ADF0, 0x0813AE30): 64 bytes, 28 instructions. */
u32 func_0813ADF0(const u8 *bytes, u32 length, u32 crc)
{
    u16 index;

    crc = ~crc;
    for (index = 0; index < length; index++) {
        u8 table_index = bytes[index];

        table_index ^= crc;

        crc = ((crc >> 8) & 0x00FFFFFF) ^ g_table_08393318[table_index];
    }
    crc = ~crc;
    return crc;
}
