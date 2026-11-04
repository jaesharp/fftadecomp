#include "ffta.h"

typedef struct {
    u8 unknown_00[0x11];
    u8 mode;
} Selector080592F8;

extern u8 *data_0200F428;
extern void func_08141540(u16 song_id);

/* Complete target [0x080592F8, 0x08059344): 76 bytes. */
void func_080592F8(u8 *command)
{
    u8 *context;
    Selector080592F8 *selector;

    func_08141540(100);
    context = data_0200F428;
    selector = (Selector080592F8 *)(context + 0xD40);
    switch (selector->mode) {
    case 0:
        *command = 20;
        context[0x2CA0] = 22;
        break;
    case 1:
        *command = 40;
        context[0x2CA0] = 255;
        break;
    }
}
