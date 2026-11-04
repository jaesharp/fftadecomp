#include "ffta.h"

extern s32 func_081426B8(s32 numerator, s32 denominator);

/* Complete target [0x0813F19C, 0x0813F1D8), 60 bytes, 29 instructions.
 * 10b50004040c0904080c1204120c1b04190c91420dd20004001424042414001b4843111c03f07afa241824042414201c01e00004001410bc02bc0847 */
s32 func_0813F19C(s16 first, s16 second, u16 duration, u16 elapsed)
{
    if (elapsed < duration)
        return (s16)(first + func_081426B8((second - first) * elapsed, duration));
    return second;
}
