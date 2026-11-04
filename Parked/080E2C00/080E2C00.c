#include "ffta.h"

extern void func_0801C984(s16 first, s16 second, s16 third,
                         s16 *first_output, s16 *second_output);
extern void func_080E29C4(void *context, s16 first, s16 second,
                         u8 effect, u8 argument4);

/* 080E2C00..080E2C54, complete 84-byte target:
 * 70b5464640b482b08046081c111c1a1c079d089c2d062d0e2406240e0004001409040914120412146e460636009601ab39f7a8fe01a80022815e0020325e009440462b1cfff7befe02b008bc984670bc01bc0047
 */
void func_080E2C00(void *context, s32 x, s32 y, s32 z,
                   u32 effect, u32 argument5)
{
    s16 first_output;
    s16 second_output;

    func_0801C984((s16)x, (s16)y, (s16)z,
                  &first_output, &second_output);
    func_080E29C4(context, first_output, second_output,
                  (u8)effect, (u8)argument5);
}
