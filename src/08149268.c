#include "ffta.h"

typedef struct {
    u8 unknown_00[0x980];
    u8 category : 7;
    u8 active : 1;
    u8 unknown_981[3];
    u8 field_984;
    u8 field_985;
} CategoryState08149268;

static inline void reset_category(CategoryState08149268 *state)
{
    state->category = 0;
    state->field_984 = 0;
    state->field_985 = 0;
}

/* Complete 0x08149268..0x081492A8: conditionally reset category fields. */
void func_08149268(CategoryState08149268 *state)
{
    if (state->category != 0)
        reset_category(state);
}
