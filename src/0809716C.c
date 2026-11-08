#include "ffta.h"

/* Target: complete [0x0809716C, 0x080971F8), 140 bytes. */
typedef struct ListNode ListNode;
typedef struct TreeNode TreeNode;
typedef struct ListContext ListContext;
typedef struct Object Object;

typedef struct {
    u8 unknown_00[0x28];
    u16 flags;
    u8 unknown_2A[0xCE];
    u8 identifier;
    u8 unknown_F9[2];
    u8 priority;
} SceneRecord;

typedef struct {
    void *allocator;
    u8 unknown_04[0xC];
    ListContext *objects;
    u8 unknown_14[8];
    void *manager;
} State;

struct Object {
    SceneRecord *record;
    u8 unknown_04[0x1C];
    u8 identifier;
    u8 unknown_21[3];
    u32 priority;
    u8 unknown_28[0x10];
    u16 enabled;
    u8 unknown_3A[2];
    void *manager;
    u8 unknown_40[0x40];
    State *state;
};

typedef struct {
    SceneRecord *record;
    u32 unknown_04;
    Object *result;
} Search;

typedef void (*BufferInitializer)(void *destination, s32 bytes);
typedef s32 (*SearchCallback)(const ListNode *node, Search *search);

extern BufferInitializer const g_callbacks_0836D4B8[];
extern void *func_08007138(void *allocator, u32 bytes);
extern u32 func_08099CB8(State *state);
extern ListNode *func_080C7A74(ListContext *context, void *object);
extern TreeNode *func_080C7AB4(ListContext *context, void *object, s32 key);
extern void func_080C7CC0(ListContext *context, SearchCallback callback,
                         Search *search);
extern s32 func_0809AB5C(const ListNode *node, Search *search);

Object *func_0809716C(State *state, SceneRecord *record)
{
    Search search;
    Object *object;

    search.record = record;
    search.result = 0;
    func_080C7CC0(state->objects, func_0809AB5C, &search);
    object = search.result;
    if (object == 0) {
        object = func_08007138(state->allocator, sizeof(*object));
        g_callbacks_0836D4B8[0](object, sizeof(*object));
        object->record = record;
        object->priority = func_08099CB8(state);
        object->record->priority = object->priority;
        object->state = state;
        object->manager = state->manager;
        object->enabled = 1;
        func_080C7A74(state->objects, object);
        func_080C7AB4(state->objects, object, object->priority);
        record->flags |= 1;
        object->identifier = record->identifier;
    }
    return object;
}
