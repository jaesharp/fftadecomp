#include "ffta.h"

typedef struct {
    u8 unknown_00[0x28];
    u16 flags;
} FlaggedObject;

extern u8 func_080C82B8(const FlaggedObject *object);
extern u8 func_080C832C(const FlaggedObject *object);

/* Complete [0x0802C7E0, 0x0802C830): 80 bytes. */
void func_0802C7E0(u16 *tiles, const FlaggedObject *object)
{
    if (func_080C82B8(object)) {
        tiles[49] = 0xD0D8;
        tiles[66] = 0xD0D9;
        tiles[50] = 0xD0DA;
    }
    if (func_080C832C(object))
        tiles[82] = 0xD0D7;
}
