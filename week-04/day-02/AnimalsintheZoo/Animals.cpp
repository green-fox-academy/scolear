#include "Animals.h"

Animals::Animals(std::string name) : _name(name) {}

std::string Animals::getName() {
    return _name;
}
