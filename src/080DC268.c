#include "ffta.h"

struct Task;

struct Configuration080DC268 {
    void *object;
    u8 phase;
    u8 step;
    u8 mode;
    u8 flags;
    u32 unknown08;
    const void *first;
    const void *second;
};

struct Request080DC268 {
    u16 phase;
    u16 unknown02;
    const struct Configuration080DC268 *configuration;
    u32 unknown08[3];
    u16 behavior;
    u16 duration;
    u32 unknown18;
};

extern s32 func_080DB540(struct Task *, struct Request080DC268 *, void *);
extern struct Task *func_08005B6C(s32 (*)(struct Task *, struct Request080DC268 *, void *),
                                u16, struct Request080DC268 *, struct Task *);

struct Task *func_080DC268(void *object, const void *first, const void *second,
                         u8 behavior, struct Task *parent)
{
    struct Request080DC268 request;
    struct Configuration080DC268 configuration;

    configuration.object = object;
    configuration.phase = 0;
    configuration.step = 0;
    configuration.mode = 9;
    configuration.first = first;
    configuration.second = second;
    configuration.flags = 0;
    request.behavior = behavior;
    request.duration = 3;
    request.configuration = &configuration;
    return func_08005B6C(func_080DB540, 0x2c, &request, parent);
}
