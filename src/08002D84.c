#include "ffta.h"

/* Complete target: [0x08002D84, 0x08002DA4), 32 bytes. */
u8 func_08002D84(u8 character)
{
    return (u8)(character - 'a') <= 'z' - 'a'
        ? character - ('a' - 'A') : character;
}
