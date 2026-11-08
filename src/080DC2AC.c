#include "ffta.h"

struct Task;

struct Payload080DC2AC {
    void *object;
    u8 state;
    u8 phase;
    u8 kind;
    u8 flags;
    u32 unknown_08;
    u32 first;
    u32 second;
};

struct Descriptor080DC2AC {
    u16 phase;
    u16 unknown_02;
    const struct Payload080DC2AC *payload;
    u32 unknown_08[3];
    u16 first;
    u16 second;
    u32 unknown_18;
};

extern s32 func_080DB540(struct Task *, struct Descriptor080DC2AC *, void *);
extern struct Task *func_08005B6C(
    s32 (*)(struct Task *, struct Descriptor080DC2AC *, void *),
    u16, struct Descriptor080DC2AC *, struct Task *);

struct Task *func_080DC2AC(void *object, u32 first, u32 second,
                         u8 a, u8 b, struct Task *parent)
{
    struct Descriptor080DC2AC descriptor;
    struct Payload080DC2AC payload;

    payload.object = object;
    payload.state = 0;
    payload.phase = 0;
    payload.kind = 9;
    payload.first = first;
    payload.second = second;
    payload.flags = 0;
    descriptor.first = a;
    descriptor.second = b;
    descriptor.payload = &payload;
    return func_08005B6C(func_080DB540, 0x2C, &descriptor, parent);
}
