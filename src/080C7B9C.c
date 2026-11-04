#include "ffta.h"

/* 080C7B9C..080C7BC8: 44 bytes, including the callback literal.
 * 00b582b0021c906800280bd00091002001900349101c6a4600f0b0f8019802e0
 * 697e0c08002002b002bc0847
 */
typedef struct TreeNode TreeNode;
struct TreeNode {
    u8 unknown_00[8];
    TreeNode *parent;
    TreeNode *child;
    TreeNode *next;
};

typedef struct {
    u8 unknown_00[8];
    TreeNode *root;
} Tree;

typedef struct Node080C7E68 Node080C7E68;

typedef struct {
    Node080C7E68 **cursor;
    u32 count;
} Cursor080C7E68;

extern void func_080C7D18(Tree *, s32 (*)(TreeNode *, void *), void *);
extern s32 func_080C7E68(Node080C7E68 *, Cursor080C7E68 *);

u32 func_080C7B9C(Tree *tree, Node080C7E68 **cursor)
{
    Cursor080C7E68 context;

    if (!tree->root)
        return 0;

    context.cursor = cursor;
    context.count = 0;
    func_080C7D18(tree, (s32 (*)(TreeNode *, void *))func_080C7E68,
                  &context);
    return context.count;
}
