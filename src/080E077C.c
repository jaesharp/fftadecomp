#include "ffta.h"

typedef struct {
    s16 start_x;
    s16 start_y;
    s16 start_z;
    s16 end_x;
    s16 end_y;
    s16 end_z;
    s16 midpoint_bias;
    u16 samples;
    s16 *output_x;
    s16 *output_y;
    s16 *output_z;
} CurveTaskParameters;

typedef struct {
    u16 phase;
    u16 unknown_02;
    const CurveTaskParameters *parameters;
    u32 unknown_08[5];
} CurveTaskRequest;

typedef u32 (*TaskCallback)(void *task, void *request, void *payload);

extern u32 func_080E0240(void *task, void *request, void *payload);
extern void *func_08005B6C(TaskCallback callback, u16 payload_size,
                          void *request, void *parent);

void *func_080E077C(s16 start_x, s16 start_y, s16 start_z,
                    s16 end_x, s16 end_y, s16 end_z,
                    s16 midpoint_bias, u16 samples,
                    s16 *output_x, s16 *output_y, s16 *output_z,
                    void *parent)
{
    CurveTaskRequest request;
    CurveTaskParameters parameters = {
        start_x, start_y, start_z,
        end_x, end_y, end_z,
        midpoint_bias, samples,
        output_x, output_y, output_z
    };
    request.parameters = &parameters;
    return func_08005B6C(func_080E0240, 0x4C, &request, parent);
}
