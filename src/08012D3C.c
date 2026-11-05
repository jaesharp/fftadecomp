#include "ffta.h"

/* Complete [0x08012D3C,0x08012FD8), 668 bytes, 177 reached instructions. */
typedef struct {
    u8 unknown_00[0xA];
    u8 type;
    u8 unknown_0B[0xB];
    u16 scale;
    u16 limit;
    u8 width;
    u8 unknown_1B;
    u8 active;
    u8 unknown_1D[3];
    u16 counter;
    u8 unknown_22[0x1E];
    u8 row;
    u8 unknown_41[0x2F];
    u8 renderer[0x290];
    u8 *buffer;
    u8 *selected;
    const u8 *script;
} CommandState08012D3C;

extern CommandState08012D3C *data_0200918C;
extern const s8 data_0836D630[];
extern u8 func_0801843C(u8 type);
extern u8 func_08018484(u8 type);
extern void func_080135B8(void *renderer, s8 value);
extern void func_08013528(void *renderer, const void *source);
extern void func_080137C0(void *renderer, u8 selection);
extern void func_08013728(void *renderer, s16 amount);

void func_08012D3C(void)
{
    while (data_0200918C->script[0] == 0x40) {
        switch (data_0200918C->script[1]) {
        case 110:
            data_0200918C->selected += data_0200918C->width << 6;
            data_0200918C->row++;
            if (func_0801843C(data_0200918C->type))
                func_080135B8(data_0200918C->renderer,
                             data_0836D630[data_0200918C->row]);
            else
                func_08013528(data_0200918C->renderer,
                             data_0200918C->selected);
            if (func_08018484(data_0200918C->type))
                func_080137C0(data_0200918C->renderer, 5);
            data_0200918C->script += 2;
            break;
        case 120:
            data_0200918C->scale = 0x1000;
            data_0200918C->limit = 0x1000;
            data_0200918C->script += 2;
            break;
        case 117:
            data_0200918C->scale = 0x80;
            data_0200918C->limit = 0x100;
            data_0200918C->script += 2;
            break;
        case 107:
            data_0200918C->active = 1;
            data_0200918C->counter = 0;
            data_0200918C->script += 2;
            break;
        case 108:
            func_080137C0(data_0200918C->renderer,
                         data_0200918C->script[2]);
            data_0200918C->script += 3;
            break;
        case 60:
            func_08013728(data_0200918C->renderer,
                         -data_0200918C->script[2]);
            data_0200918C->script += 3;
            break;
        case 62:
            func_08013728(data_0200918C->renderer,
                         data_0200918C->script[2]);
            data_0200918C->script += 3;
            break;
        case 102:
            data_0200918C->script += 4;
            break;
        default:
            return;
        }
    }
}
