#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main ()
{
    FILE* fptr;

    fptr = fopen("../program.txt", "w");
    fprintf(fptr, "This is a line of text.\nThis is another.\n");
    fclose(fptr);

    fptr = fopen("../program.txt", "r");

    int i=1;
    char buffer[100];

    while(fgets(buffer, 100, fptr)){
        printf("%d. line: %s",  i, buffer);
        i++;
    }

    fclose(fptr);

    return 0;
}