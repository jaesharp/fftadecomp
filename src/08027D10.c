#include "ffta.h"

typedef struct State08027D10 {
    u8 unknown_00[4];
    u8 mode;
} State08027D10;

extern State08027D10 *data_0200F438;

/* Complete [0x08027D10, 0x08027DA0), 144 bytes.
 * Target: 00b5002205480068007901380e283cd880000349401800688746000038f40002347d0208707d0208887d02088c7d0208747d0208787d02087c7d02087c7d02087c7d02089a7d0208747d0208807d0208847d0208907d0208947d0208987d0208002212e0012210e002220ee003220ce004220ae0052208e0062206e0072204e0082202e0092200e00a22101c02bc0847
 */
u32 func_08027D10(void)
{
    u32 result = 0;

    switch (data_0200F438->mode) {
    case 1:
        result = 0;
        break;
    case 4:
    case 10:
        result = 1;
        break;
    case 5:
        result = 2;
        break;
    case 6:
    case 7:
    case 8:
        result = 3;
        break;
    case 11:
        result = 4;
        break;
    case 12:
        result = 5;
        break;
    case 2:
        result = 6;
        break;
    case 3:
        result = 7;
        break;
    case 13:
        result = 8;
        break;
    case 14:
        result = 9;
        break;
    case 15:
        result = 10;
        break;
    }
    return result;
}
