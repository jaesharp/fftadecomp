#include "ffta.h"

extern u8 data_0839A5CC[];
extern const s16 data_0839A5D2[];
s32 func_08007A4C(u8 angle);
s16 func_08007A60(u8 angle);
void func_080107D4(void *object, s16 x, s16 y, s16 z);
void func_080112CC(Vec3 *object, s16 x, s16 y, s16 z);

void func_080F1E20(Vec3 **objects, u8 angle, u8 radius, u8 style)
{
    s32 x[6];
    s32 y[6];
    u8 i;

    for (i = 0; i < 3; i++) {
        x[i] = (-func_08007A60(angle + data_0839A5CC[i]) * radius) >> 8;
        x[i + 3] = -x[i];
        y[i] = ((s16)func_08007A4C(angle + data_0839A5CC[i]) * radius) >> 8;
        y[i + 3] = -y[i];
        x[i] += 120;
        x[i + 3] += 120;
        y[i] += 32;
        y[i + 3] += 32;
    }
    for (i = 0; i < 6; i++) {
        func_080107D4(objects[i], (s16)x[i], (s16)y[i], 0);
        func_080112CC(objects[i], data_0839A5D2[style], data_0839A5D2[style], 0);
    }
}
