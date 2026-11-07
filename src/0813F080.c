/* 0x0813F080, complete 164 bytes. Initialize an object within a region. */
#include "ffta.h"

typedef struct {
    u8 active;
    u8 unknown_01;
    s16 x;
    s16 y;
    u16 unknown_06;
    s32 x_fixed;
    s32 y_fixed;
    const void *definition;
    u16 field_14;
    u16 field_16;
    u8 field_18;
    u8 unknown_19;
    u16 field_1a;
    u16 field_1c;
    u16 field_1e;
} Object;

typedef struct {
    s16 x;
    s16 y;
    s16 width;
    s16 height;
} Region;

extern void func_0813F1D8(Object *object, u8 kind);
extern u16 func_08002804(void);
extern void func_0813E750(Object *object, u8 mode);

void func_0813F080(Object *object, const Region *region,
                   u16 field_16, u16 field_14, u16 field_1a,
                   u8 kind, u8 mode)
{
    object->active = 1;
    func_0813F1D8(object, kind);
    object->x = region->x + (s16)func_08002804() % region->width;
    object->y = region->y + (s16)func_08002804() % region->height;
    object->field_16 = field_16;
    object->field_14 = field_14;
    object->field_1a = field_1a;
    func_0813E750(object, mode);
    object->x_fixed = object->x * 256;
    object->y_fixed = object->y * 256;
}
