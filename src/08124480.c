/* Complete 224-byte target: f0b54f464646c0b4079c0006050e09060e0e1206170e1b061b0e98462406240ea146ff2d12d1084a00238025ed00118d281c0840002810d10133842040001218172bf4dd00240ee0800000022806002805da281cfdf7eefb04e0141c03e0281ca3f774ff041c201cf63006700130077001304146017072f741fc211c75f730f8041c2068011cf631097809060916f73000228256201c75f7a7fc2068011cf6310978f93001702068011cf7310978fa300170201c0121424600f0eaf84846002804d0206b02214942084002e0206b01210843206318bc9846a146f0bc01bc0047 */
#include "ffta.h"

typedef struct {
    u8 unknown_00[0x28];
    u16 flags;
    u8 unknown_2A[0xCC];
    u8 x;
    u8 y;
    u8 facing;
    u8 previousX;
    u8 previousY;
    u8 unknown_FB[0xD];
} SceneRecord;

typedef struct {
    SceneRecord *record;
    u8 unknown_04[0x2C];
    u32 flags;
} SceneObject;

extern SceneRecord g_state_02000080[24];

SceneRecord *func_08121CB4(u8 selector);
SceneRecord *func_080C83CC(u8 selector);
void *func_08096D7C(void);
SceneObject *func_08099560(void *context, SceneRecord *record);
void func_08099E68(void *object, s8 x, s8 y);
void func_08124710(SceneObject *object, u8 update, u8 value);

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

void func_08124480(u8 selector, u8 x, u8 y, u8 facing, u8 enabled)
{
    SceneRecord *record;
    SceneObject *object;

    if (selector == 0xFF) {
        record = findActiveRecord();
    } else if ((s8)selector < 0) {
        record = func_08121CB4(selector);
    } else {
        record = func_080C83CC(selector);
    }
    record->x = x;
    record->y = y;
    record->facing = facing;
    object = func_08099560(func_08096D7C(), record);
    func_08099E68(object, (s8)object->record->x, (s8)object->record->y);
    object->record->previousX = object->record->x;
    object->record->previousY = object->record->y;
    func_08124710(object, 1, facing);
    if (enabled)
        object->flags &= ~1;
    else
        object->flags |= 1;
}
