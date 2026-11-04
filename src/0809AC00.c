/* func_0809AC00 - 0x0809AC00, 32 bytes
 *
 * MATCHED byte-for-byte with: agbcc -mthumb-interwork -O2
 *   target  10b5 82b0 0c1c 01aa 6946 2cf0b5ff 0098 2168
 *           6268 a7f01afb 02b0 10bc 02bc 0847
 *
 * The first argument points at a two-word pair; func_080C7B78 splits it,
 * writing the pair's second word to the first output slot and its first word
 * to the second.  Only the first of the two results is used afterwards: it
 * becomes the first argument of the callback stored at +4 of the second
 * argument, and the word at +0 of that same structure becomes the callback's
 * second argument.  The callback's own result is what the function returns.
 *
 * The callback address is loaded into r2 and the call goes through agbcc's
 * `bx r2` thunk at 0x0814224C.  The epilogue pops the return address into r1
 * and branches through it, a Thumb interworking return.
 */

#include "ffta.h"

typedef struct {
    u32 first;
    u32 second;
} Pair0809AC00;

typedef u32 (*Callback0809AC00)(u32 value, u32 argument);

typedef struct {
    u32 argument;
    Callback0809AC00 callback;
} Context0809AC00;

extern void func_080C7B78(const Pair0809AC00 *source, u32 *second, u32 *first);

u32 func_0809AC00(const Pair0809AC00 *source, Context0809AC00 *context)
{
    u32 second;
    u32 first;

    func_080C7B78(source, &second, &first);
    return context->callback(second, context->argument);
}
