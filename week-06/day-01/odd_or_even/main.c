#include <stdio.h>
#include <stdlib.h>

int is_even(int num) {
    if (num % 2 == 0 || num == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    int num;

    scanf("%d", &num);

    printf("The number %d is %s", num, is_even(num) == 1 ? "even." : "odd.");

    return 0;
}