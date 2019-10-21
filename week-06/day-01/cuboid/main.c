#include <stdio.h>

// Write a program that stores 3 sides of a cuboid as variables (doubles)
// You should get these variables via console input
// The program should write the surface area and volume of the cuboid like:
//
// Surface Area: 600
// Volume: 1000

int main() {

    double a;
    double b;
    double c;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    printf("Surface area: %.2lf\n", 2*(a * b + a * c + b * c));
    printf("Volume: %.2lf\n", a * b * c);

    return 0;
}