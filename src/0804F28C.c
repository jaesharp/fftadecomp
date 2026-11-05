#include "ffta.h"

/* Complete target 0x0804F28C..0x0804F370, 228 bytes, 94 instructions.
 * Actual addressed unsigned runtime calls and the observed halfword BIOS
 * fill source. Interfaces assert transport only, not effects or bounds. */
typedef struct {
    u8 unknown_00[4];
    u8 value;
} Value0804F28C;

typedef struct {
    Value0804F28C *input;
    u8 unknown_04[4];
    u8 mode;
} Display0804F28C;

extern u8 data_02003CB0[];
extern const u8 data_083A9CA4[];
extern u8 data_06012780[];
extern u32 func_08005318(const void *resource, void *destination,
                        u16 first, u16 count);
extern u32 func_08142AB0(u32 value, u32 divisor);
extern u32 func_08142B28(u32 value, u32 divisor);
extern void func_0814186C(const void *source, void *destination, u32 control);

static inline void copy_digit(const u8 *tiles, u8 digit, u8 *destination)
{
    func_0814186C(tiles + 0x240 + (digit << 6), destination, 0x20);
}

void func_0804F28C(Display0804F28C *display)
{
    u8 *tiles = data_02003CB0;
    u8 *destination;
    u8 value;
    u32 maximum;
    u8 tens;
    u16 blank;

    if ((u8)(display->mode - 4) > 1)
        return;
    func_08005318(data_083A9CA4, tiles, 0, 0);
    maximum = display->mode == 4 ? 64 : 20;
    destination = data_06012780;
    value = display->input->value;
    tens = (u8)func_08142AB0(value, 10);
    if (tens != 0) {
        copy_digit(tiles, tens, destination);
    } else {
        blank = 0;
        func_0814186C(&blank, destination, 0x01000020);
    }
    destination += 0x40;
    copy_digit(tiles, (u8)func_08142B28(value, 10), destination);
    destination += 0x40;
    func_0814186C(tiles + 0x7E0, destination, 0x10);
    destination += 0x20;
    copy_digit(tiles, (u8)func_08142AB0(maximum, 10), destination);
    destination += 0x40;
    copy_digit(tiles, (u8)func_08142B28(maximum, 10), destination);
}
