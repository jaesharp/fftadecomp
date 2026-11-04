#include "ffta.h"

typedef struct {
    u8 unknown_00[0x10];
    void *selection;
} TaskState;

typedef struct {
    u16 state;
    u8 unknown_02[0x12];
    u16 mode;
} Command;

typedef struct {
    TaskState *task;
    u16 flags;
    u16 selection;
    u8 mode;
    u8 active;
    u16 result;
    u8 first_control[0x10];
    u8 second_control[0x10];
    void *menu;
    void *dialog;
} MenuContext;

typedef struct {
    void *selection;
    u8 unknown_04[0xC];
    u8 index;
    u8 count;
} SelectionState;

extern TaskState *data_0200F454;
extern SelectionState g_state_020020D0;
extern void *func_08005B28(u32 bytes);
extern void func_08005B40(void *object);
extern u16 func_08011860(void);
extern s8 func_08013380(void);
extern void func_08013390(u32 value);
extern void func_08061564(void *context, u8 index);
extern u32 func_08066AD0(MenuContext *context);
extern void func_08066BC4(MenuContext *context);
extern void func_080688D0(MenuContext *context);

/* Complete target [0x080659AC, 0x08065B58): 428 bytes. */
s32 func_080659AC(void *owner, Command *command, MenuContext *context)
{
    u16 state = command->state;
    u16 waiting_state = 0x104;

    switch (state) {
    case 1:
        if (context->menu != 0) {
            func_08005B40(context->menu);
            context->menu = 0;
        }
        if (context->dialog != 0) {
            func_08005B40(context->dialog);
            context->dialog = 0;
        }
        break;
    case 0:
        context->mode = command->mode;
        context->task = data_0200F454;
        g_state_020020D0.selection = context->task->selection;
        g_state_020020D0.index = 0;
        g_state_020020D0.count = 3;
        break;
    case 0x100:
        context->menu = func_08005B28(0x794);
        func_080688D0(context);
        command->state = waiting_state;
        break;
    case 0x104:
        if (func_08011860()) {
            if (context->flags & 0x40) {
                context->active = 0;
                command->state = 0x103;
            } else {
                goto activate;
            }
        }
        break;
    case 0x106:
        if (context->flags & 0x80) {
            context->flags &= ~0x80;
            command->state = 3;
        }
        break;
    case 0x105:
        if ((u8)func_08066AD0(context)) {
            if (context->flags & 0x100) {
                context->flags &= ~0x100;
                command->state = 0x109;
            } else {
                command->state = waiting_state;
            }
        }
        break;
    case 0x103:
        func_08005B40(context->menu);
        context->menu = 0;
        context->selection = context->result;
        command->state = 0x106;
        break;
    case 0x109:
        context->dialog = func_08005B28(0xA04);
        func_08061564(context->dialog, 2);
        command->state = 0x10A;
        break;
    case 0x10A:
        if (func_08011860()) {
            u8 answer = func_08013380();

            func_08013390((u32)context->menu);
            func_08005B40(context->dialog);
            context->dialog = 0;
            if ((s8)answer < 0) {
activate:
                context->active = 1;
                command->state = 0x105;
            } else {
                if ((s8)answer > 0) {
                    context->result = 0xFFFF;
                    context->flags = 0x40;
                } else {
                    context->result = 0xFFFE;
                    context->flags |= 0x40;
                }
                command->state = waiting_state;
            }
        }
        break;
    }
    func_08066BC4(context);
    return 0;
}
