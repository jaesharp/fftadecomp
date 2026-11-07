typedef unsigned char u8;
typedef unsigned int u32;

struct PendingState {
    u8 unknown_00[0x5C];
    u8 *pending;
};

extern struct PendingState g_state_0200F390;
extern u8 data_03003862[];
extern void (* const data_0836D4BC)(void *, const void *, u32);
extern void func_08022854(void *);

/* 0x08022E58: complete 56-byte function, including its literal pool. */
void func_08022E58(void)
{
    struct PendingState *state = &g_state_0200F390;

    if (state->pending != 0) {
        data_0836D4BC(data_03003862, state->pending + 2, 0x3FE);
        func_08022854(state->pending);
        state->pending = 0;
    }
}
