#include "ffta.h"

/* Target: 080DBC94, complete 64-byte Thumb function. */
void func_080DBD78(const Struct080DBD5C *source,
                   s16 *tile_x, s16 *tile_y, s16 *tile_z);
s32 func_0809D6BC(s8 x, s8 z);

u8 func_080DBC94(const Struct080DBD5C *source, u16 tile_x, u16 tile_z)
{
    s16 x, y, z;

    func_080DBD78(source, &x, &y, &z);
    return func_0809D6BC((s8)((u8)x - tile_x),
                         (s8)((u8)z - tile_z));
}
