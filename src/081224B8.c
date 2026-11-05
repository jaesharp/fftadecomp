#include "ffta.h"

typedef struct {
    u16 first;
    u16 second;
    u16 timer;
    u8 ready;
    u8 filter;
    void *context;
    void *object;
} CommandState;

typedef struct {
    u8 unknown_00[0x96];
    u16 mode;
} ScriptState081224B8;

extern ScriptState081224B8 g_state_0200F390;
extern void func_0802B8E8(void);
extern u8 func_080C9540(u16 bit_index);
extern void func_081258CC(void);
extern u32 func_0802DD58(void);
extern void func_0812A060(CommandState *state);
extern void func_0812B208(CommandState *state);
extern void func_0812B230(CommandState *state);
extern void func_0812C510(CommandState *state);

/* Complete [0x081224B8, 0x08122596): 222 bytes including switch and pools. */
u32 func_081224B8(CommandState *state, const u8 *instruction)
{
    state->ready = instruction[1];
    switch (state->ready) {
    case 3:
        state->ready = 1;
        func_0802B8E8();
        break;
    case 6:
        state->ready = 3;
        break;
    case 7:
        state->ready = 5;
        break;
    case 9:
        if (g_state_0200F390.mode == 3 || func_080C9540(0x40))
            return 0x110;
        func_081258CC();
        if (func_0802DD58() == 0)
            return 0x110;
        func_0812A060(state);
        return 0x115;
    case 10:
        func_0812B208(state);
        return 0x115;
    case 11:
        func_0812B230(state);
        return 0x115;
    case 14:
        func_0812C510(state);
        return 0x115;
    }
    return 0x11C;
}
