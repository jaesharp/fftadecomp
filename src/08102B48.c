#include "ffta.h"

typedef struct {
    u16 state;
    u16 unknown02;
    void *object;
    u8 *result;
    u32 unknown0C;
    u32 unknown10;
    u16 style;
    u16 unknown16;
    u32 unknown18;
} TaskDescriptor;

typedef u32 (*TaskCallback)(void *, TaskDescriptor *, void *);

u8 func_080D3B54(void *object);
void *func_08005B6C(TaskCallback callback, u16 payload_size,
                  TaskDescriptor *descriptor, void *parent);
u32 func_081023E8(void *task, TaskDescriptor *descriptor, void *payload);

void *func_08102B48(void *object, u8 style, u8 *result, void *parent)
{
    TaskDescriptor descriptor;

    if (func_080D3B54(object))
        return 0;

    descriptor.style = style;
    descriptor.object = object;
    descriptor.result = result;
    return func_08005B6C(func_081023E8, 0x25C, &descriptor, parent);
}
