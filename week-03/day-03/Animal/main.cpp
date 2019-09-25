/*
Create an Animal class

Every animal has a hunger value, which is a whole number
Every animal has a thirst value, which is a whole number
when creating a new animal object these values are created with the default 50 value
Every animal can eat() which decreases their hunger by one
Every animal can drink() which decreases their thirst by one
Every animal can play() which increases both by one
*/

#include <iostream>
#include "Animal.h"

int main() {

    Animal dog1;

    dog1.play();

    std::cout << dog1.getHunger() << std::endl;
    std::cout << dog1.getThirst() << std::endl;

    dog1.eat();

    std::cout << dog1.getHunger() << std::endl;
    std::cout << dog1.getThirst() << std::endl;

    return 0;
}