#include "ffta.h"

typedef struct {
    u8 unknown_0000[0x2FC2];
    u8 selector : 2;
    u8 unknown_2FC2 : 6;
} State08013794;

extern State08013794 g_state_02000000;
extern const u16 data_0841A840[];

/* 08013794..080137C0: 44 bytes, 16 instructions. */
u16 func_08013794(u8 value)
{
    return data_0841A840[(u16)(g_state_02000000.selector * 4 + value - 1)];
}
