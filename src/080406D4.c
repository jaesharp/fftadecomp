#include "ffta.h"

typedef struct {
    u8 unknown_00[0x11];
    u8 row;
    u8 unknown_12[2];
} Cursor080406D4;

typedef struct {
    u8 unknown_00[0x78];
    u8 list[0x20];
    Cursor080406D4 cursor;
    u8 settings[0x14];
    u8 unknown_c0[0x0c];
} Slot080406D4;

typedef struct {
    u8 unknown_000[0x954];
    Slot080406D4 slots[1];
} State080406D4;

extern State080406D4 *g_state_03002810;
extern void func_08017FBC(void *, u32);
extern u16 func_08017B68(void *, u32);
extern void func_08017AF4(void *, u32, u32);
extern void func_08017FB0(Cursor080406D4 *, u8);
extern void func_08037DF0(u32, s32);
extern void func_08040B70(u32, s16, void *);
extern void func_08017884(void *, u32, u32);

/* Target [0x080406D4, 0x080407A4), 208 bytes:
 * f0b557464e464546e0b481b08046141c1d1c0906090e00912406240e2d062d0e154fcc20414641438a46144e564438688019ac300099d7f757fc3868801978302406a1462416211cd7f724fa002d17d1386880197830211c0b22d7f7e1f93868801998304a46110ed7f738fc4046211cf7f754fb22e0000010280003540900003a68921978324046211c00f007fa4046211cf7f743fb38688019783000990122d7f786f83968881978305144074a89180978090609160b22d7f7b2f901b038bc9846a146aa46f0bc01bc0047fd090000
 */
void func_080406D4(u32 index, u8 option, u8 row, u8 refresh)
{
    s8 selected;

    func_08017FBC(g_state_03002810->slots[index].settings, option);
    selected = row;
    func_08017B68(g_state_03002810->slots[index].list, selected);
    if (!refresh) {
        func_08017AF4(g_state_03002810->slots[index].list, selected, 11);
        func_08017FB0(&g_state_03002810->slots[index].cursor, (u8)selected);
        func_08037DF0(index, selected);
    } else {
        func_08040B70(index, selected, g_state_03002810->slots[index].list);
        func_08037DF0(index, selected);
        func_08017884(g_state_03002810->slots[index].list, option, 1);
        func_08017AF4(g_state_03002810->slots[index].list,
                      (s8)g_state_03002810->slots[index].cursor.row, 11);
    }
}
