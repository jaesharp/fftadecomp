#include "ffta.h"

typedef struct {
    u16 state;
    u8 unknown_02[0x12];
    u16 value;
} PanelCommand;

typedef struct PanelContext080185C8 PanelContext080185C8;
typedef struct PanelResource080185C8 PanelResource080185C8;

typedef struct {
    void *task;
    u16 flags;
    u16 selection;
    u8 value;
    u8 text;
    u8 unknown_0A[2];
    PanelContext080185C8 *panel;
} PanelCommandContext;

typedef struct {
    u8 unknown_00[0xC];
    u16 value;
} PanelArguments;

extern void *data_0200F454;
extern PanelArguments g_state_020020D0;
extern u8 data_084C3E60[];
extern PanelResource080185C8 data_030008B0;
extern u8 data_03000990[];
extern void *func_08005B28(u32 bytes);
extern void func_08005B40(void *object);
extern void func_080185C8(PanelContext080185C8 *context, void *buffer,
                         PanelResource080185C8 *resource, void *secondary,
                         u16 tile);
extern void func_08018624(s8 x, u8 y, u16 text, u8 width,
                         u16 value, const void *argument);
extern u32 func_08018790(void);
extern void func_08018AA8(void);
extern void func_0802A2C0(u8 x, u8 y, u8 width, u8 height);
extern void func_08141540(u16 song);
extern void func_08141570(s32 player, u16 song);

s32 func_08065B58(void *owner, PanelCommand *command,
                 PanelCommandContext *context)
{
    switch (command->state) {
    case 1:
        if (context->panel != 0) {
            func_08005B40(context->panel);
            context->panel = 0;
        }
        break;
    case 0:
        context->value = command->value;
        context->task = data_0200F454;
        context->text = g_state_020020D0.value;
        func_0802A2C0(0, 0, 30, 20);
        break;
    case 0x100:
        context->panel = func_08005B28(0x3D8);
        func_080185C8(context->panel, data_084C3E60,
                     &data_030008B0, data_03000990, 0x1C0);
        if (context->text == 25 || context->text == 27 || context->text == 28)
            func_08018624(-1, 10, context->text, 20, 0, 0);
        else
            func_08018624(-1, 10, context->text, 0, 0, 0);
        command->state = 0x104;
        break;
    case 0x104:
        if ((u16)func_08018790()) {
            if (context->flags & 0x40) {
                context->flags &= ~0x40;
                command->state = 0x103;
            } else {
                if ((u8)(context->text - 16) <= 1 || context->text == 13 || context->text == 14)
                    func_08141570(1, 8);
                else if (context->text == 25)
                    func_08141540(112);
                else if (context->text == 27)
                    func_08141540(100);
                else if (context->text == 28)
                    func_08141570(1, 107);
                command->state = 0x106;
            }
        }
        break;
    case 0x106:
        if (context->flags & 0x80) {
            context->flags &= ~0x80;
            command->state = 3;
        } else if (context->flags & 0x40) {
            func_08018AA8();
            command->state = 0x104;
        }
        break;
    case 0x103:
        func_08005B40(context->panel);
        context->panel = 0;
        func_0802A2C0(0, 0, 30, 10);
        context->selection = 0xFFFE;
        command->state = 0x106;
        break;
    }
    return 0;
}
