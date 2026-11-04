#include "ffta.h"

/* 0x0800C2FC..0x0800C344: 72 target bytes. */
typedef struct {
    u8 *allocation;
    u8 unknown_04[0x20];
    void *head;
} AllocationRecord0800C2FC;

extern u8 g_records_02009000[];
extern void *data_02008FF8;
extern void func_0800C1C8(u8 index);
extern void func_08007170(void *owner, u8 *object);

void func_0800C2FC(void)
{
    u16 index = 0;

    do {
        func_0800C1C8(index);
    } while (++index < 2);
    index = 0;
    do {
        AllocationRecord0800C2FC *record =
            (AllocationRecord0800C2FC *)(g_records_02009000 + index * 40);

        if (record->allocation != 0)
            func_08007170(data_02008FF8, record->allocation);
    } while (++index < 2);
}
