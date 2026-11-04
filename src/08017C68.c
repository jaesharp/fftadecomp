#include "ffta.h"

/* Target 0x08017C68..0x08017D18, 176 bytes, 79 instructions.
 * 30b5041c206800284cd0217c022008400d1c00283ed004202840002816d0a089411ca1810849a27c51180004000c097888422fd3501c0021a0740006000e022800d9a174a18125e074d636080820284000280dd0054aa07c411ca1740006000e8018002141562089401a0de044d636080e4aa07c411ca1740006000e8018007800060016218940182081a07c30212af117ffa07401202840002803d02168201c2af19efa30bc01bc0047000044d63608
 */
typedef struct Object17C68 Object17C68;
struct Object17C68 {
    void (*callback)(Object17C68 *);
    u32 unknown_04;
    u16 field_08;
    u16 unknown_0a;
    u16 field_0c;
    u16 unknown_0e;
    u8 flags;
    u8 unknown_11;
    u8 index;
};

extern const s8 data_0836D644[];
extern const u8 data_0836D674[];

void func_08017C68(Object17C68 *object)
{
    u8 bits;
    u32 flags;
    u32 update;

    if (!object->callback)
        return;
    bits = object->flags;
    update = bits & 2;
    flags = bits;
    if (update) {
        if (flags & 4) {
            if (object->field_0c++ >= data_0836D674[object->index]) {
                if (++object->index > 2)
                    object->index = 0;
                object->field_0c = 0;
            }
        } else {
            if (flags & 8)
                object->field_08 -= data_0836D644[object->index++];
            else
                object->field_08 += data_0836D644[object->index++];
            object->index %= 48U;
        }
    }
    if (flags & 1)
        object->callback(object);
}
