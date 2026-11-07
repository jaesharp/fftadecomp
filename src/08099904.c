/* 0x08099904, 28 bytes. Visit the tree with a callback and its argument. */
#include "ffta.h"

typedef struct {
    u32 first;
    u32 second;
} Pair08099904;

typedef u32 (*Callback08099904)(u32 value, u32 argument);

typedef struct {
    u32 argument;
    Callback08099904 callback;
} VisitContext08099904;

typedef struct TreeContext08099904 TreeContext08099904;

typedef struct {
    u8 unknown_00[0x14];
    TreeContext08099904 *tree;
} Owner08099904;

extern u32 func_0809AC00(const Pair08099904 *source,
                        VisitContext08099904 *context);
extern void func_080C7D70(TreeContext08099904 *tree,
                        u32 (*visit)(const Pair08099904 *,
                                     VisitContext08099904 *),
                        VisitContext08099904 *context);

void func_08099904(Owner08099904 *owner, Callback08099904 callback,
                   u32 argument)
{
    VisitContext08099904 context = { argument, callback };

    func_080C7D70(owner->tree, func_0809AC00, &context);
}
