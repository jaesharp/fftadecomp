#include "ffta.h"

typedef struct {
    u8 unknown_0000[0x14D3];
    u8 position;
    u8 unknown_14D4[0x372E];
    u8 counter;
    u8 animated;
} CursorState;

typedef struct {
    u8 unknown_00[8];
    u16 x;
    u16 y;
    u16 unknown_0C;
    u16 y_offset;
    u8 flags;
} Cursor;

extern CursorState *data_0200F428;
extern const u8 data_0851BA52[];
extern void func_08001CF0(const void *, s32, s32, u8, u8, u8, u8,
                          u8, u32, u8, u32);

/* Complete 176-byte cursor animation and drawing function. */
void func_0806EB48(Cursor *cursor)
{
    u8 frame;
    s32 offset;

    cursor->x = (data_0200F428->position - 2) * 8;
    if (data_0200F428->animated) {
        data_0200F428->counter++;
        data_0200F428->counter %= 20u;
        frame = data_0200F428->counter / 5u;
    } else {
        data_0200F428->counter = 0;
        frame = 0;
    }
    offset = (cursor->flags & 8) ? 24 : 0;
    func_08001CF0(data_0851BA52, cursor->x + offset + frame,
                  cursor->y + cursor->y_offset, 0, 0, 0,
                  (cursor->flags >> 3) & 1, 0, 0, 0, 0);
}
