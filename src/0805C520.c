#include "ffta.h"

extern u8 data_02003CB0[];
extern const u8 data_083AEEA4[];
extern u8 data_0600E180[];
extern const u8 data_083AF8AC[];
extern u8 data_06016400[];
extern u32 func_0800543C(void *, const void *);
extern void func_0814186C(const void *, void *, u32);

/* 0805C520..0805C568: 72 bytes, 22 instructions.
 * 10b50c4c0c49201ca8f788ff9a21090160180a492022e5f099f90949201ca8f77dff
 * 0849d0225200201ce5f08ff910bc01bc0047b03c0002a4ee3a0880e10006acf83a0800640106
 */
void func_0805C520(void)
{
    u8 *buffer = data_02003CB0;

    func_0800543C(buffer, data_083AEEA4);
    func_0814186C(buffer + 0x9a0, data_0600E180, 0x20);
    func_0800543C(buffer, data_083AF8AC);
    func_0814186C(buffer, data_06016400, 0x1a0);
}
