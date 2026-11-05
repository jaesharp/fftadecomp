#include "ffta.h"

/* Complete target: 0x080E5310..0x080E5438, 296 bytes. */

typedef struct EffectSequenceWork {
    u8 unknown_00[0x14];
    void *coordinate_child;
    void *resource;
    void *sequence_child;
    void *effect_child;
    void *motion_child;
    void *record_child;
} EffectSequenceWork;

extern u32 func_080035A8(u8 index);
extern void func_080D49FC(u8 first, u8 second, u16 third, s16 fourth, s16 fifth);
extern void *func_080D4B64(u8 index, const void *record, u16 value, u8 mode);
extern void *func_080D4704(const void *record, void *parent);
extern void *func_080D3E9C(const void *record, void *parent);
extern void *func_080D6098(s16 x, s16 y, s16 z, u8 mode, u16 count,
                           void *buffer, const void *record, void *parent);
extern void *func_080D98D4(u8 index, u16 first, u16 second, u16 third,
                           const void *record, void *parent);
extern void *func_080DFD8C(const void *records, u8 count, u16 flags,
                           u16 delay, void *parent);
extern void *func_080D3F08(void *task);
extern void *func_080D4774(void *task);
extern void *func_080D4D2C(void *resource, u8 mode);
extern void *func_080D6134(void *task);
extern void *func_080D9B64(void *task);

extern u16 g_control_flags_03000940;
extern const u8 data_0894D69C[];
extern const u8 g_object_088ED968[];
extern const u8 g_object_08949498[];
extern const u8 g_object_08396E18[];
extern const u8 g_object_08396F68[];
extern const u8 g_object_08396FAC[];

u32 func_080E5310(void *task, void *descriptor, void *payload)
{
    u16 *phase = descriptor;
    EffectSequenceWork *work = payload;

    switch (*phase) {
    case 0:
        func_080D49FC(0, 2, 0, 0, 0);
        work->resource = func_080D4B64(0, g_object_088ED968, 0x31B, 6);
        {
            u32 mask = func_080035A8(2);
            u16 flags = g_control_flags_03000940;
            flags |= mask;
            g_control_flags_03000940 = flags;
        }
        work->effect_child = func_080D4704(g_object_08949498, task);
        work->sequence_child = func_080D3E9C(data_0894D69C, task);
        work->coordinate_child = func_080D6098(120, 96, 0, 1, 4,
                                               (u8 *)work + 4,
                                               g_object_08396E18, task);
        work->motion_child = func_080D98D4(2, 0, 0, 0,
                                           g_object_08396F68, task);
        work->record_child = func_080DFD8C(g_object_08396FAC, 1, 4, 0, task);
        break;
    case 1:
        break;
    case 0x100:
        work->sequence_child = func_080D3F08(work->sequence_child);
        if (work->sequence_child != 0)
            break;
        work->effect_child = func_080D4774(work->effect_child);
        if (work->effect_child != 0)
            break;
        work->resource = func_080D4D2C(work->resource, 0);
        if (work->resource != 0)
            break;
        {
            u32 mask = func_080035A8(2);
            u16 flags = g_control_flags_03000940;
            flags &= ~mask;
            g_control_flags_03000940 = flags;
        }
        work->coordinate_child = func_080D6134(work->coordinate_child);
        if (work->coordinate_child != 0)
            break;
        work->motion_child = func_080D9B64(work->motion_child);
        if (work->motion_child != 0)
            break;
        *phase = 2;
        break;
    }
    return 0;
}
