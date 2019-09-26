#include <iostream>
#include "Farm.h"

Farm::Farm() : _slots(10) {}

void Farm::breed() {
    if (_slots > 0) {
        _animals.push_back(new Animal());
        _slots--;
    } else {
        std::cout << "Could not breed, not enough space.\n";
    }
}

void Farm::slaughter() {

    if (!_animals.empty()) {
        int min = _animals[0]->getHunger();
        int index = 0;
        for (int i = 0; i < _animals.size(); i++) {
            if (_animals[i]->getHunger() < min){
                min = _animals[i]->getHunger();
                index = i;
            }
        }
        _animals.erase(_animals.begin() + index);

    } else {
        std::cout << "There are no animals to slaughter." << std::endl;
    }
}

Animal* Farm::getAnimal(int i) {
    return _animals[i];
}

void Farm::feedAnimal(int x) {
    _animals[x]->eat();
}

int Farm::getNumberOfAnimals() {
    return _animals.size();
}

Farm::~Farm() {
    for (Animal* a : _animals) {
        delete a;
    }
}

