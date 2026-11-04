#include "ffta.h"

typedef struct {
    void *manager;
    u8 *allocation;
    u8 finished;
    u8 unknown_09[0x16FB];
} TaskContext;

void *func_08022840(u32 byte_count);
void func_08022854(u8 *object);
void func_08005A24(void *manager);
void func_08005B18(void *manager);
void *func_08005C14(void *storage, u32 byte_count);
void func_08005C34(void *manager);

extern TaskContext *data_0200F454;
extern void (*g_callbacks_0836D4B8[])(void *, u32);

void func_08064EF8(u32 unused, u8 *phase)
{
    switch (*phase) {
    case 0: {
        TaskContext *context = func_08022840(0x3800);

        data_0200F454 = context;
        g_callbacks_0836D4B8[0](context, sizeof(*context));
        data_0200F454->allocation = (u8 *)context;
        data_0200F454->manager = func_08005C14(context + 1, 0x20FC);
        *phase = 1;
        break;
    }
    case 0xFF:
        if (data_0200F454 != 0) {
            u8 *allocation = data_0200F454->allocation;

            func_08005A24(data_0200F454->manager);
            func_08005B18(data_0200F454->manager);
            func_08005C34(data_0200F454->manager);
            func_08022854(allocation);
            data_0200F454 = 0;
            *phase = 2;
        }
        break;
    case 1:
        if (data_0200F454->finished != 0)
            *phase = 0xFF;
        break;
    }
}
