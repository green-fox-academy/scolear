#include <iostream>
#include "Bird.h"

void Bird::land() {
    if(_flying) {
        _flying = false;
        std::cout << "Bird landing...\n";
    } else {
        std::cout << "Already on the ground.\n";
    }
}

void Bird::fly() {
    if(_flying) {
        std::cout << "Flying bird...\n";
    } else {
        std::cout << "It has to take off first, dummy. Use .takeOff()\n";
    }

}

void Bird::takeOff() {
    if(!_flying) {
        _flying = true;
        std::cout << "Taking off...\n";
    } else {
        std::cout << "Already woosh woosh.\n";
    }

}

Bird::Bird(std::string name) : EggLaying(name) {

}
