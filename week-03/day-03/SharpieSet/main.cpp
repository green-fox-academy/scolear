/*
Reuse your Sharpie class

Create SharpieSet class
    it contains a list of Sharpie
    countUsable() -> sharpie is usable if it has ink in it
    removeTrash() -> removes all unusable sharpies

Test your methods by making some sharpies and call them. Make sure they print something meaningful to the console.
 */
#include <iostream>
#include "SharpieSet.h"
#include "Sharpie.h"

int main() {

    SharpieSet set;

    Sharpie sharp1("blue", 1.5);
    Sharpie sharp2("red", 2.5);
    Sharpie sharp3("green", 2.5);
    Sharpie sharp4("black", 2.5);

    set.addSharpie(&sharp1);
    set.addSharpie(&sharp2);
    set.addSharpie(&sharp3);
    set.addSharpie(&sharp4);

    std::cout << "Usable sharpies in set: " << set.countUsable() << std::endl;

    std::cout << "Using first sharpie: " << std::endl;
    for (int i = 0; i < 10; ++i) {
        set.getSharpie(0)->use();
        std::cout << set.getSharpie(0)->getInkAmount() << " , ";
    }


    std::cout << "\nUsable sharpies in set: " << set.countUsable() << std::endl;
    std::cout << "Total sharpies in set: " << set.countTotal() << std::endl;
    std::cout << "Removing trash..." << std::endl;
    set.removeTrash();
    std::cout << "Total sharpies in set: " << set.countTotal() << std::endl;

    return 0;
}