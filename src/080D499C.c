#include "ffta.h"

extern u16 g_control_flags_03000940[];

/* Complete 080D499C..080D49FC: 96 bytes including the shadow-state literal. */
s16 func_080D499C(u8 background, u8 coordinate)
{
    s16 offsets[4][2] = {
        {g_control_flags_03000940[5], g_control_flags_03000940[6]},
        {g_control_flags_03000940[7], g_control_flags_03000940[8]},
        {g_control_flags_03000940[9], g_control_flags_03000940[10]},
        {g_control_flags_03000940[11], g_control_flags_03000940[12]}
    };

    return offsets[background][coordinate];
}
