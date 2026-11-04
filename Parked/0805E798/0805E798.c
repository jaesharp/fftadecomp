#include "ffta.h"

typedef struct SelectionRecord0805E798 SelectionRecord0805E798;

typedef struct {
    u8 unknown_00[0x16];
    u16 unknown_16;
} Object0805E798;

typedef struct {
    u8 unknown_0000[0x119F];
    u8 unknown_119F;
    u8 unknown_11A0;
    u8 unknown_11A1[8];
    u8 unknown_11A9;
    u8 unknown_11AA[2];
    SelectionRecord0805E798 *unknown_11AC[169];
    void *unknown_1450;
    Object0805E798 *unknown_1454;
} State0805E798;

extern State0805E798 *data_0200F448;
extern u8 g_state_02000000[];
extern u8 data_030008B0[];

extern void func_0805DD64(void);
extern u8 func_08036350(u8 value);
extern u32 func_080D0590(SelectionRecord0805E798 **output,
                         u32 capacity, u32 filter);
extern void func_08029E48(void *graphics, void *source, const u16 *scratch,
                         s16 columns, s16 rows, u8 enabled);
extern void func_0802A2C0(u8 x, u8 y, u8 width, u8 height);
extern void func_0805F44C(u8 id);
extern void func_0805F540(void *const *entries, s32 count);

/* Target [0x0805E798, 0x0805E864), 204 complete bytes:
 * 70b582b0294d286829494018002404702968284a88180068002810d08d267601
 * 8819007800280ad0043288180068002800d0c482fff7cafa2868801904701b4e
 * 34681c482118002008601b4d64191b481b4940180078d7f7affd021c1206120e
 * 201c102171f0c8fe3168164c0919087015481121009101210191002100221423
 * cbf716fb0020002100220023cbf74cfd032000f00ffe3068451900190178281c
 * 00f082fe02b070bc01bc004748f400029f11000050140000ac11000000000002
 * 691f0000a9110000b0080003
 */
void func_0805E798(void)
{
    void *entries;

    data_0200F448->unknown_119F = 0;
    if (data_0200F448->unknown_1450 != 0 &&
        data_0200F448->unknown_11A0 != 0) {
        if (data_0200F448->unknown_1454 != 0)
            data_0200F448->unknown_1454->unknown_16 = 0;
        func_0805DD64();
        data_0200F448->unknown_11A0 = 0;
    }
    data_0200F448->unknown_1450 = 0;
    entries = data_0200F448->unknown_11AC;
    data_0200F448->unknown_11A9 =
        func_080D0590(entries, 16,
                      func_08036350(g_state_02000000[0x1F69]));
    func_08029E48(data_030008B0, 0, 0, 20, 17, 1);
    func_0802A2C0(0, 0, 0, 0);
    func_0805F44C(3);
    entries = data_0200F448->unknown_11AC;
    func_0805F540(entries, data_0200F448->unknown_11A9);
}
