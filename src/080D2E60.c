#include "ffta.h"

extern void func_080CFCD0(u8 initialize);

/* 080D2E60: complete 12-byte wrapper. */
void func_080D2E60(void)
{
    func_080CFCD0(1);
}
