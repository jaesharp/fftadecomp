#include "ffta.h"

typedef struct {
    void *object;
    u16 duration;
    u8 palette;
} PaletteParameters080DB774;

typedef struct {
    u16 state;
    u16 unknown_02;
    const PaletteParameters080DB774 *parameters;
    u8 unknown_08[12];
    u16 delay;
} PaletteTask080DB774;

typedef struct {
    void *object;
    u16 duration;
    u8 palette;
    u8 unknown_07;
    u16 delay;
    u16 unknown_0a;
    void *effect;
} PaletteState080DB774;

typedef struct PaletteTransition PaletteTransition;
extern u16 data_03003A60[];
extern u8 func_080DBC18(void *object, u32 value);
extern void func_0814186C(const void *source, void *destination, u32 control);
extern PaletteTransition *func_08147D2C(u16 start, u16 count, u16 duration,
                                       const u16 *source);
extern void *func_081484CC(void *handle);

/* Complete target [0x080DB774, 0x080DB838), 196 bytes. */
u32 func_080DB774(void *context, PaletteTask080DB774 *task,
                  PaletteState080DB774 *state)
{
    switch (task->state) {
    case 0: {
        const PaletteParameters080DB774 *parameters = task->parameters;
        state->object = parameters->object;
        state->duration = parameters->duration;
        state->palette = parameters->palette;
        state->delay = task->delay;
        break;
    }
    case 1:
        break;
    case 0x100:
        if (state->delay != 0) {
            state->delay--;
            if (state->delay != 0)
                break;
        }
        if (state->duration == 0) {
            func_080DBC18(state->object, 15);
            task->state = 2;
        }
        func_0814186C(&data_03003A60[func_080DBC18(state->object,
                                                state->palette) * 16],
                      &data_03003A60[state->palette * 16], 16);
        state->effect = func_08147D2C((u16)(0x101 + (state->palette << 4)),
                                      15, state->duration,
                                      &data_03003A60[0xf1]);
        task->state++;
        break;
    case 0x101:
        state->effect = func_081484CC(state->effect);
        if (state->effect == 0) {
            func_080DBC18(state->object, 15);
            task->state = 2;
        }
        break;
    }
    return 0;
}
