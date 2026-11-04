#include "ffta.h"

extern u8 *data_020159B8;
extern u8 *data_020159BC;
extern void *data_0200F430;
extern void *data_020159C0;

extern void *func_08022840(u32 byte_count);
extern void func_08022854(u8 *allocation);
extern void func_0800A5F8(u8 *storage, u32 byte_count);
extern void func_0800A640(void);
extern void func_0800A61C(void);
extern void *func_08005C14(void *storage, u32 byte_count);
extern void func_08005A24(void *manager);
extern void *func_08005BFC(void *task);
extern void func_08005B18(void *manager);
extern void func_08005C34(void *manager);
extern void func_080D3024(void *data);

static inline void initialize_storage(u8 *storage, u32 storage_size)
{
    u8 **workspace = &data_020159BC;

    *workspace = storage + storage_size;
    func_0800A5F8(storage, storage_size);
    data_0200F430 = func_08005C14(*workspace, 0x4000);
}

/* Complete [0x080D36B0, 0x080D376C): 188 bytes, 66 instructions. */
void func_080D36B0(void *context, u8 *state)
{
    switch (*state) {
    case 0: {
        u8 **allocation = &data_020159B8;

        *allocation = func_08022840(0xA000);
        initialize_storage(*allocation, 0x6000);
        data_020159C0 = 0;
        *state = 1;
        break;
    }
    case 1:
        func_08005A24(data_0200F430);
        func_0800A640();
        if (data_020159C0 != 0)
            func_080D3024((u8 *)func_08005BFC(data_020159C0) + 0x8D0);
        break;
    case 0xFF:
        if (data_0200F430 != 0) {
            func_08005B18(data_0200F430);
            func_08005C34(data_0200F430);
            func_0800A61C();
            func_08022854(data_020159B8);
            data_0200F430 = 0;
        }
        break;
    }
}
