#include "ffta.h"

typedef struct {
    void *begin;
    void *current;
    u16 position;
    u8 state;
    u8 height;
    u8 width;
    u8 flags;
    u8 unknown_0E[2];
    u8 buffer[0x200];
    u8 secondary[0];
} State08013570;

extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete target [0x08013570, 0x080135B8): 72 bytes, 30 instructions. */
void func_08013570(State08013570 *state, void *begin, u8 width, u8 height)
{
    u16 first;
    u16 second;

    state->begin = begin;
    state->current = begin;
    state->position = 0;
    state->state = 0;
    state->height = height;
    state->width = width;
    state->flags = 0;
    first = 0;
    func_0814186C(&first, state->buffer, 0x01000100);
    second = 0;
    func_0814186C(&second, state->secondary, 0x01000040);
}
