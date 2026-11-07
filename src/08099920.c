#include "ffta.h"

/* Complete target: 0x08099920..0x0809993C, 28 bytes. */
typedef struct TreeNode TreeNode;
typedef struct TreeContext TreeContext;
typedef u32 (*NodeCallback08099920)(u32 value, u32 argument);

typedef struct {
    u32 argument;
    NodeCallback08099920 callback;
} CallbackContext08099920;

typedef struct {
    u8 unknown_00[0x18];
    TreeContext *tree;
} Owner08099920;

extern u32 func_0809AC00(TreeNode *, CallbackContext08099920 *);
extern void func_080C7D70(TreeContext *,
    u32 (*callback)(TreeNode *, CallbackContext08099920 *),
    CallbackContext08099920 *);

/* The callback context is the observed argument/function-pointer pair.
 * Ordinary call transport remains conditional on the supplied actual entries.
 */
void func_08099920(Owner08099920 *owner, NodeCallback08099920 callback,
                   u32 argument)
{
    CallbackContext08099920 context;

    context.argument = argument;
    context.callback = callback;
    func_080C7D70(owner->tree, func_0809AC00, &context);
}
