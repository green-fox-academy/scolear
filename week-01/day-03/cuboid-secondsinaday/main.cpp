#include <iostream>

int main(int argc, char* args[]) {

    /*// Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    double a = 10;
    double b = 100;
    double c = 5;

    double surfaceArea = 2 * (a * b + a * c + b * c);
    double volume = a * b * c;

    std::cout << "Surface Area: " << surfaceArea << std::endl;
    std::cout << "Volume: " << volume << std::endl;

    return 0;*/

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables

    int secondsInADay = 86400;
    int secondsPassed = currentHours * 3600 + currentMinutes * 60 + currentSeconds;

    int remaining = secondsInADay - secondsPassed;

    std::cout << "Seconds remaining from day: " << remaining;

    return 0;

}