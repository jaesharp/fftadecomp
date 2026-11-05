#include "ffta.h"

struct Object080A7DE0 {
    void *unit;
    u8 unknown_04[0x1b];
    s8 field_1f;
};

struct State080A7DE0 {
    struct Object080A7DE0 *object;
    void *task;
    u16 current;
    u16 count;
    u16 history[34];
};

extern void func_080D376C(void);
extern u8 func_080D37F8(void);
extern u8 func_080D39B0(void);
extern void *func_080D3508(u16 action, void *resource, u32 value);
extern u8 func_080D3878(const void *task);
extern void func_080D3864(void *task);
extern void func_080D37AC(void);
extern u8 func_080D37C4(void);
extern void func_080CDFC0(void *unit, u8 enabled);
extern void func_0809836C(struct Object080A7DE0 *object, u16 action,
                          s8 value, u16 option);

/* Complete [0x080A7DE0, 0x080A7EC2), 226 bytes, 81 instructions. */
u8 func_080A7DE0(struct State080A7DE0 *state)
{
    switch (state->current) {
    case 0:
        func_080D376C();
        state->current = 1;
        break;
    case 1:
        if (!func_080D37F8())
            break;
        if (!func_080D39B0())
            break;
        goto advance;
    case 4:
        state->task = func_080D3508(0x168, 0, (u32)state->object);
        state->current = 7;
        break;
    case 2:
        state->task = func_080D3508(0x156, 0, 1);
        state->current = 7;
        break;
    case 3:
        state->task = func_080D3508(0x157, 0, 1);
        state->current = 7;
        break;
    case 7:
        if (!func_080D3878(state->task))
            break;
        func_080D3864(state->task);
        state->task = 0;
        goto advance;
    case 5:
        func_080D37AC();
        state->current = 6;
        break;
    case 6:
        if (!func_080D37C4())
            break;
    advance:
        state->current = state->history[--state->count];
        break;
    case 8:
        func_080CDFC0(state->object->unit, 0);
        func_0809836C(state->object, 10, state->object->field_1f, 0);
        return 0;
    }
    return 1;
}
