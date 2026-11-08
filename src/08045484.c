#include "ffta.h"

typedef struct {
    u8 unknown00[4];
    u8 first;
    u8 second;
} ClassificationObject;

/* 0x08045484, 36 bytes. */
u32 func_08045484(ClassificationObject *object)
{
    if (object->first == 0x60 || object->second == 0x60)
        return 2;
    if (object->first == 0x5F || object->second == 0x5F)
        return 1;
    return 0;
}
