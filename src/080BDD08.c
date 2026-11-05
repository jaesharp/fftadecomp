#include "ffta.h"

typedef struct {
    void *context;
    void **entries;
    u8 unknown_08[9];
    u8 count;
    u8 unknown_12[0x4A];
} EntryList;

typedef void (*BufferInitializer)(void *destination, u32 size);
extern BufferInitializer g_callbacks_0836D4B8[];
extern void *func_08022840(u32 size);
extern u32 func_08099CDC(void *context, void **entries);

/* Complete [0x080BDD08, 0x080BDD40): 56 bytes, 22 instructions. */
EntryList *func_080BDD08(void *context)
{
    EntryList *list = func_08022840(0x5C);

    g_callbacks_0836D4B8[0](list, 0x5C);
    list->context = context;
    list->entries = func_08022840(0x34);
    list->count = func_08099CDC(context, list->entries);
    return list;
}
