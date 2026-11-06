#include "ffta.h"

s32 func_0809D6BC(s8 x, s8 y)
{
    s32 direction;

    if ((x < 0 ? -x : x) >= (y < 0 ? -y : y)) {
        if (x != 0)
            x /= x < 0 ? -x : x;
        y = 0;
    } else {
        if (y != 0)
            y /= y < 0 ? -y : y;
        x = 0;
    }
    for (direction = 0; direction < 4; direction++) {
        s8 vector_x;
        s8 vector_y;
        s8 *x_out = &vector_x;
        s8 *y_out = &vector_y;

        switch ((s8)direction) {
        case 0:
            *x_out = 0;
            *y_out = 1;
            break;
        case 1:
            *x_out = -1;
            *y_out = 0;
            break;
        case 2:
            *x_out = 0;
            *y_out = -1;
            break;
        case 3:
            *x_out = 1;
            *y_out = 0;
            break;
        default:
            *x_out = 0;
            *y_out = 0;
            break;
        }
        if (*x_out == x && *y_out == y)
            return direction;
    }
    return -1;
}
