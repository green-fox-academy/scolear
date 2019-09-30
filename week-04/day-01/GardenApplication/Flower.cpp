
#include "Flower.h"

Flower::Flower(const std::string color) : Plant(color) {
    _waterNeeds = 5;
    _effectivity = 0.75;
    _type = "flower";
}
