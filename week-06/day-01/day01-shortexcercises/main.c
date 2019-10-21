#include <stdio.h>

int main() {
    // Modify this program to greet you instead of the World!
    printf("Hello, Robika!\n");

    // Greet 3 of your classmates with this program, in three separate lines
    // like:
    //
    // Hello, Esther!
    // Hello, Mary!
    // Hello, Joe!
    printf("Hello, Laci!\n");
    printf("Hello, Levi!\n");
    printf("Hello, Misi!\n");

    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Use variables to store the informations!
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87

    char name[] = "Robert Tera";
    int age = 28;
    float height = 1.82f;

    printf("Name: %s \nAge: %d \nHeight: %.2f \n", name, age, height);


    return 0;
}