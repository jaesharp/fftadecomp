#include "ffta.h"

/* 080C7C14..080C7C40: complete 44-byte target, including callback literal.
 * 00b582b0021c906800280bd00091002001900349101c6a4600f074f8019802e0
 * 397e0c08002002b002bc0847
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

typedef struct {
    u32 key;
    TreeNode *node;
} Selection;

extern void func_080C7D18(Tree *, s32 (*)(TreeNode *, void *), void *);
extern s32 func_080C7E38(TreeNode *, void *);

TreeNode *func_080C7C14(Tree *tree, u32 key)
{
    Selection selection;

    if (!tree->root)
        return 0;

    selection.key = key;
    selection.node = 0;
    func_080C7D18(tree, func_080C7E38, &selection);
    return selection.node;
}
