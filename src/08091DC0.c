#include "ffta.h"

typedef struct TransferRecord {
    u8 status;
    u8 kind;
    u8 unknown_02[2];
    const void *source;
    void *destination;
    u32 control;
    u8 unknown_10[8];
    struct TransferRecord *next;
} TransferRecord;

typedef struct {
    u32 offset;
} RelativeData;

typedef struct {
    const void *table;
    const RelativeData *descriptor;
    u16 size;
    u8 unknown_0A[14];
    const u8 *data;
    u8 kind;
    u8 unknown_1D[31];
    TransferRecord transfer;
    u8 *buffer;
} DisplayObject;

extern void (*g_callbacks_0836D4B8[])(void *, u32);
extern void (*data_0836D4BC[])(void *, const void *, u32);
extern const u8 data_083C3454;
extern u8 data_06013C00;
extern const RelativeData data_0841CCB8;
extern const u8 data_08420774;
extern u8 data_03003B20;
extern void *func_08022840(u32 size);
extern u32 func_0800543C(void *destination, const void *source);
extern void func_08000A98(TransferRecord *entry, const void *source,
                        void *destination, u16 count);
extern u8 *func_080CBABC(u32 index);

/* 08091DC0..08091E48: 136 bytes, 47 instructions. */
DisplayObject *func_08091DC0(void)
{
    DisplayObject *object = func_08022840(0xAC);

    g_callbacks_0836D4B8[0](object, 0xAC);
    object->buffer = func_08022840(0x7C0);
    func_0800543C(object->buffer, &data_083C3454);
    func_08000A98(&object->transfer, object->buffer, &data_06013C00, 0x3E0);
    {
        const RelativeData *descriptor = &data_0841CCB8;
        const void *table = &data_08420774;

        object->descriptor = descriptor;
        object->table = table;
        object->data = (const u8 *)descriptor + descriptor->offset;
    }
    object->size = 0x1E0;
    object->kind = 6;
    data_0836D4BC[0](&data_03003B20, func_080CBABC(13), 0x20);
    return object;
}
