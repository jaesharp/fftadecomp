#include "ffta.h"

typedef struct ListNode08099840 ListNode08099840;
typedef struct ListContext08099840 ListContext08099840;
typedef u32 (*ValueCallback08099840)(void *, void *);
typedef u32 (*ListCallback08099840)(ListNode08099840 *, void *);

typedef struct {
    u8 unknown_00[0x10];
    ListContext08099840 *list;
} Owner08099840;

typedef struct {
    void *argument;
    ValueCallback08099840 callback;
} CallbackContext08099840;

extern u32 func_0809ABE8(ListNode08099840 *, void *);
extern void func_080C7CC0(ListContext08099840 *, ListCallback08099840, void *);

/* Conditional ordinary callback transport follows the complete actual helper
 * entries and immutable adapter definition, without memory or effect claims. */
/* Complete [0x08099840, 0x0809985C): 28 bytes including final literal. */
void func_08099840(Owner08099840 *owner, ValueCallback08099840 callback,
                   void *argument)
{
    CallbackContext08099840 context;

    context.argument = argument;
    context.callback = callback;
    func_080C7CC0(owner->list, func_0809ABE8, &context);
}
