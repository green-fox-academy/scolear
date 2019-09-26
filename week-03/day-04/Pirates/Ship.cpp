#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Ship.h"

Ship::Ship() : _captain(false), _capacity(100){}

void Ship::printStatus() {
    std::cout << "\nStatus: " << std::endl;
    std::cout << "Crew size: " << getCrewSize() << " Has captain: " << (hasCaptain() ? "yes" : "no") << std::endl;
    std::cout << getCaptainStatus() << std::endl;
    std::cout << "Crew alive: " << getCrewStatus().first << " Crew awake: " << getCrewStatus().second <<
}

bool Ship::hasCaptain() {
    return _captain;
}

void Ship::fillShip() {

    srand(time(nullptr));
    int num = rand()%100 + 1;

    while (_crew.size() <= num && _crew.size() < _capacity) {
        _crew.push_back(new Pirate);
        if(!hasCaptain()) {
            makeCaptain();
        }
    }
}

void Ship::makeCaptain() {
    while(!_captain) {
        _crew[0]->makeCaptain();
        _captain = true;
    }
}

std::string Ship::getCaptainStatus() {
    if (hasCaptain() && _crew[0]->isCaptain()) {
        std::string str = "Captain is ";
        str += (_crew[0]->isAlive() ? (_crew[0]->isAwake() ? "alive, awake, " : "alive, passed out, ") : "dead, ");
        str += "drank " + std::to_string( _crew[0]->getDrunkenness()) + " rums.";
        return str;
    } else {
        return "The ship has no captain.";
    }
}

int Ship::getCrewSize() {
    return _crew.size();
}

std::pair<int,int> Ship::getCrewStatus() {
    int alive = 0;
    int awake = 0;

    for (auto & i : _crew) {
        if (i->isAlive() && i->isAwake()) {
            alive++;
            awake++;
        } else if (i->isAlive()) {
            alive++;
        }
    }
    return std::make_pair(alive, awake);
}
