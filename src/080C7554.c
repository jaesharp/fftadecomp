#include "ffta.h"

typedef struct InitializerState InitializerState;

extern void func_080C68EC(InitializerState *state, u32 value);

void func_080C7554(InitializerState *state, u32 value)
{
    func_080C68EC(state, value);
}
