#include "ffta.h"

extern u8 data_03000000[];

/* Complete [0x08009920, 0x08009964): 68 bytes, 26 instructions. */
void func_08009920(u8 mode)
{
    switch (mode) {
    case 2:
        data_03000000[0x0A] = 25;
        data_03000000[0x0B] = 8;
        break;
    case 1:
        data_03000000[0x0A] = 15;
        data_03000000[0x0B] = 4;
        break;
    case 0:
    default:
        data_03000000[0x0A] = 10;
        data_03000000[0x0B] = 2;
        break;
    }
}
