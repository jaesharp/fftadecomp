#include "ffta.h"

typedef struct {
    u8 unknown_00[0x20];
} TextRegion;

typedef struct {
    u8 unknown_00[0x14];
} MenuList;

typedef struct {
    u8 unknown_00[0x14];
} MenuCursor;

typedef struct {
    u8 unknown_00[0x2c];
    TextRegion region;
    MenuList list;
    MenuCursor cursor;
} MenuWindow;

typedef struct {
    u8 unknown_00[0x30];
    u16 object_id;
    u8 unknown_32[0x16];
    s32 *count;
    MenuWindow window;
    const void *resource;
    u8 unknown_c4[8];
} MenuRecord;

typedef struct {
    u8 unknown_00[0x2c88];
    MenuRecord records[1];
} MenuContext;

typedef struct {
    u8 unknown_00[0x0e];
    u16 height;
    u8 unknown_10[0x3c];
} RenderObject;

extern MenuContext *data_03002818;
extern RenderObject data_030009E0[];
extern void func_08016210(MenuWindow *, const void *, u16, u16);
extern u16 func_08017B50(TextRegion *);
extern void func_080819F0(s32, s16, TextRegion *);
extern void func_08081B24(u16, TextRegion *);
extern void func_08017C28(MenuList *, TextRegion *, void (*)(MenuList *), u8);
extern void func_08017DB4(MenuCursor *, TextRegion *, void (*)(MenuCursor *), u8);
extern void func_08081078(MenuList *);
extern void func_0808118C(MenuCursor *);
extern void func_08085378(MenuList *);

static inline void configure_window(MenuWindow *window,
                                     void (*primary)(MenuList *),
                                     void (*secondary)(MenuCursor *),
                                     u8 flags, u8 mode)
{
    TextRegion *region = &window->region;

    func_08017C28(&window->list, region, primary, flags);
    func_08017DB4(&window->cursor, region, secondary, mode);
}

/* Initialize a window's rows and callbacks; complete target 316 bytes. */
void func_08081BEC(s32 slot)
{
    u16 object_id = data_03002818->records[slot].object_id;
    u16 count;
    s32 row;

    func_08016210(&data_03002818->records[slot].window,
                  data_03002818->records[slot].resource,
                  data_030009E0[object_id].height,
                  *data_03002818->records[slot].count);
    count = func_08017B50(&data_03002818->records[slot].window.region);
    for (row = 0; row < count; row++)
        func_080819F0(slot, row, &data_03002818->records[slot].window.region);
    func_08081B24(object_id, &data_03002818->records[slot].window.region);

    if (*data_03002818->records[slot].count > 0)
        configure_window(&data_03002818->records[slot].window,
                         func_08081078, func_0808118C, 0, 13);
    else
        configure_window(&data_03002818->records[slot].window,
                         func_08085378, func_0808118C, 0, 13);
}
