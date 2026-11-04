#include "ffta.h"

typedef struct SceneRecord08092440 {
    u8 unknown_00[0x28];
    u16 flags;
    u8 unknown_2A[0xCC];
    u8 x;
    u8 y;
    u8 z;
} SceneRecord08092440;

typedef struct SceneObject08092440 {
    SceneRecord08092440 *record;
    u8 unknown_04[0x1A];
    u8 palette;
    u8 unknown_1F[0x15];
    u16 value;
    u8 unknown_36[0xA];
    void *resource;
    u8 unknown_44[0x10];
    void *first;
    void *second;
    u8 unknown_5C[0x24];
    void *source;
} SceneObject08092440;

extern SceneObject08092440 *func_08099560(void *, SceneRecord08092440 *);
extern u8 func_080C8298(const SceneRecord08092440 *);
extern u8 func_080CDCEC(const void *);
extern u8 func_080C8240(void *);
extern SceneObject08092440 *func_0809716C(void *, SceneRecord08092440 *);
extern SceneObject08092440 *func_08099714(void *, SceneRecord08092440 *);
extern SceneObject08092440 *func_080996CC(void *, SceneRecord08092440 *);
extern void func_0809A0F4(SceneObject08092440 *);
extern u16 func_08022238(void *, u8 *);
extern void func_08099E68(void *, s8, s8);
extern void func_0809836C(void *, u16, s8, u16);
extern void func_08021DF8(void *, u16, u16);

/* Complete target [0x08092440, 0x080924F2): 178 bytes. */
SceneObject08092440 *func_08092440(void *context, SceneRecord08092440 *record)
{
    u8 palette = 0;
    u16 value;
    SceneObject08092440 *object = func_08099560(context, record);

    if (object != 0)
        return object;

    if (func_080C8298(record) || func_080CDCEC(record))
        object = func_0809716C(context, record);
    else if (func_080C8240(record))
        object = func_08099714(context, record);
    else
        object = func_080996CC(context, record);
    func_0809A0F4(object);
    value = func_08022238(record, &palette);
    object->palette = palette;
    object->value = value;
    func_08099E68(object, (s8)object->record->x, (s8)object->record->y);
    func_0809836C(object, 10, (s8)object->record->z, 0);
    func_08021DF8(object->resource, 0, 2);
    return object;
}
