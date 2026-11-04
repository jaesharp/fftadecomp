#include "ffta.h"

typedef struct RecordPair {
    u32 first;
    u32 second;
} RecordPair;

typedef struct CommandState {
    u16 current;
    u8 unknown_02[0xCA];
    u8 buffer[0x14];
    RecordPair record;
    u8 mode;
    u8 ready;
} CommandState;

typedef struct SavedState {
    u8 unknown_00[0x98];
    RecordPair record;
    u8 unknown_A0[0x30];
    u8 buffer[0x14];
    u8 mode;
} SavedState;

extern CommandState *data_0200F450;
extern SavedState g_state_020020D0;
extern void (*data_0836D4BC)(void *, const void *, u32);
extern void func_080C95C0(u16, u32);
extern void func_080C7260(void);
extern void func_080C71B4(u16);

/* Complete target [0x080623C8, 0x08062430), 104 bytes. */
void func_080623C8(void)
{
    func_080C95C0(13, 1);
    func_080C7260();
    func_080C71B4(1);
    data_0200F450->record = g_state_020020D0.record;
    data_0200F450->mode = g_state_020020D0.mode;
    data_0836D4BC(data_0200F450->buffer, g_state_020020D0.buffer, 0x14);
    data_0200F450->ready = 0;
    data_0200F450->current = 5;
}
