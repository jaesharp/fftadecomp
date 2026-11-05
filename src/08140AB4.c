#include "ffta.h"

typedef struct {
    const u8 *image;
    s32 x;
    s32 y;
    s32 destination_x;
    s32 destination_y;
    s32 unknown_14;
    s32 lifetime;
    s32 speed;
    u16 scale;
    u16 frame;
} Particle;

extern u32 func_08002804(void);
extern s32 func_08142950(s32, s32);
extern const u8 data_083A9314[];
extern const u8 data_083A931C[];

void func_08140AB4(Particle *particle, s16 x, s16 y)
{
    s16 destination_x;
    s16 destination_y;

    particle->x = x << 8;
    particle->y = y << 8;
    destination_x = func_08142950((s16)func_08002804(), 241);
    destination_y = func_08142950((s16)func_08002804(), 161);
    if ((s16)func_08142950((s16)func_08002804(), 101) > 49) {
        if ((s16)func_08142950((s16)func_08002804(), 101) > 49)
            destination_x = 0;
        else
            destination_x = 240;
    } else {
        if ((s16)func_08142950((s16)func_08002804(), 101) > 49)
            destination_y = 0;
        else
            destination_y = 160;
    }
    particle->destination_x = destination_x << 8;
    particle->destination_y = destination_y << 8;
    particle->lifetime = 100;
    particle->scale = 256;
    particle->speed = (s16)func_08142950((s16)func_08002804(), 1281) + 512;
    switch ((s16)func_08142950((s16)func_08002804(), 3)) {
    case 0:
        particle->image = data_083A9314;
        break;
    case 1:
        particle->image = data_083A9314;
        particle->frame = 2;
        break;
    default:
        particle->image = data_083A931C;
        particle->frame = 4;
        break;
    }
}
