#include "ffta.h"

typedef struct {
    u32 value;
    u32 unknown_04;
    u16 current;
    u16 count;
    u16 history[34];
} State080BC3B0;

extern void func_080BC3B0(State080BC3B0 *state, u32 value);

/* Complete [0x080BCA08, 0x080BCA12): 10 bytes. */
void func_080BCA08(State080BC3B0 *state, u32 value)
{
    func_080BC3B0(state, value);
}
