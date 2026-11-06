/* 0x08099544, 28 bytes. Find an object through the list callback. */
#include "ffta.h"

typedef struct ObjectContext08099544 ObjectContext08099544;
typedef struct SceneObject08099544 SceneObject08099544;

typedef s32 (*ObjectCallback08099544)(SceneObject08099544 *object,
                                     SceneObject08099544 **result);

extern s32 func_0809AB3C(SceneObject08099544 *object,
                         SceneObject08099544 **result);
extern void func_08099840(ObjectContext08099544 *context,
                          ObjectCallback08099544 callback,
                          SceneObject08099544 **result);

SceneObject08099544 *func_08099544(ObjectContext08099544 *context)
{
    SceneObject08099544 *result = 0;

    func_08099840(context, func_0809AB3C, &result);
    return result;
}
