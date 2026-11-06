#include "ffta.h"

/* 0809961C, complete target: 40 bytes. */
typedef struct PositionedObject0809961C PositionedObject0809961C;
typedef struct ListContext0809961C ListContext0809961C;

typedef struct ValueObject0809961C {
    void *value;
} ValueObject0809961C;

typedef struct SearchContext0809961C {
    u8 unknown_00[4];
    s8 x;
    s8 z;
    u8 unknown_06[2];
    PositionedObject0809961C *match;
} SearchContext0809961C;

typedef struct SearchOwner0809961C {
    u8 unknown_00[16];
    ListContext0809961C *list;
} SearchOwner0809961C;

typedef s32 (*SearchCallback0809961C)(const ValueObject0809961C *object,
                                     SearchContext0809961C *context);

s32 func_0809AB7C(const ValueObject0809961C *object,
                 SearchContext0809961C *context);
void func_080C7CC0(ListContext0809961C *list, SearchCallback0809961C callback,
                  SearchContext0809961C *context);

PositionedObject0809961C *func_0809961C(SearchOwner0809961C *owner, s8 x, s8 z)
{
    SearchContext0809961C context;

    context.match = 0;
    context.x = x;
    context.z = z;
    func_080C7CC0(owner->list, func_0809AB7C, &context);
    return context.match;
}
