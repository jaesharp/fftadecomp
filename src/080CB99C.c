// 0x080CB99C..0x080CB9B0: 16 code bytes and one four-byte literal.
#include "ffta.h"

typedef struct {
    u8 attributes;
    u8 unknown_1;
} __attribute__((packed)) AttributePair;

extern AttributePair g_table_083C7FE4[];

u8 func_080CB99C(u16 index)
{
    return g_table_083C7FE4[index + 2].attributes >> 4;
}
