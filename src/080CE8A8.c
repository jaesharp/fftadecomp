#include "ffta.h"

typedef struct __attribute__((packed)) {
    u16 id : 10;
    u16 flags : 6;
} Descriptor;

typedef struct CategoryNode {
    const Descriptor *descriptor;
    u32 unknown_04;
    const struct CategoryNode *next;
} CategoryNode;

typedef struct {
    u8 unknown_00[0x28C8];
    const CategoryNode *head;
} CategoryState;

extern u8 g_state_02000000[];
extern const u16 g_table_08529EE4[];
extern u8 func_080C9540(u16 bit_index);

static inline u8 contains_category(const CategoryState *state)
{
    const CategoryNode *node;

    if (state->head == 0)
        return 0;
    for (node = state->head; node != 0; node = node->next) {
        if (node->descriptor->id == 0x17F)
            return 1;
    }
    return 0;
}

u16 func_080CE8A8(void)
{
    u32 count = 0;
    u32 index;
    u16 entry;

    for (index = 0; (entry = g_table_08529EE4[index]) != 0xFFFF; index++) {
        if (func_080C9540(entry + 0x2FF))
            count++;
    }
    if (func_080C9540(0x36) ||
        contains_category((const CategoryState *)g_state_02000000))
        count++;
    return count;
}
