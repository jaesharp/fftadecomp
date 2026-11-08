#include "ffta.h"

/* 0811E934: complete 210-byte target, including its literal pools. */
typedef struct Task Task;

typedef struct {
    u16 phase;
    u16 unknown_02;
    void *argument;
    u32 value;
    u32 flags;
    u32 unknown_10;
    s16 selector;
    u16 option;
    u16 resource;
    u16 unknown_1a;
} TaskRequest;

typedef struct {
    void **resources;
    u16 count;
    Task *child;
} Sequence;

typedef int (*TaskCallback)(Task *, TaskRequest *, void *);
extern Task *func_08005B6C(TaskCallback callback, u16 size,
                          TaskRequest *request, Task *parent);
extern void func_080D35D8(void);
extern Task *func_080E051C(Task *task);
extern int func_080E2398(Task *, TaskRequest *, void *);
extern int func_080E9920(Task *, TaskRequest *, void *);

int func_0811E934(Task *parent, TaskRequest *request, Sequence *state)
{
    TaskRequest first;
    TaskRequest second;

    switch (request->phase) {
    case 0:
        state->resources = request->argument;
        state->count = request->value;
        break;
    case 1:
        func_080D35D8();
        break;
    case 0x100:
        first.selector = 0x159;
        first.option = 0x503;
        first.resource = 0x199;
        first.argument = state->resources[0];
        state->child = func_08005B6C(func_080E2398, 0x28, &first, parent);
        request->phase++;
        break;
    case 0x101:
        state->child = func_080E051C(state->child);
        if (state->child == 0) {
            second.selector = 0x199;
            second.option = 0;
            second.argument = state->resources + 1;
            second.value = state->count - 1;
            state->child = func_08005B6C(func_080E9920, 0x38, &second, parent);
            request->phase++;
        }
        break;
    case 0x102:
        state->child = func_080E051C(state->child);
        if (state->child == 0)
            request->phase = 2;
        break;
    }
    return 0;
}
