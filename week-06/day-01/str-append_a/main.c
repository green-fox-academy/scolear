#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *append_a(char *string) {
    return strcat(string, "a");
}

int main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    char str1[30];

    printf("Please enter a string:\n");
    scanf("%s", str1);

    printf("%s", append_a(str1));

    // this does the same, obviously :
    // printf("%s\n", strcat(str1, "a"));

    return 0;
}