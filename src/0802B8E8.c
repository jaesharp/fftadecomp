#include "ffta.h"

typedef struct {
    u8 unknown_00[0x94];
    u16 flags;
} MenuState;

typedef struct {
    u8 unknown_0000[0x1FFC];
    u8 setup[0x80];
} DisplayState;

extern MenuState g_state_0200F390;
extern DisplayState *data_0200F440;
extern const u8 data_083BE6B4[];
extern const u8 data_083BEF08[];
extern u8 func_080C9540(u16 bit_index);
extern void func_08141868(const void *source, void *destination, u32 control);
extern void func_0802C72C(void *destination, u16 value, u8 mode);

/* Complete 0x0802B8E8..0x0802B960: 120 bytes. */
void func_0802B8E8(void)
{
    const u8 *source = data_083BE6B4;
    u32 size;

    func_08141868(source, (void *)0x06015C00, 0x210);
    source = data_083BEF08;
    size = 0x180;
    if (func_080C9540(2)) {
        source += size;
        size = 0x280;
    }
    func_08141868(source, (void *)0x06016440, size / 4);
    if ((g_state_0200F390.flags & 2) && data_0200F440 != 0)
        func_0802C72C(data_0200F440->setup, 0x120, 1);
}
