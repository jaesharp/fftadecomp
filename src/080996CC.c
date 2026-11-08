#include "ffta.h"

/* Complete target [0x080996CC, 0x08099714): 72 bytes. */
typedef struct ListNode ListNode;
typedef struct TreeNode TreeNode;
typedef struct ListContext ListContext;

typedef struct {
    u8 unknown_00[0x14];
    ListContext *objects;
} State080996CC;

typedef struct {
    void *record;
    u8 unknown_04[0x20];
    s32 priority;
} Object080996CC;

typedef struct {
    void *record;
    u32 unknown_04;
    Object080996CC *result;
} Search080996CC;

typedef s32 (*SearchCallback080996CC)(const ListNode *node, Search080996CC *search);

extern Object080996CC *func_0809716C(State080996CC *state, void *record);
extern ListNode *func_080C7A74(ListContext *context, void *object);
extern TreeNode *func_080C7AB4(ListContext *context, void *object, s32 key);
extern void func_080C7CC0(ListContext *context, SearchCallback080996CC callback,
                         Search080996CC *search);
extern s32 func_0809AB5C(const ListNode *node, Search080996CC *search);

Object080996CC *func_080996CC(State080996CC *state, void *record)
{
    Search080996CC search;
    Object080996CC *object;

    search.record = record;
    search.result = 0;
    func_080C7CC0(state->objects, func_0809AB5C, &search);
    object = search.result;
    if (object == 0) {
        object = func_0809716C(state, record);
        func_080C7A74(state->objects, object);
        func_080C7AB4(state->objects, object, object->priority);
    }
    return object;
}
