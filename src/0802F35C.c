#include "ffta.h"

typedef struct {
    const void *source;
    s16 x;
    s16 y;
    s16 offset_x;
    s16 offset_y;
    u8 value;
    u8 extra;
    s16 timer;
} DrawState;

typedef struct {
    u16 x;
    u16 y;
    u8 unknown_04[8];
    s16 selected;
    u8 unknown_0e[0x467 - 0xe];
    u8 visible;
    u8 unknown_468[0x1248 - 0x468];
    DrawState draw;
} PanelState;

extern PanelState *data_0200F444;
extern const u8 data_0839177A[];
extern void func_08017FE8(const DrawState *state);
extern void func_08001CF0(const void *source, s32 first, s32 second,
                          u8 mode, u8 first_flag, u8 second_flag,
                          u8 third_flag, u8 fourth_flag, u32 value,
                          u8 count, u32 extra);

/* Complete target 0802F35C..0802F400: 164 bytes. */
void func_0802F35C(u8 update)
{
    if (update) {
        if (++data_0200F444->draw.timer > 5) {
            data_0200F444->draw.timer = 0;
            if (++data_0200F444->draw.offset_x > 2)
                data_0200F444->draw.offset_x = 0;
        }
        data_0200F444->draw.offset_y = data_0200F444->selected * 16;
    }
    func_08017FE8(&data_0200F444->draw);
    if (data_0200F444->visible) {
        func_08001CF0(data_0839177A, (data_0200F444->x + 1) * 8,
                      data_0200F444->y * 8 - 4, 0, 0, 0, 0, 0, 0, 0, 0);
    }
}
