#include "ffta.h"

typedef struct {
    const void *source;
    const void *cursor;
    u16 unknown_08;
    u8 unknown_0A;
    u8 unknown_0B;
    u8 unknown_0C;
    u8 unknown_0D;
    u8 unknown_0E[2];
    u16 unknown_10[0x100];
    u16 unknown_210[0x40];
} Drawing08013528;

extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete target: [0x08013528, 0x08013570), 72 bytes. */
void func_08013528(Drawing08013528 *drawing, const void *source)
{
    u16 first_zero;
    u16 second_zero;

    drawing->source = source;
    drawing->cursor = source;
    drawing->unknown_08 = 0;
    drawing->unknown_0A = 0;
    drawing->unknown_0B = 0;
    drawing->unknown_0C = 0;
    drawing->unknown_0D = 0;
    first_zero = 0;
    func_0814186C(&first_zero, drawing->unknown_10, 0x01000100);
    second_zero = 0;
    func_0814186C(&second_zero, drawing->unknown_210, 0x01000040);
}
