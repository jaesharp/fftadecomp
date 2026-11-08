#include "ffta.h"

/* Target: 080FDE58, complete 66-byte Thumb function. */
struct Object;
struct Task;
struct TaskData;

struct Request {
    u16 state;
    u16 unknown_02;
    struct Object *object;
    u8 *result;
    u8 unknown_0c[8];
    u16 mode;
    u16 direction;
    u32 unknown_18;
};

extern u8 func_080D3B54(struct Object *object);
extern int func_080FDB98(struct Task *, struct Request *, struct TaskData *);
extern struct Task *func_08005B6C(
    int (*callback)(struct Task *, struct Request *, struct TaskData *),
    u16 kind, const struct Request *request, struct Task *parent);

struct Task *func_080FDE58(struct Object *object, u8 mode, u8 direction,
    u8 *result, struct Task *parent)
{
    struct Request request;

    if (func_080D3B54(object))
        return 0;

    request.mode = mode;
    request.direction = direction;
    request.object = object;
    request.result = result;
    return func_08005B6C(func_080FDB98, 0x54, &request, parent);
}
