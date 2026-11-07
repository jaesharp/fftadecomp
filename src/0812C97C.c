#include "ffta.h"

typedef struct {
    u8 unknown_00[0x28];
    u16 flags;
} FlaggedObject;

extern u32 func_080C92F0(void *object, u32 selector);
extern u8 func_080C82B8(const FlaggedObject *object);
extern u8 func_080C8194(const void *object, u8 category);
extern u8 func_080C9540(u16 bitIndex);
extern u8 func_0812C960(void *object);

/* 0x0812C97C: 488 bytes, including constants and the selection table. */
u8 func_0812C97C(void *object, u16 selection, u32 *value)
{
    *value = func_080C92F0(object, 0x16) & 0x7F;

    if (func_080C82B8(object)) {
        switch (selection) {
        case 0x2C:
        case 0x2E:
        case 0x32:
            *value = 100;
            return 1;
        }
    }

    if (selection == 0x2C) {
        if (func_080C8194(object, 4) && func_080C9540(602)) {
            *value = 100;
            return 1;
        }
        if (func_080C8194(object, 12) && func_080C9540(603)) {
            *value = 100;
            return 1;
        }
    }

    if (func_0812C960(object)) {
        switch (selection) {
        case 4:
        case 5:
        case 6:
        case 12:
        case 18:
        case 19:
        case 22:
        case 24:
        case 27:
        case 41:
        case 42:
        case 44:
        case 46:
        case 50:
        case 56:
        case 61:
        case 71:
        case 80:
            *value = 100;
            return 1;
        }
    }

    return 0;
}
