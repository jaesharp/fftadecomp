#include "ffta.h"

extern void *func_0800A654(u32 size);
extern void func_0800A668(void *pointer);
extern void *func_08096D7C(void);
extern u32 func_08099CDC(void *context, void **list);
extern u32 func_08099D08(void *context, void **list);
extern s32 func_08099D34(void *context, void **list);
extern u8 func_080DCBBC(void **destination);
extern u8 func_080C8240(void *object);

/* Complete [0x080DCD08, 0x080DCF62): 602 bytes, 249 instructions. */
u32 func_080DCD08(u8 selector, void **destination, void **argument)
{
    void **list;
    u8 count;
    u8 index;

    switch (selector) {
    case 0:
        list = func_0800A654(0x60);
        count = func_08099CDC(func_08096D7C(), list);
        for (index = 0; index < count; index++)
            destination[index] = list[index];
        func_0800A668(list);
        break;
    case 1:
        list = func_0800A654(0x60);
        count = func_08099D08(func_08096D7C(), list);
        for (index = 0; index < count; index++)
            destination[index] = list[index];
        func_0800A668(list);
        break;
    case 2:
        list = func_0800A654(0x60);
        count = func_08099D34(func_08096D7C(), list);
        for (index = 0; index < count; index++)
            destination[index] = list[index];
        func_0800A668(list);
        break;
    case 3:
        count = func_080DCBBC(destination);
        break;
    case 4:
        if (func_080C8240(*argument)) {
            list = func_0800A654(0x60);
            count = func_08099D34(func_08096D7C(), list);
            for (index = 0; index < count; index++)
                destination[index] = list[index];
            func_0800A668(list);
        } else {
            list = func_0800A654(0x60);
            count = func_08099D08(func_08096D7C(), list);
            for (index = 0; index < count; index++)
                destination[index] = list[index];
            func_0800A668(list);
        }
        break;
    case 5:
        if (func_080C8240(*argument)) {
            list = func_0800A654(0x60);
            count = func_08099D34(func_08096D7C(), list);
            for (index = 0; index < count; index++)
                destination[index] = list[index];
            func_0800A668(list);
        } else {
            list = func_0800A654(0x60);
            count = func_08099D08(func_08096D7C(), list);
            for (index = 0; index < count; index++)
                destination[index] = list[index];
            func_0800A668(list);
        }
        count += func_080DCBBC(destination + count);
        break;
    case 6:
        if (func_080C8240(*argument)) {
            list = func_0800A654(0x60);
            count = func_08099D08(func_08096D7C(), list);
            for (index = 0; index < count; index++)
                destination[index] = list[index];
            func_0800A668(list);
        } else {
            list = func_0800A654(0x60);
            count = func_08099D34(func_08096D7C(), list);
            for (index = 0; index < count; index++)
                destination[index] = list[index];
            func_0800A668(list);
        }
        break;
    }
    return count;
}
