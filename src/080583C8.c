#include "ffta.h"
/* Target [0x080583C8, 0x080583FA): complete 50 bytes. */
typedef struct {
    u8 unknown_00[0x18];
    s16 count;
    s16 position;
} MenuWindow;

int func_080583C8(const MenuWindow *window, u16 direction)
{
    if (direction == 0x40) {
        if (window->position == 0)
            goto blocked;
    } else if (direction == 0x80) {
        if (window->position + 3 >= window->count)
            goto blocked;
    } else {
        goto blocked;
    }
    return 1;
blocked:
    return 0;
}
