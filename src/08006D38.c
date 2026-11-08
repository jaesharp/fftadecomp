#include "ffta.h"

static inline u32 read_word_offset(const u8 *encoded)
{
    u32 low = encoded[0];

    return (encoded[1] << 8) | low;
}

static inline u8 *owner_link(u8 *base, const u8 *encoded)
{
    u32 word_offset = read_word_offset(encoded);

    return word_offset != 0 ? base + word_offset * 4 : 0;
}

void func_08006D38(void *owner)
{
    u8 *data = owner;
    u8 *node = owner_link(data, data);
    u32 count;
    s32 remaining;
    u16 selected;

    if (node == 0) {
        data[2] = 0;
        data[3] = 0;
        return;
    }

    count = read_word_offset(data + 4);
    remaining = count >> 1;
    while (--remaining > 0)
        node = owner_link(data, node + 10);

    selected = node != 0 ? (node - data) >> 2 : 0;
    data[2] = selected;
    data[3] = selected >> 8;
}
