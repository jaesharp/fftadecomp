#include "ffta.h"

typedef struct Collection Collection;
typedef struct ListNode ListNode;
typedef u32 (*ValueCallback)(void *value, void *argument);

typedef struct {
    u8 unknown_00[0x14];
    Collection *collection;
} Owner;

typedef struct {
    void *argument;
    ValueCallback callback;
} CallbackContext;

extern u32 func_0809ABE8(ListNode *node, void *payload);
extern void func_080C7CC0(Collection *collection,
                          u32 (*callback)(ListNode *node, void *payload),
                          void *payload);

/* Complete [0x0809985C, 0x08099878): 28 bytes including callback literal. */
void func_0809985C(Owner *owner, ValueCallback callback, void *argument)
{
    CallbackContext context;

    context.argument = argument;
    context.callback = callback;
    func_080C7CC0(owner->collection, func_0809ABE8, &context);
}
