#include "ffta.h"

typedef struct {
    u32 field_00 : 5;
    u32 field_05 : 5;
    u32 field_0A : 5;
    u32 field_0F : 5;
    u32 field_14 : 5;
    u32 field_19 : 5;
    u32 field_1E : 5;
    u32 field_23 : 5;
    u32 field_28 : 5;
    u32 unknown_2D : 11;
} __attribute__((packed)) Record080CC3C8;

extern const Record080CC3C8 data_08528C24[];

/* Complete [0x080CC3C8, 0x080CC50E): 326 bytes including literal words. */
u32 func_080CC3C8(u8 selector, u8 index)
{
    switch (selector) {
    case 0:
    case 1:
        return data_08528C24[index].field_00;
    case 2:
    case 3:
    case 4:
        return data_08528C24[index].field_05;
    case 5:
    case 6:
        return data_08528C24[index].field_0A;
    case 7:
    case 8:
    case 9:
        return data_08528C24[index].field_0F;
    case 10:
    case 11:
        return data_08528C24[index].field_14;
    case 12:
    case 13:
        return data_08528C24[index].field_19;
    case 14:
    case 15:
        return data_08528C24[index].field_1E;
    case 16:
    case 17:
        return data_08528C24[index].field_23;
    case 18:
    case 19:
        return data_08528C24[index].field_28;
    default:
        return 0;
    }
}
