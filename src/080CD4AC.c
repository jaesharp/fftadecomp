#include "ffta.h"

/* 0x080CD4AC..0x080CD4BE: 18 bytes. */
u8 func_080CD4AC(const u8 *object)
{
    u8 value;

    if (object != 0)
        value = object[0x3b];
    else
        value = 0;
    return value;
}
