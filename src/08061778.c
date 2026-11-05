#include "ffta.h"

extern ScriptState *data_0200F450;
extern u16 data_0600E000[];
extern u16 data_06005000[];
extern void func_0814186C(const void *source, void *destination, u32 control);
extern void func_08022854(u8 *object);

/* Complete target: [0x08061778, 0x080617C4), 76 bytes. */
void func_08061778(void)
{
    u16 first_zero;
    u16 second_zero;

    if (data_0200F450 != 0) {
        u16 *first_source = &first_zero;
        u16 *second_source;

        *first_source = 0;
        func_0814186C(first_source, data_0600E000, 0x01000800);
        second_source = &second_zero;
        *second_source = 0;
        func_0814186C(second_source, data_06005000, 0x01000800);
        func_08022854((u8 *)data_0200F450);
        data_0200F450 = 0;
    }
}
