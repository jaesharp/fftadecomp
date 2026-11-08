#include "ffta.h"

typedef struct {
    void *object;
    u8 first;
    u8 second;
    u8 mode;
    u8 enabled;
    s8 x;
    u8 y;
    u16 unknown0A;
    void *source;
    void *destination;
} Parameters;

typedef struct {
    u16 phase;
    u16 unknown02;
    Parameters *parameters;
    u32 unknown08[5];
} Request;

typedef u32 (*TaskCallback)(void *task, void *descriptor, void *payload);

extern u32 func_080DB00C(void *task, void *descriptor, void *payload);
extern void *func_08005B6C(TaskCallback callback, u16 payload_size,
                          void *descriptor, void *parent);

/* Complete [0x080DC1E8, 0x080DC224): 60 bytes. */
void *func_080DC1E8(void *object, u8 first, u8 second, u8 mode,
                   void *source, void *destination, void *parent)
{
    Request request;
    Parameters parameters;

    parameters.object = object;
    parameters.first = first;
    parameters.second = second;
    parameters.mode = mode;
    parameters.source = source;
    parameters.destination = destination;
    parameters.enabled = 0;
    request.parameters = &parameters;
    return func_08005B6C(func_080DB00C, 0x1118, &request, parent);
}
