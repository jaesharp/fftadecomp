#include "ffta.h"

typedef struct {
    u8 unknown_00[0x18];
    u16 *first_plane;
    u16 *second_plane;
    u8 unknown_20[8];
    u8 stride;
    u8 unknown_29[0x23];
} TileRenderer;

typedef struct {
    u8 unknown_0000[0x1cec];
    s16 value_1cec;
    s16 value_1cee;
    s16 value_1cf0;
    u8 unknown_1cf2[6];
    s16 value_1cf8;
    s16 value_1cfa;
    s16 value_1cfc;
    s16 value_1cfe;
    s16 value_1d00;
} ComparisonState;

extern TileRenderer data_030009E0[];
extern ComparisonState *data_03002818;
extern const u16 data_0894F7DC[];
extern void func_08035578(const u16 *source, u16 *destination, u32 count, u16 offset);
extern u32 func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
extern void func_080899AC(u32 position, u8 stride, u32 spacing, u16 value,
                          u32 digits, u32 alignment, u16 tile);
extern s32 func_080CA394(const void *object);
extern s32 func_080CA610(void *object);
extern s32 func_080CA5C4(void *object);
extern s32 func_080CA520(const void *object);
extern s32 func_080CA550(const void *object);
extern s32 func_080CA538(const void *object);
extern s32 func_080CA568(const void *object);
extern s32 func_080CA580(const void *object);

void func_0807614C(void *object)
{
    s16 value;
    u16 tile;

    func_08035578(data_0894F7DC, data_030009E0[3].second_plane, 0xc0, 0xfe);

    value = func_080CA394(object);
    if (data_03002818->value_1cec > value)
        tile = 0xa000;
    else if (data_03002818->value_1cec < value)
        tile = 0x8000;
    else
        tile = 0xd000;
    func_080899AC(func_0808B8E4(3, 1, 6, 1), data_030009E0[3].stride, 100, value, 1, 0, tile);

    value = func_080CA610(object);
    if (data_03002818->value_1cee > value)
        tile = 0xa000;
    else if (data_03002818->value_1cee < value)
        tile = 0x8000;
    else
        tile = 0xd000;
    func_080899AC(func_0808B8E4(0, 1, 6, 9), 0x20, 120, value, 1, 0, tile);

    value = func_080CA5C4(object);
    if (data_03002818->value_1cf0 > value)
        tile = 0xa000;
    else if (data_03002818->value_1cf0 < value)
        tile = 0x8000;
    else
        tile = 0xd000;
    func_080899AC(func_0808B8E4(3, 1, 12, 2), data_030009E0[3].stride, 120, value, 3, 0, tile);

    value = func_080CA520(object);
    if (data_03002818->value_1cf8 > value)
        tile = 0xa000;
    else if (data_03002818->value_1cf8 < value)
        tile = 0x8000;
    else
        tile = 0xd000;
    func_080899AC(func_0808B8E4(3, 1, 11, 4), data_030009E0[3].stride, 120, value, 3, 0, tile);

    value = func_080CA550(object);
    if (data_03002818->value_1cfa > value)
        tile = 0xa000;
    else if (data_03002818->value_1cfa < value)
        tile = 0x8000;
    else
        tile = 0xd000;
    func_080899AC(func_0808B8E4(3, 1, 11, 6), data_030009E0[3].stride, 100, value, 3, 0, tile);

    value = func_080CA538(object);
    if (data_03002818->value_1cfc > value)
        tile = 0xa000;
    else if (data_03002818->value_1cfc < value)
        tile = 0x8000;
    else
        tile = 0xd000;
    func_080899AC(func_0808B8E4(0, 1, 11, 14), 0x20, 120, value, 3, 0, tile);

    value = func_080CA568(object);
    if (data_03002818->value_1cfe > value)
        tile = 0xa000;
    else if (data_03002818->value_1cfe < value)
        tile = 0x8000;
    else
        tile = 0xd000;
    func_080899AC(func_0808B8E4(3, 1, 11, 9), data_030009E0[3].stride, 100, value, 3, 0, tile);

    value = func_080CA580(object);
    if (data_03002818->value_1d00 > value)
        tile = 0xa000;
    else if (data_03002818->value_1d00 < value)
        tile = 0x8000;
    else
        tile = 0xd000;
    func_080899AC(func_0808B8E4(0, 1, 11, 17), 0x20, 120, value, 3, 0, tile);
}
