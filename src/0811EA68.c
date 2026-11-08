#include "ffta.h"

/* 0x0811EA68..0x0811EB26: complete 190-byte task callback. */
typedef struct {
    u16 phase;
    u16 unknown_02;
    void *object;
} TaskCommand;

/* Registration copies all 28 bytes; only the assigned members are known. */
typedef struct {
    u16 phase;
    u16 unknown_02;
    void *object;
    u8 unknown_08[12];
    u16 kind;
    u16 flag;
    u16 next_kind;
    u16 unknown_1A;
} TaskRequest;

typedef struct {
    void *object;
    void *child;
} CallbackState;

typedef u32 (*TaskCallback)(void *, void *, void *);

/* Conditional word-transport views of the captured callback entries. */
extern u32 func_080E2398(void *, void *, void *);
extern u32 func_08105D40(void *, void *, void *);
extern void *func_08005B6C(TaskCallback, u16, void *, void *);
extern void *func_080E051C(void *);
extern void func_080D35D8(void);

u32 func_0811EA68(void *task, TaskCommand *command, CallbackState *state)
{
    TaskRequest first;
    TaskRequest second;

    switch (command->phase) {
    case 0:
        state->object = command->object;
        break;
    case 1:
        func_080D35D8();
        break;
    case 0x100:
        first.kind = 0x159;
        first.flag = 12;
        first.next_kind = 0x19C;
        first.object = state->object;
        state->child = func_08005B6C(func_080E2398, 40, &first, task);
        command->phase++;
        break;
    case 0x101:
        state->child = func_080E051C(state->child);
        if (!state->child) {
            second.kind = 0x19C;
            second.flag = 0;
            second.object = state->object;
            state->child = func_08005B6C(func_08105D40, 56, &second, task);
            command->phase++;
        }
        break;
    case 0x102:
        state->child = func_080E051C(state->child);
        if (!state->child)
            command->phase = 2;
        break;
    }
    return 0;
}
