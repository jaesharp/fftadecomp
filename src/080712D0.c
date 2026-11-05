#include "ffta.h"

typedef struct {
    u8 unknown_000[0x95c];
    u8 count;
    u8 unknown_95d[0x2d];
    u8 pages;
} State080712D0;

extern State080712D0 *data_03002818;
extern u8 data_02003CB0[];
extern u8 data_06017B00[];
extern u8 data_06017D80[];
extern const u8 data_083B5A5C[];
typedef struct {
    u8 unknown_00[0x84];
    u8 enabled;
    u8 unknown_85[0x83];
} Unit080712D0;

extern Unit080712D0 g_state_02000000[];
extern u32 func_08005318(const u8 *archive, u8 *destination,
                         u16 first, u16 count);
extern void func_0814186C(const void *source, void *destination, u32 control);

/* Complete target [0x080712D0, 0x08071374), 164 bytes. */
void func_080712D0(void)
{
    s32 count;
    s32 i;
    u8 *buffer = data_02003CB0;
    u8 *destination = data_06017B00;
    const u8 *archive = data_083B5A5C;

    func_08005318(archive, buffer, 0x34, 1);
    func_0814186C(buffer, destination, 0x140);
    destination = data_06017D80;
    func_08005318(archive, buffer, 0x35, 1);
    func_0814186C(buffer, destination, 0x140);

    count = 0;
    for (i = 0; i < 24; i++) {
        if (g_state_02000000[i].enabled)
            count++;
    }
    data_03002818->count = count;
    data_03002818->pages = count / 4 + ((count & 3) != 0);
}
