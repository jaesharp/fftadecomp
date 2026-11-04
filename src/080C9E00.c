#include "ffta.h"

typedef struct {
    u32 value;
    u8 unknown_04[2];
    u8 selector;
    u8 unknown_07[0xFF];
    u8 cleared;
    u8 unknown_107;
} SceneRecord;

typedef struct {
    u8 unknown_00[0x80];
    SceneRecord first[24];
    u8 unknown_1940[0x1684];
    SceneRecord second[12];
} SceneState;

extern u8 g_state_02000000[];
extern const u32 g_table_085680DC[];
u32 func_08002804(void);
s32 func_08142950(s32 numerator, s32 denominator);

/* Complete [0x080C9E00, 0x080C9ED8): 216 bytes. */
void func_080C9E00(void *object)
{
    SceneRecord *record = object;
    u32 value;
    s32 attempts;
    s32 base;
    s32 count;
    s32 index;

    attempts = 3;
    do {
        if (record->selector > 5) {
            base = 500;
            count = 225;
        } else if (record->selector == 4) {
            base = 310;
            count = 190;
        } else {
            base = 0;
            count = 310;
        }
        value = g_table_085680DC[base + func_08142950((s16)func_08002804(), count)];
        for (index = 0; index < 24; index++) {
            if (((SceneState *)g_state_02000000)->first[index].value == value)
                break;
        }
        if (index != 24)
            continue;
        for (index = 0; index < 12; index++) {
            if (((SceneState *)g_state_02000000)->second[index].value == value)
                break;
        }
        if (index == 12)
            break;
    } while (--attempts != -1);
    record->value = value;
    record->cleared = 0;
}
