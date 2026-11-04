#include "ffta.h"

typedef struct {
    u8 unknown_0000[0x2fc2];
    u8 selection : 2;
    u8 unknown_2fc2 : 6;
} Global08089660;

extern Global08089660 g_state_02000000;
extern u8 *data_03002818;
extern const void *data_08393E78[];
extern void func_0814186C(const void *, void *, u32);

/* Complete [0x08089660, 0x080896C0): 96 bytes, 38 instructions.
 * 70b5464640b412488046124c124aa41820788007c00e40440068104d29682831
 * 80267600321cb8f0f1f820788007400f013080004044006829688a2292008918
 * 321cb8f0e3f808bc984670bc01bc0047783e390800000002c22f000018280003
 */
void func_08089660(void)
{
    func_0814186C(data_08393E78[g_state_02000000.selection * 2],
                  data_03002818 + 0x28, 0x100);
    func_0814186C(data_08393E78[g_state_02000000.selection * 2 + 1],
                  data_03002818 + 0x228, 0x100);
}
