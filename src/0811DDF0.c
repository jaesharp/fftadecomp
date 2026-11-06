#include "ffta.h"

typedef struct Object Object;

typedef struct {
    u16 state;
    u8 unknown02[2];
    Object *first;
    Object *second;
} Event;

typedef struct {
    u16 timer;
    s16 x;
    s16 y;
    u8 unknown06[2];
    Object *first;
    Object *second;
    void *effect;
    u8 parameters[8];
    void *handle1C;
    void *handle20;
    u32 handle24;
    void *handle28;
} Context;

extern const u8 data_083A7248[];
extern const u8 data_083A72B0[];
extern const u8 data_083A7278[];
extern const u8 data_083A72A8[];
extern const u8 data_088F4E9C[];
extern const u8 data_0894C93C[];
extern const u8 data_0894D69C[];
extern u8 data_03003920[];
extern u16 g_control_flags_03000940;

extern u32 func_080035A8(u8);
extern void func_080D35D8(void);
extern void *func_080D3E9C(const void *, void *);
extern void *func_080D3F08(void *);
extern void func_080D4020(void);
extern void *func_080D4704(const void *, void *);
extern void *func_080D4774(void *);
extern void *func_080D6098(s16, s16, u16, u8, u16, void *, const void *, void *);
extern void *func_080D6134(void *);
extern void func_080D7220(const void *, u8, u8, s16, s16, u16);
extern u32 func_080D7A70(const void *, u8, void *);
extern u32 func_080D7ABC(u32);
extern void func_080DBDC8(const Object *, s16 *, s16 *);
extern void func_080DBEB4(Object *, u8);
extern void func_080DE10C(Object *, u16);
extern void *func_080DFD8C(const void *, u8, u16, u16, void *);
extern void func_0814186C(const void *, void *, u32);

u32 func_0811DDF0(void *owner, Event *event, Context *context)
{
    switch (event->state) {
    case 0:
    {
        u16 fill;
        context->first = event->first;
        context->second = event->second;
        func_080DBDC8(context->first, &context->x, &context->y);
        context->handle24 = func_080D7A70(data_083A7248, 4, owner);
        fill = 0;
        func_0814186C(&fill, data_03003920, 0x01000010);
        break;
    }
    case 1:
        func_080D35D8();
        break;
    case 0x100:
        context->handle24 = func_080D7ABC(context->handle24);
        if (context->handle24 == 0) {
            func_080DE10C(context->first, 0x58);
            context->handle28 = func_080DFD8C(data_083A72B0, 1, 4, 0, owner);
            context->timer = 20;
            event->state++;
        }
        break;
    case 0x101:
        if (--context->timer == 0) {
            context->effect = func_080D6098((s16)(context->x + 11),
                (s16)(context->y - 31), 0, 1, 2, context->parameters,
                data_083A7278, owner);
            context->handle28 = func_080DFD8C(data_083A72A8, 1, 4, 0, owner);
            context->timer = 12;
            event->state++;
        }
        break;
    case 0x102:
        if (--context->timer == 0) {
            func_080D7220(data_088F4E9C, 0, 2, (s16)(context->x + 11),
                (s16)(context->y - 31), 0);
            context->handle20 = func_080D4704(data_0894C93C, owner);
            context->handle1C = func_080D3E9C(data_0894D69C, owner);
            context->timer = 130;
            event->state++;
        }
        break;
    case 0x103:
        if (context->timer != 0 && --context->timer == 0) {
            func_080DBEB4(context->first, 0);
            func_080DBEB4(context->second, 0);
        }
        context->handle1C = func_080D3F08(context->handle1C);
        if (context->handle1C == 0) {
            context->handle20 = func_080D4774(context->handle20);
            if (context->handle20 == 0) {
                u32 mask = func_080035A8(2);
                g_control_flags_03000940 &= ~mask;
                func_080D4020();
                context->effect = func_080D6134(context->effect);
                if (context->effect == 0)
                    event->state = 2;
            }
        }
        break;
    }
    return 0;
}
