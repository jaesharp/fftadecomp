#include "ffta.h"

typedef struct {
    u8 state;
    u8 active;
    u8 phase;
    u8 sound;
    u16 selection;
    u8 mode;
} MenuState080233A0;

extern MenuState080233A0 g_state_0200F390;
extern void *func_0802D72C(u8 first);
extern void func_0802D704(void *object);

/* Complete [0x080233A0, 0x08023488): 232 bytes. */
u32 func_080233A0(u8 selection)
{
    switch (selection) {
    case 4:
        g_state_0200F390.selection = selection;
        g_state_0200F390.mode = 0;
        return 0x10;
    case 13:
    case 14:
    case 15:
        g_state_0200F390.selection = selection;
        g_state_0200F390.sound = selection + (u8)-7;
        g_state_0200F390.mode = 0;
        return 0x11;
    case 10:
        g_state_0200F390.selection = selection;
        func_0802D704(func_0802D72C(1));
        g_state_0200F390.mode = 0;
        return 0x12;
    case 1:
        g_state_0200F390.selection = selection;
        g_state_0200F390.sound = 2;
        g_state_0200F390.mode = 0;
        return 0x13;
    case 3:
        g_state_0200F390.selection = selection;
        g_state_0200F390.sound = 3;
        g_state_0200F390.mode = 0;
        return 0x14;
    case 2:
        g_state_0200F390.selection = selection;
        g_state_0200F390.mode = 0;
        return 0x15;
    default:
        g_state_0200F390.phase = 0;
        g_state_0200F390.active = 0;
        return 1;
    }
}
