#include "ffta.h"

typedef struct {
    u8 unknown_00[0xFD];
    u8 value_FD;
} Data0809801C;

typedef struct {
    Data0809801C *data;
    u32 unknown_04;
    s16 x;
    s16 height;
    s16 y;
    u8 unknown_0E[0x10];
    u8 value_1E;
    u8 unknown_1F[0x11];
    u32 flags;
    u16 value_34;
} Context0809801C;

typedef struct {
    s32 x : 16;
    s32 height : 16;
    s32 y : 16;
} Position0809801C;

extern u8 func_0801CC7C(u8 column, u8 row);
extern u8 func_0801CD08(u8 column, u8 row);
extern u8 func_0801CC18(u8 column, u8 row);
extern u16 func_08022238(void *object, u8 *output);
extern u16 func_08022268(void *object, u8 *output);

/* Complete [0x0809801C, 0x0809812E): 274 bytes.
 * Target: f0b5474680b481b0051c286b802149020840002801d0286867e068890004001500041649194001432889000440150004000c134a904646460e400643b0464346a889000440150004000c2240141c04432868011cfd310f78011c022f0bd118040214002a07db20040014002803db0f2a01dc0f2806dd002028e00000ffff00000000ffff1806060e2006040e301c211c84f7e6fd0006002801d1002015e0301c211c84f723fe0740002f01d100200ce0301c211c84f7a2fd0006001642461114884201dc002000e00120296800280bd0081c69468af7baf8a886286b2021084000280dd0e6200ae0081c69468af796f8a886286b20210840002801d02a20a88668460078a87701b008bc9846f0bc01bc0047
 */
void func_0809801C(Context0809801C *context)
{
    Position0809801C position;
    u8 alternate;
    u8 output;

    if (context->flags & 0x10000) {
        alternate = 0;
    } else {
        position.height = context->height >> 4;
        position.x = context->x >> 5;
        position.y = context->y >> 5;
        alternate = context->data->value_FD == 2 &&
            position.x >= 0 && position.y >= 0 &&
            position.x <= 15 && position.y <= 15 &&
            func_0801CC7C((u16)position.x, (u16)position.y) &&
            (func_0801CD08((u16)position.x, (u16)position.y) & 2) &&
            (s8)func_0801CC18((u16)position.x, (u16)position.y) > position.height;
    }
    if (alternate) {
        context->value_34 = func_08022268(context->data, &output);
        if (context->flags & 0x20)
            context->value_34 = 0xE6;
    } else {
        context->value_34 = func_08022238(context->data, &output);
        if (context->flags & 0x20)
            context->value_34 = 0x2A;
    }
    context->value_1E = output;
}
