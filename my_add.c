#include <stdio.h>
#include <math.h>

unsigned int binary_conversion(unsigned int number_to_binary);

unsigned int my_add(unsigned int a, unsigned int b);

int main() {
    unsigned int first_number, second_number;
    printf("Hello\n");
    printf("welcome to Daniel's calculator\n");
    printf("i will add two numbers for you 2 decimal number in binary form and show you\n");
    printf("please enter two numbers:\n");
    scanf("%u %u", &first_number, &second_number);
    unsigned int result = my_add(first_number, second_number);
    result = binary_conversion(result);
    printf("The sum of %u and %u is %u\n", first_number, second_number, result);
    printf("thanks for using my calculator");
    return 0;
}

unsigned int binary_conversion(unsigned int number_to_binary) {
    int i;
    unsigned int final_binary = 0;
    for (i = 0; i <= 15; i++) {
        if (number_to_binary % 2 == 0) {
            number_to_binary = number_to_binary / 2;
            final_binary = final_binary + (0 * (unsigned int)pow(10, i));
        } else {
            number_to_binary = number_to_binary / 2;
            final_binary = final_binary + (1 * (unsigned int)pow(10, i));
        }
    }
    return final_binary;
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
