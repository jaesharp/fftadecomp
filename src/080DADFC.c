#include "ffta.h"

/* 0x080DADFC..0x080DAE24: 40 bytes / 15 instructions. */
struct Object0800C614;

struct TaskData080DADFC {
    u32 unknown_00;
    struct Object0800C614 *object;
};

extern void *func_08005BFC(void *task);
extern void *func_0800C614(const struct Object0800C614 *object);
extern void func_0814186C(const void *source, void *destination, u32 control);

void func_080DADFC(void *task)
{
    u16 zero;
    u16 *fill;
    struct TaskData080DADFC *data = func_08005BFC(task);
    void *destination = func_0800C614(data->object);

    fill = &zero;
    *fill = 0;
    func_0814186C(fill, destination, 0x010000A0);
}
