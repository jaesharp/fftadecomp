#include "ffta.h"

typedef struct {
    u8 unknown_00[0x18];
    u16 count;
    u16 scroll;
    u32 unknown_1C;
} Menu082254;

typedef struct {
    u8 unknown_00[0x11];
    s8 row;
    u8 unknown_12[2];
} Cursor082254;

typedef struct {
    u8 unknown_00[4];
    u16 field_04;
    u8 unknown_06[0xE];
} Entry082254;

typedef struct {
    u8 unknown_00[0x18];
    Entry082254 *entries;
} Object082254;

typedef struct {
    u8 unknown_00[0x36];
    u8 selection;
    u8 unknown_37[0x41];
    Menu082254 menu;
    Cursor082254 cursor;
    u8 settings[0x1C];
    Object082254 *object;
} Slot082254;

typedef struct {
    u8 unknown_0000[0x44D];
    u8 field_044D;
    u8 unknown_044E[0x7D2];
    u8 field_0C20;
    u8 unknown_0C21[0x2067];
    Slot082254 slots[0];
} State082254;

extern State082254 *data_03002818;
extern void func_08017FBC(void *settings, u32 direction);
extern u16 func_08017B68(Menu082254 *menu, u32 row);
extern void func_080876F4(u32 first, u16 second, u32 third);
extern void func_0808C630(u16 value);
extern void func_08080F68(Menu082254 *menu, s32 row, u32 x, u32 y);
extern void func_08017FB0(Cursor082254 *cursor, u8 row);
extern void func_080814B4(u32 index, s32 row, Menu082254 *menu);
extern void func_08017884(Menu082254 *menu, u32 direction, u32 mode);

/* Complete [0x08082254, 0x080823B0): 348 bytes, 149 instructions. */
void func_08082254(u32 index, u8 direction, u8 row, u8 refresh)
{
    Object082254 *object = data_03002818->slots[index].object;
    u16 selected;

    func_08017FBC(data_03002818->slots[index].settings, direction);
    {
    s8 requested = row;

    selected = func_08017B68(&data_03002818->slots[index].menu, requested);
    if (data_03002818->field_044D == 2)
        func_080876F4(2, object->entries[selected].field_04, 1);
    if (data_03002818->field_0C20 != 0)
        func_0808C630(object->entries[selected].field_04);
    if (refresh == 0) {
        func_08080F68(&data_03002818->slots[index].menu, requested, 11, 17);
        func_08017FB0(&data_03002818->slots[index].cursor, (u8)requested);
        data_03002818->slots[index].selection =
            func_08017B68((Menu082254 *)(index * sizeof(Slot082254) + (u32)data_03002818 + 0x2D00), requested);
    } else {
        func_080814B4(index, requested, &data_03002818->slots[index].menu);
        data_03002818->slots[index].selection =
            func_08017B68((Menu082254 *)(index * sizeof(Slot082254) + (u32)data_03002818 + 0x2D00), requested);
        func_08017884(&data_03002818->slots[index].menu, direction, 1);
        func_08080F68(&data_03002818->slots[index].menu,
                      data_03002818->slots[index].cursor.row, 11, 17);
    }
    }
}
