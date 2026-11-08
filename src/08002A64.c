#include "ffta.h"

/* Target [0x08002A64, 0x08002A76), complete 18 bytes:
 * 00b50006002801da002000e0012002bc0847
 */
s32 func_08002A64(s8 value)
{
    if (value >= 0)
        return 1;
    return 0;
}
