#include "ffta.h"

typedef struct {
    u32 key;
    u32 unknown_04;
    void *result;
} SearchContext;

typedef struct {
    u8 unknown_00[0x14];
    void *list;
} SearchOwner;

s32 func_0809AB5C(void *node, SearchContext *context);
void func_080C7CC0(void *list, s32 (*callback)(void *, SearchContext *),
                   SearchContext *context);

void *func_080995A0(SearchOwner *owner, u32 key)
{
    SearchContext context;

    context.key = key;
    context.result = 0;
    func_080C7CC0(owner->list, func_0809AB5C, &context);
    return context.result;
}
