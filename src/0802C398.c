#include "ffta.h"

typedef struct {
    u8 unknown_00[0x28];
    u16 flags;
} FlaggedObject0802C398;

typedef struct {
    u8 unknown_00[4];
    s16 x;
    s16 y;
    u8 unknown_08[4];
    FlaggedObject0802C398 *object;
    u16 flags;
} Owner0802C398;

typedef struct {
    u8 unknown_00[0x3a0];
    void *animation;
    void *position;
    u8 mode;
} State0802C398;

extern const u8 data_083916D0[];
extern const u8 data_083916E4[];
extern const u8 data_083916F2[];
extern const u8 data_083916FA[];
extern const u8 data_08391714[];
extern const u8 data_08391722[];

extern State0802C398 *data_0200F440;
extern void func_08021E64(void *animation, u8 mode);
extern void func_08021F18(void *position, s32 x, s32 y, s32 arg3,
                        s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                        s32 arg8, s32 arg9);
extern void func_08001F34(const void *source, s32 x, s32 y, u8 variant,
                        u8 flip_x, u8 flip_y, u8 flag_28, u8 flag_29,
                        u32 value, u8 mode, const void *transform);
extern void func_08001CF0(const void *source, s32 x, s32 y, u8 mode,
                        u8 first_flag, u8 second_flag, u8 third_flag,
                        u8 fourth_flag, u32 value, u8 count, u32 extra);
extern u8 func_080C82B8(const FlaggedObject0802C398 *object);

/* Complete target [0x0802C398, 0x0802C540), 424 bytes. */
void func_0802C398(Owner0802C398 *owner)
{
    u16 active = owner->flags & 0x10;
    if (active) {
        func_08021E64(data_0200F440->animation, data_0200F440->mode);
        func_08021F18(data_0200F440->position, owner->x + 44,
                      owner->y + 16, 0, 0, 0, 0, 0, 0, 0);
        func_08001F34(data_08391714, owner->x + 28,
                      owner->y + 8, 0, 0, 0, 0, 0, 0, 0,
                      (const void *)12);
        func_08001F34(data_08391722, owner->x + 20,
                      owner->y, 1, 0, 0, 0, 0, 0, 1,
                      (const void *)11);
    } else {
        u32 extra = 12;
        s16 x = owner->x;
        if ((owner->flags & 0x42) == 0x40)
            x -= 8;
        if (owner->flags & 2)
            extra = 11;
        func_08001CF0(data_083916D0, (s16)x,
                      owner->y - 16, 0, 0, 0, 0, 0, 0, 0, extra);
        func_08001CF0(data_083916E4, owner->x,
                      owner->y, 0, 0, 0, 0, 0, 0, 0, 12);
        if (func_080C82B8(owner->object)) {
            const void *source = data_083916F2;
            s32 x;
            if (owner->flags & 0x40)
                x = owner->x - 8;
            else
                x = owner->x + 80;
            func_08001CF0(source, x, owner->y,
                          0, 0, 0, 0, 0, 0, 0, 12);
        }
        {
            const void *source = data_083916FA;
            s32 x = owner->x;
            if (!(owner->flags & 0x40))
                x += 80;
            func_08001CF0(source, x, owner->y, 1, 0, 0,
                          !(owner->flags & 0x40), 0, 0, 0, 11);
        }
    }
}
