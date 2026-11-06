#include "ffta.h"

typedef struct {
    u16 state;
    u8 unknown_02[2];
    void *actor;
    u8 unknown_08[14];
    u16 selection;
} Command080FF180;

typedef struct {
    u8 selection;
    u8 unknown_01[3];
    void *object;
    void *actor;
    void *opening;
    u8 payload[8];
    void *position_task;
    void *closing;
    void *animation;
} Work080FF180;

extern const u8 data_0839E20C[];
extern const u8 data_0839E230[];
extern const u8 data_0839E274[];
extern const u8 data_0839E260[];

extern void func_080D38B4(void);
extern u8 func_080D3B54(void *actor);
extern void *func_080E03F8(void *actor, const void *script, u8 mode,
                           u8 variant, u32 value, void *parent);
extern void *func_080E05DC(void *task);
extern void *func_080DD47C(void *actor);
extern void func_080DE10C(void *object, u16 value);
extern void func_080DE3BC(void *object, u8 enabled);
extern void func_080DBDC8(void *object, s16 *x, s16 *y);
extern void *func_080D6098(s16 x, s16 y, s16 z, u8 mode, s16 layer,
                           void *payload, const void *script, void *parent);
extern void *func_080DFD8C(const void *script, u8 mode, u16 flags,
                           u16 value, void *parent);
extern u8 func_080D8858(void *actor, u16 flags);
extern void *func_080D6134(void *task);
extern void *func_080DD4A4(void *actor, u8 index);
extern void *func_080DCFE4(void *object, const void *script, u8 mode,
                           u16 first, u16 count, void *parent, s16 value);
extern void *func_080DBA5C(void *task);

/* Complete [0x080FF180, 0x080FF2C2): 322 bytes. */
u32 func_080FF180(void *parent, Command080FF180 *command, Work080FF180 *work)
{
    s16 x, y;

    switch (command->state) {
    case 0: {
        void *actor;
        u8 mode;

        work->selection = command->selection;
        actor = command->actor;
        work->actor = actor;
        mode = 3;
        if (work->selection)
            mode = 0;
        work->opening = func_080E03F8(actor, data_0839E20C,
                                     mode, 0, 0, parent);
        break;
    }
    case 1:
        func_080D38B4();
        break;
    case 0x100:
        work->opening = func_080E05DC(work->opening);
        if (work->opening == 0) {
            if (func_080D3B54(work->actor)) {
                command->state = 2;
            } else {
                work->object = func_080DD47C(work->actor);
                func_080DE10C(work->object, 0x24);
                func_080DE3BC(work->object, 1);
                func_080DBDC8(work->object, &x, &y);
                work->position_task = func_080D6098(x, y, 0, 1, 2,
                                                   work->payload,
                                                   data_0839E230, parent);
                work->animation = func_080DFD8C(data_0839E274, 1, 4, 0, parent);
                ++command->state;
            }
        }
        break;
    case 0x101:
        if (!func_080D8858(work->actor, 0)) {
            command->state = 2;
        } else {
            work->position_task = func_080D6134(work->position_task);
            if (work->position_task == 0) {
                work->closing = func_080DCFE4(func_080DD4A4(work->actor, 0),
                                             data_0839E260, 12, 0, 4, parent, 0);
                ++command->state;
            }
        }
        break;
    case 0x102:
        work->closing = func_080DBA5C(work->closing);
        if (work->closing == 0)
            command->state = 2;
        break;
    }
    return 0;
}
