#include "ffta.h"

typedef struct {
    u8 unknown_00[0x28];
    u16 flags;
    u8 unknown_2A[0xDE];
} SceneRecord;

typedef struct {
    u32 unknown_00;
    SceneRecord *record;
} Binding;

typedef struct {
    u8 unknown_00[0x4D8];
    Binding bindings[256];
} BindingState;

typedef union {
    struct {
        u8 unknown_0000[0x3CA6];
        u16 current_record;
    } selection;
    struct {
        u8 unknown_0000[0x2EBC];
        SceneRecord records[0];
    } bank;
} SceneState;

extern BindingState *data_020159CC;
extern SceneState g_state_02000000;

static inline Binding *find_binding(u8 selector)
{
    if (data_020159CC == 0)
        return 0;
    return &data_020159CC->bindings[selector];
}

static inline SceneRecord *record_at(u16 index)
{
    return &g_state_02000000.bank.records[index];
}

/* Complete [0x08121CB4, 0x08121D0A): 86 bytes. */
SceneRecord *func_08121CB4(u8 selector)
{
    Binding *binding = find_binding(selector);
    if (binding == 0 && g_state_02000000.selection.current_record != 0)
        return record_at(g_state_02000000.selection.current_record);
    return binding->record;
}
