#include "ffta.h"

extern const u8 data_08528A44[];
extern const u8 data_08528AA4[];
extern const u8 data_08528B04[];
extern const u8 data_08528B64[];
extern const u8 data_08528BC4[];

/* Complete target: [0x080CCCF0, 0x080CCD4E), 94 bytes.
 * Target bytes: 00b50006000e0238042825d88000024940180068874600000ccd0c0820cd0c0828cd0c0830cd0c0838cd0c0840cd0c08004812e0448a520800480ee0a48a520800480ae0048b5208004806e0648b5208004802e0c48b5208002002bc0847
 */
const u8 *func_080CCCF0(u8 selector)
{
    switch (selector) {
    case 2:
        return data_08528A44;
    case 3:
        return data_08528AA4;
    case 4:
        return data_08528B04;
    case 5:
        return data_08528B64;
    case 6:
        return data_08528BC4;
    default:
        return 0;
    }
}
