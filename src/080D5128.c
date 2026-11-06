#include "ffta.h"

/* Complete target: 0x080D5128..0x080D5594, 1132 bytes. */
typedef Struct08011040 Object;
typedef struct { Object *object; } ObjectHandle;

typedef union {
    struct { s16 x, y, z, unknown_06; } component;
    u32 xy;
} Position;

typedef struct {
    ObjectHandle *object;
    Position *start;
    Position *end;
    s16 *x_curve;
    s16 *y_curve;
    s16 *z_curve;
    u16 delay;
    u16 duration;
} Parameters;

typedef struct {
    u16 phase;
    u16 unknown_02;
    Parameters *parameters;
    u8 unknown_08[12];
    u16 flags;
} Descriptor;

typedef struct {
    ObjectHandle *object;
    u16 delay;
    u16 unknown_06;
} Follower;

typedef struct {
    u16 status;
    u16 unknown_02;
    ObjectHandle *object;
    Position start;
    Position end;
    s16 *x_curve;
    s16 *y_curve;
    s16 *z_curve;
    u16 duration;
    u8 follower_count;
    u8 unknown_27;
    Follower followers[4];
    u16 frame;
    u16 flags;
    u16 delay;
    u16 unknown_4E;
    void *child;
} State;

extern void func_080107D4(Object *, s16, s16, s16);
extern void func_0801115C(Object *, u8);
extern void func_080112A4(Object *, u8);
extern void *func_080E077C(s16, s16, s16, s16, s16, s16,
                          u16, u16, s16 *, s16 *, s16 *, void *);
extern void *func_080E07F8(void *);

u32 func_080D5128(void *task, Descriptor *descriptor, State *state)
{
    switch (descriptor->phase) {
    case 0: {
        Parameters *parameters = descriptor->parameters;
        state->object = parameters->object;
        state->start.component.x = parameters->start->component.x;
        state->start.component.y = parameters->start->component.y;
        state->start.component.z = parameters->start->component.z;
        state->end.component.x = parameters->end->component.x;
        state->end.component.y = parameters->end->component.y;
        state->end.component.z = parameters->end->component.z;
        state->x_curve = parameters->x_curve;
        state->y_curve = parameters->y_curve;
        state->z_curve = parameters->z_curve;
        state->delay = parameters->delay;
        state->duration = parameters->duration;
        state->flags = descriptor->flags;
        break;
    }
    case 1:
        break;
    case 0x100:
        if (state->start.xy == state->end.xy &&
            state->start.component.z == state->end.component.z &&
            state->delay == 0) {
            state->status = 4;
            descriptor->phase = 2;
        }
        state->child = func_080E077C(
            state->start.component.x, state->start.component.y,
            state->start.component.z, state->end.component.x,
            state->end.component.y, state->end.component.z,
            state->delay, state->duration, state->x_curve,
            state->y_curve, state->z_curve, task);
        descriptor->phase++;
        break;
    case 0x101:
        state->child = func_080E07F8(state->child);
        if (state->child)
            break;
        state->status = 1;
        descriptor->phase++;
        break;
    case 0x102:
        if (state->status != 2)
            break;
        if (state->follower_count) {
            s16 x, y, z;
            u8 i;
            func_08011040(state->object->object, (u16 *)&x, (u16 *)&y, (u16 *)&z);
            for (i = 0; i < state->follower_count; i++) {
                if (state->x_curve)
                    x = *state->x_curve;
                if (state->y_curve)
                    y = *state->y_curve;
                if (state->z_curve)
                    z = *state->z_curve;
                func_080107D4(state->followers[i].object->object, x, y, z);
            }
        }
        descriptor->phase++;
        break;
    case 0x103: {
        s16 x, y, z;
        u8 i;
        func_08011040(state->object->object, (u16 *)&x, (u16 *)&y, (u16 *)&z);
        if (state->x_curve)
            x = state->x_curve[state->frame];
        if (state->y_curve)
            y = state->y_curve[state->frame];
        if (state->z_curve)
            z = state->z_curve[state->frame];
        func_080107D4(state->object->object, x, y, z);
        if (state->follower_count) {
            for (i = 0; i < state->follower_count; i++) {
                s16 frame = state->frame - state->followers[i].delay;
                if (frame < 0)
                    continue;
                if (frame == 0) {
                    func_0801115C(state->followers[i].object->object, 1);
                    func_080112A4(state->followers[i].object->object, 0);
                } else if (frame >= state->duration) {
                    func_0801115C(state->followers[i].object->object, 0);
                    continue;
                }
                func_08011040(state->followers[i].object->object,
                              (u16 *)&x, (u16 *)&y, (u16 *)&z);
                if (state->x_curve)
                    x = state->x_curve[frame];
                if (state->y_curve)
                    y = state->y_curve[frame];
                if (state->z_curve)
                    z = state->z_curve[frame];
                func_080107D4(state->followers[i].object->object, x, y, z);
            }
        }
        if (++state->frame >= state->duration) {
            if (!(state->flags & 1))
                func_0801115C(state->object->object, 0);
            state->status = 3;
            descriptor->phase++;
        }
        break;
    }
    case 0x104: {
        u32 complete = 1;
        if (state->follower_count) {
            u8 i;
            s16 frame = 0;
            state->frame++;
            for (i = 0; i < state->follower_count; i++) {
                frame = state->frame - state->followers[i].delay;
                if (frame < 0) {
                    complete = 0;
                    continue;
                }
                if (frame == 0) {
                    func_0801115C(state->followers[i].object->object, 1);
                } else if (frame >= state->duration) {
                    func_0801115C(state->followers[i].object->object, 0);
                    continue;
                }
                {
                    s16 x, y, z;
                    func_08011040(state->followers[i].object->object,
                                  (u16 *)&x, (u16 *)&y, (u16 *)&z);
                    if (state->x_curve)
                        x = state->x_curve[frame];
                    if (state->y_curve)
                        y = state->y_curve[frame];
                    if (state->z_curve)
                        z = state->z_curve[frame];
                    func_080107D4(state->followers[i].object->object, x, y, z);
                }
            }
            if (frame < state->duration)
                complete = 0;
        }
        if (complete) {
            state->status = 4;
            descriptor->phase = 2;
        }
        break;
    }
    }
    return 0;
}
