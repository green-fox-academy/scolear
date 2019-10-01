#include "Mammal.h"

Mammal::Mammal(std::string name) : Animals(name) {}

std::string Mammal::breed() {
    return "pushing out little aliens.";
}
