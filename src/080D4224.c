#include "ffta.h"

typedef struct __attribute__((packed)) {
    u8 operation;
    u8 unknown_01[3];
    u16 offset;
} Command080D4224;

typedef struct __attribute__((packed)) {
    u16 value;
} EncodedHalfword080D4224;

typedef struct {
    const u8 *script;
    u16 start;
    u8 count;
    u8 flags;
    u8 unknown_08[2];
    u16 command_index;
} State080D4224;

typedef void (*Copy080D4224)(void *, const void *, u32);

extern Copy080D4224 const data_0836D4BC[];
extern u16 data_03003860[];
extern void func_081481AC(const u16 *, u16 *, u16);
extern void func_0814774C(const u16 *, u16 *, u16);
extern void func_08148214(const u16 *, u16 *, u16, u16, u16, u16);
extern void func_0814835C(u16 *, u16, u16);
extern void func_08148104(const u16 *, u16 *, u16, u16);
extern void func_0814814C(const u16 *, u16 *, u16, u16, u16, u16);
extern void func_08148274(const u16 *, u16 *, u16, u16, u8, u8);
extern void func_081482D4(const u16 *, u16 *, u16, u8);
extern void func_08148318(const u16 *, u16 *, u16, u8);
extern void func_081475A4(u16, u16, s16, s16, s16, u8);

#define DECODE16(p) (((const EncodedHalfword080D4224 *)(p))->value)

/* Complete target [0x080D4224, 0x080D4444): 544 bytes. */
void func_080D4224(State080D4224 *state)
{
    const Command080D4224 *command;
    const u8 *parameters;
    u16 start;

    command = (const Command080D4224 *)(state->script + 6) + state->command_index;
    parameters = state->script + command->offset;
    start = state->start;
    switch (command->operation) {
    case 0:
        data_0836D4BC[0](&data_03003860[start], parameters, state->count * 2);
        break;
    case 1:
        func_081481AC(&data_03003860[start], &data_03003860[start], state->count);
        break;
    case 2:
        func_0814774C(&data_03003860[start], &data_03003860[start], state->count);
        break;
    case 3:
        func_08148214(&data_03003860[start], &data_03003860[start], state->count,
                      DECODE16(parameters), DECODE16(parameters + 2), DECODE16(parameters + 4));
        break;
    case 4:
        func_0814835C(&data_03003860[start], DECODE16(parameters), state->count);
        break;
    case 5:
        func_08148104(&data_03003860[start], &data_03003860[start], state->count,
                      DECODE16(parameters));
        break;
    case 6:
        func_0814814C(&data_03003860[start], &data_03003860[start], state->count,
                      DECODE16(parameters), DECODE16(parameters + 2), DECODE16(parameters + 4));
        break;
    case 7:
        func_08148274(&data_03003860[start], &data_03003860[start], state->count,
                      DECODE16(parameters), parameters[2], parameters[3]);
        break;
    case 8:
        func_081482D4(&data_03003860[start], &data_03003860[start], state->count, parameters[0]);
        break;
    case 9:
        func_08148318(&data_03003860[start], &data_03003860[start], state->count, parameters[0]);
        break;
    case 12: {
        u8 previous = state->flags & 2;

        previous = previous != 0;

        func_081475A4(start, state->count, (s16)DECODE16(parameters),
                      (s16)DECODE16(parameters + 2), (s16)DECODE16(parameters + 4),
                      previous);
        state->flags |= 2;
        break;
    }
    case 10:
    case 11:
    case 13:
    default:
        break;
    }
}
