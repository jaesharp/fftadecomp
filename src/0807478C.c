#include "ffta.h"

typedef struct {
    u8 unknown_00[4];
    u8 index;
} Unit0807478C;

typedef struct {
    u8 unknown_00[0x452];
    u8 field_452;
    u8 unknown_453;
    const u8 *field_454;
    u8 unknown_458[0x1D0C - 0x458];
    Unit0807478C *unit_1D0C;
} State0807478C;

extern State0807478C *data_03002818;
extern u8 data_02003CB0[];
extern u8 data_06014300[];
extern u16 data_03003860[];

extern u8 func_080CB7C0(Unit0807478C *unit, u8 selector);
extern const u8 *func_080CB808(Unit0807478C *unit);
extern u8 *func_080CB868(u8 *buffer, Unit0807478C *unit);
extern void func_080CB8D4(void *object, u8 index);
extern const u8 *func_080CB928(Unit0807478C *unit);
extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete target: [0x0807478C, 0x08074848), 188 bytes. */
void func_0807478C(void)
{
    u8 *buffer = data_02003CB0;
    const u8 *resource = func_080CB808(data_03002818->unit_1D0C);
    void *object;

    func_080CB868(buffer, data_03002818->unit_1D0C);
    func_0814186C(buffer, data_06014300, ((u32)resource << 10) >> 11);
    object = (u8 *)data_03002818 + 0x2E8;
    func_080CB8D4(object, func_080CB7C0(data_03002818->unit_1D0C, 1));
    data_03002818->field_454 = func_080CB928(data_03002818->unit_1D0C);
    data_03002818->field_452 = 1;
    func_0814186C((u8 *)data_03002818 + 0x28,
                  data_03003860, 0x04000080);
    func_0814186C((u8 *)data_03002818 + 0x228,
                  data_03003860 + 0x100, 0x04000080);
}
