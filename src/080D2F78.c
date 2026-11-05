#include "ffta.h"

extern const u16 data_085295D4[][20];
extern u32 func_08142AB0(u32 value, u32 divisor);
extern u32 func_08002804(void);
extern s32 func_08142950(s32 value, s32 divisor);

/* Complete 080D2F78..080D2FB8: 64 bytes, 27 reached instructions. */
u16 func_080D2F78(u8 value)
{
    u8 row = func_08142AB0(value, 5);

    if (row > 9)
        row = 9;
    return data_085295D4[row][(s16)func_08142950((s16)func_08002804(), 20)];
}
