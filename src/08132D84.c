#include "ffta.h"

extern u32 func_08002804(void);

/* 0x08132D84..0x08132DDC: complete 88-byte owner. */
void func_08132D84(u32 *values, s32 count, s32 passes)
{
    s32 pass;
    s32 index;

    for (pass = 0; pass < passes; pass++) {
        for (index = 0; index < count; index++) {
            s32 selected = (s16)func_08002804() % count;

            if (selected != index) {
                u32 temporary = values[index];

                values[index] = values[selected];
                values[selected] = temporary;
            }
        }
    }
}
