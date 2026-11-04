#include "ffta.h"

extern void func_080DBD78(const Struct080DBD5C *source,
                         s16 *x, s16 *y, s16 *z);
extern s32 func_0809D6BC(s8 x, s8 y);

/* Complete target [0x080DBCD4, 0x080DBD2E), 90 bytes:
 * 70b5464640b483b00e1c6a46023201a988466946434600f045f86c46063402aa6d460a35301c211c2b1c00f03bf8684600782178401a00060016424611782a78891a09060916c1f7cffc0006000e03b008bc984670bc02bc0847
 */
int func_080DBCD4(void *first, void *second)
{
    s16 first_coordinates[3];
    s16 second_coordinates[3];

    func_080DBD78(first, &first_coordinates[0],
                 &first_coordinates[1], &first_coordinates[2]);
    func_080DBD78(second, &second_coordinates[0],
                 &second_coordinates[1], &second_coordinates[2]);
    return (u8)func_0809D6BC(
        (s8)((u8)first_coordinates[0] - (u8)second_coordinates[0]),
        (s8)((u8)first_coordinates[2] - (u8)second_coordinates[2]));
}
