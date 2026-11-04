#include "ffta.h"

typedef struct {
    u8 unknown_00[4];
    u8 index;
} Object0812B2EC;

typedef void (*CopyBuffer0812B2EC)(void *destination, const void *source,
                                  u32 size);

extern u8 data_02003CB0[];
extern u8 data_06014800[];
extern u8 data_03003B20[];
extern CopyBuffer0812B2EC const data_0836D4BC[];
extern u8 *func_080CB868(u8 *buffer, Object0812B2EC *object);
extern u8 func_080CB7C0(Object0812B2EC *object, u8 selector);
extern void func_080CB8D4(void *object, u8 index);
extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete [0x0812B2EC, 0x0812B340), 84 bytes. */
void func_0812B2EC(Object0812B2EC *object)
{
    u8 *buffer = data_02003CB0;
    u32 size = (u32)func_080CB868(buffer, object);

    func_0814186C(buffer, data_06014800, (size & 0x3FFFFF) >> 1);
    func_080CB8D4(buffer, func_080CB7C0(object, 1));
    data_0836D4BC[0](data_03003B20, buffer, 0x60);
}
