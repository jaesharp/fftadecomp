#include "ffta.h"

extern u8 data_03003860[];
extern void func_0801E6D4(u8 *first, u8 *second);
extern void func_0801A42C(s16 index, void *destination);
extern u8 func_0801DB98(s16 index);
extern void func_0801DC24(u16 index);

/* Complete [0x0801AECC, 0x0801AF08), 60 bytes:
 * 10b581b069460131684603f0fdfb012464426846
 * 0178490107480918201cfff79ffa201c02f052fe
 * 0006000e02f094fe01b010bc01bc004760380003
 */
void func_0801AECC(void)
{
    u8 values[2];

    func_0801E6D4(&values[0], &values[1]);
    func_0801A42C(-1, data_03003860 + values[0] * 32);
    func_0801DC24((u8)func_0801DB98(-1));
}
