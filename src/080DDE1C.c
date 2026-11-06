/* Complete target: [0x080DDE1C, 0x080DDF68), 332 bytes. */
#include "ffta.h"

struct Group080DD4A4;
struct Child080DD4A4 {
    u8 unknown_00[0x0c];
    u16 flags;
};

extern s32 func_080CA7A4(u16 entry, u8 selector);
extern struct Child080DD4A4 *func_080DD4A4(struct Group080DD4A4 *, u8);
extern u8 func_080DD580(struct Child080DD4A4 *);

u32 func_080DDE1C(struct Group080DD4A4 *group, u16 entry, u16 flags)
{
    s32 category;
    u32 result = 0;

    if (entry == 0)
        category = -1;
    else
        category = func_080CA7A4(entry, 3);

    if (flags & 1) {
        if ((flags & 0x20) && func_080DD580(func_080DD4A4(group, 0)))
            return result;

        switch ((u32)category) {
        case 13:
        case 14:
            result = 127;
            break;
        case 19:
            result = 128;
            break;
        default:
            if (flags & 0x10) {
                if (func_080DD580(func_080DD4A4(group, 0))) {
                    switch (category) {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 9:
                        result = 123;
                        break;
                    case 8:
                    case 15:
                        result = 124;
                        break;
                    case 10:
                    case 11:
                    case 12:
                        result = 125;
                        break;
                    case 16:
                        switch (entry) {
                        case 206:
                        case 207:
                        case 209:
                            result = 131;
                            break;
                        case 208:
                        case 211:
                            result = 132;
                            break;
                        case 203:
                            result = 130;
                            break;
                        default:
                            result = 129;
                            break;
                        }
                        break;
                    default:
                        result = 126;
                        break;
                    }
                } else {
                    result = category == -1 ? 126 : 347;
                }
            } else if (!(flags & 8)) {
                result = category == -1 ? 126 : 347;
            }
            break;
        }
    }
    return result;
}
