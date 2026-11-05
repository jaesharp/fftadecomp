#include "ffta.h"

extern u8 func_080B448C(u16 ability, u16 parameter);
extern s32 func_080CA7A4(u16 entry, u8 selector);
extern u32 func_080CCD50(u16 entry, u8 selector);

static inline s32 category_080B7C94(u16 ability, u16 parameter)
{
    s32 result;

    if (ability == 0) {
        if (parameter == 0) {
            result = 1;
        } else {
            s32 kind = func_080CA7A4(parameter, 3);

            if (kind == 13 || kind == 14 || kind == 19)
                result = 1;
            else
                result = func_080CA7A4(parameter, 5);
        }
    } else {
        u16 properties = func_080CCD50(ability, 4);

        if (properties & 0x80) {
            result = 1;
        } else {
            u32 shape = func_080CCD50(ability, 7);

            if (shape & 0x80)
                result = 16;
            else
                result = shape & 0x3F;
        }
    }
    return result;
}

/* Complete [0x080B7C94, 0x080B7DC8), 308 bytes, 117 instructions. */
u8 func_080B7C94(u16 ability, u16 parameter, s32 mode)
{
    u8 category;

    if (mode == 0) {
        u8 result = func_080B448C(ability, parameter);

        if (result != 0)
            return result;
        category = category_080B7C94(ability, parameter);
        switch (category) {
        case 4:
        case 5:
            return 1;
        case 12:
        case 13:
            return 2;
        case 16:
            return 16;
        default:
            return 0;
        }
    }
    return category_080B7C94(ability, parameter);
}
