
#include <iostream>

int main(int argc, char* args[]) {

   /* // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user
    std::string userName;

    std::cout << "Please enter your name:" << std::endl;
    std::cin >> userName;
    std::cout << "Hello, " << userName << std::endl;

    return 0;
*/


    /*// Write a program that asks for a double that is a distance in miles,
    // then it converts that value to kilometers and prints it

    double distance;
    std::cout << "Please enter distance in miles:" << std::endl;
    std::cin >> distance;
    std::cout << "Distance in km: " << distance * 1.609344 << std::endl;

    return 0;*/


   /* // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    int chickens;
    int pigs;

    std::cout << "Please enter two numbers:" << std::endl;
    std::cin >> chickens;
    std::cin >> pigs;

    std::cout << "Total number of legs:" << chickens * 2 + pigs * 4;
    return 0;*/



    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4
    int a, b, c, d, e;

    std::cout << "Enter five numbers:" << std::endl;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    std::cin >> e;

    int sum = a + b + c + d + e;

    std::cout << "Sum: " << sum << ", Average: " << (float)sum / 5;

    return 0;
}