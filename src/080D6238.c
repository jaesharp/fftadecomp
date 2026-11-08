#include "ffta.h"

struct Task;
struct Scene;

struct Coordinates3 {
    s16 x;
    s16 y;
    s16 z;
};

struct MotionConfiguration {
    struct Scene *scene;
    const struct Coordinates3 *from;
    const struct Coordinates3 *to;
    const s16 *x;
    const s16 *y;
    const s16 *z;
    u16 delay;
    u16 duration;
};

struct MotionRequest {
    u16 phase;
    u16 unknown02;
    const struct MotionConfiguration *configuration;
    u32 unknown08[3];
    u16 behavior;
    u16 unknown16;
    u32 unknown18;
};

extern s32 func_080D5128(struct Task *, struct MotionRequest *, void *);
extern struct Task *func_08005B6C(s32 (*)(struct Task *, struct MotionRequest *, void *),
                                u16, struct MotionRequest *, struct Task *);

struct Task *func_080D6238(struct Scene *scene, const struct Coordinates3 *from,
                         const struct Coordinates3 *to, u16 delay, u16 duration,
                         const s16 *x, const s16 *y, const s16 *z,
                         u16 behavior, struct Task *parent)
{
    struct MotionConfiguration configuration;
    struct MotionRequest request;

    configuration.scene = scene;
    configuration.from = from;
    configuration.to = to;
    configuration.delay = delay;
    configuration.duration = duration;
    configuration.x = x;
    configuration.y = y;
    configuration.z = z;
    request.behavior = behavior;
    request.configuration = &configuration;
    return func_08005B6C(func_080D5128, 0x54, &request, parent);
}
