#include "ffta.h"

typedef struct {
    void *object;
    u8 unknown_04[0x1A];
    u8 palette;
} Subject;

typedef struct {
    Subject *subject;
    u8 duration;
    u8 palette;
    u8 mode;
    u8 percentage;
    u16 colors[16];
} PaletteState;

typedef struct {
    u16 phase;
    u8 unknown_02[6];
    u8 selector;
    u8 unknown_09[11];
    u16 mode;
    u16 percentage;
    u16 duration;
} PaletteCommand;

typedef struct {
    u8 unknown_00;
    u8 palette;
    u8 unknown_02[6];
} PaletteSlot;

typedef struct PaletteTransition PaletteTransition;

extern u32 func_08142B28(u32 dividend, u32 divisor);
extern u16 func_08022238(void *object, u8 *output);
extern PaletteSlot *func_08121C98(u8 index);
extern void *func_08125578(u8 selector);
extern void *func_08096D7C(void);
extern Subject *func_08099560(void *scene, void *object);
extern PaletteTransition *func_081265B8(PaletteState *state);
extern void func_08148600(PaletteTransition *transition);

/* Complete [0x0812682C, 0x08126910), 228 bytes, 100 instructions. */
s32 func_0812682C(void *context, PaletteCommand *command, PaletteState *state)
{
    u8 source;

    switch (command->phase) {
    case 0:
    {
        void *object;

        state->mode = command->mode;
        state->percentage = command->percentage;
        state->duration = command->duration;
        object = func_08125578(command->selector);
        state->subject = func_08099560(func_08096D7C(), object);
        break;
    }
    case 0x100:
    {
        PaletteTransition *transition = func_081265B8(state);

        state->subject->palette = state->palette;
        if (transition)
            func_08148600(transition);
        command->phase = 0x101;
        break;
    }
    case 0x101:
        if (state->duration) {
            state->duration--;
            if (state->duration)
                break;
        }
        if (!(u8)func_08142B28(state->percentage, 100)) {
            u8 previous = state->subject->palette;
            s32 i;

            i = 0;
            do {
                PaletteSlot *slot = func_08121C98(i);

                if (slot->palette && slot->palette == previous) {
                    slot->palette = 0;
                    break;
                }
                i++;
            } while (i <= 6);
        }
        if (state->percentage == 100) {
            func_08022238(state->subject->object, &source);
            state->subject->palette = source;
        }
        command->phase = 0x102;
        break;
    case 0x102:
        command->phase = 3;
        break;
    }
    return 0;
}
