typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 unknown_00[8];
    u32 resource_08;
    u32 unknown_0C;
    u32 resource_10;
} ResourceView;

typedef struct {
    u8 unknown_00[0xC];
    u8 *buffer;
} BufferView;

typedef struct {
    u8 unknown_00[0xE];
    u16 tile;
    u32 resource_10;
    u32 resource_14;
    u8 *buffer_18;
    u8 *buffer_1C;
    u8 *buffer_20;
    u8 *buffer_24;
    u8 columns;
    u8 rows;
    u8 unknown_2A[0xA];
    u8 inner_x;
    u8 inner_y;
    u8 unknown_36[0x16];
} BackgroundView;

extern ResourceView *data_030027D8;
extern BufferView data_03002740;
extern BackgroundView data_030009E0[];
extern u16 data_0600BAE0[];

void *func_0808A268(s32 index, u8 priority, u32 resource0, u32 resource1,
                   u8 *buffer0, u8 *buffer1, u8 *buffer2, u8 *buffer3,
                   u8 x, u8 y, u8 width, u8 height,
                   u8 inner_x, u8 inner_y, u8 inner_width, u8 inner_height,
                   u8 columns, u8 rows);
u16 *func_0808B8E4(s32 index, u32 selector, u32 x, u32 y);
void func_0808B7C0(s32 index, u16 *destination, u16 tile, u16 count, u16 flags);
void func_08016800(u16 *destination, u8 width, u8 height, u32 unknown_word3,
                   u8 stride, u16 tile, u16 fill, u8 palette);
void func_0814186C(const void *source, void *destination, u32 control);

/* 0x08138284: complete 208-byte target, including its reached literal pool. */
void func_08138284(void)
{
    u16 zero;

    func_0808A268(3, 12, data_030027D8->resource_08,
                 data_030027D8->resource_10,
                 data_03002740.buffer, data_03002740.buffer + 0xD8, 0, 0,
                 2, 1, 27, 4, 2, 1, 27, 4, 27, 4);
    data_030009E0[3].inner_x = 2;
    data_030009E0[3].inner_y = 1;
    data_030009E0[3].tile = 0x1D7;
    zero = 0;
    func_0814186C(&zero, data_0600BAE0, 0x01000320);
    func_0808B7C0(3, func_0808B8E4(3, 1, 1, 1), 0x1D7, 25, 0xB000);
    func_08016800((u16 *)data_030009E0[3].buffer_18,
                 data_030009E0[3].columns, data_030009E0[3].rows, 0x800,
                 data_030009E0[3].columns, 13, 3, 11);
}
