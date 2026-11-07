#include "ffta.h"

typedef struct {
    u8 unknown_00[0x0A];
    u8 field_0a;
    u8 unknown_0b;
    u16 value_0c;
} Owner080665B0;

typedef struct {
    u32 unknown_00;
    void *owner;
    u16 x;
    u16 y;
    u16 field_0c;
    u16 extent;
    u8 flags;
    u8 unknown_11;
    u8 field_12;
} Record080665B0;

typedef struct {
    u8 unknown_00[9];
    u8 flags;
} TaskData080665B0;

typedef struct {
    Owner080665B0 *owner;
    u8 unknown_04[4];
    u8 mode;
    u8 unknown_09[7];
    void *task;
    u8 unknown_14[0x5C];
    Record080665B0 first;
    Record080665B0 second;
} State080665B0;

extern u8 data_030008B0[];
extern u8 data_03000990[];

extern void func_08013390(u32 value);
extern void func_08019A8C(void *context, u16 value, void *first, void *second);
extern void func_08013434(void);
extern void func_080615B0(void);
extern void func_080615C8(void);
extern void *func_08005BFC(void *task);
extern void func_08017D18(Record080665B0 *record, u8 mask);

/* Complete target [0x080665B0, 0x08066692): 226 bytes. */
void func_080665B0(State080665B0 *state)
{
    Record080665B0 *first = &state->first;
    Record080665B0 *second = &state->second;

    func_08013390((u32)((u8 *)state->owner + 0xBB0));
    func_08019A8C((u8 *)state->owner + 0xBB0, state->owner->value_0c,
                  data_030008B0, data_03000990);

    switch (state->mode) {
    case 1:
    case 2:
        func_08013434();
        break;
    case 5:
    case 6:
        func_080615B0();
        break;
    case 4:
        if (((TaskData080665B0 *)func_08005BFC(state->task))->flags & 1)
            func_080615C8();
        else
            func_080615B0();
        break;
    }

    state->owner->field_0a = first->flags;
    if (first->y + first->extent <= 0x40)
        func_08017D18(first, 0);
    else
        func_08017D18(first, 1);

    if (second != 0) {
        if (second->x <= 0xE0 && second->y <= 0x40)
            second->flags &= ~4;
        second->flags |= 0x40;
    }

    if (state->mode == 4)
        ((TaskData080665B0 *)func_08005BFC(state->task))->flags |= 8;
}
