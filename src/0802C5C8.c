#include "ffta.h"

/* Target [0802C5C8,0802C624), complete 92 bytes:
 * 30b509040c0c12041b061b0ed20b8518632c00d96324002c08d1002b06d02c800149081c13e00000d6e00000201c0a2116f15afa0004000c002801d0064940182880201c0a2116f18bfa03494018688030bc01bc004700001ed00000
 */
void func_0802C5C8(u16 *destination, u16 value, u16 index, u8 mode)
{
    u16 *selected = destination + index;
    u32 quotient;

    if (value > 99)
        value = 99;

    if (value == 0 && mode != 0) {
        selected[0] = 0;
        selected[1] = 0xE0D6;
    } else {
        quotient = (u16)(value / 10u);
        if (quotient != 0)
            quotient += 0xD01E;
        selected[0] = quotient;
        selected[1] = value % 10u + 0xD01E;
    }
}
