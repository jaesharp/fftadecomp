#include "ffta.h"

/* Target [0x081374DC, 0x08137774), 664 bytes:
 * f0b557464e464546e0b488b0051c0906090e079168300078002800d0e7e0291c78310888013008800e39087808802c1c7a34208889467c2149198846002827d00138208020880a210bf000fb0004002807d1281c7e300088424612888018434618802088002813d1184800681849401800f098fa0004000c14210bf0e7fa143042461080291c7e310120088005202080281c71300178071c00291bd0481c3870281c6c300023c05e291c6e310024095f2c1c723422783b78fff70cfa4946088038782478a0426dd300206ae0b0f3000298890000174c2068174a801800f062fa4b461888291c6c3108802e1c703630788a46002822d120680f49401800f052fa0004000c35210bf0a1fa1130291c723108702068084a801800f044fa0004000c1e210bf093fac830291c6e310880012021e00000b0f30002988900002068154bc01800f02ffa0004000c35210bf07efa0a30291c7231087020680e4c001900f021fa0004000c1e210bf070fa2030291c6e310880002030700988534618880a1a002a00da52427f2a0add814204d94018188005e0988900003e49401852461080012038704b461878d0f6ecf92a1c82320004001444460023e15e4843c01114880019108049460878d0f6d2f92a1c84320004001443460024195f4843c011118840181080291c8031098840181080291c823108880004c01520380004000c0e1cb0280cd8281c843000880004c11520204042814203db2c1c7434c0290cdd281c73300021017001300170041c079a002a02d0583800f0ecf82078002822d0281cfef784fc31880904c9152a1c843212881204d2150024009401940294039408235b42049305942b1c76331b78023b06930123caf6f1fb079b002b03d0281c1c3000f07ef808b038bc9846a146aa46f0bc01bc004700ffffff
 */
typedef struct {
    u8 unknown_00[0x68];
    u8 stopped;
    u8 unknown_69;
    u16 angle;
    u16 start;
    u16 end;
    u8 direction;
    u8 elapsed;
    u8 duration;
    u8 active;
    u8 visible;
    u8 unknown_75;
    u8 id;
    u8 unknown_77;
    u16 timer;
    u16 lifetime;
    u16 interval;
    u16 speed;
    u16 offset;
    u16 x;
    u16 y;
} State081374DC;

extern u8 *data_0200F3B0;
extern u16 func_08137A80(void *state);
extern s32 func_081369B0(s32 start, s32 end, u32 duration, u32 elapsed);
extern s16 func_08007A60(u8 index);
extern s32 func_08007A4C(u8 index);
extern void func_081378EC(void *component);
extern void *func_08136028(void *animation);
extern void func_0813785C(void *component);
extern void func_08001F34(const void *source, s32 x, s32 y, u32 variant,
                         u32 flip_x, u32 flip_y, u32 flag_28, u32 flag_29,
                         u32 value, u32 mode, u32 transform);

void func_081374DC(State081374DC *state, u8 enabled)
{
    if (!state->stopped) {
        state->timer++;
        state->angle = (u8)state->angle;
        if (state->lifetime) {
            state->lifetime--;
            if ((u16)(state->lifetime % 10U) == 0)
                state->interval += state->speed;
            if (state->lifetime == 0) {
                state->interval = func_08137A80(data_0200F3B0 + 0x8998) % 20U + 20;
                state->speed = 1;
                state->lifetime = 5;
            }
        }
        if (state->elapsed) {
            state->elapsed++;
            state->angle = func_081369B0((s16)state->start, (s16)state->end,
                                         state->duration, state->elapsed);
            if (state->elapsed >= state->duration)
                state->elapsed = 0;
        } else {
            s32 difference;
            func_08137A80(data_0200F3B0 + 0x8998);
            state->start = state->angle;
            if (!state->direction) {
                state->duration = func_08137A80(data_0200F3B0 + 0x8998) % 53U + 17;
                state->end = func_08137A80(data_0200F3B0 + 0x8998) % 30U + 200;
                state->direction = 1;
            } else {
                state->duration = func_08137A80(data_0200F3B0 + 0x8998) % 53U + 10;
                state->end = func_08137A80(data_0200F3B0 + 0x8998) % 30U + 32;
                state->direction = 0;
            }
            difference = state->end - state->start;
            if (difference < 0)
                difference = -difference;
            if (difference > 127) {
                if (state->end > state->start)
                    state->start += state->end;
                else
                    state->start -= 256;
            }
            state->elapsed = 1;
        }
        state->x += (func_08007A60((u8)state->angle) * (s16)state->interval) >> 7;
        state->y += ((s16)func_08007A4C((u8)state->angle) * (s16)state->interval) >> 7;
        state->y += state->offset;
    }
    if ((u16)(((s16)state->x >> 7) - 32) > 176 ||
        ((s16)state->y >> 7) < -32 || ((s16)state->y >> 7) > 192) {
        state->active = 0;
        state->visible = 0;
        if (enabled)
            func_081378EC((u8 *)state + 0x1C);
    }
    if (state->visible) {
        const void *image = func_08136028(state);
        func_08001F34(image, (s16)state->x >> 7, (s16)state->y >> 7,
                       1, 0, 0, 0, 0, -8, 0, state->id - 2);
        if (enabled)
            func_0813785C((u8 *)state + 0x1C);
    }
}
