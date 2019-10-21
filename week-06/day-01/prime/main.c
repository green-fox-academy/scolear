#include <stdio.h>
#include <stdlib.h>

int is_prime (int num) {
    for (int i = 2; i <= num / 2 ; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    int a;

    puts("Please enter a number:");
    scanf("%d", &a);

    printf("Number %d is %s", a, is_prime(a) ? "a prime" : "not a prime");

    return 0;
}