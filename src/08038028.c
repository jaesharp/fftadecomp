#include "ffta.h"

typedef struct {
    u8 unknown_00;
    u8 palette;
    u8 unknown_02[0x32];
    s8 x;
    s8 y;
    u8 unknown_36[0x12];
    s8 offset_x;
    s8 offset_y;
    s8 extra_x;
    u8 unknown_4B;
} RenderRecord;

typedef struct {
    u8 unknown_00[8];
    u16 width;
    u16 y;
    u16 x;
    u16 offset_y;
    u8 flags;
} RenderPanel;

extern RenderRecord data_030009E0[];
extern const u8 data_083919CE[];
extern const u8 data_083919C6[];

void func_08001F34(const void *graphics, s32 x, s32 y, u8 variant,
    u8 flip_x, u8 flip_y, u8 flag_28, u8 flag_29, u32 value, u8 mode, const void *transform);

/* Complete target: [0x08038028, 0x08038238), 528 bytes. */
void func_08038028(u32 index, void *context)
{
    RenderPanel *panel = context;
    u8 anchor = ((RenderPanel *)context)->flags & 0x80;

    if (anchor != 0) {
        u8 flip = panel->flags & 8;
        if (flip != 0) {
            func_08001F34(data_083919CE,
                (data_030009E0[index].x + data_030009E0[index].extra_x + data_030009E0[index].offset_x) * 8 + panel->x - 1,
                panel->y + panel->offset_y + (data_030009E0[index].y + data_030009E0[index].offset_y - 1) * 8 + 1,
                0, 0, 0, 0, 0, panel->width, data_030009E0[index].palette, 0);
        } else {
            func_08001F34(data_083919CE,
                (data_030009E0[index].x + data_030009E0[index].offset_x - 1) * 8 + panel->x - 1,
                panel->y + panel->offset_y + (data_030009E0[index].y + data_030009E0[index].offset_y - 1) * 8 + 1,
                0, 0, 0, 0, 0, panel->width, data_030009E0[index].palette, 0);
        }
    } else {
        u8 flip = panel->flags & 8;
        if (flip != 0) {
            func_08001F34(data_083919C6,
                panel->width + panel->x + (data_030009E0[index].x + data_030009E0[index].extra_x + data_030009E0[index].offset_x + 4) * 8,
                panel->y + panel->offset_y + (data_030009E0[index].y + data_030009E0[index].offset_y - 1) * 8,
                0, 0, 0, 1, 0, 0, data_030009E0[index].palette, 0);
        } else {
            func_08001F34(data_083919C6,
                panel->width + panel->x + (data_030009E0[index].x + data_030009E0[index].offset_x - 1) * 8,
                panel->y + panel->offset_y + (data_030009E0[index].y + data_030009E0[index].offset_y - 1) * 8,
                0, 0, 0, 0, 0, 0, data_030009E0[index].palette, 0);
        }
    }
}
