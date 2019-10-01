#ifndef INSTRUMENTSTOSTRINGEDINSTRUMENTS_INSTRUMENT_H
#define INSTRUMENTSTOSTRINGEDINSTRUMENTS_INSTRUMENT_H


#include <string>

class Instrument {
public:
    Instrument(std::string name);
    virtual void play() = 0;
    std::string _name;

};


#endif //INSTRUMENTSTOSTRINGEDINSTRUMENTS_INSTRUMENT_H
