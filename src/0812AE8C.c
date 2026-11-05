#include "ffta.h"

typedef struct Transfer0812AE8C Transfer0812AE8C;

typedef struct {
    u8 unknown_000[8];
    u8 unknown_008[0x2f8];
    u8 *tiles;
    u8 unknown_304[0xe];
    u8 name[18];
} State0812AE8C;

extern u8 data_06016600[];
extern void func_080161D4(void *, void *, void *, u8, u8, u8, u8);
extern void func_0814186C(const void *, void *, u32);
extern Transfer0812AE8C *func_0812B4E0(State0812AE8C *);
extern void func_08000ADC(Transfer0812AE8C *, const void *, void *, u16);

/* Complete target: [0x0812AE8C, 0x0812AF1C), 144 bytes. */
void func_0812AE8C(State0812AE8C *state)
{
    u8 i;

    func_080161D4(state->unknown_008, state->tiles, state->name, 10, 0, 0, 1);
    for (i = 0; i < 9; i++) {
        u16 offset = i * 2;

        if (state->name[offset] == 0x40 && state->name[offset + 1] == 0x73) {
            u16 zero;
            u16 *source = &zero;

            *source = 0;
            func_0814186C(source, state->tiles + i * 128, 0x01000040);
        }
    }
    func_08000ADC(func_0812B4E0(state), state->tiles, data_06016600, 0x120);
}
