#include "ffta.h"

typedef struct AudioState AudioState;
extern AudioState data_0200F2A0;
extern u8 data_020084D8;
extern void func_08145358(AudioState *state, u16 interval);

/* Complete [0x08141748, 0x08141780): 56 bytes, 18 instructions. */
void func_08141748(u16 interval)
{
    if (data_020084D8 & 1) {
        func_08145358(&data_0200F2A0, interval);
        *(u16 *)0x020084D4 = 0xFFFF;
    }
}
