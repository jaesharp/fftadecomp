#include "ffta.h"

extern void func_0801C984(s16 first, s16 second, s16 third,
                        s16 *first_output, s16 *second_output);
extern void func_080E29C4(void *object, s16 first, s16 second,
                        u8 effect, u8 argument);

/* Complete 080E2C00..080E2C54, 84 bytes. */
void func_080E2C00(void *object, s16 x, s16 y, s16 z,
                   u8 effect, u8 argument)
{
    s16 first_output;
    s16 second_output;

    func_0801C984(x, y, z, &first_output, &second_output);
    func_080E29C4(object, first_output, second_output, effect, argument);
}
