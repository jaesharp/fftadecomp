#include "ffta.h"

typedef struct {
    u8 unknown_00[0x0A];
    u8 x, y, z;
    u8 width, height, depth;
} MapBox0801CB20;

extern MapBox0801CB20 data_02007F10;
extern void func_0801C918(s16 first, s16 second, s16 third,
                         s16 *first_output, s16 *second_output, s16 *third_output);

/* Complete target [0x0801CB20, 0x0801CBE8): 200 bytes including its literal. */
void func_0801CB20(s16 *first_output, s16 *second_output, s16 *third_output)
{
    s16 position[3];
    s16 *first = &position[0];
    s16 *second = &position[1];
    s16 *third = &position[2];
    u8 box[6];
    u8 *width = &box[0];
    u8 *depth = &box[1];
    u8 *x = &box[2];
    u8 *z = &box[3];

    *width = data_02007F10.width;
    *depth = data_02007F10.depth;
    *x = data_02007F10.x;
    *z = data_02007F10.z;
    {
    u8 *height = &box[4];
    u8 *y = &box[5];
    *height = data_02007F10.height;
    *y = data_02007F10.y;
    *first = ((*width << 5) + 16) >> 1;
    *second = (*height - *y) << 3;
    *third = ((*depth << 5) + 16) >> 1;
    *first += 16 + (*x << 5);
    *second += *y << 4;
    *third += 16 + (*z << 5);
    func_0801C918(position[0], *second, *third,
                  first_output, second_output, third_output);
    }
}
