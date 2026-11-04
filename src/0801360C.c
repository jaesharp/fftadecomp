#include "ffta.h"

typedef struct {
    u32 unknown_00;
    u8 *output;
    u16 cursor;
    u8 variant;
    u8 unknown_0B[0x205];
    u8 glyph[1];
} GlyphContext;

s16 func_0801348C(void *glyph, s16 character, u8 variant);
void func_080139B8(u8 *context, s32 source, s32 destination, s32 shift);
void func_08013890(GlyphContext *context, u32 source, u32 destination);
void func_08013910(GlyphContext *context, u32 operation, u32 block);
void func_08013858(GlyphContext *context, s32 operation, s32 block);

/* Complete target: [0x0801360C, 0x08013728), 284 bytes. */
void func_0801360C(GlyphContext *context, s32 character)
{
    s32 shift = context->cursor & 7;
    s32 width = func_0801348C(context->glyph, character, context->variant);
    s32 remaining = width;
    s32 block = 0;
    s32 total;

    if (shift == 0) {
        total = width;
        if (remaining > 0) {
            do {
                func_080139B8((u8 *)context, block, block, 0);
                func_08013890(context, block, block);
                remaining -= 8;
                if (remaining < 0) {
                    break;
                }
                block++;
            } while (remaining > 0);
        }
    } else {
        func_080139B8((u8 *)context, 0, 0, shift);
        func_08013890(context, 0, 0);
        {
            s32 after_first_block = width - 8;
            remaining = after_first_block + shift;
        }
        total = shift + width;
        if (remaining > 0) {
            block = 1;
            do {
                if (block <= 1) {
                    func_080139B8((u8 *)context, block, block, shift);
                }
                func_08013890(context, block, block);
                remaining -= 8;
                if (remaining < 0) {
                    break;
                }
                block++;
            } while (remaining > 0);
        }
    }

    shift = total;
    context->cursor += width;
    context->output += (shift & 0xFFF8) * 8;
    if (block) {
        func_08013910(context, 6, block - 1);
    } else {
        func_08013910(context, 6, 0);
    }
    if ((shift & 7) == 0) {
        func_08013858(context, 0, 0);
    } else {
        func_08013910(context, 7, block);
        if (block) {
            func_08013910(context, 0, block);
            func_08013858(context, 1, block);
        }
    }
}
