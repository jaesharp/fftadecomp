#include "ffta.h"

extern void func_08019A50(u16 value, u8 *id, u16 *offset);
extern void func_0801174C(void *context, u8 kind, u16 selection,
                          void *first, void *second, u32 field5, s32 field6,
                          u32 width, u32 height, u32 tile);
extern void func_0801339C(u16 value);

/* Complete target [0x08019A8C, 0x08019AE2): 86 bytes, 40 instructions.
 * 70b5464640b487b0061c081c90461d1c0004000c6c461a3406a9221cfff7d2ff
 * 06a80178228800950220019002901820039004200490e82080000590301c4346
 * f7f73efe0220f9f763fc07b008bc984670bc01bc0047
 */
void func_08019A8C(void *context, u16 value, void *first, void *second)
{
    u8 id;
    u16 offset;

    func_08019A50(value, &id, &offset);
    func_0801174C(context, id, offset, first, second, 2, 2, 24, 4, 0x3A0);
    func_0801339C(2);
}
