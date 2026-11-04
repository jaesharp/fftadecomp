#include "ffta.h"

typedef struct {
    u8 unknown_00[8];
    u16 *dest;
    u16 *source;
    u8 unknown_10[5];
    u8 rows;
    u8 columns;
    u8 unknown_17;
    u16 field_18;
    u16 field_1A;
    u8 unknown_1C[2];
    u8 stride;
    u8 unknown_1F;
} MenuList;

typedef struct {
    u8 unknown_00[0x11];
    u8 row;
    u8 unknown_12[2];
} MenuControls;

typedef struct {
    u8 unknown_00[4];
    MenuList *list;
    u8 unknown_08[8];
    u8 flags;
} MenuCursor;

typedef struct {
    u16 value;
    u8 field_02;
    u8 unknown_03;
} MenuEntry;

typedef struct {
    u8 unknown_0000[0xD20];
    MenuList list;
    MenuControls controls;
    MenuCursor cursor;
    u8 unknown_0D68[0x1F3C];
    MenuEntry entries[256];
} MenuState;

extern MenuState *data_0200F428;
extern u16 data_03000000;
extern void func_08017FBC(void *, u32);
extern u16 func_08017B68(MenuList *, u32);
extern void func_0802B07C(MenuList *, u16);
extern void func_0805C220(MenuList *, u16, u8, u32, u32);
extern void func_0805C09C(void);
extern void func_0802B108(MenuList *);
extern void func_08017E28(MenuCursor *);

/* Complete target [0x0805C10C, 0x0805C220): 276 bytes, 111 instructions. */
void func_0805C10C(void)
{
    MenuControls *controls = &data_0200F428->controls;
    u8 row = controls->row;
    u16 up = data_03000000 & 0x40;
    u8 selected;

    if (up) {
        row--;
        func_08017FBC(&data_0200F428->cursor, 0x40);
        selected = func_08017B68(&data_0200F428->list, (s8)row);
        func_0802B07C(&data_0200F428->list, 0x40);
        func_0805C220(&data_0200F428->list,
                      data_0200F428->entries[selected].value,
                      data_0200F428->entries[selected].field_02, 0, 0);
        func_0805C09C();
        func_0802B108(&data_0200F428->list);
        func_08017E28(&data_0200F428->cursor);
    } else if (data_03000000 & 0x80) {
        row++;
        func_08017FBC(&data_0200F428->cursor, 0x80);
        selected = func_08017B68(&data_0200F428->list, (s8)row);
        func_0802B07C(&data_0200F428->list, 0x80);
        func_0805C220(&data_0200F428->list,
                      data_0200F428->entries[selected].value,
                      data_0200F428->entries[selected].field_02, 3, 0);
        func_0805C09C();
        func_0802B108(&data_0200F428->list);
        func_08017E28(&data_0200F428->cursor);
    }
}
