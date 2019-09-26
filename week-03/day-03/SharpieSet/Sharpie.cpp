#include <iostream>
#include "Sharpie.h"

Sharpie::Sharpie(std::string color, float width) {
    _color = color;
    _width = width;
    _inkAmount = 10;
}

void Sharpie::use() {
    _inkAmount--;
    if (_inkAmount < 0) _inkAmount = 0;
}

int Sharpie::getInkAmount() const {
    return _inkAmount;
}
