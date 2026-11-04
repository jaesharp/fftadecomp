#include "ffta.h"

typedef struct {
    u8 state;
} State0806FE14;

typedef struct {
    u8 unknown_0000[0x1a88];
    u8 context[0x29e4];
    u8 next;
} State0806B460;

typedef struct {
    u8 current;
} Command0806B460;

extern State0806B460 *data_0200F428;
extern u8 func_0806FE14(const State0806FE14 *);
extern void func_08141540(u16);

void func_0806B460(Command0806B460 *command)
{
    u8 *state = &command->current;

    if (func_0806FE14((const State0806FE14 *)data_0200F428->context) == 4) {
        func_08141540(100);
        command->current = 60;
        data_0200F428->next = 23;
    } else if (func_0806FE14((const State0806FE14 *)data_0200F428->context) == 1) {
        func_08141540(104);
        *state = 62;
        data_0200F428->next = 23;
    }
}
