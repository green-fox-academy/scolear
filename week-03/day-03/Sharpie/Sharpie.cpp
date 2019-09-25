//
// Created by scolear on 2019. 09. 25..
//

#include "Sharpie.h"

Sharpie::Sharpie(std::string color, float width) {
    _color = color;
    _width = width;
    _inkAmount = 100;
}

void Sharpie::use() {
    _inkAmount--;
}