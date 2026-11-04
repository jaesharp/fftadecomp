#include "ffta.h"

typedef struct {
    u8 unknown_00[4];
    u16 field_04;
    u16 field_06;
    u8 unknown_08[4];
    u16 field_0C;
    u16 field_0E;
    s16 field_10;
    s16 field_12;
    s16 field_14;
    s16 field_16;
    u16 field_18;
} Record080B7FC8;

extern s32 func_081426B8(s32, s32);

/* Complete [0x080B7FC8, 0x080B8100): 312 bytes, 151 reached instructions.
 * f0b5474680b4041ca089a188401a0004000c8046e089e188401a0004070c1021605e002809d04246100400141023e15e
 * 8af05efb0004060c00e000261221605e002808d0380400141222a15e8af050fb0004050c00e00025300401140a1c0029
 * 00da4a421423e05e824209da002903daa08a40420004060c3004002800dda68a280401140a1c002900da4a421623e05e
 * 824209da002903dae08a40420004050c2804002800dde58a208b002823d041460804021c3b04002a01d1002b36d01114
 * 002900da49421427e05f814200da160c1914002900da49421622a05e814200da1d0c30040014a388c018a08028040014
 * e788c01914e0a288101c203000040a49884213d8e188081c20300004000cdf280cd830040014101aa08028040014081a
 * e080012003e0000000002f01002008bc9846f0bc02bc0847
 */
s32 func_080B7FC8(Record080B7FC8 *record)
{
    u16 difference_x = record->field_0C - record->field_04;
    u16 difference_y = record->field_0E - record->field_06;
    u16 step_x;
    u16 step_y;
    s32 magnitude;

    if (record->field_10 != 0)
        step_x = func_081426B8((s16)difference_x, record->field_10);
    else
        step_x = 0;
    if (record->field_12 != 0)
        step_y = func_081426B8((s16)difference_y, record->field_12);
    else
        step_y = 0;

    magnitude = (s16)step_x;
    if (magnitude < 0)
        magnitude = -magnitude;
    if (magnitude < record->field_14) {
        if ((s16)step_x < 0)
            step_x = -record->field_14;
        if ((s16)step_x > 0)
            step_x = record->field_14;
    }

    magnitude = (s16)step_y;
    if (magnitude < 0)
        magnitude = -magnitude;
    if (magnitude < record->field_16) {
        if ((s16)step_y < 0)
            step_y = -record->field_16;
        if ((s16)step_y > 0)
            step_y = record->field_16;
    }

    if (record->field_18 != 0) {
        if (difference_x == 0 && difference_y == 0)
            return 0;
        magnitude = (s16)difference_x;
        if (magnitude < 0)
            magnitude = -magnitude;
        if (magnitude < record->field_14)
            step_x = difference_x;
        magnitude = (s16)difference_y;
        if (magnitude < 0)
            magnitude = -magnitude;
        if (magnitude < record->field_16)
            step_y = difference_y;
        record->field_04 += (s16)step_x;
        record->field_06 += (s16)step_y;
    } else {
        if ((u16)(record->field_04 + 0x20) > 0x12F)
            return 0;
        if ((u16)(record->field_06 + 0x20) > 0xDF)
            return 0;
        record->field_04 -= (s16)step_x;
        record->field_06 -= (s16)step_y;
    }
    return 1;
}
