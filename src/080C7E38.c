#include "ffta.h"

/* 080C7E38..080C7E68: complete 48-byte target.
 * 30b582b0051c0c1c01204042009001aa281c6946fff794fe21680098814201d0
 * 012001e06560002002b030bc02bc0847
 */
typedef struct {
    u32 first;
    u32 second;
} Pair;

typedef struct TreeNode TreeNode;
struct TreeNode {
    Pair pair;
    TreeNode *parent;
    TreeNode *child;
    TreeNode *next;
};

typedef struct {
    u32 key;
    TreeNode *node;
} Selection;

extern void func_080C7B78(const Pair *source, u32 *second, u32 *first);

s32 func_080C7E38(TreeNode *node, void *context)
{
    Selection *selection = context;
    u32 second = (u32)-1;
    u32 first;
    s32 result;

    func_080C7B78(&node->pair, &second, &first);
    if (selection->key != second) {
        result = 1;
    } else {
        selection->node = node;
        result = 0;
    }
    return result;
}
