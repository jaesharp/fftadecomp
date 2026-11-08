#include "ffta.h"

extern s32 func_081426B8(s32 numerator, s32 denominator);

s32 func_0813F19C(s16 first, s16 second, u16 duration, u16 elapsed)
{
    if (elapsed >= duration)
        return second;

    first += func_081426B8((second - first) * elapsed, duration);
    return first;
}
