
#include "Sharpie.h"

Sharpie::Sharpie(std::string color, float width) {
    _color = color;
    _width = width;
    _inkAmount = 100;
}

void Sharpie::use() {

    if (_inkAmount > 0) {
        _inkAmount--;
    }
}

int Sharpie::getInkAmount() {
    return _inkAmount;
}

