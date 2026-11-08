#include "ffta.h"

/* 08009728..0800975C: 52 bytes. */
struct ControlState {
    u16 flags;
    u8 unknown_02[0x38];
    u8 unknown_3A;
    u8 unknown_3B;
    u8 unknown_3C;
    u8 unknown_3D;
    u8 unknown_3E;
    u8 unknown_3F;
};

extern struct ControlState g_control_flags_03000940;

void func_08009728(void)
{
    g_control_flags_03000940.flags &= ~0x2000;
    g_control_flags_03000940.unknown_3B = 0;
    g_control_flags_03000940.unknown_3F = 0;
    g_control_flags_03000940.unknown_3A = 0;
    g_control_flags_03000940.unknown_3E = 0;
}
