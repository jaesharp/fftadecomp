#include "ffta.h"

typedef struct {
    u8 head_low;
    u8 head_high;
    u8 selected_low;
    u8 selected_high;
    u8 count_low;
    u8 count_high;
} Owner08006DA0;

typedef struct {
    u8 unknown_00[8];
    u8 previous_low;
    u8 previous_high;
    u8 next_low;
    u8 next_high;
} Block08006DA0;

extern void func_08006D38(void *owner);

static inline u16 read_offset08006DA0(const u8 *field)
{
    u32 low = field[0];
    u32 high = field[1];
    return (high << 8) | low;
}

static inline Block08006DA0 *decode_offset08006DA0(Owner08006DA0 *owner, u16 offset)
{
    return offset ? (Block08006DA0 *)((u8 *)owner + offset * 4) : 0;
}

/* Complete target [0x08006DA0, 0x08006E26): 134 bytes, 66 instructions. */
/* Target bytes: 70b5041c0b1c197a587a00020843002802d08000201800e00020051c987ad97a0a020243061c002a02d09000201800e00020021c002d05d008023043a872000ae87204e0080230432070000a6070002a06d0197a587a000208431072000a507200209872d87218725872217960790002084301382071000a6071201cfff78cff70bc01bc0047 */
void func_08006DA0(Owner08006DA0 *owner, Block08006DA0 *block)
{
    Block08006DA0 *previous = decode_offset08006DA0(owner,
        read_offset08006DA0(&block->previous_low));
    Block08006DA0 *next = decode_offset08006DA0(owner,
        block->next_low | (block->next_high << 8));
    u16 value;

    if (previous) {
        value = block->next_low | (block->next_high << 8);
        previous->next_low = value;
        previous->next_high = value >> 8;
    } else {
        value = block->next_low | (block->next_high << 8);
        owner->head_low = value;
        owner->head_high = value >> 8;
    }
    if (next) {
        value = read_offset08006DA0(&block->previous_low);
        next->previous_low = value;
        next->previous_high = value >> 8;
    }
    block->next_low = 0;
    block->next_high = 0;
    block->previous_low = 0;
    block->previous_high = 0;
    value = read_offset08006DA0(&owner->count_low);
    value--;
    owner->count_low = value;
    owner->count_high = value >> 8;
    func_08006D38(owner);
}
