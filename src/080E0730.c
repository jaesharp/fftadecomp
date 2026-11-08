#include "ffta.h"

struct Task;

struct CurveConfiguration {
    u16 from_x;
    u16 from_y;
    u16 to_x;
    u16 to_y;
    u16 radius;
    u8 direction;
    u8 unknown0b;
    u16 duration;
    u16 unknown0e;
    const void *x_curve;
    const void *y_curve;
};

struct CurveRequest {
    u16 phase;
    u16 unknown02;
    const struct CurveConfiguration *configuration;
    u32 unknown08[5];
};

struct CurveInitialization {
    struct CurveRequest request;
    struct CurveConfiguration configuration;
};

extern s32 func_080DFF8C(struct Task *, struct CurveRequest *, void *);
extern struct Task *func_08005B6C(s32 (*)(struct Task *, struct CurveRequest *, void *),
                                u16, struct CurveRequest *, struct Task *);

struct Task *func_080E0730(u16 from_x, u16 from_y, u16 to_x, u16 to_y,
                         u16 radius, u8 direction, u16 duration,
                         const void *x_curve, const void *y_curve,
                         struct Task *parent)
{
    struct CurveInitialization initialization;
    struct CurveConfiguration *configuration = &initialization.configuration;

    configuration->from_x = from_x;
    configuration->from_y = from_y;
    configuration->to_x = to_x;
    configuration->to_y = to_y;
    configuration->radius = radius;
    configuration->direction = direction;
    configuration->duration = duration;
    configuration->x_curve = x_curve;
    configuration->y_curve = y_curve;
    initialization.request.configuration = &initialization.configuration;
    return func_08005B6C(func_080DFF8C, 0x60, &initialization.request, parent);
}
