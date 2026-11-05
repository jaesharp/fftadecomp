#include "ffta.h"

typedef struct {
    u8 unknown_00[6];
    u8 complete;
} Control08127A1C;

typedef struct {
    u8 unknown_00[0xA];
    s16 coordinate;
} Target08127A1C;

typedef struct {
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
    u16 state;
    u8 unknown_02[2];
    Control08127A1C *control;
    u32 offset;
    u8 unknown_0C[8];
    u8 selector;
    u8 unknown_15;
    u16 fixed;
    u16 duration;
} Descriptor08127A1C;

typedef struct {
    Control08127A1C *control;
    Target08127A1C *target;
    s16 offset;
    u8 unknown_0A[2];
    u16 duration;
    u8 fixed;
    u8 unknown_0F[9];
    TransitionState transition;
} Work08127A1C;

extern void *func_08125578(u8 selector);
extern void *func_08096D7C(void);
extern Target08127A1C *func_08099560(void *scene, void *record);
extern u32 func_08141898(u32 value);
extern s32 func_081426B8(s32 value, s32 divisor);
extern void func_08007620(TransitionState *state, s16 first, s16 second,
                          s16 target_first, s16 target_second);
extern void func_080076F4(TransitionState *state);
extern u32 func_08007894(const void *state);

/* Complete 08127A1C..08127AF6: 218 bytes, 95 reached instructions. */
s32 func_08127A1C(void *context, Descriptor08127A1C *descriptor,
                  Work08127A1C *work)
{
    switch (descriptor->state) {
    case 0: {
        void *record;
        work->control = descriptor->control;
        record = func_08125578(descriptor->selector);
        work->target = func_08099560(func_08096D7C(), record);
        work->offset = descriptor->offset;
        work->fixed = descriptor->fixed;
        work->duration = descriptor->duration;
        break;
    }
    case 0x100: {
        s32 first = work->target->coordinate;
        s32 last = first + work->offset;
        u16 step;

        if (work->fixed == 0) {
            s32 distance = last - first;
            if (first > last)
                distance = first - last;
            step = func_081426B8((u16)func_08141898(distance * distance),
                                work->duration);
        } else {
            step = work->duration;
        }
        func_08007620(&work->transition, first, 0, (s16)last, (s16)step);
        descriptor->state = 0x101;
        break;
    }
    case 0x101:
        func_080076F4(&work->transition);
        work->target->coordinate = work->transition.first;
        if (!func_08007894(&work->transition))
            break;
    case 0x103:
        work->control->complete = 1;
        descriptor->state = 3;
        break;
    }
    return 0;
}
