#include "ffta.h"

typedef struct SelectionRecord SelectionRecord;
typedef void (*BufferInitializer)(void *destination, u32 size);

typedef union {
    SelectionRecord *selections[16];
    u8 *records[16];
} OutputEntries;

typedef struct {
    u8 unknown_0000[0x1198];
    u8 field_1198;
    u8 field_1199;
    u8 field_119A;
    u8 unknown_119B[2];
    u8 field_119D;
    u8 unknown_119E[0xB];
    u8 count_11A9;
    u8 unknown_11AA;
    u8 count_11AB;
    OutputEntries entries;
    u8 storage_11EC[0x5C];
    u8 storage_1248[0x108];
    const u8 *entries_1350[64];
    void *field_1450;
    void *field_1454;
    void *field_1458;
} MenuState;

extern MenuState *data_0200F448;
extern u8 g_state_02000000[];
extern BufferInitializer g_callbacks_0836D4B8[];
extern void func_08060DEC(u8 index, u8 value);
extern u8 func_08036350(u8 selector);
extern u32 func_080D1B80(const u8 **output, u32 capacity, u32 filter);
extern u32 func_080D0590(SelectionRecord **output, u32 capacity, u32 filter);
extern u32 func_080D0AB0(u8 **output, u32 limit);
extern void func_080CFCD0(u32 mode);
extern u32 func_0805D1A4(void);

/* Complete target [0x0805D23C, 0x0805D4EC): 688 bytes, 253 instructions. */
void func_0805D23C(u16 mode)
{
    data_0200F448->field_1458 = 0;
    data_0200F448->field_1450 = 0;
    data_0200F448->field_1454 = 0;
    g_callbacks_0836D4B8[0](&data_0200F448->entries, 0x40);
    g_callbacks_0836D4B8[0](data_0200F448->storage_11EC, 0x5C);
    g_callbacks_0836D4B8[0](data_0200F448->storage_1248, 0x108);
    g_callbacks_0836D4B8[0](data_0200F448->entries_1350, 0x100);
    func_08060DEC(3, 0);
    func_08060DEC(2, 0);
    func_08060DEC(7, 0);

    switch ((s16)mode) {
    case 0:
        data_0200F448->count_11AB =
            func_080D1B80(data_0200F448->entries_1350, 0x40,
                          func_08036350(g_state_02000000[0x1F69]));
        if (data_0200F448->count_11AB) {
            data_0200F448->field_1198 = 3;
            data_0200F448->field_119D = 0x40;
            data_0200F448->field_119A = 5;
            data_0200F448->field_1199 = 2;
        } else {
            data_0200F448->field_1198 = 0;
            data_0200F448->field_119D = 0x41;
            data_0200F448->field_119A = 6;
            data_0200F448->field_1199 = 2;
        }
        break;
    case 1:
        func_080CFCD0(0);
        data_0200F448->count_11A9 =
            func_080D0590(data_0200F448->entries.selections, 0x10,
                          func_08036350(g_state_02000000[0x1F69]));
        if (data_0200F448->count_11A9) {
            data_0200F448->field_1198 = 4;
            data_0200F448->field_119D = 0x43;
            data_0200F448->field_119A = 5;
            data_0200F448->field_1199 = 2;
        } else {
            data_0200F448->field_1198 = 0;
            data_0200F448->field_119D = 0x42;
            data_0200F448->field_119A = 6;
            data_0200F448->field_1199 = 2;
        }
        break;
    case 2:
        data_0200F448->count_11A9 =
            func_080D0AB0(data_0200F448->entries.records, 0x10);
        if ((u8)func_0805D1A4()) {
            data_0200F448->field_1198 = 5;
            data_0200F448->field_119D = 0x44;
            data_0200F448->field_119A = 5;
            data_0200F448->field_1199 = 2;
        } else {
            data_0200F448->field_1198 = 0;
            data_0200F448->field_119D = 0x45;
            data_0200F448->field_119A = 6;
            data_0200F448->field_1199 = 2;
        }
        break;
    case 3:
        data_0200F448->field_119A = 10;
        data_0200F448->field_1199 = 2;
        break;
    }
}
