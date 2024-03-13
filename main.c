#include <stdio.h>
#include <math.h>

unsigned int binary_conversion(unsigned int n);

unsigned int my_add(unsigned int a, unsigned int b);

int main() {
    printf("%d\n", my_add(42, 123));
    return 0;
}

unsigned int binary_conversion(unsigned int n) {
    int i = 0;
    unsigned int binary = 0;
    for (i = 0; n > 0; i++) {
        if (n % 2 == 0) {
            n = n / 2;
            binary = binary + (0 * pow(10, i));
        } else {
            n = n / 2;
            binary = binary + (1 * pow(10, i));

        }

    }
    return binary;
}

unsigned int my_add(unsigned int a, unsigned int b) {
    a = binary_conversion(a);
    b = binary_conversion(b);
    unsigned int final_result = 0;
    int i = 0;
    for (i = 0; i < 16; i++) {
        if (a % 10 == 1 && b % 10 == 1) {
            final_result = final_result + (1 * pow(10, i));
            a = a / 10;
            b = b / 10;
        }

    }
}