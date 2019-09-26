#include <iostream>
#include "Pirate.h"
#include "Ship.h"

int main() {

    Pirate pali;

    Pirate jani;

    jani.brawl(&pali);

    pali.howsItGoingMate();
    jani.howsItGoingMate();

    Ship Beluga;
    Beluga.printStatus();
    Beluga.fillShip();
    Beluga.printStatus();


    return 0;
}