#include <stdio.h>
#include <stdlib.h>

int old_enough(int age);

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (old_enough(age)) {
        printf("You can drink!");
    } else {
        printf("Too young, get outta here ya wanker");
    }

    return 0;
}

int old_enough(int age) {
    int limit = 18;
    if (age < limit) {
        return 0;
    } else {
        return 1;
    }
}