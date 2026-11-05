#include "ffta.h"

/* Complete 0x08074DC4..0x08074FA4, 480 bytes, 198 instructions.
 * Target: f0b54f464646c0b48fb0664f66490868664a8018002399460122904643460370086882694369624800690090842149004018019048460290039011240494082605960c2006900b250795089409960a900b950c900d9504200c2115f023fa554ab221490050180470534bd01806709f2040001318002169301880504bd0180170bc214900501843460370013150180370bd235b00d01805700231501806700ea84a4602804649474accf0fefc0024a51c0420012101222b1c16f032fd011c0b20221c4243404bd2181204120cc0200002009004200b2316f091fce31c04200121002216f01dfd394a111c0180042c15dc3749601031308000401802682a480068344bc018610009198900091b49012c4bc918012300930023a0f718f92c1c072cc5dd244da621490068180068ac225200a9180978284bea1812780091052301930c240294c023a1f71bfaa42149006818006800940126019602940c210b22c023a1f71cfb1d4d042001210122012316f0d7fc041c381c3e210322a3f7f1fa021c281c211c0123c0f795fb07480068074a801806700fb018bc9846a146f0bc01bc00470000b03c000218280003f50b000040270003e00900036501000031010000e0b4000680050001a70100000cd00000b06856088c060000590100003ec00000
 */
typedef struct {
    u8 unknown_00;
    u8 field_01;
    u8 unknown_02[12];
    u16 tile;
    u8 unknown_10[8];
    u16 *first_plane;
    u16 *second_plane;
    u8 unknown_20[8];
    u8 stride;
    u8 height;
    u8 unknown_2A[10];
    u8 x;
    u8 y;
    u8 unknown_36[0x12];
    u8 flag_48;
    u8 flag_49;
    u8 width_4A;
    u8 height_4B;
} TileRenderer;

typedef struct {
    u8 unknown_00[0x14];
    void *second;
    void *first;
    u8 unknown_1C[0x68C - 0x1C];
    u8 text[0xBF5 - 0x68C];
    u8 ready;
} State;

typedef struct {
    u8 unknown_00[0x10];
    u8 *tiles;
} Graphics;

extern u8 data_02003CB0[];
extern State *data_03002818;
extern Graphics data_03002740;
extern TileRenderer data_030009E0[];
extern u8 data_0600B4E0[];
extern const u8 *data_085668B0[];

/* Local ordinary call views follow root transport and complete saved entries. */
extern TileRenderer *func_0808A268(s32 index, u8 style, void *first, void *second,
    void *plane0, void *plane1, void *extra0, void *extra1,
    u8 x0, u8 y0, u8 width0, u8 height0,
    u8 x1, u8 y1, u8 width1, u8 height1, u8 width, u8 height);
extern void func_0814186C(const void *source, void *destination, u32 control);
extern u16 *func_0808B8E4(u32 index, u32 plane, s32 x, s32 y);
extern void func_0808B7C0(int index, u16 *destination, u16 tile, u16 count, u16 flags);
extern u16 func_08015110(void *context, u8 *destination, const u8 *text, u8 mode, u8 reset);
extern void func_08016344(u16 *destination, u8 width, u8 height,
    u16 flags, u8 stride, u16 tile, u8 palette);
extern void func_08016560(u16 *destination, u8 width, u8 height,
    u16 flags, u8 stride, u16 tile, u8 palette);
extern u32 func_08018524(u8 *buffer, u16 tile, u8 variant);
extern void func_08035678(u16 value, u16 *destination, u32 count, u16 step);

void func_08074DC4(void)
{
    u8 *buffer = data_02003CB0;
    u16 fill;
    s32 i;
    const u8 *text;

    data_03002818->ready = 1;
    func_0808A268(4, 12, data_03002818->first, data_03002818->second,
        data_03002740.tiles, data_03002740.tiles + 0x108, 0, 0,
        17, 8, 12, 11, 17, 8, 12, 11, 12, 11);
    data_030009E0[4].x = 17;
    data_030009E0[4].y = 8;
    data_030009E0[4].tile = 0x1A7;
    data_030009E0[4].field_01 = 0;
    data_030009E0[4].flag_48 = 1;
    data_030009E0[4].flag_49 = 1;
    data_030009E0[4].width_4A = 11;
    data_030009E0[4].height_4B = 8;
    fill = 0;
    func_0814186C(&fill, data_0600B4E0, 0x01000580);
    for (i = 0; i < 8; i += 2) {
        func_0808B7C0(4, func_0808B8E4(4, 1, 1, i + 2),
            i * 11 + 0x1A7, 11, 0xC000);
        *func_0808B8E4(4, 1, 0, i + 3) = 0xD00C;
        if (i <= 4) {
            text = data_085668B0[(i >> 1) + 0x31];
            func_08015110(data_03002818->text, data_0600B4E0 + i * 352,
                text, 0, 1);
        }
    }
    func_08016344(data_030009E0[4].second_plane,
        data_030009E0[4].stride, data_030009E0[4].height,
        0xC0, data_030009E0[4].stride, 5, 12);
    func_08016560(data_030009E0[4].first_plane, 12, 11, 0xC0, 12, 1, 12);
    func_08035678(0xC03E, func_0808B8E4(4, 1, 1, 1),
        func_08018524(buffer, 0x3E, 3), 1);
    data_03002818->ready = 1;
}
