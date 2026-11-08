#include "ffta.h"

/* 0x08013A5C..0x08013A86: 42 bytes.
 * 00b50004020c0548c07c00280ad10449100400144018007805e00000d0200002b0664908102002bc0847
 */
typedef struct {
    u8 unknown_00[0x13];
    u8 mode;
} State08013A5C;

extern State08013A5C g_state_020020D0;
extern const u8 data_084966B0[];

u8 func_08013A5C(u16 index)
{
    u8 result;

    if (g_state_020020D0.mode == 0)
        result = data_084966B0[(s16)index];
    else
        result = 0x10;
    return result;
}
