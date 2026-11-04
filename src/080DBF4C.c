#include "ffta.h"

typedef struct {
    u8 unknown_00[8];
    s16 x, y, z;
} Position080DBF4C;
typedef struct { s16 left, top, right, bottom; } Rect080DBF4C;

extern void func_0801C984(s16, s16, s16, s16 *, s16 *);

/* Complete target [0x080DBF4C, 0x080DBF8E): 66 bytes. */
void func_080DBF4C(const Position080DBF4C *position, Rect080DBF4C *rectangle)
{
    s16 screen_x;
    s16 screen_y;
    s16 *horizontal = &screen_x;
    s16 *vertical = &screen_y;

    func_0801C984(position->x, position->y, position->z, horizontal, vertical);
    rectangle->left = screen_x - 16;
    rectangle->right = screen_x + 16;
    rectangle->top = *vertical - 32;
    rectangle->bottom = *vertical + 8;
}
