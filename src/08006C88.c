#include "ffta.h"

typedef struct {
    u8 head_low;
    u8 head_high;
    u8 selected_low;
    u8 selected_high;
    u8 count_low;
    u8 count_high;
} Owner08006C88;

typedef struct {
    u8 unknown_00[6];
    u8 size_low;
    u8 size_high;
    u8 previous_low;
    u8 previous_high;
    u8 next_low;
    u8 next_high;
} Block08006C88;

static inline u16 read_field08006C88(const u8 *field)
{
    u32 low = field[0];
    u32 high = field[1];
    return (high << 8) | low;
}

static inline Block08006C88 *decode_offset08006C88(Owner08006C88 *owner, u16 offset)
{
    return offset ? (Block08006C88 *)((u8 *)owner + offset * 4) : 0;
}

/* Complete target [0x08006C88, 0x08006D36): 174 bytes, 87 instructions. */
/* Target bytes: f0b5051c161c1f1c09040c0c002038603060a978e87800020843002802d08000281800e00020031c002b3dd09979d87900020843844228d80be09979d87900020843844205d99179d07900020843844228d91a1c117a507a00020843002802d08000281800e00020031c002be5d119e09979d87900020843844205d99179d0790002084384420dd9131c997ad87a00020843002802d08000281800e00020021c002ae5d133603a60f0bc01bc0047 */
void func_08006C88(Owner08006C88 *owner, u16 count,
                  Block08006C88 **before, Block08006C88 **selected)
{
    Block08006C88 *lower;
    Block08006C88 *upper;

    *selected = 0;
    *before = 0;
    lower = decode_offset08006C88(owner, read_field08006C88(&owner->selected_low));
    if (lower) {
        if (count <= read_field08006C88(&lower->size_low)) {
            while ((upper = lower,
                    lower = decode_offset08006C88(owner,
                        read_field08006C88(&upper->previous_low))) != 0) {
                if (count > read_field08006C88(&lower->size_low) &&
                    count <= read_field08006C88(&upper->size_low))
                    break;
            }
        } else {
            while ((upper = decode_offset08006C88(owner,
                    read_field08006C88(&lower->next_low))) != 0) {
                if (count > read_field08006C88(&lower->size_low) &&
                    count <= read_field08006C88(&upper->size_low))
                    break;
                lower = upper;
            }
        }
        *before = lower;
        *selected = upper;
    }
}
