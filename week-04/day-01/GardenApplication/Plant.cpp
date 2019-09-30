
#include "Plant.h"

Plant::Plant(std::string color) : _color(color) {
    _waterlevel = 0;
    _effectivity = 1;
    _waterNeeds = 10;
}

void Plant::waterPlant(float amount) {
    _waterlevel += amount * _effectivity;
}

bool Plant::needsWater() {
    return _waterNeeds > _waterlevel;
}

std::string Plant::getDetailedInfo() {
    return _color + " " + _type + " \t| " +  std::to_string(_waterlevel);
}

std::string Plant::getInfo() {
    return "The " + _color + " " + _type + " " + (needsWater() ? "needs water." : "doesn't need water.");
}
