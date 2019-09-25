#include <iostream>
#include "SharpieSet.h"

SharpieSet::SharpieSet() {

}

int SharpieSet::countUsable() {
    int usable = 0;
    for (int i = 0; i < _sharpies.size(); ++i) {
        if (_sharpies[i].getInkAmount() != 0) {
            usable++;
        }
    }
    return usable;
}

void SharpieSet::removeTrash() {
    for (int i = 0; i < _sharpies.size(); ++i) {
        if (_sharpies[i].getInkAmount() == 0) {
            _sharpies.erase(_sharpies.begin() + i);
        }
    }
}

void SharpieSet::addSharpie(Sharpie &sharpie) {

    _sharpies.push_back(sharpie);

}

Sharpie SharpieSet::getSharpie(int x) {
    return _sharpies[x];
}

