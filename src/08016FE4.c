#include "ffta.h"

typedef struct Rectangle {
    u8 left;
    u8 top;
    u8 width;
    u8 height;
} Rectangle;

typedef struct Region16FE4 {
    u16 *primary;
    u16 *secondary;
    const u16 *primary_pattern;
    const u16 *secondary_pattern;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u8 unknown_14[2];
    u8 stride;
    u8 unknown_17[5];
    u8 flags;
    u8 unknown_1D[2];
    u8 alignment;
    u16 content_width;
    u16 content_height;
} Region16FE4;

extern u16 func_080161A0(u8, u8, u8);
extern void func_08016AEC(u16 *, u8, const u16 *, Rectangle, u8);
extern void func_08016A98(u16 *, u8, u8, u16, u8);

static inline void set_rectangle(Rectangle *area, u8 left, u8 top,
                                  u8 width, u8 height)
{
    area->left = left;
    area->top = top;
    area->width = width;
    area->height = height;
}

/* Complete target [0x08016FE4, 0x0801717E), 410 bytes. */
void func_08016FE4(Region16FE4 *region)
{
    Rectangle area;
    u16 offset;

    if (region->flags & 8) {
        set_rectangle(&area, 0, 0, 30, region->height + 2);
    } else {
        set_rectangle(&area, 0, 0, region->width, region->height);
    }
    offset = func_080161A0(region->x, region->y, region->stride);
    if (region->primary_pattern) {
        if (region->flags & 8) {
            u16 *destination = region->primary + func_080161A0(0, region->y - 1, region->stride);
            func_08016AEC(destination, region->stride, region->primary_pattern, area, 30);
        } else {
            func_08016AEC(region->primary + offset, region->stride,
                         region->primary_pattern, area, region->width);
        }
    } else if (region->alignment & 0x10) {
        func_08016A98(region->primary + offset, region->width,
                      region->height, 0, region->stride);
    } else {
        if (region->alignment & 1)
            offset += (region->width - (s16)region->content_width) >> 1;
        else if (region->alignment & 2)
            offset += region->width - region->content_width;
        func_08016A98(region->primary + offset, region->content_width,
                      region->content_height, 0, region->stride);
    }

    if (region->secondary_pattern) {
        if (region->flags & 8) {
            u16 *destination = region->secondary + func_080161A0(0, region->y - 1, region->stride);
            func_08016AEC(destination, region->stride, region->secondary_pattern, area, 30);
        } else {
            func_08016AEC(region->secondary + offset, region->stride,
                         region->secondary_pattern, area, region->width);
        }
    } else if (region->alignment & 0x10) {
        func_08016A98(region->secondary + offset, region->width,
                      region->height, 0, region->stride);
    } else {
        func_08016A98(region->secondary + offset, region->content_width,
                      region->content_height, 0, region->stride);
    }
}
