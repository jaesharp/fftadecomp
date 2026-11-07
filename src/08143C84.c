#include "ffta.h"

/* Target: complete 48-byte owner at 08143C84.
 * The complete helper entries consume and produce four-word records:
 * classification, sign, signed exponent and unsigned significand.
 * Input and returned encoded values are transported as 32-bit words.
 * These conditional local views do not assert a unique historical nominal
 * floating type, arithmetic equivalence or helper effects/termination.
 */
typedef struct {
    u32 classification;
    u32 sign;
    s32 exponent;
    u32 significand;
} Parts08143C84;

extern void func_08143A84(const u32 *, Parts08143C84 *);
extern Parts08143C84 *func_08143B04(Parts08143C84 *, Parts08143C84 *,
    Parts08143C84 *);
extern u32 func_081439C8(Parts08143C84 *);

u32 func_08143C84(u32 left_word, u32 right_word)
{
    Parts08143C84 left;
    Parts08143C84 right;
    Parts08143C84 result;

    func_08143A84(&left_word, &left);
    func_08143A84(&right_word, &right);
    return func_081439C8(func_08143B04(&left, &right, &result));
}
