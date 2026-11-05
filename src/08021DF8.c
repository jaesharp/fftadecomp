#include "ffta.h"

typedef struct ListNode08021DF8 ListNode08021DF8;
typedef struct ListContext08021DF8 ListContext08021DF8;
typedef u32 (*ListCallback08021DF8)(ListNode08021DF8 *node, void *payload);

typedef struct {
    u32 unknown_00;
    ListContext08021DF8 *children;
} ListObject08021DF8;

typedef struct {
    u16 clear;
    u16 set;
} FlagMasks08021DF8;

extern u32 func_08022148(ListNode08021DF8 *node, void *payload);
extern void func_080C7CC0(ListContext08021DF8 *context,
                        ListCallback08021DF8 callback, void *payload);

/* Complete target: [0x08021DF8, 0x08021E28), 48 bytes. */
void func_08021DF8(ListObject08021DF8 *object, u16 clear, u16 set)
{
    if (object != 0) {
        FlagMasks08021DF8 masks = { clear, set };

        if (object->children != 0)
            func_080C7CC0(object->children, func_08022148, &masks);
    }
}
