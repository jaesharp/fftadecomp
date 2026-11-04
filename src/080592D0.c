#include "ffta.h"

typedef struct {
    u8 *destination;
    u32 value;
    u32 state_value;
} ByteStoreContext;

typedef struct {
    u8 unknown_0000[0x2CA0];
    u8 value;
} State080592D0;

extern State080592D0 *data_0200F428;
extern void func_08141540(u16);

/* Complete 0x080592D0..0x080592F8, 40 bytes including literal pools. */
void func_080592D0(ByteStoreContext *context)
{
    *context->destination = context->value;
    data_0200F428->value = context->state_value;
    func_08141540(0x69);
}
