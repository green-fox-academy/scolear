
#include <iostream>
#include "StringedInstrument.h"

StringedInstrument::StringedInstrument(std::string name, int strings) : Instrument(name), _numberOfStrings(strings) {}

void StringedInstrument::play() {
    std::cout << _name << ", a " << _numberOfStrings << "-stringed instrument that goes " << sound() << std::endl;
}