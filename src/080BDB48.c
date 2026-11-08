#include "ffta.h"

typedef struct Node080BDB48 {
    u32 unknown_00;
    struct Node080BDB48 *next;
} Node080BDB48;

/* Complete [0x080BDB48, 0x080BDB5E): 22 bytes. */
u32 func_080BDB48(Node080BDB48 *node)
{
    u32 count = 0;

    while (node != 0) {
        count++;
        node = node->next;
    }
    return count;
}
