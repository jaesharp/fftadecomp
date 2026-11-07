#include "ffta.h"

extern void func_08011B30(u8 kind, u16 entry);
extern void func_0801339C(u16 value);

/* 0x080610F8: 144 bytes, including the 23-entry switch table. */
void func_080610F8(u8 entry)
{
    func_08011B30(4, entry);

    switch (entry) {
    case 0x40:
    case 0x43:
    case 0x44:
    case 0x4C:
    case 0x52:
    case 0x53:
    case 0x55:
    case 0x56:
        func_0801339C(2);
        break;
    default:
        break;
    }
}
