#include "ffta.h"

/* Complete target [0x0800FDFC, 0x0800FEAC): 176 bytes, 76 instructions. */
typedef struct {
    u16 left;
    u16 right;
} Scanline0800FDFC;

typedef struct {
    s16 x;
    s16 y;
    u8 type;
    u8 unknown_05;
    u16 flags;
    Scanline0800FDFC lines[160];
    u16 horizontal_radius;
    u16 vertical_radius;
} Scanlines0800FDFC;

typedef struct ScanlineTask ScanlineTask;
extern void func_0800F93C(Scanlines0800FDFC *, u16 *);
extern ScanlineTask *func_0800C3CC(
    void (*callback)(Scanlines0800FDFC *, u16 *), u32, u32, u16 *);
extern void *func_0800C614(const ScanlineTask *);
extern void func_08010058(void *, u16, u8, u8, u8);
extern void func_0800F860(s32, s32, u16, u16, Scanline0800FDFC *, u32);
extern u16 data_04000040[];

static inline void render_task(ScanlineTask *task)
{
    Scanlines0800FDFC *state = func_0800C614(task);

    func_08010058(task, 0, 160, 245, 250);
    func_0800F860(state->x, state->y, state->horizontal_radius,
                  state->vertical_radius, state->lines, 1);
}

ScanlineTask *func_0800FDFC(u8 window, u16 x, u16 y, u16 radius)
{
    ScanlineTask *task = func_0800C3CC(func_0800F93C, 0x298, 2,
                                    data_04000040 + window);
    Scanlines0800FDFC *state = func_0800C614(task);

    state->x = x;
    state->y = y;
    state->type = 8;
    state->horizontal_radius = radius;
    state->vertical_radius = 0;
    render_task(task);
    return task;
}
