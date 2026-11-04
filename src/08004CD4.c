#include "ffta.h"

typedef struct {
    u8 flags;
    u8 unknown_01[8];
    u8 field_09;
} SerialState08004CD4;

typedef struct {
    u8 unknown_00[6];
    u16 interrupt_mask;
} InterruptState08004CD4;

extern SerialState08004CD4 data_030028A0;
extern u8 data_03002884;
extern u8 data_03002B60;
extern u8 data_03002B44;
extern InterruptState08004CD4 data_03000EA0;
extern u16 data_03000E50;
extern u16 data_04000200;
extern u16 data_04000128;
extern u16 data_04000134;
extern void func_08003398(void);

/* Complete target [0x08004CD4, 0x08004D68): 148 bytes, 42 instructions. */
void func_08004CD4(void)
{
    u16 mask;

    data_030028A0.field_09 = 0;
    data_03002884 = 0;
    data_03002B60 = 0;
    data_03002B44 = 0;
    *(u32 *)0x0400010C = 0;
    mask = data_03000EA0.interrupt_mask & 0xFF3F;
    data_03000EA0.interrupt_mask = mask;
    data_03000E50 = mask;
    data_04000200 = mask;
    data_04000128 = 0;
    if (data_030028A0.flags & 8)
        data_04000134 = 0x8055;
    else
        data_04000134 = 0x8022;
    *(u16 *)0x0400012A = 0;
    func_08003398();
}
