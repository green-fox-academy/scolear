#include <stdio.h>
#include <stdlib.h>

int equals(int a, int b);

int main()
{
    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    int a;
    int b;

    printf("Enter the first number: ");
    scanf("%d", &a);

    printf("Enter the second number: ");
    scanf("%d", &b);

    printf("Are they equal? : %s", equals(a, b) == 1 ? "Yes" : "No");

    return 0;
}

int equals(int a, int b) {
    if (a == b) {
        return 1;
    } else {
        return 0;
    }
}