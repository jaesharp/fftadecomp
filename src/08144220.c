#include "ffta.h"

typedef enum {
    FP_SNAN,
    FP_QNAN,
    FP_ZERO,
    FP_NUMBER,
    FP_INFINITY
} FloatClass08144220;

typedef struct {
    FloatClass08144220 classification;
    u32 sign;
    s32 exponent;
    u32 fraction;
} UnpackedFloat08144220;

/* Conditional interface from the complete helper and its published definition. */
extern float func_081439C8(const UnpackedFloat08144220 *number);

/* Complete [0x08144220,0x08144280):96 bytes including both literal words.
 * The actual helper consumes classification/sign/fraction words0/4/12 and
 * exponent8 on its finite-number path. The zero path leaves exponent and
 * fraction unspecified, as in the target. This local record/interface view
 * asserts no universal initialization, memory effects, bounds or termination.
 */
float func_08144220(s32 value)
{
    UnpackedFloat08144220 number;

    number.classification = FP_NUMBER;
    number.sign = value < 0;
    if (value == 0) {
        number.classification = FP_ZERO;
    } else {
        number.exponent = 30;
        if (number.sign) {
            if (value == (-2147483647 - 1))
                return -2147483648.0f;
            number.fraction = -value;
        } else {
            number.fraction = value;
        }
        while (number.fraction < 0x40000000) {
            number.fraction <<= 1;
            --number.exponent;
        }
    }
    return func_081439C8(&number);
}
