#include "ffta.h"

/* 0x08099644..0x0809966C: complete 40-byte owner. */
typedef struct PositionedObject08099644 PositionedObject08099644;
typedef struct ListContext08099644 ListContext08099644;

typedef struct {
    void *value;
} ValueObject08099644;

typedef struct {
    u8 unknown_00[4];
    s8 x;
    s8 z;
    u8 unknown_06[2];
    PositionedObject08099644 *match;
} SearchContext08099644;

typedef struct {
    u8 unknown_00[16];
    ListContext08099644 *list;
} SearchOwner08099644;

typedef s32 (*SearchCallback08099644)(const ValueObject08099644 *,
                                    SearchContext08099644 *);

extern s32 func_0809ABB0(const ValueObject08099644 *, SearchContext08099644 *);
/* Conditional ordinary call view, supported by complete incoming transport. */
extern void func_080C7CC0(ListContext08099644 *, SearchCallback08099644,
                          SearchContext08099644 *);

PositionedObject08099644 *func_08099644(SearchOwner08099644 *owner, s8 x, s8 z)
{
    SearchContext08099644 context;

    context.match = 0;
    context.x = x;
    context.z = z;
    func_080C7CC0(owner->list, func_0809ABB0, &context);
    return context.match;
}
