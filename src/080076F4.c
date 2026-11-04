#include "ffta.h"

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

/* Complete [0x080076F4, 0x0800777C): 136 bytes, 68 instructions. */
void func_080076F4(TransitionState *state)
{
    if (state->remaining > 0) {
        state->remaining--;
        state->second += state->step_second;
        state->error += state->delta_first;
        while (state->error >= state->delta_second) {
            state->first += state->step_first;
            state->error -= state->delta_second;
        }
        if (state->half_second > 0 && state->error >= state->half_second) {
            state->error -= state->delta_second;
            state->first += state->step_first;
        }
    }
}
