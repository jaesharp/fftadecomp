#include "ffta.h"

typedef struct {
    u16 left;
    u16 right;
} Scanline;

typedef struct {
    u16 count;
    u16 frames[1][4];
} PositionedAnimation;

typedef struct {
    s16 x;
    s16 y;
    u8 type;
    u8 unknown_05;
    u16 flags;
    Scanline lines[160];
    s32 *shapes;
    PositionedAnimation *animation;
    u16 frame;
    u16 remaining;
    u16 frameCount;
} AnimatedScanlines;

typedef struct ScanlineTask ScanlineTask;

extern void func_0800F93C(AnimatedScanlines *state, u16 *destination);
extern ScanlineTask *func_0800C3CC(
    void (*callback)(AnimatedScanlines *, u16 *), u32 size, u32 type,
    u16 *destination);
extern AnimatedScanlines *func_0800C614(ScanlineTask *task);
extern void func_0800C628(ScanlineTask *task, u8 enabled);
extern u16 data_04000040[];

/* Complete [0x0800FF68, 0x0800FFF8), 144 bytes. */
ScanlineTask *func_0800FF68(u8 window, s32 *shapes,
                          PositionedAnimation *animation, u16 x, u16 y)
{
    ScanlineTask *task = func_0800C3CC(func_0800F93C,
                                    sizeof(AnimatedScanlines), 2,
                                    data_04000040 + window);
    AnimatedScanlines *state = func_0800C614(task);

    state->x = x;
    state->y = y;
    state->type = 11;
    state->shapes = shapes;
    state->animation = animation;
    state->frame = 0;
    state->frameCount = animation->count;
    state->remaining = animation->frames[0][1];
    func_0800C628(task, 1);
    return task;
}
