#include "ffta.h"

typedef struct {
    u16 count;
    s8 position;
    u8 unknown_03;
} Entry0804F948;

typedef struct {
    u8 unknown_000[0x53c];
    Entry0804F948 entries[0];
} Source0804F948;

typedef struct {
    u8 width, height, rows, unknown_03;
    u16 count, palette;
    u8 unknown_08[6];
    u16 tile;
} Settings0804F948;

typedef struct {
    u32 callback;
    void *owner;
    u16 *tiles;
    u8 unknown_0c[9];
    u8 row_height;
    u8 visible;
    u8 unknown_17;
    s16 remaining;
    u16 count;
    u8 unknown_1c[4];
} Menu0804F948;

typedef struct {
    u32 first;
    void *owner;
    u16 field_08, field_0a, field_0c, field_0e;
    u8 flags, position, field_12, unknown_13;
} List0804F948;

typedef struct {
    u8 unknown_00[0x2c];
    Menu0804F948 menu;
    List0804F948 list;
    u8 unknown_60[0x18];
} Window0804F948;

typedef struct {
    Source0804F948 *source;
    u16 flags;
    u8 unknown_06[2];
    u8 mode;
    u8 unknown_09;
    u8 count;
    u8 unknown_0b;
    Settings0804F948 settings;
    Window0804F948 window;
    void *resource;
} State0804F948;

typedef void (*CursorCallback0804F948)(void *);

extern void func_08016210(void *, void *, u16, u16);
extern s32 func_08017B50(Menu0804F948 *);
extern void func_080505BC(State0804F948 *, s16);
extern void func_08017AD8(Menu0804F948 *);
extern void func_08017AF4(Menu0804F948 *, s8, u8);
extern void func_08050B9C(State0804F948 *, u8, u8);
extern void func_08015D58(void *, u32, CursorCallback0804F948);
extern void func_08017FB0(void *, u8);
extern void func_08016234(void *);
extern void func_08017D18(void *, u8);
extern void func_0804FBB0(State0804F948 *);
extern void func_080503E4(State0804F948 *);
extern u8 func_0804FAE4(State0804F948 *, s32);
extern u32 func_0804FB38(const State0804F948 *, u32);
extern u32 func_0804FB84(const State0804F948 *, u32);
extern void func_08017F04(void *);
extern void func_08017E80(void *);

void func_0804F948(State0804F948 *state)
{
    switch (state->mode) {
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    {
        Window0804F948 *panel = &state->window;
        Settings0804F948 *settings = &state->settings;
        Menu0804F948 *menu = &panel->menu;
        List0804F948 *list = &panel->list;
        CursorCallback0804F948 callback = 0;
        Entry0804F948 *entry = &state->source->entries[state->mode];
        s32 i;
        s32 count;

        func_08016210(panel, state->resource, settings->tile + 0x140,
                      settings->count);
        switch (state->mode) {
        case 3:
            func_08017AC4((Struct08017AC4 *)menu, (u32)func_0804FAE4,
                          (u32)state);
            break;
        case 4:
            func_08017AC4((Struct08017AC4 *)menu, (u32)func_0804FB38,
                          (u32)state);
            break;
        case 5:
            func_08017AC4((Struct08017AC4 *)menu, (u32)func_0804FB84,
                          (u32)state);
            break;
        }
        menu->count = entry->count;
        count = func_08017B50(menu);
        state->count = count;
        for (i = 0; i < count; ++i) {
            func_080505BC(state, (s16)i);
            count = state->count;
        }
        func_08017AD8(menu);
        func_08017AF4(menu, entry->position, 11);
        if (state->mode == 4) {
            for (i = 0; i < state->count; ++i)
                func_08050B9C(state, (u8)i, 1);
        }
        if (menu->visible < settings->count)
            callback = func_08017F04;
        else
            state->flags |= 0x10;
        func_08015D58(panel, (u32)func_08017E80, callback);
        func_08017FB0(list, (u8)entry->position);
        func_08016234(panel);
        if (((u8 *)&state->flags)[0] & 1)
            func_08017D18(&state->window.list, 1);
        break;
    }
    case 2:
    case 7:
        func_0804FBB0(state);
        break;
    case 8:
        func_080503E4(state);
        break;
    }
}
