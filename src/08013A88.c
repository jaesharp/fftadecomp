#include "ffta.h"

extern void func_08141868(const void *source, void *destination, u32 control);

/* Complete target: 34 bytes. */
void func_08013A88(void *destination, u16 count)
{
    u32 zero = 0;

    func_08141868(&zero, destination, ((u32)count << 3) | 0x01000000);
}
