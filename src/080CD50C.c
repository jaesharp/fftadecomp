#include "ffta.h"

typedef struct {
    u8 unknown_00[6];
    u8 job;
    u8 unknown_07[0x34];
    u8 selected;
} Unit;

typedef struct {
    u8 unknown_00[4];
    u8 value;
    u8 unknown_05[3];
} SelectionInfo;

extern const SelectionInfo *const g_table_0851BA84[];

/* Complete target 080CD50C..080CD542, 54 bytes.
 * 00b5002803d0011c3b31097800e0002100290dd081793b300278044889000918d20008688018007903e0000084ba5108002002bc0847
 */
u8 func_080CD50C(Unit *unit)
{
    u8 selected;
    u8 value;

    if (unit)
        selected = unit->selected;
    else
        selected = 0;

    if (selected) {
        u32 job = unit->job;
        u32 selection = unit->selected;
        u32 base = (u32)g_table_0851BA84;
        u32 row_address = base + job * sizeof(const SelectionInfo *);
        u32 record_offset = selection * sizeof(SelectionInfo);
        const SelectionInfo *info = *(const SelectionInfo *const *)row_address;
        value = ((const SelectionInfo *)((u32)info + record_offset))->value;
    } else {
        value = 0;
    }
    return value;
}
