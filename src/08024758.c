#include "ffta.h"

typedef struct {
    u8 unknown_00[4];
    u8 state;
    u8 unknown_05[3];
    u8 mode;
    u8 size;
    u8 enabled;
    u8 unknown_0B[9];
    s16 index_14;
    u16 index_16;
    s16 index_18;
    u8 unknown_1A[2];
    u8 left;
    u8 top;
    u8 right;
    u8 bottom;
    s16 screen_left;
    s16 screen_top;
    s16 screen_right;
    s16 screen_bottom;
} Record08024758;

typedef void (*BufferInitializer08024758)(void *destination, u32 size);
extern BufferInitializer08024758 const g_callbacks_0836D4B8[];
extern void func_0801CAE0(u16 *coordinates);

/* 0x08024758..0x080247FC: 164 bytes, including literals. */
void func_08024758(Record08024758 *record)
{
    u8 width, height, left, top;
    u16 coordinates[6];

    g_callbacks_0836D4B8[0](record, sizeof(*record));
    record->state = 0;
    record->mode = 2;
    record->size = 8;
    record->enabled = 1;
    record->index_16 = 0xFFFF;
    record->index_18 = -1;
    record->index_14 = -1;

    func_0801CD4C(&width, &height, &left, &top);
    record->left = left;
    record->top = top;
    record->right = left + width;
    record->bottom = top + height;

    func_0801CAE0(coordinates);
    record->screen_left = coordinates[0] - 0x68;
    record->screen_top = coordinates[1] - 0x50;
    record->screen_right = coordinates[2] - 0x88;
    record->screen_bottom = coordinates[3] - 0x60;
}
