#include "ffta.h"

typedef struct {
    u8 unknown_00[0xC];
    u8 width;
    u8 unknown_0D[7];
    u16 *tiles;
} TileGrid0812B258;

extern u8 data_02003CB0[];
extern TileGrid0812B258 data_03000990;
extern const u8 data_083C5024[];
extern u8 data_06015800[];
extern const u8 data_083C52A8[];
extern u8 data_06009C00[];
extern const u16 data_083C4D38[];
extern u8 data_03003B00[];
extern u32 func_0800543C(void *destination, const void *source);
extern void func_0814186C(const void *source, void *destination, u32 control);
extern void func_0802B4A8(TileGrid0812B258 *grid, u8 x, u8 y,
                          const u16 *source, u8 width, u8 height);
extern u8 *func_080CBABC(u32 index);
extern u8 *func_080CBA84(u32 index);

/* Complete target: 0x0812B258..0x0812B2EC, 148 bytes. */
void func_0812B258(void)
{
    u8 *buffer = data_02003CB0;
    TileGrid0812B258 *grid;
    u8 width;
    u8 *palette;
    const u8 *source;

    func_0800543C(buffer, data_083C5024);
    func_0814186C(buffer, data_06015800, 0x580);
    func_0800543C(buffer, data_083C52A8);
    func_0814186C(buffer, data_06009C00, 0x340);
    grid = &data_03000990;
    width = grid->width;
    grid->width = 32;
    func_0802B4A8(grid, 1, 1, data_083C4D38, 22, 17);
    grid->width = width;
    source = func_080CBABC(24);
    palette = data_03003B00;
    func_0814186C(source, palette, 16);
    func_0814186C(func_080CBA84(11), palette + 0x80, 16);
}
