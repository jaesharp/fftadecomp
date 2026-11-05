#include "ffta.h"

/* Complete [0x0800C2C0, 0x0800C2FC): 60 bytes, 17 instructions. */
typedef void (*BufferInitializer0800C2C0)(void *destination, u32 size);
typedef struct {
    void *allocation;
    u8 unknown_04[0x20];
    void *head;
} Record0800C2C0;

extern void *data_02008FF8;
extern Record0800C2C0 g_records_02009000[];
extern BufferInitializer0800C2C0 const g_callbacks_0836D4B8[];
extern u16 data_02009138;
extern u8 data_0200913A;

void func_0800C2C0(void *allocator)
{
    data_02008FF8 = allocator;
    g_callbacks_0836D4B8[0](g_records_02009000, 0x50);
    data_02009138 = 0x3FF;
    data_0200913A = 0xFF;
}
