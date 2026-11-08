#include "ffta.h"

typedef struct Task Task;

typedef struct {
    u16 message;
    u16 unknown_02;
    void *data;
    u32 unknown_08;
    u32 unknown_0c;
    u32 unknown_10;
    u16 delay;
    u16 unknown_16;
    u32 unknown_18;
} TaskEvent;

typedef struct {
    u32 value;
    u32 id : 16;
    u32 slot : 8;
} TaskPayload;

extern s32 func_080DB774(Task *task, TaskEvent *event, void *data);
extern Task *func_08005B6C(s32 (*callback)(Task *, TaskEvent *, void *),
                           u16 size, TaskEvent *event, Task *parent);

Task *func_080DC498(u32 value, u16 id, u8 slot, u16 delay, Task *parent)
{
    TaskEvent event;
    TaskPayload payload;

    payload.value = value;
    payload.id = id;
    payload.slot = slot;
    event.delay = delay;
    event.data = &payload;
    return func_08005B6C(func_080DB774, 0x10, &event, parent);
}
