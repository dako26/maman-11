
#include <stdio.h>
#include <string.h>

int suffix(char str[], char c);

int main() {
    char word[127];
    char letter;
    printf("Hello!\n");
    printf("I will check all the suffixes from the letters you provided in the word you entered.\n");
    printf("Please enter the word you want me to check: ");
    scanf("%s", word);
    printf("Please enter the letter you want me to check: ");
    scanf(" %c", &letter);
    printf("Number of occurrences: %d\n", suffix(word, letter));
    printf("Thanks for using my suffixes system.\n");
    return 0;
}

int suffix(char str[], char c) {
    int index, counter = 0;
    for (index=0; index < strlen(str); index++){
        if (str[index] == c){
            counter++;
            printf("%s\n",&str[index]);
            }
        }
    return counter;
}