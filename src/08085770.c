#include "ffta.h"

typedef struct {
    u8 unknown_000[0x95e];
    u8 unknown_95e_0 : 1;
    u8 enabled : 1;
    u8 unknown_95e_2 : 6;
    u8 unknown_95f[0x13ad];
    void *unit;
} State08085770;

extern State08085770 *data_03002818;
extern const u8 *g_table_08526680[];
extern u8 data_0600B4E0[];
extern u32 func_080C8570(u8 first, u8 second, u8 field);
extern u16 func_0801539C(void *context, u8 *tiles, const u8 *text,
                         u8 mode, u8 width);
extern u8 func_080CD2C4(void *unit, u8 index);
extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete target [0x08085770, 0x08085820), 176 bytes. */
void func_08085770(u32 selection, s32 mode)
{
    u32 index = (u8)selection;
    u32 text_index = func_080C8570(index, index, 0);
    const u8 *text = g_table_08526680[text_index];
    u16 zero;
    u16 *source = &zero;
    u8 *tiles;
    *source = 0;
    tiles = data_0600B4E0;
    func_0814186C(source, tiles, 0x01000160);
    func_0801539C((u8 *)data_03002818 + 0x68c, tiles, text, mode == 0, 12);
    if (func_080CD2C4(data_03002818->unit, index))
        data_03002818->enabled = 1;
    else
        data_03002818->enabled = 0;
}
