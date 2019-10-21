// Write a program that stores a number, and the user has to figure it out.
// The user can input guesses, after each guess the program would tell one
// of the following:
//
// The stored number is higher
// The stried number is lower
// You found the number: 8

#include <stdio.h>

int main() {

    int solution = 615;
    int guess = 0;

    printf("Enter a guess:\n");

    while (guess != solution) {
        scanf("%d", &guess);

        if (guess > solution) {
            printf("Number is lower.\n");
        } else if (guess < solution) {
            printf("Number is higher.\n");
        }
    }
    printf("You have found it!\n");

    return 0;
}