/* Complete target: [0x08099580, 0x080995A0), 32 bytes. */
#include "ffta.h"

typedef struct {
    u8 unknown_00[0x18];
    void *list;
} Object99580;

typedef struct {
    u32 key;
    u32 unknown_04;
    void *result;
} Search99580;

u32 func_0809AB5C(void *node, Search99580 *context);
void func_080C7CC0(void *list, u32 (*callback)(void *, Search99580 *),
                   Search99580 *context);

void *func_08099580(const Object99580 *object, u32 key)
{
    Search99580 context;

    context.key = key;
    context.result = 0;
    func_080C7CC0(object->list, func_0809AB5C, &context);
    return context.result;
}
