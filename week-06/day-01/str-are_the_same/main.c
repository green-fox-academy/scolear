
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int are_the_same (char *str1, char *str2) {
    int ret = strcasecmp(str1, str2);

    if(ret != 0) {
        return 0;
    } else {
        return 1;
    }
}

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char str1[20];
    char str2[20];

    printf("Please enter first string:\n");
    scanf("%s", str1);

    printf("Please enter second string:\n");
    scanf("%s", str2);

    printf("Strings 1 and 2 are %s", are_the_same(str1, str2) == 1 ? "the same." : "different.");

    return 0;
}