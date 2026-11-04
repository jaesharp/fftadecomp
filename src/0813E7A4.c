#include "ffta.h"

/* Target [0x0813E7A4, 0x0813E8FA), 342 bytes:
 * f0b5474680b4051c0e1c1204170c1b041b0c98461620295ee8684018e860688b002863d0287e00281bd0e88ba98b4208914203d2081c8001111c2de0e98ba88b081a8001490803f065ff0006000ec9f635f9a98a0004001441430912a868401a27e0e88ba98b4208914210d2081c8001111c03f04fff0006000ec9f61ff9a98a0004001441430912a868401a11e0e98ba88b081a8001490803f03cff0006000ec9f60cf9a98a0004001441430912a8684018a860a88b0130a8830004000ce98b884213d9287e012148404042c00f2876c3f6c6ff6c8b640800040014698b04f065f840102418ec830020a88338040012aa681218aa60434618040012e9680918e960131200246b800912a9800427ea5f0221705e0627f15f4018824215dc180400140022b15e884206db0223e85e0423f25e8918884203dd281c2030047005e0291c20310120087000e02c7008bc9846f0bc01bc0047
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
} State0813E7A4;

typedef struct {
    s16 x;
    s16 y;
    s16 width;
    s16 height;
} Bounds0813E7A4;

extern s32 func_081426B8(s32 numerator, s32 denominator);
extern s16 func_08007A60(u8 index);
extern u32 func_08002804(void);
extern s32 func_08142950(s32 value, s32 divisor);

void func_0813E7A4(State0813E7A4 *state, const Bounds0813E7A4 *bounds,
                   u16 delta_x, u16 delta_y)
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
        if (++state->elapsed > state->period) {
            u32 random;
            u16 half_duration;
            state->direction = state->direction != 1;
            random = func_08002804();
            half_duration = state->duration >> 1;
            state->period = half_duration +
                (func_08142950((s16)random, state->duration) >> 1);
            state->elapsed = 0;
        }
    }
    state->fixed_x += (s16)delta_x << 8;
    state->fixed_y += (s16)delta_y << 8;
    state->x = state->fixed_x >> 8;
    state->y = state->fixed_y >> 8;
    if (state->y <= bounds->y + bounds->height) {
        if (state->x < bounds->x || state->x > bounds->x + bounds->width) {
            state->updated = 0;
        } else {
            state->updated = 1;
        }
    } else {
        state->active = 0;
    }
}
