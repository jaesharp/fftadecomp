#include "ffta.h"

extern u16 *func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
extern void func_0808B7C0(s32 index, u16 *destination, u16 tile,
                         u16 count, u16 flags);
extern void func_0808B80C(u32 index, u16 *destination, u16 tile,
                         u32 count, u16 flags);

/* Target [0x0808C9C4,0x0808CACC), 264 bytes, 100 instructions. */
void func_0808C9C4(void)
{
    func_0808B7C0(6, func_0808B8E4(6, 1, 1, 1), 0x30D, 11, 0xB000);
    func_0808B7C0(6, func_0808B8E4(6, 1, 1, 5), 0x323, 11, 0xB000);
    func_0808B7C0(6, func_0808B8E4(6, 1, 1, 9), 0x339, 11, 0xB000);
    func_0808B7C0(6, func_0808B8E4(6, 1, 1, 13), 0x34F, 11, 0xB000);
    func_0808B80C(6, func_0808B8E4(6, 1, 1, 7), 0x365, 4, 0xC000);
    func_0808B80C(6, func_0808B8E4(6, 1, 1, 11), 0x36D, 4, 0xC000);
    func_0808B80C(6, func_0808B8E4(6, 1, 1, 15), 0x375, 4, 0xC000);
    func_0808B7C0(6, func_0808B8E4(6, 1, 7, 3), 0x37D, 5, 0xE000);
}
