#include "ffta.h"

typedef struct {
    u16 phase;
    u16 unknown_02;
    u32 input;
} Descriptor080F2680;

typedef struct {
    u16 x;
    u16 y;
    u8 counter;
    u8 unknown_05[3];
    void *sprites[10];
    void *timeline;
    void *first_effect;
    void *effects[4];
    u32 input;
    void *sound;
} Payload080F2680;

typedef struct {
    u8 frame;
    u8 index;
    s16 x;
    s16 y;
    u8 unknown_06[2];
} Spawn080F2680;

extern u16 data_03003920[];
extern u16 g_control_flags_03000940;
extern const u8 data_088F5BD4[];
extern const u8 data_0894DB58[];
extern const u8 data_0894B850[];
extern const u8 data_0894B6F0[];
extern const u8 data_0894B744[];
extern const u8 data_0894B7A0[];
extern const u8 data_0894B7FC[];
extern const u8 data_0839A8C8[];
extern const Spawn080F2680 data_0839A7CC[];
extern const u8 data_0850341C[];

extern void func_0814186C(const void *source, void *destination, u32 control);
extern u32 func_080035A8(u8 index);
extern void func_080D7220(const void *resource, u8 bank, u8 channel,
                        s16 x, s16 y, u16 extra);
extern void *func_080D3E9C(const void *resource, void *parent);
extern void func_080D3F84(void *task, u8 first, u8 second);
extern void *func_080D4704(const void *resource, void *parent);
extern void func_080D47A0(void *task, u8 enabled);
extern void *func_080DFD8C(const void *resource, u8 mode, u16 flags,
                         u16 value, void *parent);
extern void *func_080D5CC0(const void *resource, u16 index, s16 x, s16 y,
                         u16 tile, u8 palette, u8 flags, u8 relative);
extern void func_08011198(void *object);
extern u8 func_080D5F24(void **objects, u16 count);
extern void *func_080D3F08(void *task);
extern void *func_080D4774(void *task);
extern void func_080D4938(void **tasks, u16 count);

u32 func_080F2680(void *task, Descriptor080F2680 *descriptor,
                 Payload080F2680 *payload)
{
    switch (descriptor->phase) {
    case 0:
        payload->input = descriptor->input;
        payload->x = 120;
        payload->y = 96;
        {
            u16 fill = 0;
            func_0814186C(&fill, data_03003920, 0x01000010);
        }
        break;
    case 0x100:
        func_080D7220(data_088F5BD4, 1, 3,
                     (s16)payload->x, (s16)payload->y, 0);
        payload->timeline = func_080D3E9C(data_0894DB58, task);
        func_080D3F84(payload->timeline, 8, 0xFF);
        payload->first_effect = func_080D4704(data_0894B850, task);
        payload->effects[0] = func_080D4704(data_0894B6F0, task);
        payload->effects[1] = func_080D4704(data_0894B744, task);
        payload->effects[2] = func_080D4704(data_0894B7A0, task);
        payload->effects[3] = func_080D4704(data_0894B7FC, task);
        func_080D47A0(payload->effects[0], 1);
        func_080D47A0(payload->effects[1], 1);
        func_080D47A0(payload->effects[2], 1);
        func_080D47A0(payload->effects[3], 1);
        payload->sound = func_080DFD8C(data_0839A8C8, 1, 4, 0, task);
        descriptor->phase++;
        break;
    case 0x101:
        {
            u8 i;
            u8 count;
            payload->counter++;
            for (i = 0, count = 0; i < 10; i++) {
                if (payload->sprites[i]) {
                    count++;
                } else {
                    if (payload->counter == data_0839A7CC[i].frame) {
                        payload->sprites[i] = func_080D5CC0(
                            data_0850341C, data_0839A7CC[i].index,
                            data_0839A7CC[i].x, data_0839A7CC[i].y,
                            0x3C7, 7, 1, 0);
                        func_08011198(payload->sprites[i]);
                    }
                }
            }
            if (count > 9)
                descriptor->phase++;
        }
        break;
    case 0x102:
        if (!func_080D5F24(payload->sprites, 10))
            break;
        payload->timeline = func_080D3F08(payload->timeline);
        if (payload->timeline)
            break;
        payload->first_effect = func_080D4774(payload->first_effect);
        if (payload->first_effect)
            break;
        func_080D4938(payload->effects, 4);
        {
            u32 mask = func_080035A8(3);
            g_control_flags_03000940 &= ~mask;
        }
        descriptor->phase = 2;
        break;
    }
    return 0;
}
