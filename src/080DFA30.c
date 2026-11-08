#include "ffta.h"

typedef struct SchedulerDescriptor080DFA30 {
    u8 unknown_00[4];
    void *object;
    u32 identifier;
    u32 mode;
    u8 unknown_10[4];
    u16 first;
    u16 second;
    u16 delay;
} SchedulerDescriptor080DFA30;

typedef u32 (*SchedulerCallback080DFA30)(void *task, void *descriptor,
                                       void *payload);
u32 func_080DF14C(void *task, SchedulerDescriptor080DFA30 *descriptor,
                  void *payload);
void *func_08005B6C(SchedulerCallback080DFA30 callback, u16 payload_size,
                  void *descriptor, void *parent);

/* 0x080DFA30: 64 target bytes, including the callback literal. */
void *func_080DFA30(void *object, u16 identifier, u8 mode, u8 first,
                   u8 second, u16 delay, void *parent)
{
    SchedulerDescriptor080DFA30 descriptor;

    descriptor.object = object;
    descriptor.identifier = identifier;
    descriptor.mode = mode;
    descriptor.first = first;
    descriptor.second = second;
    descriptor.delay = delay;
    return func_08005B6C((SchedulerCallback080DFA30)func_080DF14C,
                         0x20, &descriptor, parent);
}
