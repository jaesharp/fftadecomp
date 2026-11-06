#include "ffta.h"

/* Complete target: 490 bytes. */
typedef struct __attribute__((packed)) PackedCommand {
    u8 operation;
    u8 unknown01;
    u16 length;
    u16 data_offset;
} PackedCommand;

typedef struct __attribute__((packed)) PackedHalfword {
    u16 value;
} PackedHalfword;

typedef struct CommandState {
    const u8 *data;
    u16 first;
    u8 count;
    u8 unknown07[3];
    u16 current;
    u8 unknown0C[4];
    u32 result;
} CommandState;

#define READ16(p) (((const PackedHalfword *)(p))->value)

extern u32 func_08147D2C(u16, u16, u16, const u16 *);
extern u32 func_08147B28(u16, u16, u16);
extern u32 func_08147BA4(u16, u16, u16);
extern u32 func_08147C2C(u16, u16, u16, u16, u16, u16);
extern u32 func_08147CC0(u16, u16, u16, u16, u16, u16);
extern u32 func_0814731C(u16, u16, u16, u16);
extern u32 func_081473E4(u16, u16, u16, u16, u16, u16);
extern u32 func_08147D94(u16, u16, u16, u16, u8, u8);
extern u32 func_08147EC8(u16, u16, u16, u8);
extern u32 func_08147F50(u16, u16, u16, u8);
extern u32 func_08147FD8(u16, u16, u16, u16, u16);
extern u32 func_08148034(u16, u16, u16, u16, u16, const u8 *);

void func_080D4038(CommandState *state)
{
    const PackedCommand *command = (const PackedCommand *)(
        state->data + (state->current * 6 + 6));
    const u8 *parameters = state->data + command->data_offset;
    u16 first = state->first;

    switch (command->operation) {
    case 0:
        state->result = func_08147D2C(first, state->count,
            command->length, (const u16 *)parameters);
        break;
    case 1:
        state->result = func_08147B28(first, state->count,
            command->length);
        break;
    case 2:
        state->result = func_08147BA4(first, state->count,
            command->length);
        break;
    case 3:
        state->result = func_08147C2C(first, state->count,
            command->length, READ16(parameters),
            READ16(parameters + 2), READ16(parameters + 4));
        break;
    case 4:
        state->result = func_08147CC0(first, state->count,
            command->length, READ16(parameters) & 0x1F,
            (READ16(parameters) & 0x3E0) >> 5,
            (READ16(parameters) & 0x7C00) >> 10);
        break;
    case 5:
        state->result = func_0814731C(first, state->count,
            command->length, READ16(parameters));
        break;
    case 6:
        state->result = func_081473E4(first, state->count,
            command->length, READ16(parameters),
            READ16(parameters + 2), READ16(parameters + 4));
        break;
    case 7:
        state->result = func_08147D94(first, state->count,
            command->length, READ16(parameters),
            parameters[2], parameters[3]);
        break;
    case 8:
        state->result = func_08147EC8(first, state->count,
            command->length, parameters[0]);
        break;
    case 9:
        state->result = func_08147F50(first, state->count,
            command->length, parameters[0]);
        break;
    case 10:
        state->result = func_08147FD8(first, state->count, parameters[0],
            command->length, parameters[1] != 0);
        break;
    case 11:
        state->result = func_08148034(first, state->count, parameters[0],
            command->length, parameters[1] != 0, parameters + 2);
        break;
    }
}
