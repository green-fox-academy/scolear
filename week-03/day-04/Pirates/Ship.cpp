#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Ship.h"

Ship::Ship() : _captain(false), _capacity(100){
    fillShip();
}

Ship::Ship(std::string name) : _captain(false), _capacity(100), _name(name){
    fillShip();
}

void Ship::printStatus() {
    std::cout << "\nStatus: " << _name << std::endl;
    std::cout << "Crew size: " << getCrewSize()  << std::endl;
    std::cout << getCaptainStatus() << std::endl;
    std::cout << "Crew alive: " << getCrewStatus().first << " Crew awake: " << getCrewStatus().second << std::endl;
}

void Ship::fillShip() {

    // todo: Calling this in quick succession means all ships have the same sized crew...
    // srand(time(nullptr));
    int num = rand()%_capacity + 1;

    while (_crew.size() <= num && _crew.size() < _capacity) {
        _crew.emplace_back(new Pirate);
        if(!hasCaptain()) {
            makeCaptain();
        }
    }
}

bool Ship::hasCaptain() {
    if (!_crew[0]->isAlive()) _captain = false;
    return _captain;
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

int Ship::getCapacity() {
    return _capacity;
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

bool Ship::hasAvailableCrew() {
    return (getCrewStatus().second > 0);
}

void Ship::throwOutTheDead() {
    for (int i = 0; i < _crew.size(); i++) {
        if (!_crew[i]->isAlive()) _crew.erase(_crew.begin() + i);
    }
}

bool Ship::battle(Ship* otherShip) {

    int i = 0, j = 0;
    while (hasAvailableCrew() && otherShip->hasAvailableCrew()) {

        _crew[i]->brawl(otherShip->_crew[j]);
        i++;
        j++;

        if (i >= _crew.size()) i = 0;
        if (j >= otherShip->_crew.size()) j = 0;

        throwOutTheDead();
        otherShip->throwOutTheDead();
    }

    return hasAvailableCrew();
}
