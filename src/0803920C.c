#include "ffta.h"

/* Build the seven-record display window; complete target is 384 bytes. */
typedef struct {
    u8 unknown_00;
    u8 kind;
    u16 unknown_02;
    u32 first;
    u32 second;
    u32 unknown_0C;
} Record0803920C;

typedef struct {
    u8 kind;
    u8 unknown_01[3];
    u32 first;
    u32 second;
} Display0803920C;

typedef struct {
    u8 mode;
    u8 unknown_01[3];
} Style0803920C;

typedef struct {
    u8 unknown_000[0x4DC];
    u8 first;
    u8 unknown_4DD[2];
    u8 enabled;
    Record0803920C records[20];
    Display0803920C display[7];
    u8 unknown_674[0x868];
    Style0803920C styles[7];
} State0803920C;

extern State0803920C *g_state_03002810;

void func_0803920C(void)
{
    u16 output = 0;
    u16 position;
    s32 i;
    s32 count;

    for (position = g_state_03002810->first;
         position < g_state_03002810->first + 7; position++) {
        u16 slot = position % 20U;
        g_state_03002810->display[output].first = g_state_03002810->records[slot].first;
        g_state_03002810->display[output].second = g_state_03002810->records[slot].second;
        if (position == g_state_03002810->first + 6) {
            g_state_03002810->display[output].kind = g_state_03002810->records[slot].kind + 4;
        } else {
            u8 kind = g_state_03002810->records[slot].kind;
            u8 next_kind = g_state_03002810->records[(position + 1) % 20].kind;
            if (kind <= 1) {
                if (next_kind > 1)
                    g_state_03002810->display[output].kind = kind + 8;
                else
                    g_state_03002810->display[output].kind = kind;
            } else {
                if (next_kind <= 1)
                    g_state_03002810->display[output].kind = kind + 4;
                else
                    g_state_03002810->display[output].kind = kind;
            }
        }
        output++;
    }
    count = 7;
    for (i = 0; i < count; i++) {
        u8 kind = g_state_03002810->records[(i + g_state_03002810->first) % 20].kind;
        if (g_state_03002810->enabled == 0)
            g_state_03002810->styles[i].mode = 0;
        else if (kind <= 1)
            g_state_03002810->styles[i].mode = 0x60;
        else
            g_state_03002810->styles[i].mode = 0x70;
    }
}
