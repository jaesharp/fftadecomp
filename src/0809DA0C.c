#include "ffta.h"

/* Complete 694-byte owner, 262 reached instructions.
 * Byte predicate results are observed through the conditional word ABI. */
extern u8 func_080CD8FC(const void *);
extern u32 func_080CDAF4(const void *);
extern u8 func_080CDB0C(const void *);
extern u8 func_080CD8CC(const void *);
extern u8 func_080CD8E4(const void *);
extern u8 func_080CD914(const void *);
extern u8 func_080CDB24(const void *);
extern u8 func_080CD98C(const void *);
extern u8 func_080CDB3C(const void *);
extern u8 func_080CDB6C(const void *);
extern u8 func_080CDB84(const void *);
extern u8 func_080CDB9C(const void *);
extern u8 func_080CDBB4(const void *);
extern u8 func_080CDA94(void *);
extern u8 func_080CE3A8(const void *);
extern u8 func_08131030(u32);
extern u8 func_080CE3A0(const void *);
extern u8 func_080CD9D4(const void *);
extern u8 func_080CD9EC(const void *);
extern u8 func_080CDA04(const void *);
extern u8 func_080CDBCC(const void *);
extern u8 func_080CDA4C(const void *);
extern u8 func_080CDB54(const void *);
extern u8 func_080C8280(const void *);
extern u8 func_080CDCA4(void *);

u32 func_0809DA0C(void *object, u16 selector)
{
    if (selector == 0)
        selector = 1;
    if (selector > 24)
        selector = 1;

    switch (selector) {
    case 1:
        if (func_080CD8FC(object))
            return 1;
        break;
    case 2:
        if ((u8)func_080CDAF4(object))
            return 2;
        break;
    case 3:
        if (func_080CDB0C(object))
            return 3;
        break;
    case 4:
        if (func_080CD8CC(object))
            return 4;
        break;
    case 5:
        if (func_080CD8E4(object))
            return 5;
        break;
    case 6:
        if (func_080CD914(object))
            return 6;
        break;
    case 7:
        if (func_080CDB24(object))
            return 7;
        break;
    case 8:
        if (func_080CD98C(object))
            return 8;
        break;
    case 9:
        if (func_080CDB3C(object))
            return 9;
        break;
    case 10:
        if (func_080CDB6C(object))
            return 10;
        break;
    case 11:
        if (func_080CDB84(object))
            return 11;
        break;
    case 12:
        if (func_080CDB9C(object))
            return 12;
        break;
    case 13:
        if (func_080CDBB4(object))
            return 13;
        break;
    case 16:
        if ((func_080CDA94(object) && func_080CE3A8(object) == 1) ||
            (func_08131030((u32)object) && func_080CE3A0(object) == 1))
            return 16;
        break;
    case 15:
        if ((func_080CDA94(object) && func_080CE3A8(object) == 2) ||
            (func_08131030((u32)object) && func_080CE3A0(object) == 2))
            return 15;
        break;
    case 14:
        if ((func_080CDA94(object) && func_080CE3A8(object) == 3) ||
            (func_08131030((u32)object) && func_080CE3A0(object) == 3))
            return 14;
        break;
    case 17:
        if (func_080CD9D4(object))
            return 17;
        break;
    case 18:
        if (func_080CD9EC(object))
            return 18;
        break;
    case 19:
        if (func_080CDA04(object))
            return 19;
        break;
    case 20:
        if (func_080CDBCC(object))
            return 20;
        break;
    case 21:
        if (func_080CDA4C(object))
            return 21;
        break;
    case 22:
        if (func_080CDB54(object))
            return 22;
        break;
    case 23:
        if (func_080C8280(object) && !func_08131030((u32)object))
            return 23;
        break;
    case 24:
        if (func_080CDCA4(object))
            return 24;
        break;
    }
    return 0;
}
