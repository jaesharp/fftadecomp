#include "ffta.h"

typedef struct {
    void *owner;
} Manager08066048;

typedef struct {
    u8 key_low;
    u8 key_high;
    u8 unknown_02[14];
} Record08066048;

typedef struct {
    Manager08066048 *manager;
    u8 unknown_04[12];
    Record08066048 *current;
    u8 unknown_14[0xA28];
    Record08066048 selected;
} State08066048;

extern State08066048 *data_0200F454;
extern void (*const data_0836D4BC)(void *, const void *, u32);
extern void *func_08005B00(Manager08066048 *, u32);
extern void func_08005B0C(Manager08066048 *, u8 *);
extern u8 func_080C9540(u16);
extern void func_080C9574(u16, u16);
extern u32 func_080D29D4(void *);

/* Complete [0x08066048, 0x08066114), 204 bytes.
 * Target: f0b54f464646c0b481460020804600240f4800680068c0219ff74efd051c362063f06afa0006002804d101243620012163f07cfa281c6cf0a9fc061c002c03d03620002163f072fa2c1c0023014f05e054f40002bcd4360801331034b34212da2078617803221140090201434945f3d10121884612480068124a80183b68211c1022dcf0c1f84046002809d10e490c4800680c4a80180b68291c1022dcf0b4f8074c20680068291c9ff70cfd2168054a8818086118bc9846a146f0bc01bc004754f400023c0a0000bcd43608
 */
void func_08066048(u32 value)
{
    u32 found = 0;
    u32 restore = 0;
    void *temporary;
    Record08066048 *record;
    u32 count;
    s32 i;

    temporary = func_08005B00(data_0200F454->manager, 0xC0);
    if (!func_080C9540(0x36)) {
        restore = 1;
        func_080C9574(0x36, 1);
    }
    count = func_080D29D4(temporary);
    if (restore)
        func_080C9574(0x36, 0);

    record = temporary;
    for (i = 0; i < (s32)count; i++, record++) {
        if ((record->key_low | ((record->key_high & 3) << 8)) == value) {
            found = 1;
            data_0836D4BC(&data_0200F454->selected, record, 16);
            break;
        }
    }
    if (!found)
        data_0836D4BC(&data_0200F454->selected, temporary, 16);
    func_08005B0C(data_0200F454->manager, temporary);
    data_0200F454->current = &data_0200F454->selected;
}
