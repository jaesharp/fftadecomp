#include "ffta.h"

extern u32 func_08005BB0(const void *object);

/* Complete [0x080DFEB8, 0x080DFECC): 20 bytes. */
u32 func_080DFEB8(const void *object)
{
    if (func_08005BB0(object) != 0)
        return 1;
    return 0;
}
