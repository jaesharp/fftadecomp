#include "ffta.h"

/* Complete [0x080CB9CC, 0x080CB9E0): 20 bytes, 8 instructions. */
extern const u8 data_083D3D14[];

u32 func_080CB9CC(u16 category)
{
    return data_083D3D14[category * 2 + 4] >> 4;
}
