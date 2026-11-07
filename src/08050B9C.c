#include "ffta.h"

typedef struct MenuEntry {
    u16 unknown_00;
    u16 value;
} MenuEntry;

typedef struct MenuData {
    u8 unknown_00[0x424];
    const MenuEntry *entries[0];
} MenuData;

typedef struct MenuState {
    MenuData *data;
    u8 unknown_04[4];
    u8 kind;
    u8 unknown_09[0x3F];
    u8 menu;
} MenuState;

extern u16 func_08017B68(void *menu, s8 index);
extern void func_08017AF4(void *menu, s8 index, u32 action);

/* 08050B9C..08050BF0: 84 bytes, 38 instructions. */
void func_08050B9C(MenuState *state, u8 index, u8 skip_empty)
{
    u32 action = 11;

    if (state->kind == 4) {
        u32 identifier = func_08017B68(&state->menu, index);
        const MenuEntry *entry = state->data->entries[identifier];

        if (entry->value)
            action = 10;
        else if (skip_empty)
            return;
    }
    func_08017AF4(&state->menu, index, action);
}
