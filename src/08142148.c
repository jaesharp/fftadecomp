#include "ffta.h"

/* Complete [0x08142148,0x08142160), 24 bytes, 9 reached instructions.
 * The indirect call transports the incoming R0 word under ordinary ARM ABI. */
u32 func_08142148(void *argument, u32 (*callback)(void *))
{
    if (callback(argument))
        return 0x8004;
    return 0;
}
