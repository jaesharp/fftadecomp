#include "ffta.h"

typedef union {
    u32 packed;
    struct {
        s16 x;
        s16 y;
    } coordinates;
} Point0809AE84;

typedef struct {
    Point0809AE84 current;
    Point0809AE84 target;
    s16 step_x;
    s16 step_y;
    s16 delta_x;
    s16 delta_y;
    s16 error;
    s16 unknown_12;
    s16 count;
} Line0809AE84;

s32 func_0809AE84(Line0809AE84 *line)
{
    s32 i;

    for (i = 0; i < line->count; ++i) {
        if (line->current.packed == line->target.packed)
            return i;
        if (line->delta_x > line->delta_y) {
            line->current.coordinates.x += line->step_x;
            line->error -= line->delta_y;
            if (line->error < 0) {
                line->error += line->delta_x;
                line->current.coordinates.y += line->step_y;
            }
        } else {
            line->current.coordinates.y += line->step_y;
            line->error -= line->delta_x;
            if (line->error < 0) {
                line->error += line->delta_y;
                line->current.coordinates.x += line->step_x;
            }
        }
    }
    return i;
}
