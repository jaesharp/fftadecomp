#include "ffta.h"

typedef struct MenuOwner MenuOwner;
typedef struct MenuObject MenuObject;

typedef struct {
    u8 unknown00[8];
    void *allocator;
    u8 unknown0C[0x428];
    u8 resource;
    u8 render_a;
    s16 x;
    s16 y;
    u8 render_b;
    u8 unknown43B;
    u8 selection;
    u8 previous;
    u8 unknown43E[2];
    MenuOwner *owner;
    MenuObject *object;
    void *item;
    u8 unknown44C[0x18BD];
    u8 flags;
} MenuState;

extern MenuState *data_03002818;
extern u8 data_0200F292;
extern const u8 data_08393ECA[];
extern const u8 data_08393ED2[];

extern MenuOwner *func_08021A3C(void *, u16, u16, u16, u16);
extern void *func_08021AD0(MenuOwner *);
extern MenuObject *func_08021B1C(MenuOwner *);
extern void func_08021BD4(MenuObject *, void *);
extern void func_08021DF8(MenuObject *, u16, u16);
extern void func_08021E7C(MenuOwner *);
extern void *func_08021618(MenuObject *, void *, u32, u32, u32, u32, u32);
extern void func_08021F18(MenuObject *, s32, s32, u8, u8, u8, u8, u8, u8, u8);
extern void func_08001CF0(const u8 *, s32, s32, u8, u8, u8, u8, u8, u32, u8, u32);
extern void func_0814186C(const void *, void *, u32);

void func_080888B4(u32 unused, u8 *stage)
{
    u16 fill;
    s32 phase = *stage;

    if (phase == 5)
        goto fixed_position;
    if (phase <= 5) {
        if (phase == 2)
            goto refresh;
        if (phase <= 2) {
            if (phase == 0)
                goto initialize;
            if (phase == 1)
                goto acknowledge;
        } else {
            if (phase == 3)
                goto active;
            if (phase == 4)
                goto positioned;
        }
    } else {
        if (phase == 0xFD)
            goto restore;
        if (phase <= 0xFD) {
            if (phase == 6)
                goto shifted_position;
        } else if (phase == 0xFE) {
            goto release;
        }
    }
    goto finished;

    initialize:
        data_03002818->owner = func_08021A3C(data_03002818->allocator, 500, 540, 0, 0);
        data_03002818->selection = 0;
        data_03002818->previous = 0;
        fill = 0;
        func_0814186C(&fill, data_03002818->item, 0x01000002);
        data_03002818->object = func_08021B1C(data_03002818->owner);
        func_08021DF8(data_03002818->object, 0, 2);
        if (data_03002818->item != 0)
            func_08021BD4(data_03002818->object, data_03002818->item);
        data_03002818->item = func_08021618(data_03002818->object, 0, 0, 20,
            data_03002818->resource, data_03002818->selection, 0);
    acknowledge:
        *stage = 0xFC;
        goto finished;
    refresh:
        if (data_03002818->item != 0)
            func_08021BD4(data_03002818->object, data_03002818->item);
        data_03002818->item = func_08021618(data_03002818->object, 0, 0, 20,
            data_03002818->resource, data_03002818->selection, 0);
        *stage = 3;
    positioned: {
        s32 x;
        s32 y;
        s32 draw_y;
        u8 enabled;
        y = data_03002818->y;
        draw_y = y - 8;
        if ((u32)(y + 24) > 192)
            goto finished;
        x = data_03002818->x;
        if ((u32)(x + 16) > 240)
            goto finished;
        func_08021F18(data_03002818->object, x + 16, draw_y, 0, 0, 0, 0, 0,
            data_03002818->render_a, data_03002818->render_b);
        if (data_03002818->flags & 1) {
            enabled = data_03002818->flags & 4;
            if (enabled)
                func_08001CF0(data_08393ECA, x, y - 9, 0, 0, 0, 0, 0, 0, 1, 0);
            else if (data_03002818->flags & 24)
                func_08001CF0(data_08393ED2, x, y - 9, 0, 0, 0, 0, 0, 0, 1, 0);
        }
        goto finished;
    }
    active: {
        s32 x;
        s32 y;
        s32 draw_y;
        u8 enabled;
        if (data_03002818->previous != data_03002818->selection) {
            data_03002818->previous = data_03002818->selection;
            if (data_03002818->item != 0)
                func_08021BD4(data_03002818->object, data_03002818->item);
            data_03002818->item = func_08021618(data_03002818->object, 0, 0, 20,
                data_03002818->resource, data_03002818->selection, 0);
            func_08021DF8(data_03002818->object, 0, 2);
        }
        func_08021E7C(data_03002818->owner);
        y = data_03002818->y;
        draw_y = y - 8;
        if ((u32)(y + 24) > 192)
            goto finished;
        x = data_03002818->x;
        if ((u32)(x + 16) > 240)
            goto finished;
        func_08021F18(data_03002818->object, x + 16, draw_y, 0, 0, 0, 0, 0,
            data_03002818->render_a, data_03002818->render_b);
        if (data_03002818->flags & 1) {
            enabled = data_03002818->flags & 4;
            if (enabled)
                func_08001CF0(data_08393ECA, x, y - 9, 0, 0, 0, 0, 0, 0, 1, 0);
            else if (data_03002818->flags & 24)
                func_08001CF0(data_08393ED2, x, y - 9, 0, 0, 0, 0, 0, 0, 1, 0);
        }
        goto finished;
    }
    fixed_position:
        func_08021E7C(data_03002818->owner);
        func_08021F18(data_03002818->object, 24, 148, 0, 0, 0, 0, 0,
            data_03002818->render_a, 2);
        goto finished;
    shifted_position: {
        s32 x;
        s32 draw_y;
        func_08021E7C(data_03002818->owner);
        draw_y = data_03002818->y + 60;
        if ((u32)draw_y > 160)
            goto finished;
        x = data_03002818->x;
        if ((u32)x > 240)
            goto finished;
        func_08021F18(data_03002818->object, x, draw_y, 0, 0, 0, 0, 0,
            data_03002818->render_a, 2);
        goto finished;
    }
    restore:
        *stage = data_0200F292;
        goto finished;
    release:
        func_08021AD0(data_03002818->owner);
        *stage = 0xFC;
        goto finished;
finished:
    ;
}
