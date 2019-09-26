#include <iostream>
#include "Sharpie.h"

Sharpie::Sharpie(std::string color, float width) {
    _color = color;
    _width = width;
    _inkAmount = 10;
}

void Sharpie::use() {
    _inkAmount--;
}

float Sharpie::getInkAmount() const {
    return _inkAmount;
}
