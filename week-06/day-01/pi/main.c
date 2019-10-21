
// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

double areaOfCircle(double radius) {
    return radius * radius * PI;
}



int main()
{
    printf("%lf", areaOfCircle(5.2));
    return 0;
}