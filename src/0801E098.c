#include "ffta.h"

typedef struct {
    u8 unknown_00[4];
    u8 field_04;
    u8 unknown_05;
    u16 field_06;
    u16 field_08;
    u16 field_0A;
    u16 field_0C;
    u16 field_0E;
} State0801E098;

extern State0801E098 g_state_02007F40;
extern u16 data_0836DA94[];
extern u16 data_0836DA9C[];
extern u16 data_0836DA8C[];

/* Target 0801E098..0801E0DC: 68 bytes.
 * HEX: 0006000e0b4a10710b4940004118098811810a49411809885181094940180088d0801089f038401090815089a0384010d0817047407f000294da36089cda36088cda3608
 */
void func_0801E098(u8 index)
{
    g_state_02007F40.field_04 = index;
    g_state_02007F40.field_08 = data_0836DA94[index];
    g_state_02007F40.field_0A = data_0836DA9C[index];
    g_state_02007F40.field_06 = data_0836DA8C[index];
    g_state_02007F40.field_0C = (g_state_02007F40.field_08 - 240) >> 1;
    g_state_02007F40.field_0E = (g_state_02007F40.field_0A - 160) >> 1;
}
