#include "ffta.h"

typedef struct {
    u8 mode;
    u8 unknown_01[0x125];
    u16 field_126;
} State08005028;

typedef struct {
    u16 field_00;
    u16 entries[6];
} Table08005028;

extern u16 data_03002B68;
extern State08005028 data_030028A0;
extern Table08005028 data_03002890;
extern Table08005028 data_03002B50;

/* Complete entry forwards R0-R2 to SWI 0x0B.  Conditional call view only. */
extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete 96-byte target, 36 instructions and five literal words. */
void func_08005028(void)
{
    u16 first_fill;
    u16 second_fill;

    data_03002B68 = 0;
    data_030028A0.field_126 = data_030028A0.mode == 8 ? 0 : 5;
    data_03002890.field_00 = 0;
    data_03002B50.field_00 = 0;
    first_fill = 0;
    func_0814186C(&first_fill, data_03002890.entries, 0x01000006);
    second_fill = 0;
    func_0814186C(&second_fill, data_03002B50.entries, 0x01000006);
}
