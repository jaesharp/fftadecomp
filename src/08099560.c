#include "ffta.h"

typedef struct ListNode ListNode;
typedef struct ListContext ListContext;

typedef struct Object {
    u32 key;
} Object;

typedef struct Search {
    u32 key;
    u32 unknown_04;
    Object *result;
} Search;

typedef struct Owner {
    u8 unknown_00[0x10];
    ListContext *context;
} Owner;

typedef s32 (*SearchCallback)(const ListNode *node, Search *search);
extern s32 func_0809AB5C(const ListNode *node, Search *search);
extern void func_080C7CC0(ListContext *context, SearchCallback callback, Search *search);

/* Complete [0x08099560, 0x08099580): 32 bytes. */
Object *func_08099560(Owner *owner, u32 key)
{
    Search search;
    search.key = key;
    search.result = 0;
    func_080C7CC0(owner->context, func_0809AB5C, &search);
    return search.result;
}
