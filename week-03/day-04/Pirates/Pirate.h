/*
Create a Pirate class. While you can add other fields and methods, you must have these methods:-

    drinkSomeRum() - intoxicates the Pirate some
    howsItGoingMate() - when called, the Pirate replies, if drinkSomeRun was called:-
        0 to 4 times, "Pour me anudder!"
        else, "Arghh, I'ma Pirate. How d'ya d'ink its goin?", the pirate passes out and sleeps it off.

If you manage to get this far, then you can try to do the following.

    die() - this kills off the pirate, in which case, drinkSomeRum, etc. just result in he's dead.
    brawl(x) - where pirate fights another pirate (if that other pirate is alive)
                and there's a 1/3 chance, 1 dies, the other dies or they both pass out.

And... if you get that far...
Add a parrot.
 */
#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

class Pirate {
public:
    Pirate();

    void drinkSomeRum();
    void howsItGoingMate();
    int getDrunkenness();
    void passOut();
    void wakeUp();
    bool isAwake();
    void die();
    bool isAlive();
    void makeCaptain();
    bool isCaptain();

    void brawl(Pirate* otherPirate);

private:
    int _intoxication;
    bool _alive;
    bool _awake;
    bool _captain;

};

#endif //PIRATES_PIRATE_H
