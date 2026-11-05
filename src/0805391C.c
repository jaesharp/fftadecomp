#include "ffta.h"

typedef struct {
    u8 unknown_00[0x12];
    u8 width;
    u8 height;
    u8 unknown_14[0x24];
    u16 *buffer;
    u8 unknown_3C[0xA];
    u16 field_46;
    u8 unknown_48[3];
    u8 mode;
} Window0805391C;

typedef struct {
    u8 unknown_00[0x14];
    u32 value;
} Display0805391C;

extern Display0805391C data_030008B0;
extern Display0805391C data_03000990;

extern void func_08017424(void *object, u32 first, u32 second,
                          u8 arg3, u8 arg4, u8 width, u8 height,
                          u16 arg7, u8 arg8, u16 arg9, u16 arg10, u8 arg11);
extern void func_08016210(void *object, const void *content, u16 first, u16 second);
extern void func_08016C90(void *object, u8 mode);
extern void func_0814186C(const void *source, void *destination, u32 control);

/* 0x0805391C..0x080539B4: complete 152-byte target. */
void func_0805391C(Window0805391C *window, const void *content,
                   u16 count, u8 first, u8 second)
{
    u16 zero;

    func_08017424(window, data_030008B0.value, data_03000990.value,
                  first, second, 15, 5, 0x800, 32, 13, 3, 11);
    func_08016210(window, content, count, 2);
    window->mode = 11;
    window->field_46 = 0;
    zero = 0;
    func_0814186C(&zero, window->buffer,
                  0x01000000 | (window->width * window->height));
    func_08016C90(window, 1);
}
