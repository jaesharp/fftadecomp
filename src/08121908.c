#include "ffta.h"

typedef struct {
    u8 unknown_00[0x2192];
    u16 current;
    u16 queued[4];
    u8 count;
} QueueState08121908;

typedef struct {
    void *manager;
    void *allocation;
    void *task;
    u8 action;
} ScriptContext08121908;

typedef struct {
    u8 unknown_00;
    u8 active;
} ModeState08121908;

extern QueueState08121908 g_state_02000000;
extern ScriptContext08121908 *data_020159CC;
extern ModeState08121908 g_state_0200F390;
extern void func_08009FD0(void);
extern u8 func_08009FBC(void);
extern void func_08121E48(void);
extern void func_08121E9C(void);
extern void *func_0812237C(u16 event);
extern void func_08005A24(void *manager);
extern u32 func_08121C38(void);
extern void func_08121C18(void);
extern void func_08121F80(void);
extern void func_08009FF8(void);
extern u8 func_08121F38(void);
extern void func_08121A48(void);
extern void func_08121EF0(void);
extern void func_08121E74(void);

/* Complete [0x08121908, 0x081219F4): 236 bytes, 70 instructions. */
void func_08121908(void *task, u8 *state)
{
    switch (*state) {
    case 0:
        if (g_state_02000000.count != 0)
            func_08009FD0();
        *state = 1;
        break;
    case 1:
        if (func_08009FBC()) {
            func_08121E48();
            func_08121E9C();
            data_020159CC->task = func_0812237C(g_state_02000000.current);
            g_state_0200F390.active = 1;
            *state = 2;
        }
        break;
    case 2:
        if (data_020159CC->action != 0)
            *state = 3;
        func_08005A24(data_020159CC->manager);
        func_08121C38();
        break;
    case 3:
        func_08005A24(data_020159CC->manager);
        func_08121C18();
        func_08121F80();
        *state = 4;
        break;
    case 4:
        g_state_0200F390.active = 0;
        func_08009FF8();
        func_08121F38();
        func_08121A48();
        func_08121EF0();
        func_08121E74();
        *state = 1;
        break;
    }
}
