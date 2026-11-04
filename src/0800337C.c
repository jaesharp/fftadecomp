#include "ffta.h"

extern u16 g_control_flags_03000940;

/* 0800337C..08003398: 28 bytes, including literal pool.
 * a021c904002008800348a021490001808020c0040180704740090003
 */
void func_0800337C(void)
{
    u16 *shadow;
    u16 control;

    *(u16 *)0x05000000 = 0;
    shadow = &g_control_flags_03000940;
    *shadow = control = 0x140;
    *(u16 *)0x04000000 = control;
}
