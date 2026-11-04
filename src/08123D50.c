#include "ffta.h"

typedef struct {
    u8 unknown_0000[0x2190];
    u8 field_2190;
} State08123D50;

typedef struct {
    u8 unknown_00[0x94];
    u16 field_94;
} Control08123D50;

extern State08123D50 g_state_02000000;
extern Control08123D50 g_state_0200F390;
extern Table data_03002710;

void func_0800397C(u8 value);
void func_08096BA0(void);
u8 func_080C95A8(u16 index);
void func_080BD11C(u8 value);
void *func_08096D7C(void);
void func_0809AB14(void *object);
void func_081256BC(void);
void func_08024758(void *object);
void func_08121BF4(void);
void func_080231E8(u8 index, u8 *flag);
void func_08096E78(u8 index, u8 *flag);
void func_080D36B0(void *context, u8 *state);
void func_080231F4(u8 index, u8 *flag);
void func_0802326C(void *context, u8 *state);

/* 0x08123D50..0x08123E00: complete 176-byte target.
 * 10b522482249401801780220414048420843c00fdff60afe1e4c221c94321188
 * 80200843108072f713ff3520a5f714fc0006000e99f7caf972f7f8ff76f7c2fe
 * 01f094fc1c34201c00f7defcfdf72aff114c124a201c0421e2f698fe104a201c
 * 0221e2f693fe0f4a201c0521e2f68efe0d4a201c0621e2f689fe0c4a201c0721
 * e2f684fe10bc01bc00470000000000029021000090f3000210270003e9310208
 * 796e0908b1360d08f53102086d320208
 */
void func_08123D50(void)
{
    Control08123D50 *state;
    Table *table;

    func_0800397C(g_state_02000000.field_2190 != 2);
    state = &g_state_0200F390;
    state->field_94 |= 0x80;
    func_08096BA0();
    func_080BD11C(func_080C95A8(0x35));
    func_0809AB14(func_08096D7C());
    func_081256BC();
    func_08024758(state->unknown_00 + 0x1C);
    func_08121BF4();
    table = &data_03002710;
    func_08006ADC(table, 4, (u32)func_080231E8);
    func_08006ADC(table, 2, (u32)func_08096E78);
    func_08006ADC(table, 5, (u32)func_080D36B0);
    func_08006ADC(table, 6, (u32)func_080231F4);
    func_08006ADC(table, 7, (u32)func_0802326C);
}
