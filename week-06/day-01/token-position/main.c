
#include <stdio.h>
#include <string.h>
#include <zconf.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

int main ()
{
    char string[55] = "this is a string for testing";

    ptrdiff_t index;

    for (char *p = strtok(string, "i"); p != NULL; p = strtok(NULL, "i")) {
        index = p - string;
        printf("%li, ", index);
    }



    return 0;
}