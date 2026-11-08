#include "ffta.h"

typedef struct {
    u32 value : 7;
    u32 enabled : 1;
    u32 mode : 4;
    u32 flag4 : 1;
    u32 flag5 : 1;
    u32 flag6 : 1;
    u32 unknown_flag : 1;
    u8 path[5];
} __attribute__((packed)) PathCell081491C0;

typedef void (*BufferInitializer081491C0)(void *destination, u32 size);
extern BufferInitializer081491C0 g_callbacks_0836D4B8[];

void func_081491C0(PathCell081491C0 *grid, s16 x, s16 y, u8 enabled,
                   u16 value, u8 flag4, u8 flag5)
{
    PathCell081491C0 *cell = &grid[y * 16 + x];

    cell->enabled = enabled;
    cell->value = value;
    cell->mode = 1;
    cell->flag4 = flag4;
    cell->flag5 = flag5;
    cell->flag6 = 0;
    g_callbacks_0836D4B8[0](cell->path, sizeof(cell->path));
}
