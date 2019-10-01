
#ifndef DEVICES_PRINTER2D_H
#define DEVICES_PRINTER2D_H


#include "Printer.h"

class Printer2D : public Printer {
public:
    Printer2D(int, int);
    std::string getSize() override;

protected:
    int _sizeX;
    int _sizeY;
};


#endif //DEVICES_PRINTER2D_H
