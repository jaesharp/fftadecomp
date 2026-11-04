#include "ffta.h"

extern u16 data_03003860[];
extern void func_08087660(const u16 *source, u16 *destination,
                         u8 divisor, u8 multiplier);

/* Complete [0x0808EEB4, 0x0808EEE8): 52 bytes. */
void func_0808EEB4(void)
{
    u16 *source = data_03003860 + 0xD0;

    func_08087660(source, source - 0xD0, 64, 40);
    func_08087660(source + 16, source - 0xC0, 64, 40);
}
