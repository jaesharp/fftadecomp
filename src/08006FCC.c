#include "ffta.h"

typedef struct {
    u16 previous, next, marker, size;
    u16 free_previous, free_next;
} __attribute__((packed)) Block08006FCC;

extern void func_08006DA0(void *owner, void *block);
extern void func_08006E28(void *owner, void *block);

static inline Block08006FCC *decode_offset08006FCC(u8 *owner, u16 value)
{
    return value ? (Block08006FCC *)(owner + value * 4) : 0;
}

/* Complete target [0x08006FCC, 0x080070C8): 252 bytes, 118 instructions.
 * Target bytes: f0b54f464646c0b4061c0d1ca846a979e879000208430338a871000ae8717020287173206871014a03e0000070730000251c2978687800020843002802d08000311800e000210c1c002c05d021796079000208439042ebd0454503d0301c291cfff7b8fe01488146ff2720e070730000444503d0301c211cfff7acfea879e979090201430331a279e0790002104309180904080c3840a871090ee971a078e17809020143081c3840a870090ae970a978e87800020843002802d08000311800e000210c1c002c0fd021796079000208434845cdd0002d03d0a81b8003000c00e000202070000a6070301c291cfff7b6fe18bc9846a146f0bc01bc0047
 */
void func_08006FCC(u8 *owner, Block08006FCC *block)
{
    Block08006FCC *original = block;
    Block08006FCC *neighbor;

    block->size -= 3;
    block->marker = 0x7370;
    for (;;) {
        neighbor = decode_offset08006FCC(owner, block->previous);
        if (neighbor == 0 || neighbor->marker != 0x7370)
            break;
        block = neighbor;
    }
    if (block != original)
        func_08006DA0(owner, block);
    for (;;) {
        neighbor = decode_offset08006FCC(owner, block->next);
        if (neighbor == 0 || neighbor->marker != 0x7370)
            break;
        if (neighbor != original)
            func_08006DA0(owner, neighbor);
        block->size += 3 + neighbor->size;
        block->next = neighbor->next;
    }
    if (neighbor) {
        u16 offset = block ? (u16)((u32)((u8 *)block - owner) >> 2) : 0;
        ((u8 *)neighbor)[0] = offset;
        ((u8 *)neighbor)[1] = offset >> 8;
    }
    func_08006E28(owner, block);
}
