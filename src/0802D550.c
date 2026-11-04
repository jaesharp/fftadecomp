#include "ffta.h"

typedef struct {
    u16 state;
    u16 unknown_02;
    s16 x;
    s16 y;
    u32 unknown_08;
    void *object;
    u16 flags;
    u8 mode;
} Owner0802D550;

typedef struct {
    u16 state;
    u16 unknown_02;
    void *object;
    u8 unknown_08[0xC];
    u16 flags;
} Descriptor0802D550;

typedef struct {
    void *manager;
    void *allocation;
    void *first_task;
    void *second_task;
} TaskContext0802D550;

typedef struct {
    u16 held;
    u16 unknown_02;
} Input0802D550;

extern TaskContext0802D550 *data_0200F440;
extern Input0802D550 data_03000000;
extern u8 g_state_020020D0[];
extern void func_0802D520(Owner0802D550 *owner);
extern void func_0802C168(Owner0802D550 *owner);
extern void func_0802C270(Owner0802D550 *owner);
extern void func_0802C398(Owner0802D550 *owner);
extern void func_08141520(u16 value);
extern u32 func_08005C04(void *task, void *descriptor);

/* Complete target: 0x0802D550..0x0802D704, 436 bytes. */
u32 func_0802D550(void *task, Descriptor0802D550 *descriptor,
                   Owner0802D550 *owner)
{
    switch (descriptor->state) {
    case 1:
        if (data_0200F440)
            data_0200F440->second_task = 0;
        break;
    case 0:
        owner->mode = 1;
        owner->object = descriptor->object;
        owner->flags = descriptor->flags;
        func_0802D520(owner);
        break;
    case 0x10D:
        descriptor->state = 0x100;
        break;
    case 0x100:
        func_0802C168(owner);
        owner->state = 0x101;
        descriptor->state = 0x10B;
        break;
    case 0x10A:
        owner->object = descriptor->object;
        owner->flags = descriptor->flags;
        func_0802C168(owner);
        owner->state = 0x102;
        {
            u16 x = owner->flags & 0x40;
            if (x)
                x = 160;
            owner->x = x;
        }
        owner->mode = 2;
        break;
    case 0x10B:
        func_0802C270(owner);
        func_0802C398(owner);
        descriptor->state = owner->state;
        break;
    case 0x101:
        {
            s32 complete = 0;
            if (owner->flags & 0x40) {
                owner->x -= 12;
                if (owner->x <= 160) {
                    owner->x = 160;
                    complete = 1;
                }
            } else {
                owner->x += 12;
                if (owner->x >= 0) {
                    owner->x = 0;
                    complete = 1;
                }
            }
            func_0802C398(owner);
            if (complete) {
                owner->mode = 2;
                descriptor->state = 0x102;
            }
        }
        break;
    case 0x102:
        if (!(owner->flags & 0x10) && (data_03000000.unknown_02 & 4)) {
            func_08141520(156);
            g_state_020020D0[0xB5] ^= 1;
            descriptor->state = 0x10A;
            descriptor->object = owner->object;
            descriptor->flags = owner->flags;
            func_08005C04(task, descriptor);
            descriptor->state = 0x10B;
        }
        func_0802C398(owner);
        break;
    case 0x103:
        descriptor->state = 0x105;
        if (owner->flags & 0x40)
            owner->x = 204;
        else
            owner->x = -44;
        if (owner->mode != 3) {
            owner->mode = 3;
            func_0802C398(owner);
        }
        break;
    }
    return 0;
}
