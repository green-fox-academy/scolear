
#include "Printer2D.h"

Printer2D::Printer2D(int x, int y) : _sizeX(x), _sizeY(y) {}

std::string Printer2D::getSize() {
    return std::to_string(_sizeX) + " X " + std::to_string(_sizeY);
}
