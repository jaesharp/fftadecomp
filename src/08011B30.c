/* 0x08011B30: complete 304-byte owner. */
#include "ffta.h"

typedef struct {
    u8 unknown_00[0x14];
    u16 *tilemap;
} WindowParent;

typedef struct {
    WindowParent *parent;
    u8 unknown_04[4];
    u8 state;
    u8 unknown_09;
    u8 kind;
    u8 unknown_0b;
    u16 flags;
    s8 column;
    s8 row;
    u8 width;
    u8 height;
    u16 tile;
    u8 unknown_14[6];
    u8 base_width;
    u8 unknown_1b[0x0f];
    u8 pending;
    u8 unknown_2b[0x2d5];
    u8 *pixels;
    u8 unknown_304[4];
    u8 *current_data;
    u8 data_tag;
    u8 data_limit;
    u8 data_body[0x1fe];
    u8 scratch[0];
} WindowObject;

extern WindowObject *data_0200918C;
extern const u8 *func_080182CC(WindowObject *, u8, u16 *);
extern u16 func_08013E9C(u8 *, const u8 *, u8 *, u16, u8 *, u8 *);
extern u8 func_0801843C(u8);
extern u8 func_080184D0(u8);
extern u8 func_08018470(u8);
extern void func_08013A88(void *, u16);
extern void func_08015858(u16 *, u8, u8, u8, u8, u8, u16, u8);

void func_08011B30(u8 kind, u16 entry)
{
    const u8 *table;
    u16 clear_width = data_0200918C->base_width * 2;
    u8 row_offset;
    s32 i;

    table = func_080182CC(data_0200918C, kind, &entry);
    data_0200918C->data_tag = 0x40;
    data_0200918C->data_limit = 0x63;
    func_08013E9C(data_0200918C->data_body, table,
                  data_0200918C->scratch, entry, 0, 0);
    data_0200918C->current_data = &data_0200918C->data_tag;
    row_offset = (data_0200918C->flags & 0xc0) ? 2 : 1;
    if (func_0801843C(data_0200918C->kind) ||
        func_080184D0(data_0200918C->kind)) {
        data_0200918C->state = 4;
    } else if (func_08018470(data_0200918C->kind)) {
        WindowObject *object;

        for (i = 1; i < (data_0200918C->height >> 1); i++)
            func_08013A88(data_0200918C->pixels +
                         i * data_0200918C->base_width * 64, clear_width);
        object = data_0200918C;
        func_08015858(object->parent->tilemap, object->column + 1,
                      object->row + row_offset, object->base_width,
                      object->height >> 1, 0x20, object->tile, 0x0c);
    }
    data_0200918C->pending = 0;
}
