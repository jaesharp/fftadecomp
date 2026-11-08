#include "ffta.h"

void func_08006C88(void *owner, u16 count, u8 **before, u8 **selected);
void func_08006D38(void *owner);

static inline u16 read_field(const u8 *field)
{
    u8 low = field[0];
    u8 high = field[1];

    return ((u16)high << 8) | low;
}

static inline void write_field(u8 *field, u16 value)
{
    field[0] = value;
    field[1] = value >> 8;
}

static inline u16 block_offset(u8 *owner, u8 *block)
{
    return block != 0 ? (block - owner) >> 2 : 0;
}

void func_08006E28(u8 *owner, u8 *block)
{
    u8 *before;
    u8 *selected;
    u16 offset;
    u16 count;
    u8 count_low;

    func_08006C88(owner, read_field(block + 6), &before, &selected);
    offset = block_offset(owner, block);
    if (before != 0) {
        write_field(before + 10, offset);
    } else {
        write_field(owner, offset);
    }
    if (selected != 0) {
        write_field(selected + 8, offset);
    }
    write_field(block + 8, block_offset(owner, before));
    write_field(block + 10, block_offset(owner, selected));
    count_low = owner[4];
    count = (owner[5] << 8) | count_low;
    count++;
    owner[4] = count;
    owner[5] = count >> 8;
    func_08006D38(owner);
}
