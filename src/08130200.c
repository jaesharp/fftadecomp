#include "ffta.h"

typedef struct ActionState {
    void *source;
    void *target;
    u8 unknown_08[0x1E];
    u16 flags;
} ActionState;

extern ActionState data_0200F3F0;
extern void func_0812F2A4(u16 action, u16 equipment, u8 kind);
extern void func_0812F328(u8 index);
extern void func_0812F34C(u32 value);
extern u8 func_0812F358(void);
extern void func_0812F39C(s32 index);
extern s32 func_0812FE38(void *source, void *target, u16 action,
                       u16 equipment, u16 attribute, u8 mode, u8 extra);
extern u8 func_08130868(void *source, void *target);
extern u8 func_08130FBC(void);
extern s32 func_08131B20(void);

s32 func_08130200(void *source, void *target, u16 action, u16 equipment,
                  u16 attribute, u16 mode)
{
    ActionState *state = &data_0200F3F0;
    s32 result;
    s32 index;
    u16 flags;

    if (action == 0) {
        u8 mode_byte = mode;
        s32 value = func_0812FE38(source, target, 0, equipment, attribute,
                                  mode_byte, 0);
        if (value > 0 && func_08130868(source, target))
            return 0;
        return value;
    }

    func_0812F2A4(action, equipment, 0);
    state->source = source;
    state->target = target;
    flags = state->flags;
    if (mode == 2)
        flags |= 0x10;
    state->flags = flags;

    result = 0;
    for (index = 0; index < 3; index++) {
        func_0812F328((u8)index);
        func_0812F34C(0);
        if (func_08130FBC()) {
            func_0812F39C(index);
            func_0812F34C((u32)target);
            switch (func_0812F358()) {
            case 1:
            case 2:
            case 3:
            case 5:
                return func_08131B20();
            case 4:
            case 6:
            case 7:
                result = func_08131B20();
                break;
            }
        }
    }
    return result;
}
