#include "ffta.h"

extern u16 data_02003CB0[];
extern u16 data_0600C560[];
extern void func_0814186C(const void *, void *, u32);
extern void func_080CB9E0(void *, u32);
extern u32 func_080CBA14(u8);
extern u16 *func_0808B8E4(u32, u32, s32, s32);
extern void func_0808B80C(s32, u16 *, u16, u16, u16);

/* Complete owner: 0x08080EF8..0x08080F68, 112 bytes. */
void func_08080EF8(void *unused, u8 index)
{
    u16 *buffer = data_02003CB0;
    u16 *tiles;
    u16 fill;
    u16 *source = &fill;
    u16 flags;

    *source = 0;
    tiles = data_0600C560;
    func_0814186C(source, tiles, 0x010002C0);
    if (index != 0) {
        func_080CB9E0(buffer, index);
        func_0814186C(buffer, tiles, 0x80);
        flags = func_080CBA14(index) << 12;
        func_0808B80C(8, func_0808B8E4(8, 1, 5, 2), 0x22B, 4, flags);
    }
}
