#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int count_lines (char* filename) {
    FILE* fptr;

    if (!(fptr = fopen(filename, "r"))) return 0;

    int i = 0;
    char buffer[100];

    while(fgets(buffer, 100, fptr)){
        i++;
    }
    fclose(fptr);

    return i;
}

int main ()
{
    int lines = count_lines("../../Printlines/program.txt");
    printf("Number of lines: %d\n", lines);
    return 0;
}