#include "ffta.h"

typedef struct {
    u8 unknown_00[0x15];
    u8 width;
    u8 count;
    u8 unknown_17;
    s16 limit;
    u8 unknown_1A[6];
} Menu;

typedef struct {
    u8 unknown_00[0x11];
    s8 selected;
    u8 unknown_12[2];
} MenuControls;

typedef struct {
    u8 unknown_0000[0xD20];
    Menu menu;
    MenuControls controls;
} Context;

extern Context *data_0200F428;
extern u16 func_08017B50(Menu *menu);
extern void func_0802ACD4(Menu *menu, s8 row, u8 color, u8 column, u8 width);

/* 0x0805C09C: complete 112-byte owner. */
void func_0805C09C(void)
{
    Menu *menu = &data_0200F428->menu;
    MenuControls *controls = &data_0200F428->controls;
    s8 selected = controls->selected;
    u8 i;

    for (i = 0; i < func_08017B50(menu); ++i) {
        if (i == selected)
            func_0802ACD4(menu, selected, 11, 2, menu->width - 2);
        else
            func_0802ACD4(menu, i, 255, 2, menu->width - 2);
    }
}
