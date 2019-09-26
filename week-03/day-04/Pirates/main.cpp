#include <iostream>
#include "Pirate.h"
#include "Ship.h"

int main() {

    //srand(time(nullptr));

    Pirate pali;

    Pirate jani;

    pali.makeCaptain();
    jani.brawl(&pali);

    pali.howsItGoingMate();
    jani.howsItGoingMate();

    Ship Beluga("Beluga");
    Beluga.fillShip();
    Beluga.printStatus();

    Ship Astra("Astra");
    Astra.fillShip();
    Astra.printStatus();

    Beluga.battle(&Astra);

    Beluga.printStatus();
    Astra.printStatus();


    return 0;
}