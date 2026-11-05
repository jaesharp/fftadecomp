#include "ffta.h"

/* These views describe accessed fields, not complete allocation extents. */
typedef struct {
    u8 unknown_00[6];
    u8 done;
} Owner0812A084;

typedef struct {
    u16 phase;
    u8 unknown_02[2];
    Owner0812A084 *owner;
    u8 unknown_08[12];
    u16 variant;
} Task0812A084;

typedef struct SceneRecord0812A084 SceneRecord0812A084;
typedef struct TransferRecord0812A084 TransferRecord0812A084;

typedef struct {
    Owner0812A084 *owner;
    u16 frame;
    u16 variant;
    u8 unknown_008[0x290];
    const u8 *resource;
    SceneRecord0812A084 *record;
    u8 unknown_2A0[0x54];
    u8 render_next;
    u8 unknown_2F5;
    u8 selector;
    u8 load_count;
    u8 tick;
    u8 unknown_2F9[3];
    u8 *graphics;
    u8 *tiles;
    u8 *characters;
    u8 *text;
    u8 *workspace;
    u8 cursor_index;
    u8 cursor_position;
    u8 name[18];
    u8 position;
    u8 index;
    u8 length;
    u8 timer;
    u8 alternate;
    u8 unknown_329[3];
    u8 *window;
    u8 stage;
} State0812A084;

typedef struct {
    u8 unknown_00[0x14];
    u16 *tiles;
} TileGrid0812A084;

typedef struct {
    u16 held;
    u16 repeat;
    u16 pressed;
} Input0812A084;

extern u8 data_02001F1C[];
extern u8 g_state_020021A0[];
extern Input0812A084 data_03000000;
extern TileGrid0812A084 data_030008B0;
extern TileGrid0812A084 data_03000990;
extern u8 data_06005000[];
extern u8 data_06008000[];
extern u8 data_0600A280[];
extern u8 data_0600E000[];
extern u8 data_06016300[];

extern void func_080157A8(u16 *, u8, u8, u8, u8, u8, u16, u8);
extern void func_0801E458(u8, u8, u8, s16, s16, void *, void *);
extern void *func_08022840(u32);
extern void func_08022854(u8 *);
extern void func_0802B8E8(void);
extern SceneRecord0812A084 *func_080C83CC(u8);
extern const u8 *func_080CB928(SceneRecord0812A084 *);
extern void func_080CEA80(u8);
extern u8 *func_08121B64(u32);
extern void func_08121B78(u8 *);
extern void func_0812A440(State0812A084 *);
extern void func_0812A52C(State0812A084 *);
extern void func_0812A5BC(Task0812A084 *, State0812A084 *);
extern void func_0812A91C(State0812A084 *);
extern void func_0812AC08(State0812A084 *);
extern void func_0812AD14(State0812A084 *, u8);
extern void func_0812AE8C(State0812A084 *);
extern u32 func_0812AF1C(State0812A084 *);
extern u32 func_0812B094(State0812A084 *);
/* The reached entry does not consume R0. This call view records the root's
 * supplied state word; it does not assert a unique cross-TU prototype. */
extern void func_0812B258(State0812A084 *);
extern void func_0812B2EC(SceneRecord0812A084 *);
extern void func_0812B340(void);
extern void func_0812B41C(TransferRecord0812A084 *, void *, u8);
extern void func_0812B44C(TransferRecord0812A084 *, const u8 *, void *, u8);
extern void func_0812B468(State0812A084 *, u8);
extern TransferRecord0812A084 *func_0812B4E0(State0812A084 *);
extern void func_0812B504(const void *);
extern void func_0812B59C(u8 *);
extern void func_0814186C(const void *, void *, u32);
extern u32 func_08142B28(u32, u32);
extern u32 func_081444B8(const void *);

s32 func_0812A084(void *context, Task0812A084 *task, State0812A084 *state)
{
    u8 category;

    state->render_next = 0;
    switch (task->phase) {
    case 0:
        state->owner = task->owner;
        state->variant = task->variant;
        break;
    case 1:
        break;
    case 0x100:
        if (state->variant) {
            func_0814186C(data_02001F1C, state->name, 10);
            category = 15;
        } else {
            func_0814186C(g_state_020021A0, state->name, 10);
            category = 8;
        }
        state->resource = func_080CB928(
            state->record = func_080C83CC(category));
        state->graphics = func_08022840(0xC600);
        state->tiles = func_08022840(0x480);
        state->characters = func_08022840(0xF0);
        state->text = func_08022840(0x100);
        state->workspace = func_08022840(0x100);
        state->window = func_08121B64(0xA04);
        func_0812B340();
        state->frame = 0;
        state->selector = 0;
        state->cursor_position = 0;
        state->cursor_index = 0;
        state->timer = 0;
        state->length = func_081444B8(state->name) >> 1;
        func_0812B59C(state->name);
        state->position = 0;
        state->index = 0;
        state->load_count = 0;
        state->tick = 0;
        task->phase = 0x101;
        break;
    case 0x101:
        state->tick++;
        if ((u8)func_08142B28(state->tick, 3) == 0) {
            func_0812B468(state, state->load_count);
            func_0812AD14(state, state->load_count);
            if (++state->load_count > 1)
                task->phase = 0x102;
            state->tick = 0;
        }
        break;
    case 0x102:
        func_0812B2EC(state->record);
        func_0812B258(state);
        func_0812AE8C(state);
        func_0812B41C(func_0812B4E0(state), data_06016300, state->selector);
        func_0812B44C(func_0812B4E0(state), state->graphics,
                     data_0600A280, state->selector);
        func_080157A8(data_030008B0.tiles, 2, 4, 21, 6, 32, 0x114, 11);
        task->phase = 0x103;
        break;
    case 0x103:
        if ((u8)func_0812AF1C(state))
            task->phase = 0x104;
        break;
    case 0x104:
        if (data_03000000.repeat & 8) {
            task->phase = 0x106;
            state->stage = 0;
        }
        func_0812A91C(state);
        func_0812AC08(state);
        func_0812B504(state);
        func_0812A440(state);
        break;
    case 0x106:
        func_0812A5BC(task, state);
        func_0812A52C(state);
        break;
    case 0x107:
        if ((u8)func_0812B094(state))
            task->phase = 0x108;
        break;
    case 0x108:
        func_08022854(state->graphics);
        func_08022854(state->tiles);
        func_08022854(state->characters);
        func_08022854(state->text);
        func_08022854(state->workspace);
        func_08121B78(state->window);
        func_080CEA80(*(u8 *)&state->variant);
        {
            u16 zero = 0;
            func_0814186C(&zero, data_030008B0.tiles, 0x01000400);
        }
        {
            u16 zero = 0;
            func_0814186C(&zero, data_03000990.tiles, 0x01000400);
        }
        func_0802B8E8();
        func_0801E458(2, 1, 0, 0, 0, data_06008000, data_0600E000);
        func_0801E458(3, 1, 1, 0, 0, data_06008000, data_06005000);
        state->owner->done = 1;
        task->phase = 3;
        break;
    }
    return 0;
}
