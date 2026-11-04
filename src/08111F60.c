#include "ffta.h"

typedef struct {
    s16 current, remaining, error, step, period, distance;
} InterpolationState;

struct Resource080D5CC0;
struct Struct08011058;
struct ListNode;

typedef struct {
    u16 phase;
    u16 unknown_02;
    Struct08011040 **owner;
} Descriptor;

typedef struct {
    u16 counter;
    u8 unknown_02[4];
    s16 first_index;
    s16 second_index;
    s16 third_index;
    s16 positions[8];
    Struct08011040 **owner;
    Struct08011040 *object;
} Payload;

extern const struct Resource080D5CC0 data_08504C6C;
/* Conditional coordinate ABI: the actual entries discard the upper 16 bits. */
extern u32 func_080D5CC0(const struct Resource080D5CC0 *, u16, s16, s16,
                        u16, u8, u8, u8);
extern void func_08011058(struct Struct08011058 *, s16);
extern void func_080E0608(InterpolationState *, s16, s16, s16);
extern void func_080E064C(InterpolationState *);
extern u8 func_080E0690(InterpolationState *);
extern void func_080107D4(void *, u16, s16, u16);
extern void func_08011428(struct ListNode *);

/* 0x08111F60: complete 364-byte target, including its middle literal pool. */
u32 func_08111F60(void *task, Descriptor *descriptor, Payload *payload)
{
    switch (descriptor->phase) {
    case 0:
        payload->owner = descriptor->owner;
        break;
    case 1:
        break;
    case 0x100: {
        InterpolationState motion;
        u16 x, y, z;
        u8 index;

        func_08011040(*payload->owner, &x, &y, &z);
        payload->object = (Struct08011040 *)func_080D5CC0(
            &data_08504C6C, 0, (s16)x, (s16)y, 0x38F, 6, 1, 0);
        func_08011058((struct Struct08011058 *)payload->object, 1);
        func_080E0608(&motion, (s16)y, -64, 7);
        index = 0;
        payload->positions[index] = motion.current;
        do {
            index++;
            func_080E064C(&motion);
            payload->positions[index] = motion.current;
        } while (!func_080E0690(&motion));
        payload->first_index = 0;
        payload->second_index = -3;
        payload->third_index = -6;
        descriptor->phase++;
        break;
    }
    case 0x101: {
        s16 index;

        payload->first_index++;
        payload->second_index++;
        payload->third_index++;
        payload->counter++;
        if (payload->first_index <= 7)
            func_080107D4(*payload->owner, 120,
                payload->positions[payload->first_index], 0);
        index = payload->second_index;
        if (payload->counter & 1)
            index = payload->third_index;
        if ((u16)index <= 7)
            func_080107D4(payload->object, 120, payload->positions[index], 0);
        if (payload->first_index > 7 && payload->second_index > 7 &&
            payload->third_index > 7) {
            func_08011428((struct ListNode *)*payload->owner);
            *payload->owner = 0;
            func_08011428((struct ListNode *)payload->object);
            payload->object = 0;
            descriptor->phase = 2;
        }
        break;
    }
    }
    return 0;
}
