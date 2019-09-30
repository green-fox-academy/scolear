
#include "Tree.h"
Tree::Tree(const std::string color) : Plant(color) {
    _waterNeeds = 10;
    _effectivity = 0.4;
    _type = "tree";
}