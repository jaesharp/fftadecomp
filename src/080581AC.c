#include "ffta.h"

typedef struct {
    u8 unknown_00[0x18];
    s16 total;
    s16 offset;
} ScrollState;

typedef struct {
    u8 unknown_00[0xE];
    u16 extent;
    u8 unknown_10;
    u8 value;
} ScaledState;

typedef struct {
    u8 unknown_00[0x2C];
    ScrollState scroll;
    u8 unknown_48[4];
    ScaledState scaled;
    u8 tail[0];
} Menu;

typedef struct {
    u16 held;
    u16 pressed;
    u16 repeated;
    u8 unknown_06;
    u8 flags;
} Input;

typedef struct {
    void (*callback)(void *);
    void *argument;
    u16 buttons;
    u16 unknown_0A;
} Action;

struct State080023D0;
extern Input data_03000000;
extern void func_080023D0(struct State080023D0 *);
extern void func_0805872C(ScaledState *, u8);
extern u32 func_080583C8(ScrollState *, u16);
extern void func_08141540(u16);
/* Conditional observed caller ABI; the complete 17FBC entry ignores R0/R1. */
extern void func_08017FBC(void *, u16);

/* Complete 412-byte owner, including its four actual literal words. */
void func_080581AC(Menu *menu, void (*changed)(void *), void *context,
                   u8 visible_count, const Action *actions, u8 action_count)
{
    s8 index;

    if (visible_count > 3) {
        if (data_03000000.repeated & 0x80) {
            s8 next;
            func_080023D0((struct State080023D0 *)&data_03000000);
            next = menu->scaled.value + 1;
            if (next <= 2) {
                func_08141540(0x6D);
                func_0805872C(&menu->scaled, next);
                func_08017FBC(menu->tail, 0x80);
            } else if ((u8)func_080583C8(&menu->scroll, 0x80)) {
                func_08141540(0x6D);
                changed(context);
                func_08017FBC(menu->tail, 0x80);
            }
        }
        if (data_03000000.repeated & 0x40) {
            s8 next;
            func_080023D0((struct State080023D0 *)&data_03000000);
            next = menu->scaled.value - 1;
            if (next >= 0) {
                func_08141540(0x6D);
                func_0805872C(&menu->scaled, next);
            } else if ((u8)func_080583C8(&menu->scroll, 0x40)) {
                func_08141540(0x6D);
                changed(context);
            } else {
                goto actions;
            }
            func_08017FBC(menu->tail, 0x40);
        }
    } else {
        if (data_03000000.repeated & 0x80) {
            u8 next;
            func_080023D0((struct State080023D0 *)&data_03000000);
            next = menu->scaled.value + 1;
            if ((s8)next > visible_count - 1)
                next = visible_count - 1;
            else
                func_08141540(0x6D);
            func_0805872C(&menu->scaled, next);
        } else if (data_03000000.repeated & 0x40) {
            u8 next;
            func_080023D0((struct State080023D0 *)&data_03000000);
            next = menu->scaled.value - 1;
            if ((s8)next < 0)
                next = 0;
            else
                func_08141540(0x6D);
            func_0805872C(&menu->scaled, next);
        }
    }
actions:
    for (index = 0; index < action_count; index++) {
        if (data_03000000.pressed & actions[index].buttons)
            actions[index].callback(actions[index].argument);
    }
}
