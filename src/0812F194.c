#include "ffta.h"

/* 0x0812F194 .. 0x0812F1AC: 24 bytes. */
typedef struct {
    u16 first;
    u16 second;
} ValuePair0812F194;

extern const ValuePair0812F194 data_083A84A4[];

void func_0812F194(u8 selection, u16 *first, u16 *second)
{
    const ValuePair0812F194 *table = data_083A84A4;
    const ValuePair0812F194 *pair = &table[selection];

    *first = pair->first;
    *second = pair->second;
}
