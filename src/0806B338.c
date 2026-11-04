#include "ffta.h"

typedef struct {
    u16 held;
    u16 pressed;
    u16 repeated;
} InputState0806B338;

typedef struct {
    u8 unknown_00[0x20];
} MenuList0806B338;

typedef struct {
    u8 unknown_00[0x11];
    u8 row;
    u8 unknown_12[2];
} MenuControls0806B338;

typedef struct {
    u16 item;
    u8 quantity;
    u8 unknown_03;
} Item0806B338;

typedef struct {
    u8 unknown_0000[0x14c0];
    MenuList0806B338 list;
    MenuControls0806B338 controls;
    u8 cursor[0x10];
    u8 unknown_1504[0x3000];
    Item0806B338 items[0x178];
} State0806B338;

extern State0806B338 *data_0200F428;
extern InputState0806B338 data_03000000;
extern void func_08017FBC(void *cursor, u32 direction);
extern u16 func_08017B68(MenuList0806B338 *list, s8 row);
extern void func_0802B07C(MenuList0806B338 *list, u16 direction);
extern void func_0806E66C(MenuList0806B338 *list, u16 item, u8 flags,
                        u8 quantity, u32 mode, u32 row, u32 option);
extern void func_0806E528(void);
extern void func_08017E28(void *cursor);

/* Complete target [0x0806B338, 0x0806B460): 296 bytes, 119 instructions. */
/* Target bytes: f0b5474680b483b0204f3a68a72149015018467c1e480188402008400004050c002d3dd0701e0006060e1a4b9846d0184021acf727fe3868a6246401001931060916acf7f5fb0006060e386800194021bff778fe38680419b10040180e4a811809880e4bc2181278013bc018037801200090002001900290201c03f05bf903f0b7f838684044acf733fd40e028f4000200000003f4140000044500000745000080200840002832d0701c0006060e1b48804610188021acf7e5fd3868a6246401001931060916acf7b3fb0006060e386800198021bff736fe38680419b10040180f4a811809880f4bc2181278013bc018037801200090032001900295201c03f019f903f075f838684044acf7f1fc03b008bc9846f0bc01bc00470000f41400000445000007450000 */
void func_0806B338(void)
{
    MenuControls0806B338 *controls = &data_0200F428->controls;
    u8 row = controls->row;
    u16 up = data_03000000.held & 0x40;
    u8 selected;

    if (up) {
        row--;
        func_08017FBC(data_0200F428->cursor, 0x40);
        selected = func_08017B68(&data_0200F428->list, (s8)row);
        func_0802B07C(&data_0200F428->list, 0x40);
        func_0806E66C(&data_0200F428->list,
                      data_0200F428->items[selected].item,
                      data_0200F428->items[selected].unknown_03,
                      data_0200F428->items[selected].quantity, 1, 0, 0);
        func_0806E528();
        func_08017E28(data_0200F428->cursor);
    } else if (data_03000000.held & 0x80) {
        row++;
        func_08017FBC(data_0200F428->cursor, 0x80);
        selected = func_08017B68(&data_0200F428->list, (s8)row);
        func_0802B07C(&data_0200F428->list, 0x80);
        func_0806E66C(&data_0200F428->list,
                      data_0200F428->items[selected].item,
                      data_0200F428->items[selected].unknown_03,
                      data_0200F428->items[selected].quantity, 1, 3, 0);
        func_0806E528();
        func_08017E28(data_0200F428->cursor);
    }
}
