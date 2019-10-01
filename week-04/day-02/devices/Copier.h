#ifndef DEVICES_COPIER_H
#define DEVICES_COPIER_H


#include "Printer2D.h"
#include "Scanner.h"

class Copier : public Printer2D, public Scanner {
public:
    Copier(int x, int y, int speed);
    void copy();
};


#endif //DEVICES_COPIER_H
