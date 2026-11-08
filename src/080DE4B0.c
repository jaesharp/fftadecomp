#include "ffta.h"

typedef struct {
    void *object;
    u8 *result;
    u8 mode;
    s8 event;
    s8 repeat_count;
    u8 delay;
    u16 initial_delay;
} EventDefinition;

typedef struct {
    u16 state;
    u16 unknown_02;
    const EventDefinition *definition;
    u32 unknown_08[5];
} EventCommand;

typedef u32 (*TaskCallback)(void *, void *, void *);
extern u32 func_080DDA94(void *task, void *command, void *state);
extern void *func_08005B6C(TaskCallback callback, u16 payload_size,
                          void *descriptor, void *parent);

/* Complete [0x080DE4B0, 0x080DE4F4): 68 bytes including callback literal. */
void *func_080DE4B0(void *object, u8 *result, u8 mode, s8 event,
                    s8 repeat_count, u8 delay, u16 initial_delay, void *parent)
{
    EventCommand request;
    EventDefinition definition;

    definition.object = object;
    definition.result = result;
    definition.mode = mode;
    definition.event = event;
    definition.repeat_count = repeat_count;
    definition.delay = delay;
    definition.initial_delay = initial_delay;
    request.definition = &definition;
    return func_08005B6C(func_080DDA94, 0x10, &request, parent);
}
