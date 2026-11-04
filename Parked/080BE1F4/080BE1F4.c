#include "ffta.h"

/* Complete target [0x080BE1F4, 0x080BE3B8): 452 bytes, 216 instructions.
 * Target SHA256: 57fddfe36c03884f030f88e080de537f2f8dcbd63a54d0ec4cbc3c330533cdd2.
 */
typedef struct {
    u8 unknown_00[0xf6];
    u8 field_f6;
    u8 field_f7;
} UnitE1F4;

typedef struct {
    UnitE1F4 *unit;
} UnitOwnerE1F4;

typedef struct {
    UnitOwnerE1F4 *owner;
    u8 unknown_04[4];
    u16 identifier;
    u8 unknown_0a[0x1e];
    u8 field_28;
} OwnerE1F4;

typedef struct {
    u16 identifier;
    u8 unknown_02[10];
    u16 value;
    u8 unknown_0e[3];
    u8 flags;
    u8 unknown_12[2];
} RecordE1F4;

typedef struct {
    UnitOwnerE1F4 *owner;
    u8 unknown_04[0x320];
    u16 count;
    u8 unknown_326[2];
} ElementE1F4;

typedef struct {
    u8 unknown_00[0x2908];
    u16 count;
} GroupE1F4;

typedef struct {
    u8 x;
    u8 y;
    u8 unknown_02[2];
} PositionE1F4;

typedef struct {
    UnitE1F4 *context;
    u8 origin_x;
    u8 origin_y;
    u8 x;
    u8 y;
    u16 identifier;
    u16 value;
} RequestE1F4;

extern u8 func_080C48A4(UnitE1F4 *first, UnitE1F4 *second, u16 identifier);
extern s32 func_080B4A1C(RequestE1F4 *request, s8 direction, u8 mode,
                        PositionE1F4 *output);
extern s32 func_080B7EA0(const PositionE1F4 *positions, s32 count, s8 x, s8 y);
extern void func_080BDC98(s32 *grid, u8 column, u8 row);
extern u32 func_080BDD7C(s32 *grid, u8 column, u8 row, u8 first, u8 second,
                        u8 field_01, u16 value, u8 guard, u8 coordinate_guard);

s32 func_080BE1F4(OwnerE1F4 *owner, s32 *grid, GroupE1F4 *group,
                   u8 x, u8 y, u16 value, u8 reverse, PositionE1F4 *positions)
{
    ElementE1F4 *element;
    ElementE1F4 *selected = 0;
    RecordE1F4 *record = 0;
    RecordE1F4 *records;
    RequestE1F4 request;
    u16 result;
    s32 count;
    s32 i;

    element = (ElementE1F4 *)group;
    for (i = 0; i < group->count; i++, element++) {
        if (element->owner->unit->field_f6 == x &&
            element->owner->unit->field_f7 == y) {
            selected = element;
            break;
        }
    }
    if (selected == 0)
        return 0;

    if (!func_080C48A4(owner->owner->unit, selected->owner->unit,
                       owner->identifier))
        return 0;

    request.context = owner->owner->unit;
    request.identifier = owner->identifier;
    request.value = value;
    request.origin_x = selected->owner->unit->field_f6;
    request.origin_y = selected->owner->unit->field_f7;
    request.x = request.origin_x;
    request.y = request.origin_y;
    count = func_080B4A1C(&request, 0, 1, positions);
    if (!func_080B7EA0(positions, count,
                        (s8)selected->owner->unit->field_f6,
                        (s8)selected->owner->unit->field_f7)) {
        positions[count].x = selected->owner->unit->field_f6;
        positions[count].y = selected->owner->unit->field_f7;
        count++;
    }
    if (count <= 0)
        return 0;

    records = (RecordE1F4 *)selected->unknown_04;
    for (i = 0; i < selected->count; i++) {
        if (records[i].identifier == owner->identifier) {
            record = &records[i];
            break;
        }
    }

    result = 0xffff;
    if (record != 0) {
        result = record->value;
        if (record->flags & 1)
            return 0;
        if (owner->field_28)
            result = -result;
        if (reverse == 1)
            result = -result;
    }

    while (count > 0) {
        if ((s16)result < 0)
            func_080BDC98(grid, positions->x, positions->y);
        else
            func_080BDD7C(grid, positions->x, positions->y, 0, 0, 0xff, 1, 0, 0);
        positions++;
        count--;
    }
    return 1;
}
