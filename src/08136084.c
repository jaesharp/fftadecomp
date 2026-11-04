#include "ffta.h"

/* Complete [0x08136084, 0x08136538): 1204 bytes, 444 instructions. */
typedef struct {
    u8 phase;
    u8 unknown_01[0x333];
} Effects08136084;

typedef struct {
    u8 unknown_0000[0x8000];
    u16 palettes[2][256];
    u8 scene[0x21C];
    u32 field_861C;
    Effects08136084 effects;
    u8 unknown_8954[6];
    u16 progress;
    u16 duration;
    u8 first;
    u8 second;
    u8 third;
    u8 fourth;
    u8 field_8962;
    u8 unknown_8963;
    u16 delay;
    u8 next_phase;
    u8 result;
    u16 next_duration;
    u8 unknown_896A[0x1E];
    u8 field_8988;
    u8 unknown_8989[2];
    u8 field_898B;
    u8 unknown_898C;
    u8 field_898D;
} Context08136084;

typedef struct {
    u8 unknown_00[0x4C];
    u8 first;
    u8 second;
} Controls08136084;

typedef struct {
    u8 unknown_00[2];
    u8 field_02;
    u8 field_03;
    u8 field_04;
    u8 field_05;
    u8 unknown_06[2];
    u32 *words;
    u8 *flags;
} Runner08136084;

typedef struct PaletteTransition PaletteTransition;
typedef void (*Clear08136084)(void *, u32);
extern Context08136084 *data_0200F3B0;
extern Runner08136084 data_0200F3A0;
extern u8 g_state_0200F390;
extern u8 data_0300280C;
extern Controls08136084 g_control_flags_03000940;
extern Clear08136084 g_callbacks_0836D4B8[];
extern void *func_08137AEC(u32);
extern u8 func_08137B14(void);
extern void func_08135B40(void);
extern void func_08135E88(void);
extern PaletteTransition *func_08147D2C(u16, u16, u16, const u16 *);
extern void func_081369EC(PaletteTransition *);
extern u32 func_08136538(void *);
extern void func_081457FC(void);
extern void func_08135984(void);
extern void func_08135D6C(void);
extern u16 func_0814180C(void);
extern void func_081416DC(u16);
extern u32 func_08136DEC(void);
extern u32 func_08137040(void);
extern u8 func_0813BCE4(void);
extern void func_08136A10(u8 *);
/* The two effects helpers receive the same observed 0x8620 object view. */
extern void func_081379C8(Effects08136084 *);
extern void func_081371DC(Effects08136084 *);
extern void func_08148540(void);
extern PaletteTransition *func_08147A7C(u16, u16, u16);
extern void func_08148600(PaletteTransition *);
extern void func_08141748(u16);
extern void func_081379F0(u16, u16, u8, u8, u8, u8);
extern void func_08137B00(u8 *);
extern void func_08137AD0(void);
extern void func_08006B9C(Runner08136084 *);

void func_08136084(void *task, u8 *phase)
{
    switch (*phase) {
    case 0:
        data_0200F3B0 = func_08137AEC(0x899C);
        g_callbacks_0836D4B8[0](data_0200F3B0, 0x899C);
        if (func_08137B14() == 2 || data_0300280C == 1)
            *phase = 3;
        else
            *phase = 1;
        data_0200F3B0->effects.phase = 0;
        break;
    case 1:
        func_08135B40();
        func_08135E88();
        func_081369EC(func_08147D2C(0, 256, 10, data_0200F3B0->palettes[0]));
        func_081369EC(func_08147D2C(256, 256, 10, data_0200F3B0->palettes[1]));
        *phase = 9;
        data_0200F3B0->next_phase = 2;
        data_0200F3B0->delay = 40;
        data_0200F3B0->field_8988 = 0;
        break;
    case 2:
        if ((u8)func_08136538(data_0200F3B0->scene))
            *phase = 3;
        break;
    case 3:
        func_081457FC();
        func_08135984();
        func_08135D6C();
        {
            Context08136084 *context = data_0200F3B0;
            context->field_898D = 0;
            context->field_898B = 0;
        }
        if (!(u8)func_0814180C() || func_08137B14() == 2)
            func_081416DC(42);
        func_081369EC(func_08147D2C(0, 256, 10, data_0200F3B0->palettes[0]));
        func_081369EC(func_08147D2C(256, 128, 10, data_0200F3B0->palettes[1]));
        *phase = 9;
        data_0200F3B0->next_phase = 5;
        data_0200F3B0->delay = 40;
        break;
    case 5:
        data_0200F3B0->effects.unknown_01[0] = 1;
        if (data_0200F3B0->effects.phase == 0)
            data_0200F3B0->effects.phase = 1;
        if (!(u8)func_0814180C()) {
            *phase = 10;
            data_0200F3B0->next_duration = 20;
            data_0200F3B0->result = 5;
            break;
        }
        if ((u8)func_08136DEC()) {
            data_0200F3B0->field_861C = 0;
            *phase = 6;
        }
        break;
    case 6:
        if ((u8)func_08137040()) {
            *phase = 7;
            if (func_0813BCE4())
                data_0200F3B0->field_8962 = 1;
        }
        break;
    case 7:
        if (!(u8)func_0814180C()) {
            *phase = 10;
            data_0200F3B0->next_duration = 20;
            data_0200F3B0->result = 5;
            break;
        }
        func_08136A10(phase);
        break;
    case 10:
        data_0200F3B0->effects.phase = 3;
        func_081379C8(&data_0200F3B0->effects);
        func_08148540();
        func_08148600(func_08147A7C(0, 512, data_0200F3B0->next_duration));
        func_08141748(5);
        data_0200F3B0->delay = data_0200F3B0->next_duration;
        *phase = 9;
        data_0200F3B0->next_phase = 0xFF;
        break;
    case 11:
        data_0200F3B0->effects.phase = 3;
        func_081379C8(&data_0200F3B0->effects);
        func_08148540();
        func_08148600(func_08147A7C(0, 512, data_0200F3B0->next_duration));
        func_08141748(5);
        data_0200F3B0->duration = data_0200F3B0->next_duration;
        data_0200F3B0->progress = 0;
        *phase = 8;
        data_0200F3B0->next_phase = 0xFF;
        data_0200F3B0->first = g_control_flags_03000940.first;
        data_0200F3B0->second = g_control_flags_03000940.second;
        data_0200F3B0->third = 0;
        data_0200F3B0->fourth = 0;
        break;
    case 8:
        func_081379F0(data_0200F3B0->duration, data_0200F3B0->progress,
                       data_0200F3B0->first, data_0200F3B0->second,
                       data_0200F3B0->third, data_0200F3B0->fourth);
        if (data_0200F3B0->progress >= data_0200F3B0->duration)
            *phase = data_0200F3B0->next_phase;
        else
            data_0200F3B0->progress++;
        break;
    case 9:
        if (data_0200F3B0->delay == 0)
            *phase = data_0200F3B0->next_phase;
        else
            data_0200F3B0->delay--;
        break;
    case 0xFF:
        g_state_0200F390 = data_0200F3B0->result;
        func_08137B00((u8 *)data_0200F3B0);
        func_08137AD0();
        func_08006B9C(&data_0200F3A0);
        break;
    }
    func_081371DC(&data_0200F3B0->effects);
}
