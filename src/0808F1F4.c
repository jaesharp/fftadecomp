#include "ffta.h"

/* 0x0808F1F4 .. 0x0808F414: 544 bytes. */
typedef struct {
    u8 unknown_00[0x0C];
    s16 x;
    s16 y;
    u8 unknown_10[4];
    u8 flag_14;
    u8 flag_15;
    u8 unknown_16;
    u8 variant;
    u8 flip_x;
    u8 flip_y;
    u8 unknown_1a[4];
    u8 parameter_1e;
    u8 unknown_1f[0x135];
    const void *graphics;
} RenderRecord;

typedef struct {
    RenderRecord *record;
    u8 unknown_04;
    u8 previous_mode;
    u8 mode;
} RenderView;

extern const void *func_08021DA8(const void *, u8 *, u8 *);
extern void func_08021D48(const void *, s16 *, s16 *);
extern u32 func_08021C2C(const void *);
extern u16 func_08021C8C(const void *);
extern u32 func_08021E60(const void *);
extern void func_08021D14(const void *, u16 *, u16 *);
extern void func_08001F34(const void *, s32, s32, u8, u8, u8,
                          u8, u8, u32, u8, u32);
extern void func_080018A0(const void *, s32, s32, u8, u8, u8,
                          u32, u8, u32, s16, s16, u16, u8);
extern void (*data_0839402C)(const void *, s32, s32, u8, u8, u8,
                            u8, u8, u32, const void *, u32, u32);

void func_0808F1F4(const void *object, RenderView *view)
{
    u8 flip_x, flip_y;
    s16 offset_x, offset_y;
    u16 scale_x, scale_y;
    const void *graphics = func_08021DA8(object, &flip_x, &flip_y);

    if (graphics != 0) {
        func_08021D48(object, &offset_x, &offset_y);
        if (graphics == view->record->graphics) {
            u8 affine = func_08021C2C(object);
            if (affine) {
                u16 value = func_08021C8C(object);
                u32 mode = (u8)func_08021C2C(object) ? 2 : view->mode;
                u32 parameter = func_08021E60(object);
                RenderRecord *record = view->record;
                func_08001F34(graphics,
                    record->x + offset_x, record->y + offset_y,
                    record->variant, record->flip_x, record->flip_y,
                    flip_x, flip_y, value, mode, parameter);
            } else {
                u16 value = func_08021C8C(object);
                u32 parameter = func_08021E60(object);
                data_0839402C(view->record->graphics,
                    view->record->x + offset_x, view->record->y + offset_y,
                    view->record->variant, view->record->flip_x, view->record->flip_y,
                    view->record->flag_14, view->record->flag_15, value,
                    &view->record->parameter_1e, parameter, affine);
            }
            view->mode = view->previous_mode;
        } else {
            u16 value;
            func_08021D14(object, &scale_x, &scale_y);
            value = func_08021C8C(object);
            if (scale_x == 0x100 && scale_y == 0x100) {
                u32 mode = (u8)func_08021C2C(object) ? 2 : view->mode;
                u32 parameter = func_08021E60(object);
                RenderRecord *record = view->record;
                func_08001F34(graphics,
                    record->x + offset_x, record->y + offset_y,
                    record->variant, record->flip_x, record->flip_y,
                    flip_x, flip_y, value, mode, parameter);
            } else {
                u32 mode = (u8)func_08021C2C(object) ? 2 : view->mode;
                u32 parameter = func_08021E60(object);
                RenderRecord *record = view->record;
                func_080018A0(graphics,
                    record->x + offset_x, record->y + offset_y,
                    0, 0, 0, value, mode, parameter,
                    (s16)scale_x, (s16)scale_y, 0, 0);
            }
        }
    }
}
