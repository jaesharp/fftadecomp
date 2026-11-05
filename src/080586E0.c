#include "ffta.h"

extern void func_0814186C(const void *source, void *destination, u32 control);
extern void func_0802ACA0(u16 *entries, u16 first, u8 palette, u16 count);

/* Complete target: 080586E0..0805871C, 60 bytes including the literal. */
void func_080586E0(u16 *entries)
{
    u16 zero;
    u16 *source = &zero;

    *source = 0;
    func_0814186C(source, entries, 0x01000014);
    func_0802ACA0(entries, 0xC0, 8, 10);
    func_0802ACA0(entries + 10, 0xCA, 8, 10);
}
