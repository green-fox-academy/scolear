#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char *repeat_string(char string[], int times) {

    if (times < 1) return "";

    int size = 0;
    while (string[size] != '\0') {
        size++;
    }

    if (size < 1) return "";

    char *newstr = (char *) malloc(size * times * sizeof(char));

    strcpy(newstr, string);

    for (int i = 0; i < times - 1; ++i) {
        strcat(newstr, string);
    }

    return newstr;
}

int main()
{
    char *str = "Apple";
    char *test = "";

    printf("%s\n", repeat_string(str, 0));
    printf("%s\n", repeat_string(test, 5));
    printf("%s\n", repeat_string(str, 5));

    return 0;
}