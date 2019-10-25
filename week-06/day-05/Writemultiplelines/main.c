#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

int print_multiple_lines (char* path, char* word, int times) {

    FILE* fptr;
    if (!(fptr = fopen(path, "w"))) return -1;

    for (int i = 0; i < times; ++i) {
        fputs(word, fptr);
        fputc('\n',fptr);
    }
    fclose(fptr);

    return 0;
}

int main()
{
    print_multiple_lines("../test.txt", "apple", 5);
    return 0;
}