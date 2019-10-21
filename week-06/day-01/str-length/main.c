#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_length (char *string) {

    int i = 0;

    while (string[i] != '\0') {
        i++;
    }
    return i;
    // return strlen(string);
}

int main()
{
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    char name[60];

    printf("Please enter your name:\n");
    scanf("%s",name);

    printf("%d", string_length(name));

    return 0;
}