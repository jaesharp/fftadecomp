#include "ffta.h"

typedef struct {
    u32 value;
} ObjectRecord;

typedef struct {
    u16 code;
    u16 unknown_02;
    ObjectRecord *record;
    void *object;
    u8 unknown_0C[8];
    u16 angle;
    u16 parameter;
    u8 unknown_18[4];
} EffectRequest;

typedef struct {
    u8 unknown_00[6];
    u8 mode;
    u8 unknown_07;
    u16 angle;
    u16 unknown_0A;
    void *object;
    void *child;
    ObjectRecord *record;
} EffectState;

typedef u32 (*EffectCallback)(void *, void *, void *);

extern void *func_08005B6C(EffectCallback, u16, void *, void *);
extern void func_080D38B4(void);
extern u32 func_080DD47C(ObjectRecord *record);
extern void *func_080E051C(void *object);
extern u32 func_080E3788(void *, void *, void *);

/* Complete target: [0x08100E58, 0x08100EF0), 152 bytes. */
u32 func_08100E58(void *owner, EffectRequest *event, EffectState *state)
{
    EffectRequest request;

    switch (event->code) {
    case 0:
        state->angle = event->angle;
        state->mode = event->parameter;
        state->record = event->record;
        state->object = (void *)func_080DD47C(state->record);
        break;
    case 1:
        func_080D38B4();
        break;
    case 0x100:
        request.angle = state->angle;
        request.parameter = 0;
        request.record = state->record;
        request.object = state->object;
        state->child = func_08005B6C(func_080E3788, 0x34, &request, owner);
        event->code++;
        break;
    case 0x101:
        state->child = func_080E051C(state->child);
        if (state->child == 0)
            event->code++;
        break;
    case 0x102:
        event->code = 2;
        break;
    }
    return 0;
}
