#include "ffta.h"

typedef struct {
    void *object;
    u8 unknown_04[4];
    s16 x;
    s16 height;
    s16 y;
    s16 value_0E;
    s16 value_10;
    u8 unknown_12[0x0B];
    u8 direction;
} Record0809C6B8;

extern u8 func_0801CC7C(u8, u8);
extern u8 func_0801CC18(u8, u8);
extern u32 func_08002804(void);
extern s32 func_08142950(s32, s32);

static inline s32 height_at(s8 x, s8 y)
{
    if (x < 0 || y < 0 || x > 15 || y > 15 ||
        !func_0801CC7C((u8)x, (u8)y))
        return -1;
    return func_0801CC18((u8)x, (u8)y);
}

/* Complete [0x0809C6B8, 0x0809C8C8): 528 bytes, 252 instructions. */
void func_0809C6B8(u8 selector, Record0809C6B8 *record, u32 value)
{
    s32 x = record->x >> 5;
    s32 height = record->height >> 4;
    s32 y = record->y >> 5;
    s32 first;
    s32 second;

    switch (selector) {
    case 1:
    case 3:
        first = height_at(x, y - 1);
        second = height_at(x, y + 1);
        first -= height;
        second -= height;
        if (first == second || (first >= 0 && second >= 0) ||
            (first < 0 && second < 0)) {
            if ((s16)func_08142950((s16)func_08002804(), 101) <= 50) {
                record->value_10 = value;
                record->direction = 3;
            } else {
                record->value_10 = -value;
                record->direction = 4;
            }
        } else if (first < second) {
            record->value_10 = value;
            record->direction = 3;
        } else {
            record->value_10 = -value;
            record->direction = 4;
        }
        break;
    case 0:
    case 2:
        first = height_at(x - 1, y);
        second = height_at(x + 1, y);
        first -= height;
        second -= height;
        if (first == second || (first >= 0 && second >= 0) ||
            (first < 0 && second < 0)) {
            if ((s16)func_08142950((s16)func_08002804(), 101) <= 50) {
                record->value_0E = value;
                record->direction = 1;
            } else {
                record->value_0E = -value;
                record->direction = 2;
            }
        } else if (first < second) {
            record->value_0E = value;
            record->direction = 1;
        } else {
            record->value_0E = -value;
            record->direction = 2;
        }
        break;
    }
}
