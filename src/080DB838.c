#include "ffta.h"

typedef struct {
    u8 unknown_00[8];
    s16 x, y, z;
} Position080DB838;

typedef struct {
    s16 x, y;
    s16 rectangle[4];
} ProjectedBounds080DB838;

extern const s16 g_object_083955A0[];
extern const s16 g_object_083955A8[];
extern void func_0801C984(s16, s16, s16, s16 *, s16 *);
extern u8 func_080D8604(s16 *, const s16 *, u8, const s16 *);

/* Complete [0x080DB838, 0x080DB8AC): 116 bytes.
 * The complete helper entries support signed halfword coordinates and the
 * rectangle's four signed halfwords. Calls use conditional ARM ABI views;
 * no memory extent, alias, numeric-result or termination theorem is assumed. */
u8 func_080DB838(const Position080DB838 *position)
{
    const s16 *area = g_object_083955A0;
    const s16 *adjustment = g_object_083955A8;
    ProjectedBounds080DB838 projected;
    s16 *rectangle = projected.rectangle;
    s16 *y = &projected.y;
    u8 status, outside;

    func_0801C984(position->x, position->y, position->z,
                   &projected.x, y);
    rectangle[0] = projected.x - 16;
    rectangle[2] = projected.x + 16;
    rectangle[1] = *y - 32;
    rectangle[3] = *y + 8;
    status = func_080D8604(rectangle, area, 1, adjustment);
    outside = 0;
    if (status == 0)
        outside = 1;
    return outside;
}
