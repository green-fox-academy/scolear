#include <iostream>
#include "Helicopter.h"
#include "Bird.h"

int main() {

    Helicopter h;
    Bird b("bibi");

    h.fly();
    h.takeOff();
    h.fly();
    h.land();

    b.fly();
    b.takeOff();
    b.fly();
    b.land();

    return 0;
}