#include "ffta.h"

typedef void (*BufferCopier08022BA4)(void *destination,
                                    const void *source, u32 size);
extern BufferCopier08022BA4 data_0836D4BC[];
extern u8 data_030039A0[];
extern const u8 data_08391414[];
extern u8 data_06009280[];
extern u8 data_06005800[];
extern u8 data_06005000[];
extern u8 *func_080CBABC(u32 index);
extern void func_0801D2B8(void *destination, void *first, void *second,
                        u8 count, u16 index, u8 mode);
extern void func_08022B24(void);

/* Complete target [0x08022BA4, 0x08022C2C): 136 bytes. */
void func_08022BA4(u8 first, u8 second)
{
    u8 *destination = data_030039A0;
    u8 *source = func_080CBABC(4);

    if (first != 0) {
        data_0836D4BC[0](destination + 4,
                          source + data_08391414[first - 1] * 2, 14);
    }
    if (second != 0) {
        data_0836D4BC[0](destination + 0x12,
                          source + data_08391414[second - 1] * 2, 14);
    }
    func_0801D2B8(data_06009280, data_06005800, data_06005000, 10, 0, 3);
    func_08022B24();
}
