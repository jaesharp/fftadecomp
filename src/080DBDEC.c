#include "ffta.h"

/* Complete owner [0x080DBDEC, 0x080DBEB4), 200 bytes.
 * The list contains objects whose signed coordinates occupy offsets 8, 10,
 * and 12. Other members are not interpreted here. Published DCD08 supplies
 * the selector/list/context interface; C918 consumes three signed halfwords
 * and three halfword output pointers, including two outgoing stack words.
 * The actual SVC entry at 08141870 and this caller support a conditional
 * two-word input/word result interface. No BIOS arithmetic or memory-effect
 * proof, original nominal prototype, or helper termination claim is made.
 */
typedef struct CoordinateObject080DBDEC {
    u8 unknown_00[8];
    s16 x;
    s16 y;
    s16 z;
} CoordinateObject080DBDEC;

extern void *func_0800A654(u32 size);
extern void func_0800A668(void *object);
extern u32 func_080DCD08(u8 selector, void **destination, void **argument);
extern void func_0801C918(s16 first, s16 second, s16 third,
                        s16 *first_output, s16 *second_output,
                        s16 *third_output);
extern s32 func_08141870(s32 first, s32 second);

void func_080DBDEC(u8 selector, void **argument, s16 *first_output,
                   s16 *second_output, s16 *third_output)
{
    void **list;
    u8 count;
    u8 index;
    s16 first;
    s16 second;
    s16 third;
    s32 first_sum;
    s32 second_sum;
    s32 third_sum;

    list = func_0800A654(0x60);
    count = func_080DCD08(selector, list, argument);
    first_sum = 0;
    second_sum = 0;
    third_sum = 0;
    for (index = 0; index < count; index++) {
        CoordinateObject080DBDEC *object = list[index];
        func_0801C918(object->x, object->y, object->z,
                     &first, &second, &third);
        first_sum += first;
        second_sum += second;
        third_sum += third;
    }
    func_0800A668(list);
    first_sum = func_08141870(first_sum, count);
    second_sum = func_08141870(second_sum, count);
    third_sum = func_08141870(third_sum, count);
    *first_output = first_sum;
    *second_output = second_sum;
    if (third_output != 0)
        *third_output = third_sum;
}
