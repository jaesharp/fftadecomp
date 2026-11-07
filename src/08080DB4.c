#include "ffta.h"

typedef struct Unit Unit;
typedef struct {
    u8 unknown_00[0x1CF2];
    s16 first;
    s16 second;
    s16 third;
} DisplayStats;

extern DisplayStats *data_03002818;
extern void func_080CA2E8(Unit *);
extern s32 func_080CA394(Unit *);
extern s32 func_080CA610(Unit *);
extern s32 func_080CA5C4(Unit *);

/* 0x08080DB4: 76 bytes. */
void func_08080DB4(Unit *unit)
{
    func_080CA2E8(unit);
    data_03002818->first = func_080CA394(unit);
    data_03002818->second = func_080CA610(unit);
    data_03002818->third = func_080CA5C4(unit);
}
