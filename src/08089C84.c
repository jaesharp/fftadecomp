#include "ffta.h"

typedef struct {
    u8 unknown_00[6];
    u16 flags_06;
} DisplayState08089C84;

typedef struct {
    u8 unknown_00[0x10];
    void (*callback_10)(void);
} DisplayCallbacks08089C84;

extern void func_0808A1E8(void);
extern u8 data_030027A4;
extern DisplayCallbacks08089C84 data_030008D0;
extern DisplayState08089C84 data_03000EA0;

/* Complete target [0x08089C84, 0x08089CAC): 40 bytes, 12 instructions. */
void func_08089C84(void)
{
    data_030027A4 = 0xFF;
    data_030008D0.callback_10 = func_0808A1E8;
    data_03000EA0.flags_06 |= 4;
}
