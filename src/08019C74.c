#include "ffta.h"

typedef struct {
    u8 unknown_00[0x24];
    s16 x;
    s16 y;
    u8 unknown_28[4];
    u16 flags;
    u8 unknown_2e[0x1ea];
    u8 adjust_x_enabled;
    u8 unknown_219[3];
    u8 adjust_y_enabled;
    u8 unknown_21d[7];
    u16 adjust_x;
    u16 adjust_y;
    u8 unknown_228[10];
    s16 reference_x;
    s16 reference_y;
} ScrollState08019C74;

extern ScrollState08019C74 g_state_02007F40;
extern void func_08003508(s16 coordinate, u8 layer);
extern void func_08003558(s16 coordinate, u8 layer);

static inline s32 adjusted_coordinate(const u16 *adjustment, s16 coordinate)
{
    return coordinate + *adjustment;
}

/* Target: complete [0x08019C74, 0x08019D18), 164 bytes, 71 instructions. */
/* Complete [0x08019C74, 0x08019D18): 164 bytes, 71 instructions. */
void func_08019C74(void)
{
    u16 x = (u16)(g_state_02007F40.x - g_state_02007F40.reference_x);
    u16 y = (u16)(g_state_02007F40.y - g_state_02007F40.reference_y);

    if (g_state_02007F40.flags & 0x400) {
        if (g_state_02007F40.adjust_x_enabled)
            x = adjusted_coordinate(&g_state_02007F40.adjust_x, x);
        if (g_state_02007F40.adjust_y_enabled)
            y = adjusted_coordinate(&g_state_02007F40.adjust_y, y);
    }
    func_08003508(x, 1);
    func_08003558(y, 1);
    func_08003508(x, 0);
    func_08003558(y, 0);
}
