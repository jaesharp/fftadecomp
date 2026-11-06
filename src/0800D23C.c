#include "ffta.h"

struct Object0800C614;
extern void *func_0800C614(const struct Object0800C614 *object);

typedef struct {
    u8 field_00;
    u8 field_01;
    u8 field_02;
    u8 field_03;
    s32 field_04;
    s32 field_08;
} Channel0800D23C;

typedef struct {
    u16 value;
    u8 start;
    u8 end;
    Channel0800D23C channels[2];
} Record0800D23C;

/* Actual root uses a 28-byte record stride and repeats the same member widths
 * at offsets4..15 and16..27. Published 0800D664 and0800D73C corroborate the
 * stride and range bytes2/3. Complete 0800C614 consumes an object pointer and
 * returns its data pointer or zero. This local view asserts no data capacity,
 * nonnull result, initialization, helper effects or historical nominal type.
 * Source compatibility requires suitable record storage for an actual store.
 */
void func_0800D23C(const struct Object0800C614 *object, u8 kind, u8 index,
                   u8 field, s32 value)
{
    Record0800D23C *record = 0;

    switch (kind) {
    case 0:
        record = func_0800C614(object);
        break;
    case 1:
        record = (Record0800D23C *)func_0800C614(object) + index;
        break;
    case 2:
        record = (Record0800D23C *)func_0800C614(object) + index;
        break;
    }

    switch (field) {
    case 0:
        record->value = value;
        break;
    case 1:
        if (value < 0)
            value = 0;
        else if (value > 159)
            value = 159;
        record->start = value;
        break;
    case 2:
        if (value < 0)
            value = 0;
        else if (value > 159)
            value = 159;
        record->end = value;
        break;
    case 3:
        record->channels[0].field_00 = value;
        break;
    case 4:
        record->channels[0].field_02 = value;
        break;
    case 5:
        record->channels[0].field_03 = value;
        break;
    case 6:
        record->channels[0].field_01 = value;
        break;
    case 7:
        record->channels[0].field_04 = value;
        break;
    case 8:
        record->channels[0].field_08 = value;
        break;
    case 9:
        record->channels[1].field_00 = value;
        break;
    case 10:
        record->channels[1].field_02 = value;
        break;
    case 11:
        record->channels[1].field_03 = value;
        break;
    case 12:
        record->channels[1].field_01 = value;
        break;
    case 13:
        record->channels[1].field_04 = value;
        break;
    case 14:
        record->channels[1].field_08 = value;
        break;
    }
}
