
#include <iostream>
#include "Helicopter.h"

void Helicopter::land() {
    if(_flying) {
        _flying = false;
        std::cout << "Landing...\n";
    } else {
        std::cout << "Already landed.\n";
    }
}

void Helicopter::fly() {
    if(_flying) {
        std::cout << "Flying...\n";
    } else {
        std::cout << "It has to take off first. Use heliObj.takeOff()\n";
    }
}

void Helicopter::takeOff() {
    if(!_flying) {
        _flying = true;
        std::cout << "Taking off...\n";
    } else {
        std::cout << "Already flying.\n";
    }
}

void Helicopter::startEngine() {

}

void Helicopter::stopEngine() {

}

void Helicopter::accelerate() {

}
