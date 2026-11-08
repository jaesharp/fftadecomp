#include "ffta.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 unknown_06[2];
} Position;

typedef struct {
    u8 unknown_00[0x14];
} Projection;

typedef struct {
    Projection vertical;
    Projection planar;
    s16 difference_x;
    s16 difference_y;
    s16 difference_z;
    s16 distance;
    Position start;
    Position end;
} PathState;

extern void func_080A04E8(PathState *state, const Position *start,
                         const Position *end);

/* Complete [0x080A8050, 0x080A805A): 10 bytes. */
void func_080A8050(PathState *state, const Position *start,
                   const Position *end)
{
    func_080A04E8(state, start, end);
}
