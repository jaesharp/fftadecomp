#include "ffta.h"

struct SelectionState;

/* Physical request copied as seven words by the scheduler. */
typedef struct {
    u16 state;
    u16 unknown_02;
    const struct SelectionState *selection;
    u8 unknown_08[0xC];
    u16 selector;
    u8 unknown_16[6];
} SelectionRequest08115AE4;

typedef u32 (*SelectionTaskCallback08115AE4)(void *task, void *request,
                                           void *payload);

extern u8 func_080DD494(const struct SelectionState *selection);
extern u32 func_0811584C(void *task, void *request, void *payload);
extern void *func_08005B6C(SelectionTaskCallback08115AE4 callback,
                         u16 payload_size, void *request, void *parent);

void *func_08115AE4(const struct SelectionState *selection, u8 selector,
                  void *parent)
{
    void *task;

    if (func_080DD494(selection)) {
        SelectionRequest08115AE4 request;

        request.selector = selector;
        request.selection = selection;
        task = func_08005B6C(func_0811584C, 0x30, &request, parent);
    } else {
        task = 0;
    }
    return task;
}
