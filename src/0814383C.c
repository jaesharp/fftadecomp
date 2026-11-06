typedef unsigned long long u64;

typedef struct Number14383C {
    int kind;
    unsigned int sign;
    int exponent;
    u64 fraction;
} Number14383C;

extern double func_08142BE8(const Number14383C *);

double func_0814383C(int value)
{
    Number14383C number;

    number.kind = 3;
    number.sign = value < 0;
    if (value == 0) {
        number.kind = 2;
    } else {
        number.exponent = 60;
        if (number.sign) {
            if (value == (-2147483647 - 1))
                return -2147483648.0;
            number.fraction = -value;
        } else {
            number.fraction = value;
        }
        while (number.fraction < ((u64)1 << 60)) {
            number.fraction <<= 1;
            number.exponent--;
        }
    }
    return func_08142BE8(&number);
}
