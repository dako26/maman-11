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
    result = binary_conversion(result);
    printf("The sum of %u and %u is %u\n", a, b,result);
    printf("thanks for using our calculator");
    return 0;
}

unsigned int binary_conversion(unsigned int n) {
    int i;
    unsigned int binary = 0;
    for (i = 0; i <= 15; i++) {
        if (n % 2 == 0) {
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

    unsigned int carry = 0;
    unsigned int result = 0;
    unsigned int i;
    for (i = 0; i < sizeof(int) * 4; i++) {
        unsigned int bit1 = (a >> i) & 1;
        unsigned int bit2 = (b >> i) & 1;
        unsigned int sum = bit1 ^ bit2 ^ carry;
        carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry);
        result |= (sum << i);
    }
    return result;
}
