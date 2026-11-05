#include "ffta.h"

typedef struct {
    u8 unknown_00[8];
    u16 *large_second;
    u16 *large_first;
    u16 *small_second;
    u16 *small_first;
    u8 buffer[1];
} ResourceState;

extern u8 data_0300284C;
extern ResourceState *data_030027D8;
extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete [0x08137B20, 0x08137B50), 48 bytes. */
void func_08137B20(ResourceState *resource, u8 mode)
{
    u16 zero;

    data_0300284C = mode;
    data_030027D8 = resource;
    {
        u16 *source = &zero;

        *source = 0;
        func_0814186C(source, resource, 0x01001170);
    }
}
