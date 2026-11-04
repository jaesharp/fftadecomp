#include "ffta.h"

typedef void (*BufferCopier0801407C)(void *destination, const void *source,
                                    u32 size);

extern BufferCopier0801407C const data_0836D4BC[];
extern u8 data_020078B0[];
extern u32 func_08013BEC(u8 value);
extern u16 func_08013C20(u8 code);

/* Complete target [0x0801407C, 0x080142DA): 606 bytes, 114 instructions.
 * SHA256: 7009d5d20a3fbcb1270cc079547ff7778196f430d6c38b75a80ed3237e0df3c8
 */
u16 func_0801407C(u8 *destination, const u8 *source)
{
    u16 count = 0;

    while (*source) {
        if (*source == '@') {
            *destination++ = *source++;
            switch (*source) {
            case '%':
                if ((u8)func_08013BEC(source[1])) {
                    u16 length = func_08013C20(source[1]);

                    destination--;
                    if (length)
                        data_0836D4BC[0](destination, data_020078B0, length);
                    destination += length;
                    source += 2;
                    count += length;
                    break;
                }
            case '!':
            case '<':
            case '>':
            case 'g':
            case 'l':
            case 'r':
            case 't':
                *destination++ = *source++;
                *destination++ = *source++;
                count += 3;
                break;
            case 'f':
                *destination++ = *source++;
                *destination++ = *source++;
                *destination++ = *source++;
                count += 4;
                break;
            case 'S':
                {
                    int i;

                    for (i = 0; i < 2; i++) {
                        while (*source) {
                            *destination++ = *source++;
                            count++;
                        }
                        *destination++ = *source++;
                        count++;
                    }
                }
                break;
            case 'a':
            case 'b':
            case 'c':
            case 'k':
            case 'n':
            case 'p':
            case 's':
            case 'u':
            case 'w':
            case 'x':
            case 'y':
                *destination++ = *source++;
                count += 2;
                break;
            }
        } else {
            *destination++ = *source++;
            *destination++ = *source++;
            count += 2;
        }
    }
    *destination = 0;
    count++;
    return count;
}
