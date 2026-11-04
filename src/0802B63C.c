#include "ffta.h"

typedef struct {
    void *manager;
    void *allocation;
    void *first_task;
    void *second_task;
} TaskContext0802B63C;

typedef void (*BufferInitializer0802B63C)(void *destination, u32 size);

extern TaskContext0802B63C *data_0200F440;
extern BufferInitializer0802B63C g_callbacks_0836D4B8[];
extern const u8 data_083BE1F4[];
extern void *func_08022840(u32 size);
extern void *func_08005C14(void *storage, u32 byte_count);
extern u8 *func_0800543C(void *destination, const void *source);

/* Complete [0x0802B63C, 0x0802B6A0): 100 bytes, including mapped literals. */
void func_0802B63C(u32 size)
{
    u8 *allocation = func_08022840(size);

    data_0200F440 = (TaskContext0802B63C *)allocation;
    g_callbacks_0836D4B8[0](allocation, 0x209c);
    data_0200F440->allocation = allocation;
    data_0200F440->manager = func_08005C14(allocation + 0x209c, size - 0x209c);
    func_0800543C((u8 *)data_0200F440 + 0x65c, data_083BE1F4);
}
