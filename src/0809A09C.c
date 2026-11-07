#include "ffta.h"

typedef struct {
    u8 unknown_00[0x40];
    void *owner;
    u8 unknown_44[8];
    void *entries[2];
} EntrySlots;

extern void func_08021BD4(void *owner, void *entry);

/* 0x0809A09C: 42 bytes. */
void func_0809A09C(EntrySlots *slots)
{
    s32 i;

    for (i = 0; i < 2; ++i) {
        if (slots->entries[i] != 0) {
            func_08021BD4(slots->owner, slots->entries[i]);
            slots->entries[i] = 0;
        }
    }
}
