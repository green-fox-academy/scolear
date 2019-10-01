//
// Created by scolear on 2019. 10. 01..
//

#include "Copier.h"

Copier::Copier(int x, int y, int speed) : Printer2D(x, y), Scanner(speed) {}

void Copier::copy() {
    scan();
    print();
}
