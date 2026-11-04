#include "ffta.h"

struct Unit {
    u8 unknown_00[0xF6];
    u8 x;
    u8 y;
};

struct Owner {
    struct Unit *unit;
};

struct Context {
    struct Owner *owner;
    u8 unknown_04[4];
    struct Owner **negative;
    struct Owner **positive;
    u16 negative_count;
    u16 positive_count;
};

extern int abs(int value);
extern u8 func_080C8280(const void *object);

/* Complete [0x080C4A40, 0x080C4B20): 224 bytes. */
int func_080C4A40(struct Context *context, u8 x, u8 y)
{
    s16 score = 0;
    int i;

    for (i = 0; i < context->positive_count; i++) {
        struct Owner *other = context->positive[i];

        if (other != context->owner && !func_080C8280(other->unit)) {
            int value = abs(other->unit->y - y) + 32;
            score += value - abs(other->unit->x - x);
        }
    }
    for (i = 0; i < context->negative_count; i++) {
        struct Owner *other = context->negative[i];

        if (other != context->owner && !func_080C8280(other->unit)) {
            int value = abs(other->unit->y - y) + 32;
            score -= value - abs(other->unit->x - x);
        }
    }
    return score;
}
