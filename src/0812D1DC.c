#include "ffta.h"

/* Complete target: 0x0812D1DC..0x0812D2F0, 276 bytes. */
extern const s8 g_table_083A8448[];

extern s32 func_080C7EA4(const void *unit, u32 selector);
extern u32 func_0812C56C(void *unit);
extern s32 func_0812C700(s8 x, s8 y, s8 targetX, s8 targetY, s8 direction);
extern u8 func_0812C97C(void *unit, u16 selector, s32 *chance);
extern u8 func_0812D07C(void *unit, u16 entry, u32 selector);
extern u8 func_0812D0BC(const void *unit, s32 selector);
extern s32 func_0812D1B8(void *unit);
extern u8 func_08133A58(void *unit, s32 selector);

s32 func_0812D1DC(void *source, void *unit, u8 x, u8 y,
                   u8 targetX, u8 targetY, u8 direction, s32 selector)
{
    s32 chance;
    s32 index;
    s32 entry;

    if (!func_0812C97C(unit, selector, &chance)) {
        if (!func_08133A58(unit, selector))
            return 0;
        for (index = 0; index < 5; index++) {
            entry = func_080C7EA4(unit, (u8)(index + 0x1D));
            if (entry != 0 && !func_0812D07C(unit, entry, selector))
                return 0;
        }
        if (func_0812D0BC(unit, selector))
            return 0;
        if (!(u8)func_0812C56C(unit))
            return 100;
        chance += func_0812D1B8(source);
        chance += g_table_083A8448[func_0812C700((s8)x, (s8)y,
                            (s8)targetX, (s8)targetY, (s8)direction)];
        if (chance < 0)
            chance = 0;
        if (chance > 99)
            chance = 100;
    }
    return 100 - chance;
}
