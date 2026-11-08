#include "ffta.h"

struct Task;

struct Coordinates080D62CC {
    s16 x;
    s16 y;
};

struct Movement080D62CC {
    void **object;
    s16 start_x;
    s16 start_y;
    s16 end_x;
    s16 end_y;
    u16 start_offset;
    u16 end_offset;
    u16 count;
    u16 unknown_12;
    const s16 *x;
    const s16 *y;
};

struct MovementRequest080D62CC {
    u16 phase;
    u16 unknown_02;
    const struct Movement080D62CC *movement;
    const u8 *options;
    u32 unknown_0C[2];
    u16 behavior;
    u16 unknown_16;
    u32 unknown_18;
};

extern u32 func_080D5A60(struct Task *, struct MovementRequest080D62CC *, void *);
extern struct Task *func_08005B6C(
    u32 (*callback)(struct Task *, struct MovementRequest080D62CC *, void *),
    u16 size, struct MovementRequest080D62CC *request, struct Task *parent);

/* Complete [0x080D62CC, 0x080D6334): 104 bytes. */
struct Task *func_080D62CC(void **object,
                         const struct Coordinates080D62CC *from,
                         const struct Coordinates080D62CC *to,
                         u16 start_offset, u16 end_offset, u16 count,
                         const s16 *x, const s16 *y, u16 behavior,
                         struct Task *parent)
{
    struct Movement080D62CC movement;
    struct MovementRequest080D62CC request;

    movement.object = object;
    movement.start_x = from->x;
    movement.start_y = from->y;
    movement.end_x = to->x;
    movement.end_y = to->y;
    movement.start_offset = start_offset;
    movement.end_offset = end_offset;
    movement.count = count;
    movement.x = x;
    movement.y = y;
    request.behavior = behavior;
    request.movement = &movement;
    request.options = 0;
    return func_08005B6C(func_080D5A60, 0x28, &request, parent);
}
