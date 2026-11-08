#include "ffta.h"

typedef struct {
    u8 unknown_00[0x3A];
    u8 value;
} Object080CD498;

/* Complete 080CD498..080CD4AA, 18 bytes. Target:
00b5002802d03a30007800e0002002bc0847 */
u8 func_080CD498(const Object080CD498 *object)
{
    if (object == 0)
        return 0;
    return object->value;
}
