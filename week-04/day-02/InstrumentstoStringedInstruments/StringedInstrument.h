
#ifndef INSTRUMENTSTOSTRINGEDINSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTSTOSTRINGEDINSTRUMENTS_STRINGEDINSTRUMENT_H


#include "Instrument.h"

class StringedInstrument : public Instrument {
public:
    StringedInstrument(std::string name, int strings);

    virtual std::string sound() = 0;
    void play() override;

protected:
    int _numberOfStrings;
};


#endif //INSTRUMENTSTOSTRINGEDINSTRUMENTS_STRINGEDINSTRUMENT_H
