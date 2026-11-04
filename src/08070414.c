/* Complete target [0x08070414, 0x08070604), 496 bytes including pools. */
#include "ffta.h"

typedef struct {
    u8 unknown_000[0x43A];
    u8 mode;
    u8 unknown_43B[0x44C - 0x43B];
    u8 phase;
    u8 unknown_44D[2];
    u8 saved_phase;
    u8 unknown_450[0x95E - 0x450];
    u8 active : 1;
    u8 other_flags : 7;
    u8 unknown_95F[0xC1E - 0x95F];
    u8 enabled;
    u8 unknown_C1F[0x2C38 - 0xC1F];
    u8 saved_control[0x50];
} Context;

typedef struct {
    u8 unknown_00[4];
    void *entries;
} SharedResource;

extern Context *data_03002818;
extern u8 g_control_flags_03000940[];
extern u8 data_030027A4;
extern SharedResource data_03000E30;
extern Table data_03002730, data_03000880;
extern u32 data_03000910[];
extern u8 data_03000EC0[];
extern void *func_081443FC(void *, const void *, u32);
extern void func_0807109C(u32);
extern void func_08089C4C(void);
extern void func_08087160(void);
extern void func_08087300(void);
extern void func_0804C834(void *, s32);
extern void func_080712D0(void);
extern void func_080C95C0(u16, u32);
extern void func_08006A7C(Table *, u32 *, u8 *, u8);
extern void func_08073704(u8, u8 *);
extern void func_08071374(void);
extern void func_0807411C(u8, u8 *);
extern void func_080888B4(u8, u8 *);
extern void func_08087FB8(u8, u8 *);
extern void func_08087F0C(u8, u8 *);
extern void func_0808B288(u8, u8 *);
extern void func_08089C84(void);
extern void func_080891BC(void);
extern void func_080069F4(Table *, u8);
extern void func_08006B5C(Table *);
extern void func_08006B8C(Table *, u8);
extern void func_08071234(u32);
extern void func_08003934(u8);

void func_08070414(u8 index, u8 *phase)
{
    data_03002818->saved_phase = *phase;
    switch (*phase) {
    case 0:
        func_081443FC(data_03002818->saved_control, g_control_flags_03000940, 0x50);
        func_0807109C(0);
        data_03002818->active = 0;
        data_03002818->mode = 3;
        data_030027A4 = 0xFF;
        func_08089C4C();
        func_08087160();
        func_08087300();
        func_0804C834(data_03000E30.entries, 0x40);
        func_080712D0();
        data_03002818->enabled |= 0xFF;
        func_080C95C0(0x33, 6);
        func_08006A7C(&data_03002730, data_03000910, data_03000EC0, 8);
        func_08006ADC(&data_03002730, 0, (u32)func_08073704);
        func_08006ADC(&data_03002730, 1, (u32)func_08071374);
        func_08006ADC(&data_03002730, 2, (u32)func_08071374);
        func_08006ADC(&data_03002730, 3, (u32)func_08071374);
        func_08006ADC(&data_03002730, 4, (u32)func_0807411C);
        func_08006ADC(&data_03002730, 7, (u32)func_08071374);
        func_08006ADC(&data_03002730, 5, (u32)func_080888B4);
        func_08006ADC(&data_03002730, 6, (u32)func_08087FB8);
        func_08006ADC(&data_03000880, 0, (u32)func_08087F0C);
        func_08006ADC(&data_03000880, 1, (u32)func_0808B288);
        func_08089C84();
        func_080891BC();
        data_03002818->phase = 0;
        *phase = 5;
        break;
    case 5:
        func_080069F4(&data_03002730, 8);
        *phase = data_03002818->saved_phase;
        break;
    case 0xFF:
        func_0804C834(data_03000E30.entries, 0x40);
        func_08006B5C(&data_03002730);
        func_08006B8C(&data_03000880, 0);
        func_08006B8C(&data_03000880, 1);
        func_08071234(0);
        func_081443FC(g_control_flags_03000940, data_03002818->saved_control, 0x50);
        func_08089C4C();
        func_08003934(5);
        break;
    }
}
