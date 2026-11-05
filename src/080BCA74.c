#include "ffta.h"

typedef struct PoolEntry PoolEntry;
struct PoolEntry {
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s8 priority;
    u8 active;
    u8 unknown_12[2];
    PoolEntry *previous;
    PoolEntry *next;
};

typedef struct {
    PoolEntry entries[16];
    PoolEntry *head;
    u16 cursor;
    s16 delay;
} EntryPool;

static inline s32 findFree(PoolEntry *entry, s32 count)
{
    s32 i;

    for (i = 0; i < count; i++, entry++) {
        if (entry->active == 0 && entry->next == 0 && entry->previous == 0)
            return i;
    }
    return -1;
}

PoolEntry *func_080BCA74(EntryPool *pool)
{
    s16 offset;
    PoolEntry *entry;

    offset = findFree(&pool->entries[pool->cursor], 16 - pool->cursor);
    if (offset >= 0) {
        pool->cursor += offset;
    } else {
        offset = findFree(pool->entries, 16);
        if (offset < 0)
            return 0;
        pool->cursor = offset;
    }
    entry = &pool->entries[pool->cursor];
    pool->cursor++;
    if (pool->cursor > 15)
        pool->cursor = 0;
    return entry;
}
