#include "ffta.h"

/* Target 08099878, 28 bytes: 00b582b000920191806903496a462ef01bfa02b001bc0047e9ab0908 */
typedef struct ListNode ListNode;
typedef struct ListContext ListContext;
typedef u32 (*ValueCallback)(void *value, void *argument);

typedef struct {
    u8 unknown_00[0x18];
    ListContext *collection;
} CollectionOwner;

typedef struct {
    void *argument;
    ValueCallback callback;
} CallbackContext;

extern u32 func_0809ABE8(ListNode *node, void *payload);
extern void func_080C7CC0(ListContext *collection,
                        u32 (*callback)(ListNode *node, void *payload),
                        void *payload);

void func_08099878(CollectionOwner *owner, ValueCallback callback, void *argument)
{
    CallbackContext context = { argument, callback };

    func_080C7CC0(owner->collection, func_0809ABE8, &context);
}
