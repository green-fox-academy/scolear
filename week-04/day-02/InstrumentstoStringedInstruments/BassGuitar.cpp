#include "BassGuitar.h"

BassGuitar::BassGuitar( int strings) : StringedInstrument("Bass Guitar", strings) {}

BassGuitar::BassGuitar() : StringedInstrument("Bass Guitar", 4) {}

std::string BassGuitar::sound() {
    return "Duum-duum-duum";
}
