#include "ffta.h"

/* 080C7E68..080C7E78: 0a6801c24868013048600a6001207047 */
typedef struct Node080C7E68 Node080C7E68;

typedef struct {
    Node080C7E68 **cursor;
    u32 count;
} Cursor080C7E68;

s32 func_080C7E68(Node080C7E68 *node, Cursor080C7E68 *context)
{
    Node080C7E68 **cursor = context->cursor;

    *cursor++ = node;
    context->count++;
    context->cursor = cursor;
    return 1;
}
