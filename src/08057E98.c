#include "ffta.h"

typedef struct {
    u8 unknown_00[0x0C];
    u16 *tiles;
    u8 unknown_10[5];
    u8 width;
    u8 unknown_16[6];
    u16 tileBase;
    u8 unknown_1E;
    u8 palette;
} MenuWindow;

typedef struct {
    u8 unknown_00[7];
    u8 field_07;
    u8 unknown_08[0xE8];
    u8 field_F0;
    u8 unknown_F1[0x11];
    u8 field_102;
    u8 field_103;
    u8 unknown_104[4];
} MenuUnitRecord;

typedef struct {
    u8 unknown_00[0x80];
    MenuUnitRecord records[24];
} MenuUnitTable;

extern MenuUnitTable g_state_02000000;
typedef struct State0805871C State0805871C;
typedef struct State0802AB64 State0802AB64;
extern u8 func_0805871C(State0805871C *window, u8 row);
extern u32 func_080CBA14(u8 value);
extern void func_0802AB64(State0802AB64 *window, u16 destination, u16 source,
                         u8 width, u8 height, u16 palette, u8 copy);
extern void func_0802ACA0(u16 *destination, u16 tile, u8 palette, u16 count);
extern void func_08029730(u16 *destination, u32 digits, u8 value);

/* Complete target: [0x08057E98, 0x08058104), 620 bytes, 290 instructions. */
void func_08057E98(MenuWindow *window, u8 row, u8 unitId, u8 mode)
{
    u8 bank = func_0805871C((State0805871C *)window, row);
    u8 width = window->width;
    u16 rowStart = row * 5;
    u16 base = rowStart * width;
    u32 bankRow = (bank & 3) * 5;
    u16 source = bankRow * width + window->tileBase;
    MenuUnitTable *unit;
    u32 state_address;
    u8 palette;
    u16 destination;
    u16 i;

    state_address = (u32)&g_state_02000000;
    unit = (MenuUnitTable *)(unitId * sizeof(MenuUnitRecord) + state_address);
    palette = func_080CBA14(unit->records[0].field_07);

    switch (mode)
    {
    case 0:
    {
        destination = base;
        func_0802AB64((State0802AB64 *)window, destination, source, window->width,
                     window->width, window->palette, 1);
        destination += 2 * window->width;
        source += 2 * window->width;
        func_0802AB64((State0802AB64 *)window, destination, source, window->width, 4, palette, 0);
        func_0802ACA0(&window->tiles[base + 2 * window->width + 4], 0x93, 14, 6);
        func_0802ACA0(&window->tiles[base + 3 * window->width + 4], 0x99, 14, 6);
        func_08029730(&window->tiles[base + 3 * window->width + 10], 2, unit->records[0].field_F0);
        func_0802ACA0(&window->tiles[base + 3 * window->width + 12], 0x8F, 14, 4);
        destination = base + 4 * window->width;
        for (i = 0; i < window->width; i++, destination++)
            window->tiles[destination] = 0;
        break;
    }
    case 1:
    {
        destination = base;
        func_0802AB64((State0802AB64 *)window, destination, source, window->width,
                     window->width, window->palette, 1);
        destination += 2 * window->width;
        source += 2 * window->width;
        func_0802AB64((State0802AB64 *)window, destination, source, window->width, 4, palette, 0);
        func_0802ACA0(&window->tiles[base + 2 * window->width + 5], 0x120, 15, 2);
        func_0802ACA0(&window->tiles[base + 3 * window->width + 5], 0x122, 15, 2);
        func_0802ACA0(&window->tiles[base + 2 * window->width + 9], 0x120, 14, 2);
        func_0802ACA0(&window->tiles[base + 3 * window->width + 9], 0x122, 14, 2);
        func_08029730(&window->tiles[base + 3 * window->width + 7], 1, unit->records[0].field_103);
        func_08029730(&window->tiles[base + 3 * window->width + 11], 1, unit->records[0].field_102);
        destination = base + 4 * window->width;
        for (i = 0; i < window->width; i++, destination++)
            window->tiles[destination] = 0;
        break;
    }
    }
}
