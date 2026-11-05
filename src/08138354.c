#include "ffta.h"

extern u8 *data_030027D8;
extern u16 data_0600BAE0[];

extern void func_0814186C(const void *source, void *destination, u32 control);
extern u16 func_08015110(void *context, void *destination, const u8 *text,
                         u32 mode, u32 enabled);

/* Complete target [0x08138354, 0x0813839C), 72 bytes. */
void func_08138354(const u8 *text)
{
    u16 fill_value;
    u16 *source = &fill_value;

    *source = 0;
    func_0814186C(source, data_0600BAE0, 0x01000320);
    func_08015110(data_030027D8 + 0xF9C, data_0600BAE0, text, 5, 1);
}
