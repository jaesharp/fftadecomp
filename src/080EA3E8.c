#include "ffta.h"

typedef struct {
    u16 phase;
} Descriptor080EA3E8;

typedef struct {
    u16 counter;
    u16 unknown_02;
    void *display;
} Payload080EA3E8;

extern const u8 data_08398A80[];
extern void func_0801E610(u8 *first, u8 *second);
extern void *func_080D979C(u8, u8, u8, const void *, void *);
extern void func_080D984C(void *, u8, u8, u8);
extern void func_080D9B38(void *);
extern void func_080D9B58(void *);
extern void func_0801B878(void);

/* Complete [0x080EA3E8, 0x080EA4A0): 184 bytes. */
u32 func_080EA3E8(void *task, Descriptor080EA3E8 *descriptor,
                 Payload080EA3E8 *payload)
{
    switch (descriptor->phase) {
    case 0:
        payload->counter = 90;
        break;
    case 0x100:
        if (payload->counter != 0) {
            if (--payload->counter == 0) {
                u8 first;
                u8 second;
                u8 selected;

                func_0801E610(&first, &second);
                selected = second <= first ? second : first;
                payload->display = func_080D979C(2, selected, 0,
                                                 data_08398A80, task);
                func_080D984C(payload->display, 0, 16, 143);
                payload->counter = 210;
                descriptor->phase++;
            }
        }
        break;
    case 0x101:
        if (payload->counter != 0) {
            if (--payload->counter == 0) {
                func_080D9B38(payload->display);
                descriptor->phase++;
            }
        }
        break;
    case 0x102:
        func_080D9B58(payload->display);
        func_0801B878();
        descriptor->phase = 2;
        break;
    }
    return 0;
}
