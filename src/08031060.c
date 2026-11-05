#include "ffta.h"

typedef struct {
    u8 unknown_00[0x78];
    u8 *heap;
    u8 unknown_7c[0x1c];
    void *allocation_98;
    u8 unknown_9c[0x978];
    u8 *row_a[3];
    u8 unknown_a20[0xc0];
    u8 *row_b[3];
    u8 unknown_aec[0xc0];
    u8 *row_c[3];
    u8 unknown_bb8[0x50];
    void *allocation_c08;
} State08031060;

typedef struct {
    u32 unknown_00;
    void *allocation;
} Slot08031060;

extern u8 g_state_0200F390[];
extern u8 *data_0200F38C;
extern State08031060 *g_state_03002810;
extern Slot08031060 data_03000E30;

u8 *func_080070C8(u8 *storage, u32 bytes);
void *func_08007138(void *owner, u32 bytes);
u32 func_0800717C(void *owner, const u8 *payload);
void func_0814186C(const void *source, void *destination, u32 control);

void func_08031060(void)
{
    u16 state_zero;
    u16 *state_source;
    u16 allocation_zero[1];
    u16 slot_zero[1];

    data_0200F38C = func_080070C8(g_state_0200F390, 0x100d0);
    g_state_03002810 = func_08007138(data_0200F38C, 0x7570);
    state_source = &state_zero;
    *state_source = 0;
    func_0814186C(state_source, g_state_03002810, 0x01003ab8);
    g_state_03002810->heap = data_0200F38C;
    g_state_03002810->allocation_98 = func_08007138(data_0200F38C, 0x3040);
    allocation_zero[0] = 0;
    func_0814186C(allocation_zero, g_state_03002810->allocation_98, 0x01001820);
    data_03000E30.allocation = func_08007138(data_0200F38C, 0x740);
    slot_zero[0] = 0;
    func_0814186C(slot_zero, data_03000E30.allocation, 0x010003a0);
    g_state_03002810->allocation_c08 = func_08007138(data_0200F38C, 0x1c10);
    func_0800717C(g_state_03002810->heap, g_state_03002810->allocation_98);
    g_state_03002810->row_a[0] = (u8 *)g_state_03002810 + 0xf40;
    g_state_03002810->row_b[0] = (u8 *)g_state_03002810 + 0x13f0;
    g_state_03002810->row_c[0] = (u8 *)g_state_03002810 + 0x18a0;
    g_state_03002810->row_a[1] = (u8 *)g_state_03002810 + 0x1d50;
    g_state_03002810->row_b[1] = (u8 *)g_state_03002810 + 0x2330;
    g_state_03002810->row_c[1] = (u8 *)g_state_03002810 + 0x2910;
    g_state_03002810->row_a[2] = (u8 *)g_state_03002810 + 0x2ef0;
    g_state_03002810->row_b[2] = (u8 *)g_state_03002810 + 0x4670;
    g_state_03002810->row_c[2] = (u8 *)g_state_03002810 + 0x5df0;
}
