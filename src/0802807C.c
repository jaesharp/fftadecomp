#include "ffta.h"

typedef struct { u8 bytes[0x20]; } TileRow;
typedef struct { TileRow rows[4][2]; } InterleavedBlock;
typedef struct { TileRow lanes[2][4]; } PlanarBlock;

extern void (*data_0836D4BC)(void *destination, const void *source, u32 size);

/* Complete [0x0802807C,0x080280F4): 120 bytes. */
void func_0802807C(PlanarBlock *destination, const InterleavedBlock *source)
{
    s32 block;
    for (block = 0; block < 2; block++) {
        s32 row;
        for (row = 0; row < 4; row++) {
            data_0836D4BC(&destination->lanes[0][row],
                          &source->rows[row][0], sizeof(TileRow));
            data_0836D4BC(&destination->lanes[1][row],
                          &source->rows[row][1], sizeof(TileRow));
        }
        source++;
        destination++;
    }
}
