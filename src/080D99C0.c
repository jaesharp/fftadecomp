#include "ffta.h"

struct Task;

struct TransferConfiguration {
    u32 first;
    u32 second;
    u16 values[5];
};

struct TransferRequest {
    u16 phase;
    u16 unknown02;
    const struct TransferConfiguration *configuration;
    u32 unknown08[3];
    s16 channel;
    u16 unknown16;
    u32 unknown18;
};

struct TransferInitialization {
    struct TransferRequest request;
    struct TransferConfiguration configuration;
};

extern s32 func_080D963C(struct Task *, struct TransferRequest *, void *);
extern struct Task *func_08005B6C(s32 (*)(struct Task *, struct TransferRequest *, void *),
                                u16, struct TransferRequest *, struct Task *);

struct Task *func_080D99C0(u8 channel, u32 first, u32 second,
                         u16 value0, u16 value1, u16 value2,
                         u16 value3, u16 value4, struct Task *parent)
{
    struct TransferInitialization initialization;
    struct TransferConfiguration *configuration = &initialization.configuration;

    configuration->first = first;
    configuration->second = second;
    configuration->values[0] = value0;
    configuration->values[1] = value1;
    configuration->values[2] = value2;
    configuration->values[3] = value3;
    configuration->values[4] = value4;
    initialization.request.channel = channel;
    initialization.request.configuration = configuration;
    return func_08005B6C(func_080D963C, 8, &initialization.request, parent);
}
