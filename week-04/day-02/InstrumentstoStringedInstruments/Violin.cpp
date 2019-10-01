#include "Violin.h"

Violin::Violin() : StringedInstrument("Violin", 4) {}

Violin::Violin(int string) : StringedInstrument("Violin", string) {}

std::string Violin::sound() {
    return "Screech";
}
