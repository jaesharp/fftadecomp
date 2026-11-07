/* Target: 28 bytes at 080998CC. */
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Tree Tree;
typedef struct Node Node;
typedef int (*VisitFunction)(u32, u32);

typedef struct {
    u8 unknown_00[24];
    Tree *tree;
} Owner;

typedef struct {
    VisitFunction visit;
    u32 argument;
} VisitContext;

extern int func_0809AC00(Node *, const VisitContext *);
extern void func_080C7D18(Tree *, int (*)(Node *, const VisitContext *),
                          const VisitContext *);

void func_080998CC(Owner *owner, u32 argument, VisitFunction visit)
{
    VisitContext context;

    context.visit = visit;
    context.argument = argument;
    func_080C7D18(owner->tree, func_0809AC00, &context);
}
