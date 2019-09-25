
#include "Animal.h"

Animal::Animal() {
    _hunger = 50;
    _thirst = 50;
}

Animal::Animal(int hunger, int thirst) {
    _hunger = hunger;
    _thirst = thirst;
}

void Animal::eat() {
    _hunger--;
}

void Animal::drink() {
    _thirst--;
}

void Animal::play() {
    _hunger++;
    _thirst++;
}

int Animal::getHunger() const {
    return _hunger;
}

int Animal::getThirst() const {
    return _thirst;
}
