#include "ffta.h"

typedef struct {
    u8 field_00, field_01, field_02, field_03;
    u8 unknown_04[8];
} Entry08030088;

typedef struct {
    u8 unknown_00 : 5;
    u8 flag_20 : 1;
    u8 flag_40 : 1;
    u8 unknown_07 : 1;
    u8 unknown_01[5];
    u16 field_06;
    u16 field_08;
    u8 unknown_0a[2];
    u16 field_0c;
    u8 unknown_0e[2];
    u8 field_10;
    u8 unknown_11[0xb0 - 0x11];
    Entry08030088 entries[30];
    u8 unknown_218[0x3aa - 0x218];
    u8 field_3aa;
    u8 field_3ab;
} Data08030088;

typedef struct {
    Data08030088 *first;
    Data08030088 *second;
    u8 unknown_008[0x67c - 8];
    const void *table_67c;
    const void *table_680;
} State08030088;

extern State08030088 *g_state_03002810;
extern Data08030088 g_state_02002C10;
extern const u8 data_08391E40[];
extern const u8 data_083931B0[];
extern u32 func_08030044(u32 index, u32 value_03, u8 value_01);
extern void func_08043F64(void);
extern void func_08043F90(void);
extern void func_080D2E24(void);
extern void func_080D2E60(void);
extern void func_08035E04(void);

/* Complete target [0x08030088, 0x08030168), 224 bytes. */
void func_08030088(u32 mode)
{
    State08030088 *initial = g_state_03002810;
    Data08030088 *data = &g_state_02002C10;
    int i;

    initial->first = data;
    initial->second = data;
    initial->table_67c = data_08391E40;
    initial->table_680 = data_083931B0;
    data->flag_20 = 0;
    g_state_03002810->second->flag_40 = 0;
    if (mode == 0) {
        State08030088 *current;
        g_state_03002810->second->field_10 = 40;
        current = g_state_03002810;
        current->second->field_06 = 120;
        current->second->field_08 = 216;
        current->second->field_0c = 156;
        func_08043F64();
        data->field_3aa = 1;
        data->field_3ab = 1;
        for (i = 0; i < 30; i++) {
            g_state_03002810->first->entries[i].field_01 = 0;
            g_state_03002810->first->entries[i].field_00 = 0;
            g_state_03002810->first->entries[i].field_03 = 0;
            g_state_03002810->first->entries[i].field_02 = 0;
        }
        func_08030044(7, 19, 1);
        func_08030044(1, 17, 1);
        func_08043F90();
        func_080D2E24();
        func_080D2E60();
        func_08035E04();
    }
}
