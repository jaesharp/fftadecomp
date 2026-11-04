/* Complete target [0x0805AD30, 0x0805ADA4), 116 bytes including pools. */
#include "ffta.h"

typedef struct {
    u8 unknown_00[0x11];
    u8 mode;
    u8 unknown_12[2];
} MenuControls;

typedef struct {
    u8 unknown_0000[0xF3C];
    MenuControls controls;
    u8 unknown_0F50[0x2CA0 - 0xF50];
    u8 timer;
} MenuContext;

extern MenuContext *data_0200F428;
extern void func_08141540(u16 song_id);
extern u8 func_08058C0C(void);

void func_0805AD30(u8 *state)
{
    MenuControls *controls;

    func_08141540(100);
    controls = &data_0200F428->controls;
    switch (controls->mode) {
    case 0:
        if (func_08058C0C()) {
            *state = 0x41;
            data_0200F428->timer = 0xFE;
        } else {
            *state = 0x41;
            data_0200F428->timer = 0x45;
        }
        break;
    case 1:
        *state = 0x41;
        data_0200F428->timer = 0x50;
        break;
    }
}
