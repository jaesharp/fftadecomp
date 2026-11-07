#include "ffta.h"

/* 0x08142124: complete 36-byte leading-FF budget scan. */
typedef struct {
    u32 unknown_00;
    u32 budget;
} ScanBudget08142124;

extern const ScanBudget08142124 *data_0200F370;

u32 func_08142124(const u8 *bytes)
{
    u32 remaining = data_0200F370->budget;

    while (remaining != 0 && *bytes++ == 0xFF)
        remaining--;
    return remaining;
}
