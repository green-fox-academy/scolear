#include "EggLaying.h"

EggLaying::EggLaying(std::string name) : Animals(name) {}

std::string EggLaying::breed() {
    return "laying eggs.";
}
