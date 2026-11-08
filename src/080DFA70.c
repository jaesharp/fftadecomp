#include "ffta.h"

/* 0x080DFA70..0x080DFAD0: 96 bytes. */
typedef u32 (*TaskCallback)(void *task, void *request, void *state);

typedef struct {
    u8 channel;
    u8 mode;
    u8 parameter;
    u16 duration;
    u16 flags;
    u32 first;
    u32 second;
} TaskParameters;

typedef struct {
    u16 phase;
    u16 unknown_02;
    void *object;
    const TaskParameters *parameters;
    u32 unknown_0C;
    u32 unknown_10;
    u16 delay;
    u16 flags;
    u32 unknown_18;
} TaskRequest;

u32 func_080DF31C(void *task, void *request, void *state);
void *func_08005B6C(TaskCallback callback, u16 state_size,
                  void *request, void *parent);

void *func_080DFA70(void *object, u8 channel, u8 mode, u8 parameter,
                   u16 duration, u16 flags, u32 first, u32 second,
                   u16 delay, u16 task_flags, void *parent)
{
    TaskRequest request;
    TaskParameters parameters;

    parameters.channel = channel;
    parameters.mode = mode;
    parameters.parameter = parameter;
    parameters.duration = duration;
    parameters.flags = flags;
    parameters.first = first;
    parameters.second = second;
    request.object = object;
    request.parameters = &parameters;
    request.delay = delay;
    request.flags = task_flags;
    return func_08005B6C(func_080DF31C, 0x64, &request, parent);
}
