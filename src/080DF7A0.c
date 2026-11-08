#include "ffta.h"

/* 080DF7A0: complete 88-byte owner, including four referenced literals. */
typedef struct Task0DF7A0 Task0DF7A0;

typedef struct Payload0DF7A0 {
    u32 value;
    unsigned first : 8;
    unsigned second : 8;
    unsigned third : 8;
    unsigned unknown_07 : 8;
} Payload0DF7A0;

typedef struct Request0DF7A0 {
    u16 event;
    u16 unknown_02;
    const Payload0DF7A0 *payload;
    u8 unknown_08[12];
    u16 delay;
    u8 unknown_16[6];
} Request0DF7A0;

u32 func_080DEBAC(Task0DF7A0 *task, Request0DF7A0 *request, void *state);
Task0DF7A0 *func_08005B6C(
    u32 (*callback)(Task0DF7A0 *, Request0DF7A0 *, void *),
    u16 size, const Request0DF7A0 *request, Task0DF7A0 *parent);

Task0DF7A0 *func_080DF7A0(u32 value, u8 first, u8 second, u8 third,
                        u16 delay, Task0DF7A0 *parent)
{
    Request0DF7A0 request;
    Payload0DF7A0 payload;

    payload.value = value;
    payload.first = first;
    payload.second = second;
    payload.third = third;
    request.payload = &payload;
    request.delay = delay;
    return func_08005B6C(func_080DEBAC, 16, &request, parent);
}
