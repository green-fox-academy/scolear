
#include <iostream>
#include "Pirate.h"

Pirate::Pirate(): _intoxication(0), _alive(true), _awake(true){}

void Pirate::drinkSomeRum() {
    if(_alive && _awake) {
        _intoxication++;
    } else if (!_alive) {
        std::cout << "He's dead." << std::endl;
    }
}

void Pirate::howsItGoingMate() {

    if(_alive && _awake && _intoxication < 4) {
        std::cout << "\"Pour me anudder, ya wanker!\"" << std::endl;
    } else if (_alive && _awake && _intoxication >= 4) {
        std::cout << "\"Arghh, I'ma Pirate. How d'ya d'ink its goin? Bugger off!\"" << std::endl;
        passOut();
    } else if (!_alive) {
        std::cout << "He's dead." << std::endl;
    } else if (_alive && !_awake) {
        std::cout << "He's just waking up..." << std::endl;
        wakeUp();
    }
}

void Pirate::passOut() {
    _awake = false;
}

void Pirate::wakeUp() {
    _awake = true;
    _intoxication = 0;
}

void Pirate::die() {
    _alive = false;
    _awake = false;
}

bool Pirate::isAlive() {
    return _alive;
}

bool Pirate::isAwake() {
    return _awake;
}

void Pirate::brawl(Pirate *otherPirate) {
    srand(time(nullptr));
    int outcome = rand() % 30;

    while ((_alive && otherPirate->isAlive()) && (_awake && otherPirate->isAwake())) {
        switch (outcome)
        {
            case 0 ... 9:
                die();
                break;
            case 10 ... 19:
                otherPirate->die();
                break;
            case 20 ... 29:
                passOut();
                otherPirate->passOut();
                break;
            default:
                std::cout << "Something wrong with brawl()" << std::endl;
                break;
        }
    }
}

