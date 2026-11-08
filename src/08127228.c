/* Complete [0x08127228,0x0812737E): 342 bytes. */
#include "ffta.h"

typedef struct {
    u8 unknown_00[6];
    u8 complete;
} Output08127228;

typedef struct {
    u8 unknown_00[8];
    s16 x;
    u16 unknown_0A;
    s16 y;
} Object08127228;

typedef struct TransitionState {
    u16 first;
    u16 second;
    u16 target_first;
    u16 target_second;
    u16 step_first;
    u16 step_second;
    s16 delta_first;
    s16 delta_second;
    s16 error;
    s16 half_second;
    s16 remaining;
} TransitionState;

typedef struct {
    u16 phase;
    u16 unknown_02;
    Output08127228 *output;
    s32 x;
    s32 y;
    u32 unknown_10;
    u8 selector;
    u8 unknown_15;
    u16 mode;
    u16 value;
} Descriptor08127228;

typedef struct {
    Output08127228 *output;
    Object08127228 *object;
    s16 x;
    s16 y;
    u16 value;
    u8 mode;
    u8 unknown_0F[9];
    TransitionState first;
    TransitionState second;
} Payload08127228;

extern void *func_08125578(u8 selector);
extern void *func_08096D7C(void);
extern void *func_08099560(void *context, void *record);
extern u32 func_08141898(u32 value);
extern s32 func_081426B8(s32 first, s32 second);
extern void func_08007620(TransitionState *state, s16 first, s16 second,
                          s16 target_first, s16 target_second);
extern void func_080076F4(void *state);
extern u32 func_08007894(const void *state);

u32 func_08127228(void *task, Descriptor08127228 *descriptor,
                  Payload08127228 *payload)
{
    switch (descriptor->phase) {
    case 0: {
        void *record;

        payload->output = descriptor->output;
        record = func_08125578(descriptor->selector);
        payload->object = func_08099560(func_08096D7C(), record);
        payload->x = descriptor->x;
        payload->y = descriptor->y;
        payload->mode = descriptor->mode;
        payload->value = descriptor->value;
        break;
    }
    case 0x100: {
        s32 start_x = payload->object->x;
        s32 target_x = start_x + payload->x;
        s32 start_y = payload->object->y;
        s32 target_y = start_y + payload->y;
        u16 duration;

        if (payload->mode == 0) {
            s32 distance_x = target_x - start_x;
            s32 distance_y;
            u32 squared_distance;
            u16 scalar;

            if (start_x > target_x)
                distance_x = start_x - target_x;
            distance_y = target_y - start_y;
            if (start_y > target_y)
                distance_y = start_y - target_y;
            squared_distance = (u32)(distance_x * distance_x) +
                               (u32)(distance_y * distance_y);
            scalar = func_08141898(squared_distance);
            duration = func_081426B8(scalar, payload->value);
        } else {
            duration = payload->value;
        }
        func_08007620(&payload->first, (s16)start_x, 0, (s16)target_x, duration);
        func_08007620(&payload->second, (s16)start_y, 0, (s16)target_y, duration);
        descriptor->phase = 0x101;
        break;
    }
    case 0x101: {
        u32 first_complete;
        u32 second_complete;

        func_080076F4(&payload->first);
        func_080076F4(&payload->second);
        payload->object->x = payload->first.first;
        payload->object->y = payload->second.first;
        first_complete = func_08007894(&payload->first);
        second_complete = func_08007894(&payload->second);
        if (first_complete && second_complete) {
            payload->output->complete = 1;
            descriptor->phase = 3;
        }
        break;
    }
    case 0x103:
        payload->output->complete = 1;
        descriptor->phase = 3;
        break;
    }
    return 0;
}
