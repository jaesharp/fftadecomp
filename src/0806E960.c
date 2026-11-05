#include "ffta.h"

typedef struct __attribute__((packed)) {
    u8 unknown_00[0x2FC2];
    unsigned mode : 2;
} ModeState;

typedef struct {
    const u8 *data;
    u32 unknown_04;
} PaletteRecord;

extern u8 data_02003CB0[];
extern const u8 data_083B4214[], data_083A9CA4[], data_083D3D64[], data_083AEEA4[];
extern u8 data_06009800[], data_0600A1C0[], data_0600A4C0[];
extern u8 data_0600A5C0[], data_0600A6A0[], data_0600A7A0[];
extern u8 data_0600A8E0[], data_0600A8A0[], data_06015800[];
extern u8 data_0600A920[], data_06015A80[], data_0600E680[];
extern const PaletteRecord data_08393E78[];
extern ModeState g_state_02000000;
extern u16 data_03003980[];
/* Ordinary call views follow the complete saved incoming entries. */
extern u32 func_0800543C(u8 *output, const u8 *source);
extern void func_0814186C(const void *source, void *destination, u32 control);
extern s32 func_08005318(const void *source, u8 *output, u16 first, u16 count);
extern u32 func_08018524(u8 *buffer, u16 tile, u8 variant);
extern void func_08070260(const u16 *source, u16 *destination, u8 divisor, u8 multiplier);

/* Complete owner: 424 bytes, 145 reached instructions. */
void func_0806E960(void)
{
    u8 *buffer = data_02003CB0;
    u16 *palette;
    const u8 *palette_source;

    func_0800543C(buffer, data_083B4214);
    func_0814186C(buffer + 0xD40, data_06009800, 0x4E0);
    func_0814186C(buffer + 0xA40, data_0600A1C0, 0x180);
    func_0814186C(buffer + 0x1880, data_0600A4C0, 0x80);
    func_0814186C(buffer + 0x1980, data_0600A5C0, 0x70);
    func_0814186C(buffer + 0x1A60, data_0600A6A0, 0x80);
    func_0814186C(buffer + 0x1B60, data_0600A7A0, 0x80);
    func_0814186C(buffer + 0x1700, data_0600A8E0, 0x20);
    func_08005318(data_083A9CA4, buffer, 0, 0);
    func_0814186C(buffer + 0x800, data_0600A8A0, 0x20);
    func_0814186C(buffer + 0x240, data_06015800, 0x140);
    func_08005318(data_083D3D64, buffer, 0, 0);
    func_0814186C(buffer + 0x1280, data_0600A920, 0x40);
    func_0800543C(buffer, data_083AEEA4);
    func_0814186C(buffer + 0x220, data_06015A80, 0x60);
    func_08018524(buffer, 0x340, 5);
    func_08018524(buffer, 0x346, 6);
    func_08018524(buffer, 0x34C, 2);
    func_0800543C(buffer, data_083AEEA4);
    func_0814186C(buffer + 0x9A0, data_0600E680, 0x20);
    palette_source = data_08393E78[g_state_02000000.mode].data + 0x120;
    palette = data_03003980;
    func_0814186C(palette_source, palette, 0x10);
    func_08070260(palette + 0x40, palette - 0x20, 0x40, 0x28);
    func_08070260(palette + 0x50, palette - 0x10, 0x40, 0x28);
}
