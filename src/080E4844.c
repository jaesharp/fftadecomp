#include "ffta.h"

typedef struct E4844Descriptor {
    u16 phase;
    u16 unknown_02;
    void *object;
    u8 unknown_08[0xC];
    u16 selector;
    u16 flags;
} E4844Descriptor;

typedef struct E4844Payload {
    u8 selector;
    u8 flags;
    u16 countdown;
    s16 horizontal;
    s16 vertical;
    void *underlying_object;
    void *object;
    u8 unknown_10[4];
    void *coordinate_child;
    void *mask_child;
    void *selected_child;
    void *sequence_child;
    void *effect_child;
    void *sound_child;
} E4844Payload;

typedef struct PositionSourceLink PositionSourceLink;
extern PositionSourceLink *func_080DD748(PositionSourceLink *source, s16 *first, s16 *second, s16 *third);
void func_080D45D0(const void *record, u8 destination, u8 bank, u8 start, u8 count);
void *func_080D6098(s16 horizontal, s16 vertical, s16 depth, u8 mode,
                  u16 count, void *storage, const void *records, void *parent);
void *func_080DCFE4(void *object, const void *record, u8 mode, u16 duration,
                  u16 flags, void *parent, s16 fallback_duration);
void *func_080D4724(const void *record, void *parent, u16 flags);
void func_080D7220(const void *record, u8 bank, u8 layer, s16 horizontal,
                  s16 vertical, u16 flags);
void *func_080D4704(const void *record, void *parent);
void *func_080D3E9C(const void *record, void *parent);
u32 func_080035A8(u8 layer);
void *func_080DFD8C(const void *record, u8 count, u16 flags, s16 delay,
                  void *parent);
void *func_080D6134(void *task);
void *func_080D4774(void *task);
void *func_080D3F08(void *task);
void *func_080DBA5C(void *task);

extern const void *const g_object_08396CDC[];
extern const void *const g_object_08396CEC[];
extern const void *const g_object_08396CE4[];
extern const void *const g_object_08396D04[];
extern const u8 g_object_08396CC4[];
extern const u8 g_object_08948D38[];
extern const u8 g_object_0894D6D4[];
extern u16 g_control_flags_03000940;

/* Ordinary call views are conditional on the supplied complete helper entries.
 * ROM names identify observed points; table range and storage lifetime remain
 * caller premises. DD748 follows the defining pointer-output interface.
 */
u32 func_080E4844(void *task, void *descriptor_pointer, void *payload_pointer)
{
    E4844Descriptor *descriptor = descriptor_pointer;
    E4844Payload *payload = payload_pointer;
    u16 flags;
    u8 had_mask_child;

    switch (descriptor->phase) {
    case 0:
        payload->selector = descriptor->selector;
        payload->flags = descriptor->flags;
        payload->object = descriptor->object;
        payload->underlying_object = func_080DD748(payload->object,
            &payload->horizontal, &payload->vertical, 0);
        func_080D45D0(g_object_08396CDC[payload->selector], 6, 0, 0, 1);
        break;
    case 0x100:
        payload->coordinate_child = func_080D6098(payload->horizontal,
            payload->vertical, 0, 1, 1, payload->unknown_10,
            g_object_08396CC4, task);
        flags = payload->flags & 1 ? 4 : 2;
        payload->effect_child = func_080DCFE4(payload->object, 0, 12, 0,
            flags, task, 50);
        payload->selected_child = func_080D4724(
            g_object_08396CEC[payload->selector], task, 0x13);
        payload->countdown = 12;
        descriptor->phase++;
        break;
    case 0x101:
        payload->countdown--;
        if (payload->countdown == 0) {
            func_080D7220(g_object_08396CE4[payload->selector], 0, 2,
                payload->horizontal, payload->vertical, 0);
            payload->mask_child = func_080D4704(g_object_08948D38, task);
            payload->sequence_child = func_080D3E9C(g_object_0894D6D4, task);
            {
                u32 mask = func_080035A8(2);
                u16 shadow = g_control_flags_03000940;
                shadow |= mask;
                g_control_flags_03000940 = shadow;
            }
            flags = payload->flags & 1 ? 0x10 : 8;
            payload->sound_child = func_080DFD8C(
                g_object_08396D04[payload->selector], 1, flags | 4, 0, task);
            descriptor->phase++;
        }
        break;
    case 0x102:
        payload->coordinate_child = func_080D6134(payload->coordinate_child);
        if (payload->coordinate_child != 0)
            break;
        had_mask_child = payload->mask_child != 0;
        payload->mask_child = func_080D4774(payload->mask_child);
        if (payload->mask_child != 0)
            break;
        if (had_mask_child) {
            {
                u32 mask = func_080035A8(2);
                u16 shadow = g_control_flags_03000940;
                shadow &= ~mask;
                g_control_flags_03000940 = shadow;
            }
        }
        payload->sequence_child = func_080D3F08(payload->sequence_child);
        if (payload->sequence_child != 0)
            break;
        payload->selected_child = func_080D4774(payload->selected_child);
        if (payload->selected_child != 0)
            break;
        payload->effect_child = func_080DBA5C(payload->effect_child);
        if (payload->effect_child == 0)
            descriptor->phase = 2;
        break;
    }
    return 0;
}
