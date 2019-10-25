
#include <stdio.h>
#include <stdint.h>

int main() {
    int myInt = 123456789;
    float myFloat = 3.14159265359F;
    char myChar = 'c';

    int myIntRead;
    float myFloatRead;
    char myCharRead;

    /*
     * 1. Write out myInt to myInt.txt as a text!
     * 2. Write out myInt to myInt.bin as a binary file!
     *    Check the size of myInt.txt and myInt.bin! Why it is different?
     * 3. Write out myInt to myInt.bin, myFloat to myFloat.bin and myChar to myChar.bin!
     * 4. Read them back to myIntRead, myFloatRead and myCharRead and compare these variables to myInt, myFloat, myChar,
     *    they should be the same.
     */

    FILE* fptr;

    // Writing:
    fptr = fopen("myInt.txt", "w");
    fprintf(fptr, "%d", myInt);
    fclose(fptr);

    fptr = fopen("myInt.bin", "wb");
    fwrite(&myInt, sizeof(int), sizeof(myInt), fptr);
    fclose(fptr);

    fptr = fopen("myFloat.bin", "wb");
    fwrite(&myFloat, sizeof(float), sizeof(myFloat), fptr);
    fclose(fptr);

    fptr = fopen("myChar.bin", "wb");
    fwrite(&myChar, sizeof(char), sizeof(myChar), fptr);
    fclose(fptr);

    // Reading
    fptr = fopen("myInt.bin", "rb");
    fread(&myIntRead, sizeof(int), 1, fptr);
    fclose(fptr);

    fptr = fopen("myFloat.bin", "rb");
    fread(&myFloatRead, sizeof(float), 1, fptr);
    fclose(fptr);

    fptr = fopen("myChar.bin", "rb");
    fread(&myCharRead, sizeof(char), 1, fptr);
    fclose(fptr);

    printf("\n");
    if (myInt == myIntRead) printf("myInts equal, %d and %d\n", myInt, myIntRead);
    if (myFloat == myFloatRead) printf("myFloats equal, %.4f and %.4f\n", myFloat, myFloatRead);
    if (myChar == myCharRead) printf("myChars equal, %c and %c\n", myChar, myCharRead);

    return 0;
}