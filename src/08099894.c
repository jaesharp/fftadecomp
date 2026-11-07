#include "ffta.h"

typedef struct Tree Tree;
typedef u32 (*ValueCallback)(u32 value, u32 argument);

typedef struct {
    u32 first;
    u32 second;
} Pair;

typedef struct {
    u8 unknown_00[0x10];
    Tree *tree;
} Owner;

typedef struct {
    u32 argument;
    ValueCallback callback;
} CallbackContext;

extern u32 func_0809AC00(const Pair *node, CallbackContext *context);
extern void func_080C7D18(Tree *tree,
                          u32 (*callback)(const Pair *node, CallbackContext *context),
                          CallbackContext *context);

/* Complete [0x08099894, 0x080998B0): 28 bytes including callback literal. */
void func_08099894(Owner *owner, ValueCallback callback, u32 argument)
{
    CallbackContext context;

    context.argument = argument;
    context.callback = callback;
    func_080C7D18(owner->tree, func_0809AC00, &context);
}
