#include "ffta.h"

typedef struct {
    u8 unknown_00[0x18];
    u16 value_18;
} Object0809C9E8;

typedef struct {
    Object0809C9E8 *object;
    u8 unknown_04[4];
    s16 value_08;
    s16 value_0a;
    s16 value_0c;
    s16 value_0e;
    s16 value_10;
    u8 unknown_12[0xa];
    u8 flags;
    u8 value_1d;
    u8 unknown_1e;
    u8 value_1f;
} Record0809C9E8;

typedef struct {
    Record0809C9E8 *record;
    u32 flag;
} Context0809C9E8;

typedef struct {
    s32 top;
    s32 bottom;
    s32 left;
    s32 right;
} Rectangle0809C9E8;

extern u8 func_080CDADC(const void *object);
extern u8 func_080CDB24(const void *object);
extern u8 func_080CD92C(const void *object);
extern s32 func_0809C8C8(Record0809C9E8 *record, s32 mode);
extern void func_0809C6B8(u8 selector, Record0809C9E8 *record, u32 value);

/* Complete [0x0809C9E8, 0x0809CAF4): 268 bytes, 129 instructions.
 * Target: 70b588b0051c0e1c3068a84279d02968088b002875d0081c31f06cf8000600286fd1286831f08af80006002869d1286830f088ff0006002863d1297f0420084000285ed1687f002801d00120706030680a22815e0a22a85e0c1a002c00da6442281c0121fff73cff00284ad12f2c48dc34680821605e103802900822a05e103003900c21605e103800900c22a05e1030019004aa0821685e103890600821685e1030d0600c21685e103804900c21685e031c103353600299d06881420ada03999068814206dd0098984203da01990498814202dc0020287713e0297f0220084000280ed10e22a85e00280ad11021685e002806d101207060e07f291c0122fff7e7fd012008b070bc02bc0847
 */
s32 func_0809C9E8(Record0809C9E8 *record, Context0809C9E8 *context)
{
    s32 distance;
    Record0809C9E8 *other;
    Rectangle0809C9E8 first;
    Rectangle0809C9E8 second;

    if (context->record == record || !record->object->value_18)
        return 1;
    if (func_080CDADC(record->object) || func_080CDB24(record->object) ||
        func_080CD92C(record->object))
        return 1;
    if (record->flags & 4)
        return 1;
    if (record->value_1d)
        context->flag = 1;

    distance = context->record->value_0a - record->value_0a;
    if (distance < 0)
        distance = -distance;
    if (func_0809C8C8(record, 1) || distance > 47)
        return 1;

    other = context->record;
    first.left = other->value_08 - 16;
    first.right = other->value_08 + 16;
    first.top = other->value_0c - 16;
    first.bottom = other->value_0c + 16;
    second.left = record->value_08 - 16;
    second.right = record->value_08 + 16;
    second.top = record->value_0c - 16;
    second.bottom = record->value_0c + 16;

    if (!(first.left < second.right && first.right > second.left &&
          first.top < second.bottom && first.bottom > second.top)) {
        record->flags = 0;
        return 1;
    }
    if (!(record->flags & 2) && record->value_0e == 0 && record->value_10 == 0) {
        context->flag = 1;
        func_0809C6B8(other->value_1f, record, 1);
    }
    return 1;
}
