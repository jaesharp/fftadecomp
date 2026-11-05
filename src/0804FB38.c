#include "ffta.h"

typedef struct {
    u8 unknown_00[0x424];
    const u8 *entries[0];
} MenuData;

typedef struct {
    const MenuData *data;
} MenuContext;

typedef struct {
    u8 unknown_00[2];
    u8 category;
    u8 unknown_03[13];
} ItemCategory;

extern const ItemCategory g_table_08521214[];
extern u8 func_080CB99C(u16 id);

/* Complete [0x0804FB38, 0x0804FB84): 76 bytes, 31 reached instructions. */
u32 func_0804FB38(const MenuContext *context, u32 index)
{
    const u8 *item = context->data->entries[index];
    const ItemCategory *category;
    u16 id;

    if (item == 0)
        return 0;
    category = &g_table_08521214[*item];
    id = category->category ? 0x18A + category->category : 0;
    return func_080CB99C(id) + 13;
}
