// func_081413F8 - 0x081413F8, 50 bytes (0x081413F8 .. 0x0814142A plus the
// literal pool at 0x0814142C).
//
// Allocates a 0x714-byte object, hands it to the callback whose address is
// held in the cartridge-ROM word at 0x0836D4B8 - that callback lives in IWRAM
// (0x03005E79), so the call goes through agbcc's `bx r2` thunk at 0x0814224C.
// The object then gets a pointer to the read-only table at 0x083A93A4 and the
// halfword right behind it is set to 1.  The object is returned.
//
// The two fields are at +0x6C4 and +0x6C8; what lives in front of them is not
// identified yet, so it is named `unknown_00` rather than filled in with
// invented members - these offsets come from the instructions, not from
// knowledge of the struct.
//
// The object size 0x714 is used twice, so agbcc keeps it in r5 across the
// allocation call.

#include "ffta.h"

typedef void (*ObjectFunc)(void *, u32);

typedef struct {
    u8 unknown_00[0x6C4];
    u32 *unknown_6C4;
    u16 unknown_6C8;
} Object081413F8;

extern Object081413F8 *func_0813C0C4(u32 size);

Object081413F8 *func_081413F8(void)
{
    Object081413F8 *object = func_0813C0C4(0x714);
    // plausible: a read-only table in the cartridge ROM, holding the callback
    u32 *table = (u32 *)0x0836D4B8;

    ((ObjectFunc)(*table))(object, 0x714);
    // plausible: a read-only table in the cartridge ROM, pointed at by the object
    object->unknown_6C4 = (u32 *)0x083A93A4;
    object->unknown_6C8 = 1;

    return object;
}
