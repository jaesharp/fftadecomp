#include "ffta.h"

typedef struct {
    u16 phase;
    u16 unknown_02;
    void *actor;
    u8 *ready;
} Descriptor;
typedef struct {
    s16 x, y;
    u8 unknown_04[2];
    u8 palette;
    u8 unknown_07;
    u8 *ready;
    u8 *object;
    void *actor;
    void *transfer;
    void *resource;
    void *input_actor;
} Payload;
typedef struct { u16 colors[16]; } Palette;

extern const u8 data_0894AC90[];
extern const Palette data_03003A60[];
extern void *func_080DD4A4(void *, u8);
extern void *func_080DD748(void *, s16 *, s16 *, s16 *);
extern u8 func_080DBC18(void *, u32);
extern void func_08011428(void *);
/* The caller supplies an actor word; the retained callee ignores that word. */
extern int func_080DE488(void *);
extern u8 func_080DBC58(void *, u32);
extern void *func_08147D94(u16, u16, u16, u16, u8, u8);
extern void *func_080D4704(const void *, void *);
extern void *func_081484CC(void *);
extern u32 func_080DBD30(void *, u8 *, u8 *);
extern u16 func_080DBD48(void *);
extern u32 func_08011348(u32, u32, u16, u8, s16, s16, s16, s16, s16, u16);
extern void func_08011118(u8 *, u8);
extern void func_08011120(u8 *, u8);
extern void func_08011138(u8 *, u8);
extern void *func_08147D2C(u16, u16, u16, const u16 *);
extern void *func_080D4774(void *);

u32 func_08115B6C(void *task, Descriptor *descriptor, Payload *payload)
{
    u8 first, second;
    u32 resource;
    u16 frame;

    switch (descriptor->phase) {
    case 0:
        payload->input_actor = descriptor->actor;
        payload->ready = descriptor->ready;
        *payload->ready = 0;
        payload->actor = func_080DD748(func_080DD4A4(payload->input_actor, 0),
                                     &payload->x, &payload->y, 0);
        break;
    case 1:
        if (payload->actor)
            func_080DBC18(payload->actor, payload->palette);
        if (payload->object) {
            func_08011428(payload->object);
            payload->object = 0;
        }
        break;
    case 0x100:
        if ((u8)func_080DE488(payload->actor)) {
            payload->palette = func_080DBC58(payload->actor, 7);
            payload->transfer = func_08147D94(0x170, 16, 12, 0x7FFF, 16, 16);
            payload->resource = func_080D4704(data_0894AC90, task);
            descriptor->phase++;
        }
        break;
    case 0x101:
        payload->transfer = func_081484CC(payload->transfer);
        if (!payload->transfer) {
            resource = func_080DBD30(payload->actor, &first, &second);
            frame = func_080DBD48(payload->actor);
            payload->object = (u8 *)func_08011348(resource, 0, 0, 0,
                payload->x, (s16)(payload->y + 8), 0, (s16)frame, 7, 6);
            func_08011118(payload->object, first);
            func_08011120(payload->object, second);
            func_08011138(payload->object, 1);
            payload->transfer = func_08147D2C(0x170, 16, 20,
                data_03003A60[payload->palette].colors);
            *payload->ready = 1;
            descriptor->phase++;
        }
        break;
    case 0x102:
        payload->transfer = func_081484CC(payload->transfer);
        if (!payload->transfer) {
            payload->resource = func_080D4774(payload->resource);
            if (!payload->resource)
                descriptor->phase++;
        }
        break;
    case 0x103:
        break;
    }
    return 0;
}
