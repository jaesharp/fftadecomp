#include "ffta.h"

typedef struct Node0800C268 {
    u8 group;
    u8 active;
    u8 unknown_02[0x1E];
    struct Node0800C268 *previous;
    struct Node0800C268 *next;
} Node0800C268;

typedef struct {
    u8 unknown_00[0x24];
    Node0800C268 *head;
} Group0800C268;

extern Group0800C268 g_records_02009000[];
extern void *data_02008FF8;
extern void func_08007170(void *owner, u8 *object);

static inline s32 is_active(Node0800C268 *node)
{
    return node->active == 1;
}

/* Complete 0800C268..0800C2C0, 88 bytes. Target:
30b5011c002923d000224878012800d10122002a1cd00d1c0c6a4b6a002c01d0636207e0084a097888004018c000243280180360002b00d01c6204480068291cfaf762ff002004e000900002f88f0002081c30bc02bc0847 */
void *func_0800C268(void *object)
{
    if (object != 0 && is_active((Node0800C268 *)object)) {
        Node0800C268 *node = object;
        Node0800C268 *previous = node->previous;
        Node0800C268 *next = node->next;

        if (previous != 0)
            previous->next = next;
        else
            g_records_02009000[node->group].head = next;
        if (next != 0)
            next->previous = previous;
        func_08007170(data_02008FF8, (u8 *)node);
        return 0;
    }
    return object;
}
