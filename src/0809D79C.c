typedef unsigned char u8;
typedef signed char s8;

extern u8 func_0801CC7C(u8 x, u8 y);
extern u8 func_0801CC18(u8 x, u8 y);

/* Complete target: 72 bytes at 0x0809D79C. */
int func_0809D79C(s8 x, s8 y)
{
    int row = y;

    if (x < 0 || (s8)row < 0 || x > 15 || (s8)row > 15 || !func_0801CC7C(x, row))
        return -1;
    return func_0801CC18(x, row);
}
