#include "ffta.h"

typedef struct Node080C7B84 Node080C7B84;
struct Node080C7B84 {
    u8 unknown_00[8];
    Node080C7B84 *next;
};

typedef struct {
    u32 unknown_00;
    Node080C7B84 *head;
} List080C7B84;

/* Target [0x080C7B84, 0x080C7B9A), complete 22 bytes:
 * 00b54068002803d001c180680028fbd1002002bc0847
 */
s32 func_080C7B84(List080C7B84 *list, Node080C7B84 **output)
{
    Node080C7B84 *node = list->head;

    while (node != 0) {
        *output++ = node;
        node = node->next;
    }
    return 0;
}
