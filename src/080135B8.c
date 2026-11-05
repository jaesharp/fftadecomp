#include "ffta.h"

struct RowBufferState {
    u8 *base;
    u8 *next;
    u16 position;
    u8 state;
    u8 mode;
    u8 width;
    u8 index;
    u8 unknown_0E[2];
    u16 rows[0x100];
    u16 auxiliary[0x40];
};

extern void func_0814186C(const void *source, void *destination, u32 control);

/* Target: 84 bytes, 36 instructions, including both control literals. */
void func_080135B8(struct RowBufferState *buffer, u8 mode)
{
    u16 zero[2];
    u16 *fill;
    u8 width = buffer->width;

    buffer->next = buffer->base + (++buffer->index << 6) * width;
    buffer->position = 0;
    buffer->state = 0;
    buffer->mode = mode;
    fill = &zero[0];
    *fill = 0;
    func_0814186C(fill, buffer->rows, 0x01000100);
    fill = &zero[1];
    *fill = 0;
    func_0814186C(fill, buffer->auxiliary, 0x01000040);
}
