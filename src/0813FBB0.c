#include "ffta.h"

/* The complete wrapper passes R0-R2 to SWI 0x0B.  This conditional call
 * view does not assert BIOS effects or destination bounds. */
extern void func_0814186C(const void *source, void *destination, u32 control);

/* 0813FBB0: complete 36-byte target, 15 instructions and one literal. */
void func_0813FBB0(void *destination, u16 value, u16 bank)
{
    u16 fill = value | (bank << 12);
    func_0814186C(&fill, destination, 0x01000400);
}
