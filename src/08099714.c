#include "ffta.h"

typedef struct Item08099714 {
    void *key;
    u8 unknown_04[0x20];
    s32 priority;
} Item08099714;

typedef struct Manager08099714 {
    u8 unknown_00[0x18];
    void *list;
} Manager08099714;

typedef struct Search08099714 {
    void *key;
    u32 unknown_04;
    Item08099714 *found;
} Search08099714;

extern s32 func_0809AB5C(void *node, Search08099714 *search);
extern void func_080C7CC0(void *list,
                        s32 (*callback)(void *, Search08099714 *),
                        Search08099714 *search);
extern Item08099714 *func_0809716C(Manager08099714 *manager, void *key);
extern void *func_080C7A74(void *list, Item08099714 *item);
extern void *func_080C7AB4(void *list, Item08099714 *item, s32 priority);

/* Complete indexed owner: 0x08099714..0x0809975C (72 bytes). */
Item08099714 *func_08099714(Manager08099714 *manager, void *key)
{
    Search08099714 search;
    Item08099714 *item;

    search.key = key;
    search.found = 0;
    func_080C7CC0(manager->list, func_0809AB5C, &search);
    item = search.found;
    if (item == 0) {
        item = func_0809716C(manager, key);
        func_080C7A74(manager->list, item);
        func_080C7AB4(manager->list, item, item->priority);
    }
    return item;
}
