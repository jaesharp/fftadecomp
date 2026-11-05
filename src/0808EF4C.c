#include "ffta.h"

extern u16 data_0600E1A0[];
extern void func_0814186C(const void *source, void *destination, u32 control);
extern u16 *func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
extern void func_0808B858(int index, u16 *destination, u16 tile, u16 count);

/* Target: 68 bytes, 27 instructions, including two literal words. */
void func_0808EF4C(void)
{
    u16 zero;
    u16 *source = &zero;
    int row;

    *source = 0;
    func_0814186C(source, data_0600E1A0, 0x010007A0);
    for (row = 0; row <= 8; row++) {
        u16 *destination = func_0808B8E4(6, 1, 0, row * 2);
        func_0808B858(6, destination, 0, 13);
    }
}
