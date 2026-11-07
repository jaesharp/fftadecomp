#include "ffta.h"

/* Target 080998B0, 28 bytes: 00b582b000920191406903496a462ef02bfa02b001bc004701ac0908 */
typedef struct Tree Tree;
typedef struct Pair Pair;
typedef u32 (*ValueCallback)(u32 value, u32 argument);

typedef struct {
    u8 unknown_00[0x14];
    Tree *tree;
} TreeOwner;

typedef struct {
    u32 argument;
    ValueCallback callback;
} CallbackContext;

extern u32 func_0809AC00(const Pair *source, CallbackContext *context);
extern void func_080C7D18(Tree *tree,
                        u32 (*callback)(const Pair *source, CallbackContext *context),
                        CallbackContext *context);

void func_080998B0(TreeOwner *owner, ValueCallback callback, u32 argument)
{
    CallbackContext context = { argument, callback };

    func_080C7D18(owner->tree, func_0809AC00, &context);
}
