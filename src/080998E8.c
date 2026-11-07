#include "ffta.h"

typedef struct {
    u32 first;
    u32 second;
} Pair080998E8;

typedef u32 (*Callback080998E8)(u32 value, u32 argument);

typedef struct {
    u32 argument;
    Callback080998E8 callback;
} CallbackRequest080998E8;

typedef struct Tree080998E8 Tree080998E8;

typedef struct {
    u8 unknown_00[0x10];
    Tree080998E8 *tree;
} Owner080998E8;

extern u32 func_0809AC00(const Pair080998E8 *, CallbackRequest080998E8 *);
extern void func_080C7D70(Tree080998E8 *,
                         u32 (*)(const Pair080998E8 *, CallbackRequest080998E8 *),
                         CallbackRequest080998E8 *);

/* Complete [0x080998E8, 0x08099904): 28 bytes. */
void func_080998E8(Owner080998E8 *owner, Callback080998E8 callback, u32 argument)
{
    CallbackRequest080998E8 request;

    request.argument = argument;
    request.callback = callback;
    func_080C7D70(owner->tree, func_0809AC00, &request);
}
