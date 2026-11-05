#include "ffta.h"

typedef struct {
    u8 unknown_00[0x12];
    u8 width;
    u8 height;
    u8 unknown_14[0x24];
    u16 *destination;
    u8 unknown_3C[0x0F];
    u8 field_4B;
} State08053714;

typedef struct {
    u8 unknown_00[0x14];
    u32 field_14;
} Resource08053714;

extern Resource08053714 data_030008B0;
extern Resource08053714 data_03000990;
extern void func_08017424(void *state, u32 first, u32 second,
                         u8 value10, u8 value11, u8 width, u8 height,
                         u16 value14, u8 value16, u16 value18,
                         u16 value1A, u8 value17);
extern void func_08016210(void *state, const void *content, u16 first, u16 second);
extern void func_08016C90(void *state, u8 mode);
extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete target [0x08053714, 0x080537A8), 148 bytes. */
void func_08053714(State08053714 *state, const void *content,
                   u16 first, u8 value10, u8 value11)
{
    u16 zero;

    func_08017424(state, data_030008B0.field_14, data_03000990.field_14,
                  value10, value11, 9, 4, 0x800, 0x20, 0xD, 3, 0xB);
    func_08016210(state, content, first, 2);
    state->field_4B = 0xB;
    zero = 0;
    func_0814186C(&zero, state->destination,
                  (state->width * state->height) | 0x01000000);
    func_08016C90(state, 1);
}
