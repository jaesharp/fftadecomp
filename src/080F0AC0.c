#include "ffta.h"

typedef struct {
    s16 current;
    s16 remaining;
    s16 error;
    s16 step;
    s16 period;
    s16 distance;
} Interpolation080F0AC0;

typedef struct {
    u8 unknown_00[8];
    void *objects[4];
    Interpolation080F0AC0 radius;
    Interpolation080F0AC0 angle;
} Orbit080F0AC0;

extern s16 func_08007A60(u8 angle);
extern s32 func_08007A4C(u8 angle);
extern void func_080107D4(void *object, s16 x, s16 y, s16 z);
extern void func_08011058(void *object, s16 order);
extern void func_080E064C(Interpolation080F0AC0 *state);
extern u8 func_080E0690(Interpolation080F0AC0 *state);

u32 func_080F0AC0(Orbit080F0AC0 *state)
{
    s32 x[4];
    s32 y[4];
    s16 depth[4];
    u8 angle = state->angle.current;
    u8 i;
    u8 j;

    for (i = 0; i < 4; i++, angle += 64) {
        x[i] = (-func_08007A60(angle) * state->radius.current) >> 8;
        y[i] = ((s16)func_08007A4C(angle) * state->radius.current) >> 8;
    }
    for (i = 0; i < 4; i++) {
        x[i] += 120;
        y[i] += 56;
        func_080107D4(state->objects[i], x[i], y[i], 0);
        depth[i] = y[i] * 2;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i != j && depth[i] == depth[j])
                depth[i]++;
        }
        func_08011058(state->objects[i], depth[i]);
    }
    if (func_080E0690(&state->radius)) {
        return 1;
    } else {
        func_080E064C(&state->radius);
        func_080E064C(&state->angle);
        return 0;
    }
}
