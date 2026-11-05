#include "ffta.h"

typedef struct {
    u8 x;
    u8 y;
    u8 value;
    u8 unknown_03;
} PathPoint;

extern s32 func_081426B8(s32, s32);

s32 func_08148A98(PathPoint *points, s32 count)
{
    s32 i;
    for (i = 1; i < count; i++) {
        s32 dx = points[i].x - points[i - 1].x;
        s32 dy = points[i].y - points[i - 1].y;
        if ((dx < 0 ? -dx : dx) > 1 || (dy < 0 ? -dy : dy) > 1) {
            s32 j;
            for (j = count; j >= i; j--) {
                points[j].x = points[j - 1].x;
                points[j].value = points[j - 1].value;
                points[j].y = points[j - 1].y;
            }
            if (dx != 0)
                dx = func_081426B8(dx, dx < 0 ? -dx : dx);
            if (dy != 0)
                dy = func_081426B8(dy, dy < 0 ? -dy : dy);
            points[i].x = points[i - 1].x + dx;
            points[i].y = points[i - 1].y + dy;
            count++;
        }
    }
    return count;
}
