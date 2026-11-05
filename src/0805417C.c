#include "ffta.h"

typedef struct {
    u8 unknown_00[0x18];
    s16 count;
    s16 top;
} ScrollList;

u8 func_0805417C(ScrollList *list, u16 keys)
{
    if (keys == 0x40) {
        if (list->top == 0)
            goto unavailable;
    } else {
        if (keys != 0x80)
            goto unavailable;
        if (list->top + 4 >= list->count)
            goto unavailable;
    }
    return 1;

unavailable:
    return 0;
}
