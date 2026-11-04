#include "ffta.h"

extern u8 data_020084D8;
extern void func_0814513C(void);
extern void func_081456AC(u32 mode);
extern void func_08145798(void);

/* Complete [0x081414BC, 0x081414F0), 52 bytes. */
void func_081414BC(void)
{
    data_020084D8 = 0xFF;
    *(u16 *)0x020084D4 = 0xFFFF;
    func_0814513C();
    func_081456AC(0x95C880);
    func_08145798();
}
