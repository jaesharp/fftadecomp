#include "ffta.h"

/* 0x0812D99C..0x0812DA0A: 110 bytes. */
typedef struct {
    u32 name;
    u8 unknown_04[12];
} UnitTemplate;

typedef struct {
    u8 unknown_00[0x18];
    u16 health;
    u16 maximum_health;
} Unit;

extern UnitTemplate data_02002E78[];
extern u8 func_080C82B8(Unit *unit);
extern u8 func_080C8260(Unit *unit);
extern u8 func_0812C960(Unit *unit);

static inline u8 has_free_template(const UnitTemplate *templates)
{
    s32 i;

    for (i = 0; i < 20; i++) {
        if (templates[i].name == 0)
            return 1;
    }
    return 0;
}

s32 func_0812D99C(Unit *unit, u16 count)
{
    UnitTemplate *templates = data_02002E78;

    if (func_080C82B8(unit) || func_080C8260(unit) || func_0812C960(unit))
        return 0;
    if (count <= 1)
        return 0;
    if (!has_free_template(templates))
        return 0;
    return (unit->maximum_health - unit->health) * 100
           / unit->maximum_health >> 2;
}
