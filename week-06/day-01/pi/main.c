
// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

#include <stdio.h>
#include <stdlib.h>
#include "circle.h"

int main()
{
    double radius = 5.2;

    printf("Are of circle with radius %.2lf : %.2lf\n", radius, areaOfCircle(radius));
    printf("Circumference of circle with radius %.2lf : %.2lf\n", radius, circumference(radius));

    return 0;
}