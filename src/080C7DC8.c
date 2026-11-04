#include "ffta.h"

/* Target [0x080C7DC8, 0x080C7DEA), 34 bytes:
 * 30 b5 05 1c 0c 1c 00 2c 08 d0 a1 68 00 29 01 d0
 * ff f7 f6 ff 28 1c 21 1c 3f f7 c6 f9 30 bc 01 bc 00 47
 */
typedef struct Node080C7DC8 {
    u8 unknown_00[8];
    struct Node080C7DC8 *next;
} Node080C7DC8;

void func_08007170(void *owner, u8 *object);

void func_080C7DC8(void *owner, Node080C7DC8 *node)
{
    if (node) {
        if (node->next)
            func_080C7DC8(owner, node->next);
        func_08007170(owner, (u8 *)node);
    }
}
