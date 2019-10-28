#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char* dynamic_concat(char string1[], char string2[]) {

    int size1 = 0;
    int size2 = 0;
    char *newstr = NULL;

    while(string1[size1] != '\0') {
        size1++;
    }
    while(string2[size2] != '\0') {
        size2++;
    }

    newstr = (char *) malloc((size1 + size2 + 1) * sizeof(char));

    strcpy(newstr, string1);
    strcat(newstr, string2);

    return newstr;
}

int main()
{
    char *str1 = "first string, ";
    char *str2 = "second string";
    char *newstr = dynamic_concat(str1, str2);

    printf("%s", newstr);

    free(newstr);

    return 0;
}