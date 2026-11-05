#include "ffta.h"

typedef union {
    const u8 *bytes;
    const u32 *words;
} SourceCursor081443FC;

/* Complete 0x081443FC..0x0814445E: forward byte and aligned word copy. */
void *func_081443FC(void *destination, const void *source, u32 byte_count)
{
    u8 *destination_bytes = destination;
    SourceCursor081443FC cursor;

    cursor.bytes = source;
    if (byte_count >= 16 && (((u32)cursor.bytes | (u32)destination_bytes) & 3) == 0) {
        u32 *destination_words = (u32 *)destination_bytes;

        while (byte_count >= 16) {
            *destination_words++ = *cursor.words++;
            *destination_words++ = *cursor.words++;
            *destination_words++ = *cursor.words++;
            *destination_words++ = *cursor.words++;
            byte_count -= 16;
        }
        while (byte_count >= 4) {
            *destination_words++ = *cursor.words++;
            byte_count -= 4;
        }
        destination_bytes = (u8 *)destination_words;
    }
    while (byte_count--) {
        *destination_bytes++ = *cursor.bytes++;
    }
    return destination;
}
