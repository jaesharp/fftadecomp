/* Complete 174-byte target: f0b5474680b41f1c069b98460006030e1c1c1206120e0d06002d01da002038801006061c002e02da002041460880ff2b12d1084a00238024e400118d201c0840002810d10133842040001218172bf4dd00240ee0800000021806002805da181cfcf7eefe04e0141c03e0201ca3f774fa041c71f749ff211c74f738fb021c2816002805db400110300823d15e401a38803016002806db400110300c23d15e401a4146088008bc9846f0bc01bc0047 */
#include "ffta.h"

typedef struct {
    u8 unknown_00[0x28];
    u16 flags;
    u8 unknown_2A[0xDE];
} SceneRecord;

typedef struct {
    u32 unknown_00[2];
    s16 x;
    u16 unknown_0A;
    s16 y;
} SceneObject;

SceneRecord *func_08121CB4(u8 selector);
SceneRecord *func_080C83CC(u8 selector);
void *func_08096D7C(void);
SceneObject *func_08099560(void *context, SceneRecord *record);

extern SceneRecord g_state_02000080[24];

static inline SceneRecord *findActiveRecord(void)
{
    SceneRecord *record = g_state_02000080;
    s32 index;

    for (index = 0; index < 24; index++, record++) {
        if (record->flags & 0x400)
            return record;
    }
    return 0;
}

void func_08124E74(u8 selector, s8 x, s8 y, s16 *out_x, s16 *out_y)
{
    SceneRecord *record;
    SceneObject *object;

    if (x < 0)
        *out_x = 0;
    if (y < 0)
        *out_y = 0;
    if (selector == 0xFF) {
        record = findActiveRecord();
    } else if ((s8)selector < 0) {
        record = func_08121CB4(selector);
    } else {
        record = func_080C83CC(selector);
    }
    object = func_08099560(func_08096D7C(), record);
    if (x >= 0) {
        s32 position = x * 32 + 16;

        position -= object->x;
        *out_x = position;
    }
    if (y >= 0) {
        s32 position = y * 32 + 16;

        position -= object->y;
        *out_y = position;
    }
}
