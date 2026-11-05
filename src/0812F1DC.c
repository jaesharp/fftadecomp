#include "ffta.h"

extern u32 func_08002804(void);
extern s32 func_08142950(s32, s32);

/* Complete 84-byte owner. Signed low-halfword samples are reduced using
 * the addressed signed remainder runtime under the explicit native policy. */
u8 func_0812F1DC(u16 chance)
{
    if (chance == 0)
        return 0;
    if (chance < 100) {
        chance *= 100;
        chance += func_08142950((s16)func_08002804(), 100);
        if (chance < (u16)(func_08142950((s16)func_08002804(), 10000) + 1))
            return 0;
    }
    return 1;
}
