#include <stdio.h>
#include <math.h>

unsigned int binary_conversion(unsigned int n);

unsigned int my_add(unsigned int a, unsigned int b);

int main() {
    unsigned int a, b;
    printf("Hi\n");
    printf("i will add two numbers for you in binary\n");
    printf("please enter two numbers:\n");
    scanf("%u %u", &a, &b);
    unsigned int result = my_add(a, b);
    printf("The sum of %u and %u is %u\n", a, b,result);
    printf_s("thanks for using our calculator");
    return 0;
}

unsigned int binary_conversion(unsigned int n) {
    int i;
    unsigned int binary = 0;
    for (i = 0; i < 16; i++) {
        if (n == 0) {
            binary = binary << 1;
        }
        else if (n % 2 == 0) {
            n = n / 2;
            binary = binary + (0 * (unsigned int)pow(10, i));
        } else {
            n = n / 2;
            binary = binary + (1 * (unsigned int)pow(10, i));
        }


    }
    return binary;
}

    unsigned int my_add(unsigned int a, unsigned int b) {
        a = binary_conversion(a);
        b = binary_conversion(b);
        printf("The binary of a is %u\n", a);
        printf("The binary of b is %u\n", b);

        a <<= (16 - (sizeof(unsigned int) * 8));
        b <<= (16 - (sizeof(unsigned int) * 8));
        printf("The binary of a is %u\n", a);
        printf("The binary of b is %u\n", b);
        unsigned int result = 0;
        unsigned int carry = 0;
        int i;
        for (i = 0; i < 16; i++) {
            unsigned int a_bit = (a >> i) & 1;
            unsigned int b_bit = (b >> i) & 1;

            unsigned int sum = a_bit ^ b_bit ^ carry;
            result |= sum << i;
            carry = (a_bit & b_bit) | (b_bit & carry) | (a_bit & carry);
        }
        return result;
    }

