#include "ffta.h"

typedef struct {
    u16 unknown_00;
    u8 index;
    u8 unknown_03;
    u16 unit;
    u8 unknown_06[4];
    s16 x;
    s16 y;
    u8 unknown_0e[6];
} DisplayRecord08071378;

typedef struct {
    u8 unknown_000[0x95c];
    u8 count;
    u8 unknown_95d[0x13];
    u8 flags;
    u8 unknown_971[5];
    s16 y;
    u8 x;
    u8 unknown_979;
    s16 base_y;
    u8 unknown_97c[10];
    u8 selected;
    u8 unknown_987[13];
    s16 scroll;
    u8 unknown_996[0x24];
    u8 units[0x32];
    DisplayRecord08071378 records[24];
    u8 modes[0];
} State08071378;

typedef struct {
    u8 unknown_00[0x28];
    u16 flags;
    u8 unknown_2a[0xde];
} Unit08071378;

typedef struct {
    u32 unknown_00;
    Entry *entries;
} Render08071378;

extern State08071378 *data_03002818;
extern Render08071378 data_03000E30;
extern Unit08071378 g_state_02000080[];
extern u8 data_0894EAE0[];
extern u8 data_0894EB6C[];
extern const u8 data_08393ECA[];
extern const u8 data_08393ED2[];
extern void func_0804C524(Entry *base, u16 index, u32 selector,
                         u8 a4, u8 a5, u32 a6, u8 a7, u32 a8,
                         u8 *row, u16 a10, s8 a11);
extern void func_0804C7A0(Entry *entries, u16 index);
extern void func_08001CF0(const void *source, s32 first, s32 second,
                         u8 mode, u8 first_flag, u8 second_flag,
                         u8 third_flag, u8 fourth_flag, u32 value,
                         u8 count, u32 extra);

/* Complete target [0x08071378, 0x08071704), 908 bytes. */
void func_08071378(void)
{
    s32 i;
    s32 y;
    for (i = 0; i < data_03002818->count; i++) {
        s32 unit_id = data_03002818->units[i];
        Unit08071378 *unit;
        s32 mode;
        s32 tile;
        data_03002818->records[i].index = i;
        data_03002818->records[i].unit = unit_id;
        unit = &g_state_02000080[unit_id];
        mode = data_03002818->modes[unit_id];
        y = data_03002818->records[i].y - data_03002818->scroll + 44;
        if ((u32)(y - 1) <= 190) {
            if (unit->flags & 4)
                tile = 984;
            else if (unit->flags & 0x18)
                tile = 1004;
            else if (unit_id < 8)
                tile = unit_id * 20 + 128;
            else
                tile = (unit_id - 8) * 20 + 664;
            if (data_03002818->selected != i) {
                u16 unavailable = unit->flags & 0x1c;
                s32 display_mode = mode + 3;
                if (unavailable)
                    display_mode = 0;
                func_0804C524(data_03000E30.entries, i, 0,
                    data_03002818->records[i].x, y, 0, 2,
                    (u32)data_0894EAE0, data_0894EB6C, tile,
                    display_mode);
            } else {
                if (unit->flags & 0x1c)
                    func_0804C7A0(data_03000E30.entries, i);
                else
                    func_0804C524(data_03000E30.entries, i, 0,
                        data_03002818->records[i].x, y, 0, 2,
                        (u32)data_0894EAE0, data_0894EB6C, tile, mode);
            }
            if (data_03002818->flags & 2) {
                if (unit->flags & 0x1c)
                    func_0804C7A0(data_03000E30.entries, 24);
            } else if (data_03002818->selected == i) {
                if (unit->flags & 0x1c) {
                    if (unit_id < 8)
                        tile = unit_id * 20 + 128;
                    else
                        tile = (unit_id - 8) * 20 + 664;
                    func_0804C524(data_03000E30.entries, 24, 0,
                        data_03002818->records[i].x, y, 0, 2,
                        (u32)data_0894EAE0, data_0894EB6C, tile, mode);
                    {
                        u16 active = unit->flags & 4;
                        if (active)
                            func_08001CF0(data_08393ECA,
                                data_03002818->records[i].x, y - 12,
                                0, 0, 0, 0, 0, 0, 10, 0);
                        else if (unit->flags & 0x18)
                            func_08001CF0(data_08393ED2,
                                data_03002818->records[i].x, y - 12,
                                0, 0, 0, 0, 0, 0, 10, 0);
                    }
                } else {
                    func_0804C7A0(data_03000E30.entries, 24);
                }
            }
        } else {
            func_0804C7A0(data_03000E30.entries, i);
        }
    }
    y = data_03002818->base_y - data_03002818->scroll + 44;
    data_03002818->y = y;
    func_0804C788((u8 *)data_03000E30.entries, 25,
                 data_03002818->x, y);
}
