#include "ffta.h"

typedef struct {
    u8 unknown_00[0x11];
    u8 row;
    u8 unknown_12[2];
} Cursor080845B4;

typedef struct {
    u8 unknown_00[0x36];
    u8 selection;
    u8 unknown_37[0x41];
    u8 list[0x20];
    Cursor080845B4 cursor;
    u8 settings[0x20];
} Slot080845B4;

typedef struct {
    u8 unknown_0000[0x2c88];
    Slot080845B4 slots[1];
} State080845B4;

extern State080845B4 *data_03002818;
extern void func_08017FBC(void *settings, u32 direction);
extern void func_08017AF4(void *list, s32 row, u32 mode);
extern void func_08017FB0(Cursor080845B4 *cursor, u8 row);
extern u16 func_08017B68(void *list, s32 row);
extern void func_08084A98(u32 index, s32 row, void *list);
extern void func_08017884(void *list, u32 direction, u32 mode);

/* Target [0x080845B4, 0x080846B0), 252 bytes:
 * f0b557464e464546e0b481b08246141c1d1c0906090e00912406240e2d062d0e194fcc20514641438846184e464438688019ac30009993f7e7fc3868801978302406a1462416211c93f7b4fa002d21d1386880197830211c0b2293f771fa3868801998304a46110e93f7c8fc38684044b42189014018211c93f79cfa39684144034a891808702ce018280003882c0000be2c00003a68921978325046211c00f021fa38684044b42189014018211c93f781fa396841440f4a891808703868801978300099012293f703f93968881978304144094a89180978090609160b2293f72ffa01b038bc9846a146aa46f0bc01bc00470000be2c0000312d0000
 */
void func_080845B4(u32 index, u8 direction, u8 row, u8 refresh)
{
    s8 selected;

    func_08017FBC(data_03002818->slots[index].settings, direction);
    selected = row;
    func_08017B68(data_03002818->slots[index].list, selected);
    if (!refresh) {

        func_08017AF4(data_03002818->slots[index].list, selected, 11);
        func_08017FB0(&data_03002818->slots[index].cursor, (u8)selected);
        data_03002818->slots[index].selection =
            func_08017B68((u8 *)data_03002818 + index * sizeof(Slot080845B4) + 0x2d00,
                          selected);
    } else {

        func_08084A98(index, selected, data_03002818->slots[index].list);
        data_03002818->slots[index].selection =
            func_08017B68((u8 *)data_03002818 + index * sizeof(Slot080845B4) + 0x2d00,
                          selected);
        func_08017884(data_03002818->slots[index].list, direction, 1);
        func_08017AF4(data_03002818->slots[index].list,
                      (s8)data_03002818->slots[index].cursor.row, 11);
    }
}
