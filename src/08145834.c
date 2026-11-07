#include "ffta.h"

/* 0x08145834..0x081458AC, 120 bytes including reached literals. */
struct Player;
typedef void (*PlayerCallback)(struct Player *);

struct Track {
    u8 status;
    u8 unknown_01[0x4F];
};

struct Player {
    u32 unknown_00;
    u32 status;
    u8 track_count;
    u8 unknown_09[0x23];
    struct Track *tracks;
    u32 unknown_30;
    u32 signature;
    PlayerCallback previous_callback;
    struct Player *previous_player;
};

struct Scheduler {
    u32 signature;
    u32 unknown_04[7];
    PlayerCallback callback;
    struct Player *player;
};

extern struct Scheduler *data_03007FF0;
extern void func_08145528(void *);
extern void func_08144B2C(struct Player *);

void func_08145834(struct Player *player, struct Track *tracks, u8 count)
{
    struct Scheduler *scheduler;

    if (count == 0)
        return;
    if (count > 16)
        count = 16;

    scheduler = data_03007FF0;
    if (scheduler->signature != 0x68736D53)
        return;
    scheduler->signature++;
    func_08145528(player);
    player->tracks = tracks;
    player->track_count = count;
    player->status = 0x80000000;

    while (count != 0) {
        tracks->status = 0;
        count--;
        tracks++;
    }

    if (scheduler->callback != 0) {
        player->previous_callback = scheduler->callback;
        player->previous_player = scheduler->player;
        scheduler->callback = 0;
    }
    scheduler->player = player;
    scheduler->callback = func_08144B2C;
    scheduler->signature = 0x68736D53;
    player->signature = 0x68736D53;
}
