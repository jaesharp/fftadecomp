#include "ffta.h"

/* 080E308C: complete 240-byte task callback. */
typedef struct Task Task;
typedef struct Object Object;

typedef struct TaskDescriptor {
    u16 state;
    u16 unknown_02;
    u32 unknown_04;
    Object *object;
} TaskDescriptor;

typedef struct EffectState {
    u16 unknown_00;
    u16 delay;
    Object *object;
    Task *animation;
    void *outputs[2];
    Task *coordinate_task;
    u32 unknown_18;
    Task *effect_task;
} EffectState;

extern const u8 g_object_08395F80[];
extern const u8 g_object_08395FA4[];
extern const u8 g_object_08395FD4[];

void func_080D38B4(void);
Task *func_080D7A70(const void *entries, u8 mode, Task *parent);
Task *func_080D7ABC(Task *task);
void func_080DE10C(Object *object, u16 mode);
void func_080DBDC8(Object *object, s16 *x, s16 *y);
Task *func_080D6098(s16 x, s16 y, u16 depth, u8 mode, u16 count,
                    void **outputs, const void *entries, Task *parent);
Task *func_080DFD8C(const void *entries, u8 mode, u16 flags,
                    u16 index, Task *parent);
Task *func_080D6134(Task *task);
void func_080DE390(Object *object);

u32 func_080E308C(Task *task, TaskDescriptor *descriptor, EffectState *state)
{
    s16 x;
    s16 y;

    switch (descriptor->state) {
    case 0:
        state->object = descriptor->object;
        break;
    case 1:
        func_080D38B4();
        break;
    case 0x100:
        state->animation = func_080D7A70(g_object_08395F80, 3, task);
        func_080DE10C(state->object, 0x44);
        state->delay = 6;
        descriptor->state++;
        break;
    case 0x101:
        if (state->delay != 0) {
            state->delay--;
            if (state->delay != 0)
                break;
        }
        state->animation = func_080D7ABC(state->animation);
        if (state->animation != 0)
            break;
        func_080DBDC8(state->object, &x, &y);
        state->coordinate_task = func_080D6098(x, y, 0, 1, 2,
                                               state->outputs,
                                               g_object_08395FA4, task);
        state->effect_task = func_080DFD8C(g_object_08395FD4, 1, 4, 0, task);
        descriptor->state++;
        break;
    case 0x102:
        state->coordinate_task = func_080D6134(state->coordinate_task);
        if (state->coordinate_task == 0) {
            func_080DE390(state->object);
            descriptor->state = 2;
        }
        break;
    }
    return 0;
}
