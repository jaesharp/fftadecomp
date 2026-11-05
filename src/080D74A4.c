#include "ffta.h"

typedef struct {
    u8 unknown_00[2];
    u8 x;
    u8 y;
} Position;

typedef struct {
    s16 pa;
    s16 pb;
    s16 pc;
    s16 pd;
    s32 x;
    s32 y;
} AffineTransform;

extern void func_080032F8(const AffineTransform *transform, u8 layer);

void func_080D74A4(const Position *position, u8 layer, s16 x, s16 y)
{
    s32 dx = (position->x - x) * 256;
    s32 dy = (position->y - y) * 256;
    AffineTransform transform;

    transform.pa = 0x100;
    transform.pb = 0;
    transform.pc = 0;
    transform.pd = 0x100;
    transform.x = dx;
    transform.y = dy;

    func_080032F8(&transform, layer);
}
