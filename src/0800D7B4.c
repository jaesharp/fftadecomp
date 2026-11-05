#include "ffta.h"

typedef struct {
    s16 value_00;
    u8 value_02, value_03, value_04, value_05, value_06, value_07;
    u32 value_08, value_0C;
    u8 value_10, value_11, value_12, value_13;
    u32 value_14, value_18;
} ResourceEntry0800D7B4;

typedef struct Object0800C614 Object0800C614;
extern ResourceEntry0800D7B4 *func_0800C614(const Object0800C614 *object);

/* Complete [0x0800D7B4, 0x0800D884): 208 bytes, 69 instructions. */
s32 func_0800D7B4(const Object0800C614 *object, u8 mode, u8 index, u8 field)
{
    s32 value = 0;
    ResourceEntry0800D7B4 *entry = 0;

    switch (mode) {
    case 0:
        entry = func_0800C614(object);
        break;
    case 1:
        entry = func_0800C614(object) + index;
        break;
    case 2:
        entry = func_0800C614(object) + index;
        break;
    }
    switch (field) {
    case 0: value = entry->value_00; break;
    case 1: value = entry->value_02; break;
    case 2: value = entry->value_03; break;
    case 3: value = entry->value_04; break;
    case 4: value = entry->value_06; break;
    case 5: value = entry->value_07; break;
    case 6: value = entry->value_05; break;
    case 7: value = entry->value_08; break;
    case 8: value = entry->value_0C; break;
    case 9: value = entry->value_10; break;
    case 10: value = entry->value_12; break;
    case 11: value = entry->value_13; break;
    case 12: value = entry->value_11; break;
    case 13: value = entry->value_14; break;
    case 14: value = entry->value_18; break;
    }
    return value;
}
