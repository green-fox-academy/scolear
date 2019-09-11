#include <iostream>

#include <iostream>

using std::cout;

int main(int argc, char const *argv[])
{
    /*
     
    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87

    int age = 28;
    float height = 1.82;

    cout << "Robert Tera \n";
    cout << age << std::endl;
    cout << height;

    return 0;
    */

    /*

    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22

    // Print the result of 13 substracted from 22

    // Print the result of 22 multiplied by 13

    // Print the result of 22 divided by 13 (as a decimal fraction)

    // Print the integer part of 22 divided by 13

    // Print the remainder of 22 divided by 13

    int a = 22;
    int b = 13;

    cout << a + b << std::endl;
    cout << b - a << std::endl;
    cout << a * b << std::endl;
    cout << (float)a / b << std::endl;
    cout << a / b << std::endl;
    cout << a % b << std::endl;

    return 0;
    */


    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52

    int codingHoursDaily = 6;
    int semesterLength = 17;
    int workdays = semesterLength * 5;
    int workingHoursWeekly = 52;
    int totalWorkingHours = workingHoursWeekly * semesterLength;
    int codingHoursTotal = workdays * codingHoursDaily;
    float codingPercent = (float)codingHoursTotal / totalWorkingHours * 100;

    cout << "Hours spending coding: " << codingHoursTotal << std::endl;
    cout << "Percentage spent coding: " << codingPercent;

    return 0;
}
