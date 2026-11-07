#include "ffta.h"

extern s32 func_080CA7A4(u16 entry, u8 selector);
extern void func_08141520(u16 sound);

/* Complete [0x080A7EC4, 0x080A7FC4): 256 bytes including switch tables. */
void func_080A7EC4(u16 entry)
{
    s32 category;

    if (entry == 0)
        category = -1;
    else
        category = func_080CA7A4(entry, 3);

    switch (category) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
        func_08141520(0x7B);
        break;
    case 8:
    case 15:
        func_08141520(0x7C);
        break;
    case 10:
    case 11:
    case 12:
        func_08141520(0x7D);
        break;
    case 13:
    case 14:
        func_08141520(0x8A);
        break;
    case 16:
        switch (entry) {
        case 206:
        case 207:
        case 209:
            func_08141520(0x83);
            break;
        case 208:
        case 211:
            func_08141520(0x84);
            break;
        case 203:
            func_08141520(0x82);
            break;
        default:
            func_08141520(0x81);
            break;
        }
        break;
    default:
        func_08141520(0x7E);
        break;
    case 19:
        break;
    }
}
