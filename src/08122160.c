#include "script_entry.h"

typedef struct {
    u16 first;
    u16 second;
    u16 timer;
    u8 ready;
    u8 filter;
    void *context;
    void *object;
} CommandState08122160;

typedef struct {
    u8 unknown_00[4];
    u8 active;
    u8 unknown_05[0x103];
} CharacterState08122160;

typedef struct {
    u8 mode;
    u8 active;
    u8 unknown_02[0x92];
    u16 flags;
    u16 selection;
} ScriptState08122160;

typedef struct {
    u8 unknown_0000[0x2C78];
    CharacterState08122160 *character;
    u8 unknown_2C7C[0xEA0];
    u8 character_data[0x108];
    u32 flags;
    u16 count;
    u8 index;
} GlobalState08122160;

extern ScriptState08122160 g_state_0200F390;
extern GlobalState08122160 g_state_02000000;
extern void *data_030027F4;
extern void func_081253CC(void);
extern void func_081258AC(void);
extern void func_081256C8(void);
extern CharacterState08122160 *func_0803600C(void);
extern u32 func_080D241C(u16 selector, void *destination);
extern void func_080C9574(u16 bit_index, u16 enabled);
extern void func_08022E90(u16 duration, u8 mode);

/* Complete [0x08122160, 0x0812237A): 538 bytes, 190 instructions. */
u32 func_08122160(CommandState08122160 *state)
{
    switch (state->ready) {
    case 1:
        func_081253CC();
        state->ready = 2;
        break;
    case 2:
        if (!(g_state_0200F390.flags & 2)) {
            func_081258AC();
            return 0x100;
        }
        break;
    case 3:
    {
        ScriptState08122160 *script;

        func_081256C8();
        script = &g_state_0200F390;
        script->flags &= ~0x80;
        script->flags &= ~1;
        script->flags |= 8;
        if (g_state_02000000.count == 0)
            script->flags |= 0x10;
        script->selection = 1;
        state->ready = 4;
        break;
    }
    case 5:
    {
        ScriptState08122160 *script;
        u32 offset;
        const ScriptEntry *entry;

        func_081256C8();
        script = &g_state_0200F390;
        script->flags &= ~0x80;
        script->flags &= ~1;
        script->flags |= 8;
        if (g_state_02000000.count == 0)
            script->flags |= 0x10;
        offset = g_state_02000000.index * sizeof(ScriptEntry);
        entry = (const ScriptEntry *)((const u8 *)g_table_08563A70 + offset);
        if (entry->unknown_07 != 0 || (g_state_02000000.flags & 4)) {
            script->active = 0;
            script->selection = 3;
        } else {
            script->selection = 2;
        }
        state->ready = 6;
        break;
    }
    case 4:
    case 6:
        if (!(g_state_0200F390.flags & 8)) {
            g_state_0200F390.flags |= 1;
            return 0x100;
        }
        break;
    case 7:
    {
        u16 selector = 0x179;
        void *destination;

        g_state_02000000.character = func_0803600C();
        destination = g_state_02000000.character_data;
        switch (state->timer) {
        case 10:
            break;
        case 9:
            selector = 0x17B;
            break;
        case 4:
            selector = 0x17C;
            break;
        case 12:
            selector = 0x190;
            break;
        case 94:
            selector = 0x17E;
            break;
        }
        func_080D241C(selector, destination);
        data_030027F4 = destination;
        func_080C9574(0x4A, 1);
        func_08022E90(4, 16);
        g_state_0200F390.mode = 0x1B;
        state->ready = 8;
        break;
    }
    case 8:
        if (g_state_0200F390.mode == 0x20) {
            func_080C9574(0x4A, 0);
            return 0x100;
        }
        break;
    }
    return 0x11C;
}
