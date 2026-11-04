#include "ffta.h"

/* Complete 0x08018524..0x080185B8: 148 bytes, 58 instructions.
 * f0 b5 47 46 80 b4 06 1c 14 1c 09 04 0d 0c 24 06
 * 24 0e 20 1c ff f7 ee ff 07 1c 1e 2c 20 d1 0e 48
 * 80 46 ba 78 31 1c 01 23 ec f7 e4 fe 69 01 0b 4c
 * 09 19 30 1c 30 22 29 f1 87 f9 7a 78 40 46 31 1c
 * 01 23 ec f7 d7 fe e9 1c 49 01 09 19 30 1c 30 22
 * 29 f1 7a f9 14 e0 00 00 70 50 3d 08 00 80 00 06
 * 0a 48 ba 78 31 1c 01 23 ec f7 c4 fe 78 78 40 01
 * 30 18 69 01 06 4a 89 18 3a 78 12 01 29 f1 64 f9
 * 38 78 08 bc 98 46 f0 bc 02 bc 08 47 70 50 3d 08
 * 00 80 00 06
 */

extern const u32 *func_08018518(u32 index);
extern s32 func_08005318(const void *source, u8 *output,
                         u16 first, u16 count);
extern void func_0814186C(const void *source, void *destination, u32 control);
extern const u8 data_083D5070[];
extern u8 data_06008000[];

u32 func_08018524(u8 *buffer, u16 tile, u8 variant)
{
    const u8 *entry = (const u8 *)func_08018518(variant);

    if (variant == 30) {
        func_08005318(data_083D5070, buffer, entry[2], 1);
        func_0814186C(buffer, data_06008000 + tile * 32, 48);
        func_08005318(data_083D5070, buffer, entry[1], 1);
        func_0814186C(buffer, data_06008000 + (tile + 3) * 32, 48);
    } else {
        func_08005318(data_083D5070, buffer, entry[2], 1);
        func_0814186C(buffer + entry[1] * 32,
                       data_06008000 + tile * 32, entry[0] * 16);
    }
    return entry[0];
}
