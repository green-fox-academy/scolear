#ifndef INSTRUMENTSTOSTRINGEDINSTRUMENTS_VIOLIN_H
#define INSTRUMENTSTOSTRINGEDINSTRUMENTS_VIOLIN_H


#include <string>
#include "StringedInstrument.h"

class Violin : public StringedInstrument {
public:
    Violin();
    Violin(int string);
    std::string sound() override;
};


#endif //INSTRUMENTSTOSTRINGEDINSTRUMENTS_VIOLIN_H
