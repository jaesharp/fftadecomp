#include "ffta.h"

typedef struct {
    u8 unknown_00[8];
    s16 x;
    s16 y;
    s16 z;
} Object080A9A48;

typedef struct {
    Object080A9A48 *object;
    u8 unknown_04[0x20];
    s16 first_values[3];
    s16 second_values[3];
    s16 counters[3];
    u8 unknown_36[0x0A];
    u8 flags;
} Entry080A9A48;

extern void func_0801C984(s16 first, s16 second, s16 third,
                         s16 *first_output, s16 *second_output);

/* The actual root reads signed object coordinates at 8/10/12 and three
 * signed-halfword arrays at 0x24/0x2A/0x30. Published 080A9940 independently
 * establishes the incoming entry's object pointer and flags byte at 0x40.
 * Complete 0801C984 narrows all three coordinates to their low signed halves
 * and consumes two output pointers, the second through incoming stack word0.
 * These are local compatibility views, not claims of unique historical types,
 * object capacity, whole-program initialization or helper memory effects.
 */
void func_080A9A48(Entry080A9A48 *entry)
{
    s16 first_output;
    s16 second_output;
    s32 i;

    if (!(entry->flags & 2))
        return;

    func_0801C984(entry->object->x, entry->object->y, entry->object->z,
                  &first_output, &second_output);
    for (i = 0; i < 3; i++) {
        if (entry->counters[i] > 6)
            return;
        if (entry->counters[i] > 0 &&
            entry->first_values[i] == first_output &&
            entry->second_values[i] == second_output)
            return;
    }
    for (i = 0; i < 3; i++) {
        if (entry->counters[i] <= 0) {
            entry->counters[i] = 8;
            entry->first_values[i] = first_output;
            entry->second_values[i] = second_output;
            return;
        }
    }
}
