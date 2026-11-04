#include "ffta.h"

/* Target [0809920C, 080992E0):
 * 30b581b0051c0806000e6a460232694695f0baff68460178081c0d222ff0a2f92c1c6834207068460178081c0d222ff0
 * 99f92070291c69310120087068460178081c0e222ff08ef9291c6a31087068460178081c0f222ff085f9291c6b310870
 * 68460178081c10222ff07cf9291c6c31087068460178081c11222ff073f9291c6d31087068460178081c12222ff06af9
 * 291c6e31087068460178081c13222ff061f9291c6f31087068460178081c14222ff058f9291c7031087068460178081c
 * 15222ff04ff9291c7131087001b030bc01bc0047
 */

typedef struct Record9920C {
    u8 unknown_00[0x68];
    u8 value_68;
    u8 value_69;
    u8 values_6A[8];
} Record9920C;

void func_0812F194(u8 selection, u16 *first, u16 *second);
u32 func_080C8570(u8 first, u8 second, u8 selector);

void func_0809920C(Record9920C *record, u32 selection)
{
    u16 values[2];

    func_0812F194(selection, &values[0], &values[1]);
    record->value_68 = func_080C8570((u8)values[0], (u8)values[0], 0x0D);
    record->value_68 = func_080C8570((u8)values[0], (u8)values[0], 0x0D);
    record->value_69 = 1;
    record->values_6A[0] = func_080C8570((u8)values[0], (u8)values[0], 0x0E);
    record->values_6A[1] = func_080C8570((u8)values[0], (u8)values[0], 0x0F);
    record->values_6A[2] = func_080C8570((u8)values[0], (u8)values[0], 0x10);
    record->values_6A[3] = func_080C8570((u8)values[0], (u8)values[0], 0x11);
    record->values_6A[4] = func_080C8570((u8)values[0], (u8)values[0], 0x12);
    record->values_6A[5] = func_080C8570((u8)values[0], (u8)values[0], 0x13);
    record->values_6A[6] = func_080C8570((u8)values[0], (u8)values[0], 0x14);
    record->values_6A[7] = func_080C8570((u8)values[0], (u8)values[0], 0x15);
}
