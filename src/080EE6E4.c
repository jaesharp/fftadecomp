#include "ffta.h"

/* Complete [0x080EE6E4, 0x080EE948), 612 bytes. */
typedef struct {
    u16 phase;
    u16 unknown_02;
    void *primary;
    u8 unknown_08[14];
    u16 flag;
} Descriptor080EE6E4;

typedef struct {
    u16 countdown;
    s16 x;
    s16 y;
    u8 unknown_06;
    u8 flag;
    void *entity;
    Struct080DBD5C *auxiliary;
    u8 unknown_10[4];
    void *effect;
    void *sprite;
    void *object;
    void *sequence;
    void *stage;
    void *variant;
    void *primary;
    void *animation;
    void *result;
} Payload080EE6E4;

extern const u8 data_08399834[], data_08399858[], data_088EEA08[];
extern const u8 data_0894D834[], data_08399870[], data_08399884[];
extern const u8 data_084FC91C[];
extern u16 g_control_flags_03000940;
extern void *func_080E03F8(void *, const void *, u8, u8, const s16 *, void *);
extern void func_080D38B4(void);
extern void *func_080E05DC(void *);
extern void *func_080DD4A4(void *, u8);
extern Struct080DBD5C *func_080DD748(void *, s16 *, s16 *, s16 *);
extern void *func_080EEEF0(u8, void *, void *);
extern void *func_080EEE50(void *, u8, void *);
extern u8 func_080DD494(const void *);
extern void *func_080EEF6C(void *);
extern u8 func_080EEF30(void *);
extern void *func_080D6098(s16, s16, u16, u8, u16, void *, const void *, void *);
extern void func_080D49FC(u8, u8, u16, s16, s16);
extern void *func_080D4B64(u8, const void *, u16, u8);
extern u32 func_080035A8(u8);
extern void *func_080D3E9C(const void *, void *);
extern void *func_080DCFE4(void *, const void *, u8, u16, u16, void *, s16);
extern void *func_080DFD8C(const void *, u8, u16, u16, void *);
extern void *func_080D5E80(const void *, u16, s16, s16, s16, s16, u8);
extern void func_08011058(void *, s16);
extern void *func_080D3F08(void *);
extern void *func_080D4D2C(void *, u8);
extern void *func_080D6134(void *);
extern void *func_08011484(void *);
extern void *func_080DBA5C(void *);

u32 func_080EE6E4(void *task, Descriptor080EE6E4 *descriptor,
                  Payload080EE6E4 *payload)
{
    void *primary;
    u8 mode;
    s16 x, y, z;

    switch (descriptor->phase) {
    case 0:
        payload->flag = descriptor->flag;
        primary = descriptor->primary;
        payload->primary = primary;
        mode = 3;
        if (payload->flag)
            mode = 0;
        payload->stage = func_080E03F8(primary, data_08399834, mode, 1, 0, task);
        break;
    case 1:
        func_080D38B4();
        break;
    case 0x100:
        payload->stage = func_080E05DC(payload->stage);
        if (payload->stage)
            break;
        payload->entity = func_080DD4A4(payload->primary, 0);
        payload->auxiliary = func_080DD748(payload->entity,
                                         &payload->x, &payload->y, 0);
        if (payload->flag) {
            descriptor->phase = 0x102;
        } else {
            payload->stage = func_080EEEF0(5, payload->primary, task);
            descriptor->phase++;
        }
        break;
    case 0x101:
        payload->stage = func_080E05DC(payload->stage);
        if (payload->stage)
            break;
        payload->variant = func_080EEE50(payload->primary, 5, task);
        descriptor->phase++;
        break;
    case 0x102:
        if (!func_080DD494(payload->primary)) {
            payload->variant = func_080EEF6C(payload->variant);
            if (!payload->variant)
                descriptor->phase = 2;
        } else if (payload->flag || func_080EEF30(payload->variant)) {
            payload->effect = func_080D6098(payload->x, payload->y, 0, 1, 1,
                payload->unknown_10, data_08399858, task);
            func_080D49FC(0, 2, 0, payload->x, payload->y);
            payload->object = func_080D4B64(0, data_088EEA08, 0x388, 6);
            {
                u32 mask = func_080035A8(2);
                u16 flags = g_control_flags_03000940;
                flags |= mask;
                g_control_flags_03000940 = flags;
            }
            payload->sequence = func_080D3E9C(data_0894D834, task);
            payload->animation = func_080DCFE4(payload->entity, data_08399870,
                                               12, 30, 10, task, 30);
            payload->result = func_080DFD8C(data_08399884, 1, 4, 0, task);
            payload->countdown = 4;
            descriptor->phase++;
        }
        break;
    case 0x103:
        payload->countdown--;
        if (payload->countdown)
            break;
        func_080DBD5C(payload->auxiliary, &x, &y, &z);
        payload->sprite = func_080D5E80(data_084FC91C, 1, x, y, z, 0x3CC, 7);
        func_08011058(payload->sprite, 1);
        descriptor->phase++;
        break;
    case 0x104:
        payload->sequence = func_080D3F08(payload->sequence);
        if (payload->sequence)
            break;
        payload->object = func_080D4D2C(payload->object, 0);
        if (payload->object)
            break;
        {
            u32 mask = func_080035A8(2);
            g_control_flags_03000940 &= ~mask;
        }
        payload->effect = func_080D6134(payload->effect);
        if (payload->effect)
            break;
        payload->sprite = func_08011484(payload->sprite);
        if (payload->sprite)
            break;
        payload->animation = func_080DBA5C(payload->animation);
        if (!payload->animation)
            descriptor->phase = 2;
        break;
    }
    return 0;
}
