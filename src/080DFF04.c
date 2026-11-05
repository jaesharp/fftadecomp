#include "ffta.h"

typedef struct {
    u16 delay;
    u8 count;
    void *data;
} ScheduledTaskParameters;

typedef struct {
    u16 phase;
    const ScheduledTaskParameters *parameters;
} ScheduledTaskState;

typedef struct {
    u16 delay;
    u8 count;
    void *data;
    u32 task;
} ScheduledTaskPayload;

extern u8 func_080D8B4C(void);
extern u32 func_080D7A70(void *data, u8 count, void *parent);
extern u32 func_080D7ABC(u32 handle);

u32 func_080DFF04(void *parent, ScheduledTaskState *state,
                 ScheduledTaskPayload *payload)
{
    switch (state->phase) {
    case 0: {
        const ScheduledTaskParameters *parameters = state->parameters;

        payload->count = parameters->count;
        payload->data = parameters->data;
        payload->delay = parameters->delay;
        break;
    }
    case 1:
        break;
    case 0x100:
        if (func_080D8B4C())
            break;
        if (payload->data != 0 && payload->count != 0)
            payload->task = func_080D7A70(payload->data, payload->count, parent);
        state->phase++;
        break;
    case 0x101:
        if (payload->delay != 0)
            payload->delay--;
        payload->task = func_080D7ABC(payload->task);
        if (payload->task == 0 && payload->delay == 0)
            state->phase = 2;
        break;
    }
    return 0;
}
