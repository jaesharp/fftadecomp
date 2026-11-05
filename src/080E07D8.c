#include "ffta.h"

/* 080E07D8: 00b525f7e9f9002801d1002000e0012002bc0847 */
extern u32 func_08005BB0(const void *object);

u32 func_080E07D8(const void *object)
{
    if (func_08005BB0(object) != 0)
        return 1;
    else
        return 0;
}
