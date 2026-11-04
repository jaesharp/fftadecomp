#include "ffta.h"

typedef struct {
    u8 unknown_00[0x0C];
    u16 flags_0C;
    u8 unknown_0E[0x16];
    s16 value;
    u8 unknown_26[0x0E];
    u16 x;
    u16 y;
    s8 phase;
    u8 timer;
    u16 flags_3A;
} State08012FD8;

extern State08012FD8 *data_0200918C;
extern const u8 data_0836D60C[];
extern const u8 data_0851BA6A[];

void func_08001CF0(const void *source, s32 first, s32 second, u8 mode,
                  u8 first_flag, u8 second_flag, u8 third_flag, u8 fourth_flag,
                  u32 value, u8 count, u32 extra);

/* Complete target: [0x08012FD8, 0x08013060), 136 bytes. */
void func_08012FD8(void)
{
    if (data_0200918C->flags_3A & 1) {
        s8 offset = data_0836D60C[data_0200918C->phase++] + 10;

        if (data_0200918C->flags_0C & 0x20)
            offset -= 4;
        func_08001CF0(data_0851BA6A, data_0200918C->x,
                     (s8)offset + data_0200918C->y, 0,
                     0, 0, 0, 0, data_0200918C->value, 0, 0);
        data_0200918C->phase &= 0x1F;
    }
}
