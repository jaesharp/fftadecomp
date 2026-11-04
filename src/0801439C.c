#include "ffta.h"

/* Target [0x0801439C, 0x0801446A): 00b50006000e803816285dd8800002494018006887460000b8430108404401085444010844440108504401085044010864440108484401084c44010814440108184401081c4401082044010824440108284401082c44010830440108344401083844010864440108584401085c4401083c440108604401086e2026e0732024e0632022e0782020e075201ee061201ce070201ae0622018e0772016e06b2014e0792012e0252010e06c200ee074200ce072200ae0662008e0672006e03c2004e03e2002e0212000e0002002bc0847 */
u32 func_0801439C(u8 value)
{
    switch (value) {
    case 0x88: return 0x6E;
    case 0x89: return 0x73;
    case 0x8A: return 0x63;
    case 0x8B: return 0x78;
    case 0x8C: return 0x75;
    case 0x8D: return 0x61;
    case 0x8E: return 0x70;
    case 0x8F: return 0x62;
    case 0x90: return 0x77;
    case 0x91: return 0x6B;
    case 0x95: return 0x79;
    case 0x80: return 0x25;
    case 0x82: return 0x6C;
    case 0x86: return 0x74;
    case 0x87: return 0x72;
    case 0x83:
    case 0x84: return 0x66;
    case 0x81: return 0x67;
    case 0x93: return 0x3C;
    case 0x94: return 0x3E;
    case 0x96: return 0x21;
    default: return 0;
    }
}
