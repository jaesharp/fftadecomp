#include "ffta.h"

typedef struct {
    u8 x;
    u8 unknown_01;
    u8 y;
    u8 unknown_03[5];
    u8 height;
    u8 unknown_09[0x465 - 9];
    u8 initial;
    u8 progress;
} BorderState;

typedef struct {
    u8 unknown_00[0x14];
    u16 *map;
} BorderMap;

typedef struct TransferRecord TransferRecord;
extern BorderState *data_0200F444;
extern BorderMap data_03000990;
extern TransferRecord *func_0802DFCC(void);
extern u16 func_080161A0(u8 x, u8 y, u8 width);
extern void func_08000BAC(TransferRecord *request, u32 first, u32 second,
                         u16 count, u16 field_10, u16 field_12, u16 field_14);

/* Complete [0x0802E008, 0x0802E070): 104 bytes. */
void func_0802E008(void)
{
    TransferRecord *request;
    u16 *destination;

    data_0200F444->initial = data_0200F444->height;
    data_0200F444->progress = 0;
    request = func_0802DFCC();
    destination = data_03000990.map +
        func_080161A0(data_0200F444->x, data_0200F444->y, 32);
    func_08000BAC(request, 0x083C4AA8, (u32)destination, 26, 2, 52, 64);
}
