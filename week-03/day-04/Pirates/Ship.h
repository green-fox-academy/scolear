/*
Create a Ship class.
The Ship stores Pirate-s instances in a vector as the crew and has one captain who is also a Pirate.
When a ship is created it doesn't have a crew or a captain.
The ship can be filled with pirates and a captain via fillShip() method.
    Filling the ship with a captain and random number of pirates.
Ships should be represented in a nice way on command line including information about
    captains consumed rum, state (passed out / died)
    number of alive pirates in the crew
Ships should have a method to battle other ships: ship.battle(otherShip)
    should return true if the actual ship wins
    the ship should win if its calculated score is higher
    calculate score: Number of Alive pirates in the crew - Number of consumed rum by the captain
    The loser crew has a random number of losses (deaths).
    The winner captain and crew has a party, including a random number of rum :)
 */
#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H

#include <vector>
#include "Pirate.h"

class Ship {
public:
    Ship();
    explicit Ship(std::string);

    void printStatus();
    void fillShip();
    bool hasCaptain();
    void makeCaptain();
    int getCrewSize();

    bool battle(Ship* otherShip);

private:
    std::string getCaptainStatus();
    std::pair<int,int> getCrewStatus();

    std::vector<Pirate*> _crew;
    bool _captain;
    int _capacity;
    std::string _name;
};


#endif //PIRATES_SHIP_H
