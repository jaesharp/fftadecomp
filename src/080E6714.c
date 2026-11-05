#include "ffta.h"

typedef struct {
    u16 phase;
    u8 unknown_02[2];
    void *object;
    u8 unknown_08[12];
    u16 flags;
    u16 variant;
} EffectDescriptor;

typedef struct {
    u8 flags;
    u8 variant;
    s16 x;
    s16 y;
    u8 unknown_06[2];
    void *object;
    void *underlying;
    void *resource;
    u8 unknown_14[12];
    void *coordinate_child;
    void *sequence_child;
    void *effect_children[2];
    void *wrapper_child;
    void *record_child;
} EffectWork;

typedef struct PositionSourceLink PositionSourceLink;
extern PositionSourceLink *func_080DD748(PositionSourceLink *object, s16 *first, s16 *second, s16 *third);
extern void func_080D45D0(const void *record, u8 slot, u8 bank, u8 first, u8 count);
extern void func_080D49FC(u8 first, u8 second, u16 third, s16 x, s16 y);
extern void *func_080D4B64(u8 first, const void *record, u16 value, u8 mode);
extern void func_0800BDA4(void *resource, u8 enabled);
extern u32 func_080035A8(u8 index);
extern void *func_080D6098(s16 x, s16 y, s16 z, u8 mode, u16 count,
                         void *buffer, const void *records, void *parent);
extern void *func_080D3E9C(const void *record, void *parent);
extern void *func_080D4704(const void *record, void *parent);
extern void func_080D47A0(void *child, u8 enabled);
extern void *func_080DCFE4(void *object, const void *record, u8 count,
                         u16 delay, u16 flags, void *parent, s16 value);
extern void *func_080DFD8C(const void *record, u8 count, u16 flags,
                         u16 delay, void *parent);
extern void *func_080D3F08(void *child);
extern void func_080D4938(void **children, u16 count);
extern void func_080D4D14(void *resource, u8 mode);
extern void *func_080D6134(void *child);
extern void *func_080DBA5C(void *child);

extern const u8 g_object_088EA31C[];
extern const u8 g_object_088EDB7C[];
extern const u8 g_object_083974D0[];
extern const void *const g_object_083974C8[];
extern const u8 g_object_0894D7BC[];
extern const u8 g_object_08949554[];
extern const u8 g_object_08949564[];
extern const u8 g_object_083974D4[];
extern const void *const g_object_0839750C[];
extern u16 g_control_flags_03000940;

/* Ordinary helper views are conditional on the complete saved entries.
 * Symbol names identify observed points; table bounds, object validity and
 * asynchronous storage lifetime remain caller premises. DD748 retains the
 * defining pointer-output interface. The child-presence byte is a 0/1 value.
 */
u32 func_080E6714(void *task, void *descriptor_arg, void *payload_arg)
{
    EffectDescriptor *descriptor = descriptor_arg;
    EffectWork *work = payload_arg;
    u16 flags;
    u8 had_sequence;

    switch (descriptor->phase) {
    case 0:
        work->flags = descriptor->flags;
        work->variant = descriptor->variant;
        work->object = descriptor->object;
        work->underlying = func_080DD748(work->object, &work->x, &work->y, 0);
        if (work->variant == 0)
            func_080D45D0(g_object_088EA31C, 6, 0, 0, 1);
        else
            func_080D45D0(g_object_088EA31C, 6, 0, 2, 1);
        break;
    case 0x100:
        func_080D49FC(0, 2, 0, work->x, work->y);
        work->resource = func_080D4B64(0, g_object_088EDB7C, 0x3C6, 6);
        func_0800BDA4(work->resource, 1);
        {
            u32 mask = func_080035A8(2);
            u16 shadow = g_control_flags_03000940;
            shadow |= mask;
            g_control_flags_03000940 = shadow;
        }
        work->coordinate_child = func_080D6098(
            work->x, work->y, 0, 1, g_object_083974D0[work->variant],
            work->unknown_14, g_object_083974C8[work->variant], task);
        work->sequence_child = func_080D3E9C(g_object_0894D7BC, task);
        work->effect_children[0] = func_080D4704(g_object_08949554, task);
        work->effect_children[1] = func_080D4704(g_object_08949564, task);
        func_080D47A0(work->effect_children[0], 1);
        func_080D47A0(work->effect_children[1], 1);
        flags = (work->flags & 1) ? 4 : 2;
        work->wrapper_child = func_080DCFE4(
            work->object, g_object_083974D4 + 20 * work->variant,
            12, 50, flags, task, 50);
        flags = (work->flags & 1) ? 0x10 : 8;
        work->record_child = func_080DFD8C(
            g_object_0839750C[work->variant], 1, flags | 4, 0, task);
        descriptor->phase++;
        break;
    case 0x101:
        had_sequence = work->sequence_child != 0;
        work->sequence_child = func_080D3F08(work->sequence_child);
        if (work->sequence_child == 0) {
            if (had_sequence) {
                func_080D4938(work->effect_children, 2);
                func_080D4D14(work->resource, 0);
                work->resource = 0;
                {
                    u32 mask = func_080035A8(2);
                    u16 shadow = g_control_flags_03000940;
                    shadow &= ~mask;
                    g_control_flags_03000940 = shadow;
                }
            }
            work->coordinate_child = func_080D6134(work->coordinate_child);
            if (work->coordinate_child == 0)
                descriptor->phase++;
        }
        break;
    case 0x102:
        work->wrapper_child = func_080DBA5C(work->wrapper_child);
        if (work->wrapper_child == 0)
            descriptor->phase = 2;
        break;
    }
    return 0;
}
