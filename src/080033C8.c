#include "ffta.h"

/* plausible: DISPSTAT at 0x04000004 is MMIO hardware and changes during polling. */
#define DISPSTAT (*(volatile u16 *)0x04000004)

/* Complete target: [0x080033C8, 0x08003410), 72 bytes. */
void func_080033C8(u16 count)
{
    u16 i;

    for (i = 0; i < count; i++) {
        while (DISPSTAT & 1) {
        }
        while (!(DISPSTAT & 1)) {
        }
    }
}
