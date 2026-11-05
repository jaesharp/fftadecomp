#include "ffta.h"

typedef struct {
    u8 unknown_00[0x28];
    u16 flags;
    u8 unknown_2A[0xDE];
} SceneRecord;

typedef struct {
    SceneRecord first[24];
    u8 unknown_18C0[0x1684];
    SceneRecord second[12];
} State;

extern State g_state_02000080;
extern SceneRecord *func_080C83CC(u8 category);
extern SceneRecord *func_08121CB4(u8 selector);
extern void *func_08096D7C(void);
extern void *func_08099560(void *object, void *record);

static inline SceneRecord *current_record(void)
{
    SceneRecord *record = g_state_02000080.first;
    s32 index;

    for (index = 0; index < 24; index++, record++) {
        if (record->flags & 0x400)
            return record;
    }
    return 0;
}

/* Complete target: 0x081255C8..0x08125622, 90 bytes. */
void *func_081255C8(u8 selector)
{
    SceneRecord *record;

    if (selector == 0xFF)
        record = current_record();
    else if ((s8)selector < 0)
        record = func_08121CB4(selector);
    else
        record = func_080C83CC(selector);
    return func_08099560(func_08096D7C(), record);
}
