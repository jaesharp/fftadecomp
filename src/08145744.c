#include "ffta.h"

typedef struct {
    u8 status;
    u8 unknown_01[0x3F];
} SoundChannel08145744;

typedef struct {
    u32 signature;
    u8 unknown_04[0x18];
    SoundChannel08145744 *external_channels;
    u8 unknown_20[0x0C];
    void (*stop_channel)(u8);
    u8 unknown_30[0x20];
    SoundChannel08145744 channels[12];
} SoundState08145744;

extern SoundState08145744 *data_03007FF0;

/* Complete target [0x08145744, 0x08145798): 84 bytes, 37 instructions. */
void func_08145744(void)
{
    SoundState08145744 *sound = data_03007FF0;
    SoundChannel08145744 *channel;
    int count;

    if (sound->signature != 0x68736D53)
        return;
    sound->signature++;
    count = 12;
    channel = sound->channels;
    do {
        channel->status = 0;
        count--;
        channel++;
    } while (count > 0);
    channel = sound->external_channels;
    if (channel) {
        for (count = 1; count <= 4; count++, channel++) {
            sound->stop_channel((u8)count);
            channel->status = 0;
        }
    }
    sound->signature = 0x68736D53;
}
