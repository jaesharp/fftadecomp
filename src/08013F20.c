#include "ffta.h"

extern u8 func_08013BEC(u8);
extern u16 func_08013C20(u8);
extern u8 func_0801439C(u8);
extern void (*data_0836D4BC)(void *, const void *, u32);
extern const u8 data_020078B0[];

u16 func_08013F20(u8 *destination, const u8 *source)
{
    u16 length = 0;

    while (*source != 0xFF) {
        if ((s8)*source < 0) {
            *destination++ = 0x40;
            switch (*source) {
            case 0x88:
            case 0x89:
            case 0x8A:
            case 0x8B:
            case 0x8C:
            case 0x8D:
            case 0x8E:
            case 0x8F:
            case 0x90:
            case 0x91:
            case 0x95:
                *destination++ = func_0801439C(*source++);
                length += 2;
                break;
            case 0x80:
                if (func_08013BEC(source[1])) {
                    u16 count = func_08013C20(source[1]);

                    destination--;
                    if (count != 0)
                        data_0836D4BC(destination, data_020078B0, count);
                    destination += count;
                    source += 2;
                    length += count;
                    break;
                }
            case 0x81:
            case 0x82:
            case 0x86:
            case 0x87:
            case 0x93:
            case 0x94:
            case 0x96:
                *destination++ = func_0801439C(*source++);
                *destination++ = *source++;
                length += 3;
                break;
            case 0x83:
                *destination++ = func_0801439C(*source++);
                *destination++ = 0x4C;
                *destination++ = *source++;
                length += 4;
                break;
            case 0x84:
                *destination++ = func_0801439C(*source++);
                *destination++ = 0x52;
                *destination++ = *source++;
                length += 4;
                break;
            }
        } else {
            *destination++ = 0x80;
            *destination++ = *source++;
            length += 2;
        }
    }
    *destination = 0;
    return ++length;
}
