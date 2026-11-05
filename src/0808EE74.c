#include "ffta.h"

extern u8 data_02003CB0[];
extern u8 data_06000020[];
extern const u8 data_08393FC0[];
extern void func_080CB9E0(void *object, u32 value);
extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete target: 0808EE74..0808EEB4, 64 bytes including literals. */
void func_0808EE74(void)
{
    u8 *buffer = data_02003CB0;
    u8 *destination = data_06000020;
    s32 count = 42;
    s32 index = 0;

    do {
        func_080CB9E0(buffer, data_08393FC0[index]);
        func_0814186C(buffer, destination, 0x80);
        destination += 0x100;
        index++;
    } while (index < count);
}
