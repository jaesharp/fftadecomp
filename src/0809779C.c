#include "ffta.h"

typedef struct {
    u8 unknown_00[0x28];
    u16 flags;
    u8 unknown_2A[0xCC];
    u8 x;
    u8 y;
} FlaggedObject;

typedef struct {
    FlaggedObject *object;
} Node;

typedef struct {
    void *context;
    Node *other;
} Context;

extern u8 func_080C8280(const void *object);
extern s32 func_080CA3EC(const void *object);
extern u8 func_080C8298(const FlaggedObject *object);
extern u8 func_080C8240(void *object);
extern void func_081491C0(void *, s16, s16, u32, u32, u32, u32, u32);

/* Complete 0x0809779C..0x08097812: 118 bytes. */
s32 func_0809779C(Node *node, Context *context)
{
    Node *other = context->other;

    if (other == node)
        return 1;
    if (func_080C8280(node->object))
        return 1;
    if ((u32)func_080CA3EC(node->object) / 10 != 0) {
        if (func_080C8298(other->object))
            return 1;
        if (func_080C8240(node->object) == func_080C8240(other->object))
            return 1;
    }
    func_081491C0(context->context, node->object->x, node->object->y,
                  0, 0, 1, 0, 0);
    return 1;
}
