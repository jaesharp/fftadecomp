#include "ffta.h"

/* Target [0x0813E8FC, 0x0813E9F2), 246 bytes:
 * 30b5041c0d1c1621605ee1680918e160608b002857d0207e00281bd0e08ba18b4208914203d2081c8001111c2de0e18ba08b081a8001490803f0c0fe0006000ec9f690f8a18a0004001441430912a068401a27e0e08ba18b4208914210d2081c8001111c03f0aafe0006000ec9f67af8a18a0004001441430912a068401a11e0e18ba08b081a8001490803f097fe0006000ec9f667f8a18a0004001441430912a0684018a060a08b0130a0830004000c638b984207d9207e012148404042c00f20760020a083a06800126080e0680012a080211c2031012008700420225e0221685e0623e95e4018824201dd0020207030bc01bc0047
 */
typedef struct {
    u8 active;
    u8 unknown_01;
    s16 x;
    s16 y;
    u8 unknown_06[2];
    s32 fixed_x;
    s32 fixed_y;
    u8 unknown_10[4];
    u16 amplitude;
    s16 velocity;
    u8 direction;
    u8 unknown_19;
    u16 duration;
    u16 elapsed;
    u16 period;
    u8 updated;
} State0813E8FC;

typedef struct {
    u8 unknown_00[2];
    s16 y;
    u8 unknown_04[2];
    s16 height;
} Bounds0813E8FC;

extern s32 func_081426B8(s32 numerator, s32 denominator);
extern s16 func_08007A60(u8 index);

void func_0813E8FC(State0813E8FC *state, const Bounds0813E8FC *bounds)
{
    state->fixed_y += state->velocity;
    if (state->duration) {
        if (state->direction) {
            if (state->elapsed < (state->period >> 1)) {
                state->fixed_x += (state->amplitude * func_08007A60(func_081426B8(
                    state->elapsed << 6, state->period >> 1))) >> 8;
            } else {
                state->fixed_x -= (state->amplitude * func_08007A60(func_081426B8(
                    (state->period - state->elapsed) << 6, state->period / 2))) >> 8;
            }
        } else {
            if (state->elapsed < (state->period >> 1)) {
                state->fixed_x -= (state->amplitude * func_08007A60(func_081426B8(
                    state->elapsed << 6, state->period >> 1))) >> 8;
            } else {
                state->fixed_x += (state->amplitude * func_08007A60(func_081426B8(
                    (state->period - state->elapsed) << 6, state->period / 2))) >> 8;
            }
        }
        if (++state->elapsed > state->duration) {
            state->direction = state->direction != 1;
            state->elapsed = 0;
        }
    }
    state->x = state->fixed_x >> 8;
    state->y = state->fixed_y >> 8;
    state->updated = 1;
    if (state->y > bounds->y + bounds->height)
        state->active = 0;
}
